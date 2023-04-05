/**
  ******************************************************************************
  * @file           : api_uart.h
  * @brief          : UART module
  * @author        	: Gonzalo Gabriel Fernandez
  ******************************************************************************
  */

#ifndef __API_UART_H
#define __API_UART_H

#ifdef __cplusplus
extern "C" {
#endif

#include "api_types.h"

bool_t uart_init(void);
void uart_send_string(uint8_t* pstring);
void uart_send_string_size(uint8_t* pstring, uint16_t size);
void uart_receive_string_size(uint8_t* pstring, uint16_t size);

#ifdef __cplusplus
}
#endif

#endif /* __API_UART_H */