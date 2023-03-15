/**
  ******************************************************************************
  * @file           : cbuffer.c
  * @brief          : Simple circular buffer tools
  ******************************************************************************
  */

#include <assert.h>

#include "cbuffer.h"

/**
  * @brief  Circular buffer initialization.
  * @param cbuffer: pointer to circular buffer data structure
  * @param arr: pointer to the buffer content
  * @param size: buffer size
  * @retval None
  */
void cbuffer_init(cbuffer_handle_t cbuffer, uint16_t* arr, size_t size)
{
  assert(arr);
  cbuffer->head = 0;
  cbuffer->size = size;
  cbuffer->buffer = arr;
}

/**
  * @brief  Advance circular buffer head.
  * @param cbuffer: pointer to circular buffer data structure
  * @retval uint16_t
  */
uint16_t cbuffer_next(cbuffer_handle_t cbuffer)
{
  cbuffer->head++;
  if (cbuffer->head == cbuffer->size)
  {
    cbuffer->head = 0;
  } 
  return cbuffer->buffer[cbuffer->head];
}

/**
  * @brief  Retract circular buffer head.
  * @param cbuffer: pointer to circular buffer data structure
  * @retval uint16_t
  */
uint16_t cbuffer_prev(cbuffer_handle_t cbuffer)
{
  if (cbuffer->head == 0)
  {
    cbuffer->head = cbuffer->size - 1;
  } 
  else 
  {
    cbuffer->head--;
  }
  return cbuffer->buffer[cbuffer->head];
}