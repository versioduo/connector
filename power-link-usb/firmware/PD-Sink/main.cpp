extern "C" {
#include "cy_app.h"
#include "cy_app_fault_handlers.h"
#include "cy_app_instrumentation.h"
#include "cy_app_pdo.h"
#include "cy_app_sink.h"
#include "cy_app_swap.h"
#include "cy_app_timer_id.h"
#include "cy_app_vdm.h"
#include "cy_pdl.h"
#include "cy_pdstack_common.h"
#include "cy_pdstack_dpm.h"
#include "cy_pdutils_sw_timer.h"
#include "cy_usbpd_common.h"
#include "cy_usbpd_phy.h"
#include "cy_usbpd_typec.h"
#include "cy_usbpd_vbus_ctrl.h"
#include "cybsp.h"
#include "mtbcfg_ezpd.h"
}

#include <array>

namespace {
  cy_stc_pdutils_sw_timer_t timerContext{};
  cy_stc_pdstack_context_t  pdStackContext{};
  cy_stc_usbpd_context_t    usbPdContext{};

  class State {
  public:
    enum class Contract { Disconnected, Failed, Established };

    static auto contract() -> Contract {
      if (!pdStackContext.dpmConfig.attach)
        return Contract::Disconnected;

      if (!pdStackContext.dpmConfig.contractExist)
        return Contract::Failed;

      if (pdStackContext.dpmStat.contract.minVolt < 9 * 1000)
        return Contract::Failed;

      return Contract::Established;
    }

    static auto led(cy_timer_id_t id, void* context) -> void {
      uint16_t period{1000};

      switch (contract()) {
        case Contract::Disconnected:
          // LEDs off.
          Cy_GPIO_Set(LED_RED_PORT, LED_RED_PIN);
          Cy_GPIO_Set(LED_ORANGE_PORT, LED_ORANGE_PIN);
          break;

        case Contract::Failed:
          // Red LED.
          Cy_GPIO_Clr(LED_RED_PORT, LED_RED_PIN);
          Cy_GPIO_Set(LED_ORANGE_PORT, LED_ORANGE_PIN);
          break;

        case Contract::Established:
          // The orange LED blinks with a period of the negotiated voltage / 10.
          Cy_GPIO_Set(LED_RED_PORT, LED_RED_PIN);
          Cy_GPIO_Inv(LED_ORANGE_PORT, LED_ORANGE_PIN);
          period = pdStackContext.dpmStat.contract.minVolt / 10;
          break;
      }

      Cy_PdUtils_SwTimer_Start(&timerContext, nullptr, id, period, &led);
    }
  };
}

