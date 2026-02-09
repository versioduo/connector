/*******************************************************************************
 * File Name: cycfg_pins.c
 *
 * Description:
 * Pin configuration
 * This file was automatically generated and should not be modified.
 * Configurator Backend 3.70.0
 * device-db 4.34.0.9502
 * mtb-pdl-cat2 2.19.1.17368
 *
 *******************************************************************************
 * Copyright 2026 Cypress Semiconductor Corporation (an Infineon company) or
 * an affiliate of Cypress Semiconductor Corporation.
 * SPDX-License-Identifier: Apache-2.0
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 ******************************************************************************/

#include "cycfg_pins.h"

const cy_stc_gpio_pin_config_t CYBSP_SWDCK_config =
{
    .outVal = 1,
    .driveMode = CY_GPIO_DM_STRONG,
    .hsiom = CYBSP_SWDCK_HSIOM,
    .intEdge = CY_GPIO_INTR_DISABLE,
    .vtrip = CY_GPIO_VTRIP_CMOS,
    .slewRate = CY_GPIO_SLEW_FAST,
};

#if defined (CY_USING_HAL)
const cyhal_resource_inst_t CYBSP_SWDCK_obj =
{
    .type = CYHAL_RSC_GPIO,
    .block_num = CYBSP_SWDCK_PORT_NUM,
    .channel_num = CYBSP_SWDCK_PIN,
};
#endif /* defined (CY_USING_HAL) */

const cy_stc_gpio_pin_config_t CYBSP_SWDIO_config =
{
    .outVal = 1,
    .driveMode = CY_GPIO_DM_STRONG,
    .hsiom = CYBSP_SWDIO_HSIOM,
    .intEdge = CY_GPIO_INTR_DISABLE,
    .vtrip = CY_GPIO_VTRIP_CMOS,
    .slewRate = CY_GPIO_SLEW_FAST,
};

#if defined (CY_USING_HAL)
const cyhal_resource_inst_t CYBSP_SWDIO_obj =
{
    .type = CYHAL_RSC_GPIO,
    .block_num = CYBSP_SWDIO_PORT_NUM,
    .channel_num = CYBSP_SWDIO_PIN,
};
#endif /* defined (CY_USING_HAL) */

const cy_stc_gpio_pin_config_t LED_RED_config =
{
    .outVal = 1,
    .driveMode = CY_GPIO_DM_STRONG_IN_OFF,
    .hsiom = LED_RED_HSIOM,
    .intEdge = CY_GPIO_INTR_DISABLE,
    .vtrip = CY_GPIO_VTRIP_CMOS,
    .slewRate = CY_GPIO_SLEW_FAST,
};

#if defined (CY_USING_HAL)
const cyhal_resource_inst_t LED_RED_obj =
{
    .type = CYHAL_RSC_GPIO,
    .block_num = LED_RED_PORT_NUM,
    .channel_num = LED_RED_PIN,
};
#endif /* defined (CY_USING_HAL) */

const cy_stc_gpio_pin_config_t LED_ORANGE_config =
{
    .outVal = 1,
    .driveMode = CY_GPIO_DM_STRONG_IN_OFF,
    .hsiom = LED_ORANGE_HSIOM,
    .intEdge = CY_GPIO_INTR_DISABLE,
    .vtrip = CY_GPIO_VTRIP_CMOS,
    .slewRate = CY_GPIO_SLEW_FAST,
};

#if defined (CY_USING_HAL)
const cyhal_resource_inst_t LED_ORANGE_obj =
{
    .type = CYHAL_RSC_GPIO,
    .block_num = LED_ORANGE_PORT_NUM,
    .channel_num = LED_ORANGE_PIN,
};
#endif /* defined (CY_USING_HAL) */

const cy_stc_gpio_pin_config_t CYBSP_USB_DP_config =
{
    .outVal = 1,
    .driveMode = CY_GPIO_DM_ANALOG,
    .hsiom = CYBSP_USB_DP_HSIOM,
    .intEdge = CY_GPIO_INTR_DISABLE,
    .vtrip = CY_GPIO_VTRIP_CMOS,
    .slewRate = CY_GPIO_SLEW_FAST,
};

#if defined (CY_USING_HAL)
const cyhal_resource_inst_t CYBSP_USB_DP_obj =
{
    .type = CYHAL_RSC_GPIO,
    .block_num = CYBSP_USB_DP_PORT_NUM,
    .channel_num = CYBSP_USB_DP_PIN,
};
#endif /* defined (CY_USING_HAL) */

const cy_stc_gpio_pin_config_t CYBSP_USB_DM_config =
{
    .outVal = 1,
    .driveMode = CY_GPIO_DM_ANALOG,
    .hsiom = CYBSP_USB_DM_HSIOM,
    .intEdge = CY_GPIO_INTR_DISABLE,
    .vtrip = CY_GPIO_VTRIP_CMOS,
    .slewRate = CY_GPIO_SLEW_FAST,
};

#if defined (CY_USING_HAL)
const cyhal_resource_inst_t CYBSP_USB_DM_obj =
{
    .type = CYHAL_RSC_GPIO,
    .block_num = CYBSP_USB_DM_PORT_NUM,
    .channel_num = CYBSP_USB_DM_PIN,
};
#endif /* defined (CY_USING_HAL) */

void init_cycfg_pins(void)
{
    Cy_GPIO_Pin_Init(CYBSP_SWDCK_PORT, CYBSP_SWDCK_PIN, &CYBSP_SWDCK_config);
    Cy_GPIO_Pin_Init(CYBSP_SWDIO_PORT, CYBSP_SWDIO_PIN, &CYBSP_SWDIO_config);
    Cy_GPIO_Pin_Init(LED_RED_PORT, LED_RED_PIN, &LED_RED_config);
    Cy_GPIO_Pin_Init(LED_ORANGE_PORT, LED_ORANGE_PIN, &LED_ORANGE_config);
    Cy_GPIO_Pin_Init(CYBSP_USB_DP_PORT, CYBSP_USB_DP_PIN, &CYBSP_USB_DP_config);
    Cy_GPIO_Pin_Init(CYBSP_USB_DM_PORT, CYBSP_USB_DM_PIN, &CYBSP_USB_DM_config);
}
void reserve_cycfg_pins(void)
{
#if defined (CY_USING_HAL)
    cyhal_hwmgr_reserve(&CYBSP_SWDCK_obj);
    cyhal_hwmgr_reserve(&CYBSP_SWDIO_obj);
    cyhal_hwmgr_reserve(&LED_RED_obj);
    cyhal_hwmgr_reserve(&LED_ORANGE_obj);
    cyhal_hwmgr_reserve(&CYBSP_USB_DP_obj);
    cyhal_hwmgr_reserve(&CYBSP_USB_DM_obj);
#endif /* defined (CY_USING_HAL) */
}
