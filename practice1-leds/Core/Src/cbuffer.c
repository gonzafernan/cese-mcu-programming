
/* Includes ------------------------------------------------------------------*/
#include "cbuffer.h"

/* Private includes ----------------------------------------------------------*/
#include <assert.h>

/* Private define ------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/

void cbuffer_init(cbuffer_handle_t cbuffer, uint16_t* arr, size_t size)
{
  assert(arr);
  cbuffer->head = 0;
  cbuffer->size = size;
  cbuffer->buffer = arr;
}

uint16_t cbuffer_next(cbuffer_handle_t cbuffer)
{
  cbuffer->head++;
  if (cbuffer->head == cbuffer->size)
  {
    cbuffer->head = 0;
  } 
  return cbuffer->buffer[cbuffer->head];
}

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