#ifndef __LEDS_H
#define __LEDS_H

/* Includes ------------------------------------------------------------------*/
/* Private includes ----------------------------------------------------------*/
#include <stdint.h>
#include <stddef.h>

/* Private typedef -----------------------------------------------------------*/
typedef struct scbuffer_t {
  uint16_t* buffer;
  uint8_t head;
  size_t size;
} cbuffer_t;

/* Exported types ------------------------------------------------------------*/
typedef cbuffer_t* cbuffer_handle_t;

/* Exported functions prototypes ---------------------------------------------*/
void cbuffer_init(cbuffer_handle_t cbuffer, uint16_t* arr, size_t size);
uint16_t cbuffer_next(cbuffer_handle_t cbuffer);
uint16_t cbuffer_prev(cbuffer_handle_t cbuffer);

#endif /* __LEDS_H */