auto main() -> int {
  if (cybsp_init() != CY_RSLT_SUCCESS)
    CY_ASSERT(0);

  {
    static const cy_stc_sysint_t wdt_interrupt_config{
      .intrSrc{IRQn_Type(srss_interrupt_wdt_IRQn)},
      .intrPriority{},
    };

    Cy_SysInt_Init(&wdt_interrupt_config, [] {
      Cy_WDT_ClearInterrupt();
      Cy_PdUtils_SwTimer_InterruptHandler(&(timerContext));
    });
    NVIC_EnableIRQ(wdt_interrupt_config.intrSrc);
  }

  {
    static cy_stc_pdutils_timer_config_t timerConfig{
      .sys_clk_freq{Cy_SysClk_ClkSysGetFrequency()},
    };

    Cy_PdUtils_SwTimer_Init(&timerContext, &timerConfig);
  }

  __enable_irq();

  Cy_App_Instrumentation_Init(&timerContext);
  Cy_App_Instrumentation_RegisterCb([](uint8_t port, uint8_t evt) {
    evt += APP_TOTAL_EVENTS;
    sln_pd_event_handler(&pdStackContext, (cy_en_pdstack_app_evt_t)evt, nullptr);
  });

  {
    static const cy_stc_sysint_t usbpd_intr0_config{
      .intrSrc{mtb_usbpd_port0_IRQ},
      .intrPriority{},
    };

    Cy_SysInt_Init(&usbpd_intr0_config, [] { Cy_USBPD_Intr0Handler(&usbPdContext); });
    NVIC_EnableIRQ(usbpd_intr0_config.intrSrc);
  }

  {
    static const cy_stc_sysint_t usbpd_intr1_config{
      .intrSrc{mtb_usbpd_port0_DS_IRQ},
      .intrPriority{},
    };

    Cy_SysInt_Init(&usbpd_intr1_config, []() { Cy_USBPD_Intr1Handler(&usbPdContext); });
    NVIC_EnableIRQ(usbpd_intr1_config.intrSrc);
  }

  Cy_USBPD_Init(&usbPdContext, 0, mtb_usbpd_port0_HW, mtb_usbpd_port0_HW_TRIM, (cy_stc_usbpd_config_t*)&mtb_usbpd_port0_config, [] {
    return &(pdStackContext.dpmConfig);
  });

  {
    static const cy_stc_pdstack_app_cbk_t appHandler{
      .app_event_handler{Cy_App_EventHandler},
      .vconn_enable{Cy_App_VconnEnable},
      .vconn_disable{Cy_App_VconnDisable},
      .vconn_is_present{Cy_App_VconnIsPresent},
      .vbus_is_present{Cy_App_VbusIsPresent},
      .vbus_discharge_on{Cy_App_VbusDischargeOn},
      .vbus_discharge_off{Cy_App_VbusDischargeOff},
      .psnk_set_voltage{Cy_App_Sink_SetVoltage},
      .psnk_set_current{Cy_App_Sink_SetCurrent},
      .psnk_enable{[](cy_stc_pdstack_context_t* context) {
        if (State::contract() == State::Contract::Established)
          Cy_App_Sink_Enable(context);
      }},
      .psnk_disable{Cy_App_Sink_Disable},
      .eval_src_cap{Cy_App_Pdo_EvalSrcCap},
      .eval_dr_swap{Cy_App_Swap_EvalDrSwap},
      .eval_pr_swap{Cy_App_Swap_EvalPrSwap},
      .eval_vconn_swap{Cy_App_Swap_EvalVconnSwap},
      .eval_vdm{Cy_App_Vdm_EvalVdmMsg},
      .vbus_get_value{Cy_App_VbusGetValue},
    };

    static const cy_stc_pdstack_dpm_params_t dpm_params{
      .defCur{90},
      .typeCSnkWaitCapPeriod{},
      .muxEnableDelayPeriod{},
      .dpmDefCableCap{300},
      .dpmRpAudioAcc{CY_PD_RP_TERM_RP_CUR_DEF},
      .dpmSnkWaitCapPeriod{335},
    };

    Cy_PdStack_Dpm_Init(
      &pdStackContext,
      &usbPdContext,
      &mtb_usbpd_port0_pdstack_config,
      [](cy_stc_pdstack_context_t* context) -> cy_stc_pdstack_app_cbk_t* {
        return ((cy_stc_pdstack_app_cbk_t*)&appHandler);
      }(&pdStackContext),
      &dpm_params,
      &timerContext);
  }

  {
    static const std::array<uint32_t, 7> discIdResp{0xff00a841, 0x184004b4, 0x00000000, 0xf5030000};
    static const cy_stc_app_params_t     app_params{
          .appVbusPollAdcId{CY_USBPD_ADC_ID_0},
          .appVbusPollAdcInput{CY_USBPD_ADC_INPUT_AMUX_B},
          .prefPowerRole{}, // 0: Sink, 1: Source, 2: No Preference
          .prefDataRole{},  // 0: UFP, 1: DFP, 2: No Preference
          .discIdResp{(cy_pd_pd_do_t*)discIdResp.data()},
          .discIdLen{0x14},
          .swapResponse{0x3F},
    };
    Cy_App_Init(&pdStackContext, &app_params);
  }

  Cy_App_Fault_InitVars(&pdStackContext);
  Cy_App_Instrumentation_Start();
  Cy_PdStack_Dpm_Start(&pdStackContext);
  State::led(CY_PDUTILS_TIMER_USER_START_ID, nullptr);

  for (;;) {
    Cy_PdStack_Dpm_Task(&pdStackContext);
    Cy_App_Task(&pdStackContext);
    Cy_App_Instrumentation_Task();
    Cy_App_SystemSleep(&pdStackContext, nullptr);
  }
}
