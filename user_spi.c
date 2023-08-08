/*******************************************************************************
 * File Name:   user_spi.c
 *
 * Description: This file contains function definitions for SPI Master.
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

#include "user_spi.h"

/*******************************************************************************
 * Global Variables
 ******************************************************************************/
cy_stc_scb_spi_context_t UserSpiContext;


/*******************************************************************************
 * Function Name: UserSpiInterrupt
 *******************************************************************************
 *
 * Invokes the Cy_SCB_SPI_Interrupt() PDL driver function.
 *
 ******************************************************************************/
void UserSpiInterrupt(void)
{
    Cy_SCB_SPI_Interrupt(CYBSP_MASTER_SPI_HW, &UserSpiContext);
}


/*******************************************************************************
 * Function Name: InitSpiMaster
 *******************************************************************************
 *
 * Summary:
 * This function initializes the SPI master based on the configuration done in
 * design.modus file.
 *
 * Parameters:
 * None
 *
 * Return:
 * uint32_t - Returns INIT_SUCCESS if the initialization is successful.
 * Otherwise it returns INIT_FAILURE
 *
 ******************************************************************************/
uint32_t InitSpiMaster(void)
{
    cy_en_scb_spi_status_t result;
    cy_en_sysint_status_t sysSpiStatus;

    /* Configure the SPI block */

    result = Cy_SCB_SPI_Init(CYBSP_MASTER_SPI_HW, &CYBSP_MASTER_SPI_config, &UserSpiContext);
    if ( result != CY_SCB_SPI_SUCCESS)
    {
        return INIT_FAILURE;
    }

    /* Set active slave select to line 0 */
    Cy_SCB_SPI_SetActiveSlaveSelect(CYBSP_MASTER_SPI_HW, CY_SCB_SPI_SLAVE_SELECT0);

    /* Populate configuration structure */

    const cy_stc_sysint_t CYBSP_MASTER_SPI_SCB_IRQ_cfg =
    {
        .intrSrc      = CYBSP_MASTER_SPI_IRQ,
        .intrPriority = CYBSP_MASTER_SPI_INTR_PRIORITY
    };

    /* Hook interrupt service routine and enable interrupt */
    sysSpiStatus = Cy_SysInt_Init(&CYBSP_MASTER_SPI_SCB_IRQ_cfg, &UserSpiInterrupt);

    if (sysSpiStatus != CY_SYSINT_SUCCESS)
    {
        return INIT_FAILURE;
    }
    /* Enable interrupt in NVIC */
    NVIC_EnableIRQ(CYBSP_MASTER_SPI_IRQ);

    /* Enable the SPI Master block */
    Cy_SCB_SPI_Enable(CYBSP_MASTER_SPI_HW);

    /* Initialization completed */
    return INIT_SUCCESS;
}


/*******************************************************************************
 * Function Name: SendSpiPacket
 *******************************************************************************
 *
 * Summary:
 * This function sends the data to the SPI slave. Its a blocking function, waits
 * till transfer is complete successfully
 *
 * Parameters:
 * txBuffer - Pointer to the transmit buffer
 * transferSize - Number of bytes to be transmitted
 *
 * Return:
 * cy_en_scb_spi_status_t - CY_SCB_SPI_SUCCESS if the transaction completes
 * successfully. Otherwise it returns the error status
 *
 ******************************************************************************/
cy_en_scb_spi_status_t SendSpiPacket(uint8_t *txBuffer, uint32_t transferSize)
{
    cy_en_scb_spi_status_t masterStatus;

    /* Initiate SPI Master write transaction. */
    masterStatus = Cy_SCB_SPI_Transfer(CYBSP_MASTER_SPI_HW, txBuffer, NULL,
                                        transferSize, &UserSpiContext);

   /* Blocking wait for transfer completion */
    while (0UL != (CY_SCB_SPI_TRANSFER_ACTIVE &
                Cy_SCB_SPI_GetTransferStatus(CYBSP_MASTER_SPI_HW, &UserSpiContext)))
    {

    }

    return masterStatus;
}

/* [] END OF FILE */
