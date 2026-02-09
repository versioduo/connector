/*******************************************************************************
 * File Name: cycfg_pins.h
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

#if !defined(CYCFG_PINS_H)
#define CYCFG_PINS_H

#include "cycfg_notices.h"
#include "cy_gpio.h"
#include "cycfg_routing.h"

#if defined (CY_USING_HAL)
#include "cyhal_hwmgr.h"
#endif /* defined (CY_USING_HAL) */

#if defined(__cplusplus)
extern "C" {
#endif /* defined(__cplusplus) */

#define CYBSP_SWDCK_ENABLED 1U
#define CYBSP_SWDCK_PORT GPIO_PRT1
#define CYBSP_SWDCK_PORT_NUM 1U
#define CYBSP_SWDCK_PIN 1U
#define CYBSP_SWDCK_NUM 1U
#define CYBSP_SWDCK_DRIVEMODE CY_GPIO_DM_STRONG
#define CYBSP_SWDCK_INIT_DRIVESTATE 1
#ifndef ioss_0_port_1_pin_1_HSIOM
    #define ioss_0_port_1_pin_1_HSIOM HSIOM_SEL_GPIO
#endif
#define CYBSP_SWDCK_HSIOM ioss_0_port_1_pin_1_HSIOM
#define CYBSP_SWDCK_IRQ ioss_interrupt_gpio_IRQn

#if defined (CY_USING_HAL)
#define CYBSP_SWDCK_HAL_PORT_PIN P1_1
#define CYBSP_SWDCK P1_1
#define CYBSP_SWDCK_HAL_IRQ CYHAL_GPIO_IRQ_NONE
#define CYBSP_SWDCK_HAL_DIR CYHAL_GPIO_DIR_BIDIRECTIONAL 
#define CYBSP_SWDCK_HAL_DRIVEMODE CYHAL_GPIO_DRIVE_STRONG
#endif /* defined (CY_USING_HAL) */

#define CYBSP_SWDIO_ENABLED 1U
#define CYBSP_SWDIO_PORT GPIO_PRT1
#define CYBSP_SWDIO_PORT_NUM 1U
#define CYBSP_SWDIO_PIN 2U
#define CYBSP_SWDIO_NUM 2U
#define CYBSP_SWDIO_DRIVEMODE CY_GPIO_DM_STRONG
#define CYBSP_SWDIO_INIT_DRIVESTATE 1
#ifndef ioss_0_port_1_pin_2_HSIOM
    #define ioss_0_port_1_pin_2_HSIOM HSIOM_SEL_GPIO
#endif
#define CYBSP_SWDIO_HSIOM ioss_0_port_1_pin_2_HSIOM
#define CYBSP_SWDIO_IRQ ioss_interrupt_gpio_IRQn

#if defined (CY_USING_HAL)
#define CYBSP_SWDIO_HAL_PORT_PIN P1_2
#define CYBSP_SWDIO P1_2
#define CYBSP_SWDIO_HAL_IRQ CYHAL_GPIO_IRQ_NONE
#define CYBSP_SWDIO_HAL_DIR CYHAL_GPIO_DIR_BIDIRECTIONAL 
#define CYBSP_SWDIO_HAL_DRIVEMODE CYHAL_GPIO_DRIVE_STRONG
#define CYBSP_I2C_SCL (P4_0)
#define CYBSP_I2C_SDA (P4_1)
#endif /* defined (CY_USING_HAL) */

#define LED_RED_ENABLED 1U
#define LED_RED_PORT GPIO_PRT5
#define LED_RED_PORT_NUM 5U
#define LED_RED_PIN 3U
#define LED_RED_NUM 3U
#define LED_RED_DRIVEMODE CY_GPIO_DM_STRONG_IN_OFF
#define LED_RED_INIT_DRIVESTATE 1
#ifndef ioss_0_port_5_pin_3_HSIOM
    #define ioss_0_port_5_pin_3_HSIOM HSIOM_SEL_GPIO
#endif
#define LED_RED_HSIOM ioss_0_port_5_pin_3_HSIOM
#define LED_RED_IRQ ioss_interrupt_gpio_IRQn

#if defined (CY_USING_HAL)
#define LED_RED_HAL_PORT_PIN P5_3
#define LED_RED P5_3
#define LED_RED_HAL_IRQ CYHAL_GPIO_IRQ_NONE
#define LED_RED_HAL_DIR CYHAL_GPIO_DIR_OUTPUT 
#define LED_RED_HAL_DRIVEMODE CYHAL_GPIO_DRIVE_STRONG
#endif /* defined (CY_USING_HAL) */

#define LED_ORANGE_ENABLED 1U
#define LED_ORANGE_PORT GPIO_PRT5
#define LED_ORANGE_PORT_NUM 5U
#define LED_ORANGE_PIN 5U
#define LED_ORANGE_NUM 5U
#define LED_ORANGE_DRIVEMODE CY_GPIO_DM_STRONG_IN_OFF
#define LED_ORANGE_INIT_DRIVESTATE 1
#ifndef ioss_0_port_5_pin_5_HSIOM
    #define ioss_0_port_5_pin_5_HSIOM HSIOM_SEL_GPIO
#endif
#define LED_ORANGE_HSIOM ioss_0_port_5_pin_5_HSIOM
#define LED_ORANGE_IRQ ioss_interrupt_gpio_IRQn

#if defined (CY_USING_HAL)
#define LED_ORANGE_HAL_PORT_PIN P5_5
#define LED_ORANGE P5_5
#define LED_ORANGE_HAL_IRQ CYHAL_GPIO_IRQ_NONE
#define LED_ORANGE_HAL_DIR CYHAL_GPIO_DIR_OUTPUT 
#define LED_ORANGE_HAL_DRIVEMODE CYHAL_GPIO_DRIVE_STRONG
#endif /* defined (CY_USING_HAL) */

#define CYBSP_USB_DP_ENABLED 1U
#define CYBSP_USB_DP_PORT GPIO_PRT8
#define CYBSP_USB_DP_PORT_NUM 8U
#define CYBSP_USB_DP_PIN 0U
#define CYBSP_USB_DP_NUM 0U
#define CYBSP_USB_DP_DRIVEMODE CY_GPIO_DM_ANALOG
#define CYBSP_USB_DP_INIT_DRIVESTATE 1
#ifndef ioss_0_port_8_pin_0_HSIOM
    #define ioss_0_port_8_pin_0_HSIOM HSIOM_SEL_GPIO
#endif
#define CYBSP_USB_DP_HSIOM ioss_0_port_8_pin_0_HSIOM
#define CYBSP_USB_DP_IRQ ioss_interrupt_gpio_IRQn

#if defined (CY_USING_HAL)
#define CYBSP_USB_DP_HAL_PORT_PIN P8_0
#define CYBSP_USB_DP P8_0
#define CYBSP_USB_DP_HAL_IRQ CYHAL_GPIO_IRQ_NONE
#define CYBSP_USB_DP_HAL_DIR CYHAL_GPIO_DIR_INPUT 
#define CYBSP_USB_DP_HAL_DRIVEMODE CYHAL_GPIO_DRIVE_ANALOG
#endif /* defined (CY_USING_HAL) */

#define CYBSP_USB_DM_ENABLED 1U
#define CYBSP_USB_DM_PORT GPIO_PRT8
#define CYBSP_USB_DM_PORT_NUM 8U
#define CYBSP_USB_DM_PIN 1U
#define CYBSP_USB_DM_NUM 1U
#define CYBSP_USB_DM_DRIVEMODE CY_GPIO_DM_ANALOG
#define CYBSP_USB_DM_INIT_DRIVESTATE 1
#ifndef ioss_0_port_8_pin_1_HSIOM
    #define ioss_0_port_8_pin_1_HSIOM HSIOM_SEL_GPIO
#endif
#define CYBSP_USB_DM_HSIOM ioss_0_port_8_pin_1_HSIOM
#define CYBSP_USB_DM_IRQ ioss_interrupt_gpio_IRQn

#if defined (CY_USING_HAL)
#define CYBSP_USB_DM_HAL_PORT_PIN P8_1
#define CYBSP_USB_DM P8_1
#define CYBSP_USB_DM_HAL_IRQ CYHAL_GPIO_IRQ_NONE
#define CYBSP_USB_DM_HAL_DIR CYHAL_GPIO_DIR_INPUT 
#define CYBSP_USB_DM_HAL_DRIVEMODE CYHAL_GPIO_DRIVE_ANALOG
#endif /* defined (CY_USING_HAL) */

extern const cy_stc_gpio_pin_config_t CYBSP_SWDCK_config;

#if defined (CY_USING_HAL)
extern const cyhal_resource_inst_t CYBSP_SWDCK_obj;
#endif /* defined (CY_USING_HAL) */

extern const cy_stc_gpio_pin_config_t CYBSP_SWDIO_config;

#if defined (CY_USING_HAL)
extern const cyhal_resource_inst_t CYBSP_SWDIO_obj;
#endif /* defined (CY_USING_HAL) */

extern const cy_stc_gpio_pin_config_t LED_RED_config;

#if defined (CY_USING_HAL)
extern const cyhal_resource_inst_t LED_RED_obj;
#endif /* defined (CY_USING_HAL) */

extern const cy_stc_gpio_pin_config_t LED_ORANGE_config;

#if defined (CY_USING_HAL)
extern const cyhal_resource_inst_t LED_ORANGE_obj;
#endif /* defined (CY_USING_HAL) */

extern const cy_stc_gpio_pin_config_t CYBSP_USB_DP_config;

#if defined (CY_USING_HAL)
extern const cyhal_resource_inst_t CYBSP_USB_DP_obj;
#endif /* defined (CY_USING_HAL) */

extern const cy_stc_gpio_pin_config_t CYBSP_USB_DM_config;

#if defined (CY_USING_HAL)
extern const cyhal_resource_inst_t CYBSP_USB_DM_obj;
#endif /* defined (CY_USING_HAL) */

void init_cycfg_pins(void);
void reserve_cycfg_pins(void);

#if defined(__cplusplus)
}
#endif /* defined(__cplusplus) */

#endif /* CYCFG_PINS_H */
