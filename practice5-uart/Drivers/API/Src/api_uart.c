/**
  ******************************************************************************
  * @file           : api_uart.c
  * @brief          : UART module
  * @author        	: Gonzalo Gabriel Fernandez
  ******************************************************************************
  */

#include <assert.h>
#include "api_uart.h"
#include "stm32f1xx_hal.h"

static UART_HandleTypeDef huart1;

/**
  * @brief  Initialize the UART peripheral.
  * @retval bool_t
  */
bool_t uart_init(void)
{
	huart1.Instance = USART1;
	huart1.Init.BaudRate = 115200;
	huart1.Init.WordLength = UART_WORDLENGTH_8B;
	huart1.Init.StopBits = UART_STOPBITS_1;
	huart1.Init.Parity = UART_PARITY_NONE;
	huart1.Init.Mode = UART_MODE_TX_RX;
	huart1.Init.HwFlowCtl = UART_HWCONTROL_NONE;
	huart1.Init.OverSampling = UART_OVERSAMPLING_16;
	if (HAL_UART_Init(&huart1) != HAL_OK) return false;

  // CONFIG MESSAGE
	char config_msg[] =
        "UART CONFIGURATION:\r\n"
        "Baud Rate: 115200\r\n"
        "Parity: None\r\n"
        "Bits: 8\r\n"
        "Stopbits: 1\r\n"
        "Flow control: None\r\n";
	HAL_UART_Transmit(&huart1, (uint8_t*)config_msg, sizeof(config_msg), HAL_MAX_DELAY);
	return true;
}

/**
  * @brief  Send a string in blocking mode.
  * @param pstring: pointer to string buffer
  * @retval None
  */
void uart_send_string(uint8_t* pstring)
{
    assert(pstring);
    uint8_t i = 0;
    while (pstring[i] != '\0') i++;
    uart_send_string_size(pstring, i);
}

/**
  * @brief  Send an amount of data in blocking mode.
  * @param pstring: pointer to string buffer
  * @param size: amount of characters to be sent
  * @retval None
  */
void uart_send_string_size(uint8_t* pstring, uint16_t size)
{
    assert(pstring);
	HAL_UART_Transmit(&huart1, pstring, size, HAL_MAX_DELAY);
}

/**
  * @brief  Receive an amount of data in blocking mode.
  * @param pstring: pointer to string buffer
  * @param size: amount of characters to be received
  * @retval None
  */
void uart_receive_string_size(uint8_t* pstring, uint16_t size)
{
    assert(pstring);
	HAL_UART_Receive(&huart1, pstring, size, HAL_MAX_DELAY);
}