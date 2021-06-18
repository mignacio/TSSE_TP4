#ifndef SAPI_H
#define SAPI_H

#include "stdint.h"

//sapi_datatypes.h
#ifndef OFF
#define OFF    0
#endif
#ifndef ON
#define ON     (!OFF)
#endif

//sapi_gpio.h
typedef uint32_t gpioMap_t;
typedef uint8_t bool_t;

typedef enum {
   GPIO_INPUT, GPIO_OUTPUT,
   GPIO_INPUT_PULLUP, GPIO_INPUT_PULLDOWN,
   GPIO_INPUT_PULLUP_PULLDOWN,
   GPIO_ENABLE
} gpioInit_t;

bool_t gpioInit( gpioMap_t pin, gpioInit_t config );
bool_t gpioRead( gpioMap_t pin );
bool_t gpioWrite( gpioMap_t pin, bool_t value );
bool_t gpioToggle( gpioMap_t pin );


//sapi_spi.h
typedef uint8_t spiMap_t;
#define SPI0 0
bool_t spiInit( spiMap_t spi );
bool_t spiRead( spiMap_t spi, uint8_t *buffer, uint32_t bufferSize );
bool_t spiWrite( spiMap_t spi, uint8_t *buffer, uint32_t bufferSize);

#endif