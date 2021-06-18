/*=============================================================================
 * Autor: Ignacio Moya, 2021.
 *===========================================================================*/
#include "unity.h"
#include "mock_sapi.h"
#include "max31855.h"


max31855_t max31855_d;
/*
Caso de prueba #1
El constructor de la estructura max31855_t debe crear la estructura
correctamente. El buffer de datos debera iniciarse con sus 4 valores en 0
*/
void test_max31855_constructor()
{
    uint8_t aux_array[4] = {0};
    char name[7] = "device";
    gpioMap_t cs_pin = 15;

    gpioInit_IgnoreAndReturn(0);

    max31855(&max31855_d, cs_pin, name);

    TEST_ASSERT_EQUAL_UINT8(cs_pin, max31855_d.cs_pin);
    TEST_ASSERT_EQUAL_STRING("device", max31855_d.name);
    TEST_ASSERT_EQUAL_UINT8_ARRAY(aux_array, max31855_d.buffer, MAX31855_BUFFER_SIZE);
}

void test_max31855_read()
{
    gpioWrite_IgnoreAndReturn(0);
    uint8_t aux_buffer[MAX31855_BUFFER_SIZE] = {0xA, 0xB, 0xC, 0xD};
    
    spiRead_ExpectAndReturn(SPI0, aux_buffer, MAX31855_BUFFER_SIZE, 0);
    spiRead_ReturnArrayThruPtr_buffer(aux_buffer, MAX31855_BUFFER_SIZE);
    max31855_read(&max31855_d);

    TEST_ASSERT_EQUAL_UINT8_ARRAY(aux_buffer, max31855_d.buffer, MAX31855_BUFFER_SIZE);
}