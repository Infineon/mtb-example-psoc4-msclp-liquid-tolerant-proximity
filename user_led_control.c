/*******************************************************************************
 * File Name:   user_led_control.c
 *
 * Description: This file contains required functions for creating required
 *              LED data packets for SPI master.
 *
 *******************************************************************************
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
 ******************************************************************************/

#include "user_led_control.h"


/*******************************************************************************
* Global Definitions
*******************************************************************************/
uint8_t ledTxBuffer[LED_BYTES_PER_PACKET];

serialLedContext_t ledContext;

/*******************************************************************************
* Function Name: ProcessSerialLed
********************************************************************************
* Summary:
* This function creates the required data packets for the serial LEDs. 
* Each LED has 3 color and each color can have brightness fromm 0 to 255 (1 byte)
* Each bit of LED color is represented by 4 bits in the SPI transmission frame - 
* '0' => '1000' and '1' => '1110'.
*
* This functions performs following:
*  - initializes and fills the SPI packet ledTxBuffer as per user LED data,
*  - initiates transfer of ledTxBuffer through SPI master,
*  - clears the SPI Tx FIFO after the completion of data transfer
*
* Parameters:
* The pointer to the serial LED context structure serial_ledContext_t.
*
*******************************************************************************/
void ProcessSerialLed(serialLedContext_t * ptr_ledContext)
{

    uint8_t i, ledIndex, colorIndex, ledByte, nibbleIndex, bufferIndex = 1u;

    /* Clear Tx buffer */
    ledTxBuffer[0u] = 0u; /* LED frame reset byte */
    ledTxBuffer[1u] = 0u;

    /* Process each LED */
    for(ledIndex = 0u; ledIndex < NUM_OF_LEDS; ledIndex++)
    {
        /* Process each colors */
        for(colorIndex = 0u; colorIndex < NUM_OF_LED_COLORS; colorIndex++)
        {
            if(colorIndex == 0u)
            {
                /* Process the red color data*/
                ledByte = ptr_ledContext->serialLedData[ledIndex].red;
            }
            else if (colorIndex == 1u)
            {
                /* Process the green color data*/
                ledByte = ptr_ledContext->serialLedData[ledIndex].green;
            }
            else
            {
                /* Process the blue color data*/
                ledByte = ptr_ledContext->serialLedData[ledIndex].blue;
            }
            
            nibbleIndex = 0u;

            /* Convert each data bit into LED data frame nibble: '0' => '1000' and '1' => '1110' */
            /* Process a byte at a time */
            for (i = 0u; i < 8u; i++)
            {
                if (ledByte & 0x80)
                {
                    ledTxBuffer[bufferIndex] =  ledTxBuffer[bufferIndex] + LED_STATE_ON; 
                }
                else
                {
                    ledTxBuffer[bufferIndex] =  ledTxBuffer[bufferIndex] +  LED_STATE_OFF; 
                }

                /* Move the first nibble to MSB side*/
                if (nibbleIndex == 0u)
                {
                    ledTxBuffer[bufferIndex] = ledTxBuffer[bufferIndex] << 4u;
                }
                /* Each bit of LED color is represented by 4 bits in the transmission frame;
                Point to next byte in the Tx buffer byte array, if 2 color bits (1 tx buffer byte) 
                are processed  */
                nibbleIndex++;
                
                if (nibbleIndex > 1u)
                {
                    nibbleIndex = 0u;
                    bufferIndex++;

                    /* Clear next byte of the buffer */
                    ledTxBuffer[bufferIndex] = 0u;
                }
                /* Process next bit */
                ledByte = ledByte << 1u;
            }
        }
    }
    /* Send the packet to LEDs on SPI */
    SendSpiPacket(ledTxBuffer, LED_BYTES_PER_PACKET);
    /* Clear SPI transmission buffer */
    Cy_SCB_SPI_ClearTxFifo(CYBSP_MASTER_SPI_HW);
}
/* [] END OF FILE */
