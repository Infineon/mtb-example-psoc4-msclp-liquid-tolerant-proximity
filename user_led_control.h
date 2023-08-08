/******************************************************************************
* File Name: user_led_control.h
*
* Description: This file contains all the function prototypes of
*              LED data packets for SPI master.
*
* Copyright 2021-2022, Cypress Semiconductor Corporation (an Infineon company) or
* an affiliate of Cypress Semiconductor Corporation.  All rights reserved.
*
* This software, including source code, documentation and related
* materials ("Software") is owned by Cypress Semiconductor Corporation
* or one of its affiliates ("Cypress") and is protected by and subject to
* worldwide patent protection (United States and foreign),
* United States copyright laws and international treaty provisions.
* Therefore, you may use this Software only as provided in the license
* agreement accompanying the software package from which you
* obtained this Software ("EULA").
* If no EULA applies, Cypress hereby grants you a personal, non-exclusive,
* non-transferable license to copy, modify, and compile the Software
* source code solely for use in connection with Cypress's
* integrated circuit products.  Any reproduction, modification, translation,
* compilation, or representation of this Software except as specified
* above is prohibited without the express written permission of Cypress.
*
* Disclaimer: THIS SOFTWARE IS PROVIDED AS-IS, WITH NO WARRANTY OF ANY KIND,
* EXPRESS OR IMPLIED, INCLUDING, BUT NOT LIMITED TO, NONINFRINGEMENT, IMPLIED
* WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE. Cypress
* reserves the right to make changes to the Software without notice. Cypress
* does not assume any liability arising out of the application or use of the
* Software or any product or circuit described in the Software. Cypress does
* not authorize its products for use in any products where a malfunction or
* failure of the Cypress product may reasonably be expected to result in
* significant property damage, injury or death ("High Risk Product"). By
* including Cypress's product in a High Risk Product, the manufacturer
* of such system or application assumes all risk of such use and in doing
* so agrees to indemnify Cypress against all liability.
*******************************************************************************/
#ifndef SOURCE_USER_LED_CONTROL_H_
#define SOURCE_USER_LED_CONTROL_H_

#include "user_spi.h"

/*******************************************************************************
* Macros
*******************************************************************************/
#define NUM_OF_LEDS                 (3u)
#define NUM_OF_LED_COLORS           (3u)
#define NUM_OF_BITS_PER_COLOR       (8u)

/* Number of bits to be transmitted on SPI for each bit of LED color */
#define TX_BITS_PER_LED_COLOR_BIT   (4u)

#define LED_RESET_INTERVAL_BITS     (8u)

/* Number of bits to be transmitted on SPI for each LED color*/
#define TX_BITS_PER_LED_COLOR       (NUM_OF_BITS_PER_COLOR * TX_BITS_PER_LED_COLOR_BIT)

/* Number of bits to be transmitted on SPI for each LED (all 3 colors)*/
#define TX_BITS_PER_LED             (NUM_OF_LED_COLORS * TX_BITS_PER_LED_COLOR)

/* Number of bytes per packets to be transmitted on SPI for all 3 LEDs*/
#define LED_BYTES_PER_PACKET        (((TX_BITS_PER_LED * NUM_OF_LEDS) + LED_RESET_INTERVAL_BITS))/(8u)

#define LED_STATE_OFF               (8u)
#define LED_STATE_ON                (14u)

#define LED1                        (0u)
#define LED2                        (1u)
#define LED3                        (2u)

/*******************************************************************************
* RGB LED context
*******************************************************************************/
typedef struct ledData
{
    uint8_t red;
    uint8_t green;
    uint8_t blue;
} ledData_t;

/* serial LED context structure  */
typedef struct serialLedContext
{
    ledData_t serialLedData[NUM_OF_LEDS];
} serialLedContext_t;


/*******************************************************************************
* Function Prototypes
*******************************************************************************/
void ProcessSerialLed(serialLedContext_t *);

#endif /* SOURCE_USER_LED_CONTROL_H_ */

/* [] END OF FILE */
