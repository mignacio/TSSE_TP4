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

/*
Caso de prueba #2
La funcion max31855_read(); debera leer del puerto spi los 4 registros
del integrado y guardarlos correctamente en el buffer de la estructura.
*/
void test_max31855_read()
{
    gpioWrite_IgnoreAndReturn(0);
    uint8_t aux_buffer[MAX31855_BUFFER_SIZE] = {0x1A, 0x2B, 0x3C, 0x4D};
    
    spiRead_ExpectAndReturn(SPI0, aux_buffer, MAX31855_BUFFER_SIZE, 0);
    
    //Error al intentar mockear spiRead, no lo pude solucionar
    spiRead_ReturnArrayThruPtr_buffer(aux_buffer, MAX31855_BUFFER_SIZE);
    max31855_read(&max31855_d);

    TEST_ASSERT_EQUAL_HEX8_ARRAY(aux_buffer, max31855_d.buffer, MAX31855_BUFFER_SIZE);
}

/*
Caso de prueba #3
La funcion max31855_ext_temp_to_celsius debera devolver un numero entero con signo
que sea la conversion correcta de la variable de la estructura external_temp a
grados celsius. Para el maximo valor positivo posible.
*/
void test_ext_temp_to_celsius_positive()
{
    //max31855_d.external_temp = 0x1900; //+1600C
    max31855_d.buffer[0] = 0x64;
    max31855_d.buffer[1] = 0x00;
    max31855_d.buffer[2] = 0x00;
    max31855_d.buffer[3] = 0x00;
    int32_t ret_temp;
    int32_t expected_temp = 160000;
    ret_temp = max31855_ext_temp_to_celsius(&max31855_d);
    TEST_ASSERT_EQUAL_INT32(expected_temp, ret_temp);
}

/*
Caso de prueba #4
La funcion max31855_ext_temp_to_celsius debera devolver un numero entero con signo
que sea la conversion correcta de la variable de la estructura external_temp a
grados celsius. Para el valor minimo valor negativo posible.
*/
void test_ext_temp_to_celsius_negative()
{
    max31855_d.buffer[0] = 0xF0;
    max31855_d.buffer[1] = 0x60;
    max31855_d.buffer[2] = 0x00;
    max31855_d.buffer[3] = 0x00;

    int32_t ret_temp;
    int32_t expected_temp = -25000;
    ret_temp = max31855_ext_temp_to_celsius(&max31855_d);
    TEST_ASSERT_EQUAL_INT32(expected_temp, ret_temp);
}

/*
Caso de prueba #5
La funcion max31855_ext_temp_to_celsius debera devolver un numero entero con signo
que sea la conversion correcta de la variable de la estructura internal_temp a
grados celsius para el maximo valor positivo posible.
*/
void test_int_temp_to_celsius_positive()
{
    max31855_d.buffer[0] = 0x00;
    max31855_d.buffer[1] = 0x00;
    max31855_d.buffer[2] = 0x7F;
    max31855_d.buffer[3] = 0x00;
    
    int32_t ret_temp;
    int32_t expected_temp = 127000;
    ret_temp = max31855_int_temp_to_celsius(&max31855_d);
    TEST_ASSERT_EQUAL_INT32(expected_temp, ret_temp);
}

/*
Caso de prueba #6
La funcion max31855_ext_temp_to_celsius debera devolver un numero entero con signo
que sea la conversion correcta de la variable de la estructura internal_temp a
grados celsius para el maximo valor positivo posible.
*/
void test_int_temp_to_celsius_negative()
{
    max31855_d.buffer[0] = 0x00;
    max31855_d.buffer[1] = 0x00;
    max31855_d.buffer[2] = 0xC9;
    max31855_d.buffer[3] = 0x00;
    int32_t ret_temp;
    int32_t expected_temp = -55000;
    ret_temp = max31855_int_temp_to_celsius(&max31855_d);
    TEST_ASSERT_EQUAL_INT32(expected_temp, ret_temp);
}