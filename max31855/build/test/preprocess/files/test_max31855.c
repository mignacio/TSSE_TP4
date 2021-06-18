#include "src/max31855.h"
#include "build/test/mocks/mock_sapi.h"
#include "/var/lib/gems/2.5.0/gems/ceedling-0.31.0/vendor/unity/src/unity.h"










max31855_t max31855_d;











void test_max31855_constructor()

{

    uint8_t aux_array[4] = {0};

    char name[7] = "device";

    gpioMap_t cs_pin = 15;



    gpioInit_CMockIgnoreAndReturn(21, 0);



    max31855(&max31855_d, cs_pin, name);



    UnityAssertEqualNumber((UNITY_INT)(UNITY_UINT8 )((cs_pin)), (UNITY_INT)(UNITY_UINT8 )((max31855_d.cs_pin)), (

   ((void *)0)

   ), (UNITY_UINT)(25), UNITY_DISPLAY_STYLE_UINT8);

    UnityAssertEqualString((const char*)(("device")), (const char*)((max31855_d.name)), (

   ((void *)0)

   ), (UNITY_UINT)(26));

    UnityAssertEqualIntArray(( const void*)((aux_array)), ( const void*)((max31855_d.buffer)), (UNITY_UINT32)((4)), (

   ((void *)0)

   ), (UNITY_UINT)(27), UNITY_DISPLAY_STYLE_UINT8, UNITY_ARRAY_TO_ARRAY);

}













void test_max31855_read()

{

    gpioWrite_CMockIgnoreAndReturn(37, 0);

    uint8_t aux_buffer[4] = {0x1A, 0x2B, 0x3C, 0x4D};

    spiRead_CMockExpectAndReturn(39, 0, aux_buffer, 4, 0);

    spiRead_CMockIgnoreArg_buffer(40);



    spiRead_CMockReturnMemThruPtr_buffer(42, aux_buffer, 4 * sizeof(*aux_buffer));

    max31855_read(&max31855_d);



    UnityAssertEqualIntArray(( const void*)((aux_buffer)), ( const void*)((max31855_d.buffer)), (UNITY_UINT32)((4)), (

   ((void *)0)

   ), (UNITY_UINT)(45), UNITY_DISPLAY_STYLE_HEX8, UNITY_ARRAY_TO_ARRAY);

}















void test_ext_temp_to_celsius_positive()

{



    max31855_d.buffer[0] = 0x64;

    max31855_d.buffer[1] = 0x00;

    max31855_d.buffer[2] = 0x00;

    max31855_d.buffer[3] = 0x00;

    int32_t ret_temp;

    int32_t expected_temp = 160000;

    ret_temp = max31855_ext_temp_to_celsius(&max31855_d);

    UnityAssertEqualNumber((UNITY_INT)(UNITY_INT32)((expected_temp)), (UNITY_INT)(UNITY_INT32)((ret_temp)), (

   ((void *)0)

   ), (UNITY_UINT)(64), UNITY_DISPLAY_STYLE_INT32);

}















void test_ext_temp_to_celsius_negative()

{

    max31855_d.buffer[0] = 0xF0;

    max31855_d.buffer[1] = 0x60;

    max31855_d.buffer[2] = 0x00;

    max31855_d.buffer[3] = 0x00;



    int32_t ret_temp;

    int32_t expected_temp = -25000;

    ret_temp = max31855_ext_temp_to_celsius(&max31855_d);

    UnityAssertEqualNumber((UNITY_INT)(UNITY_INT32)((expected_temp)), (UNITY_INT)(UNITY_INT32)((ret_temp)), (

   ((void *)0)

   ), (UNITY_UINT)(83), UNITY_DISPLAY_STYLE_INT32);

}















void test_int_temp_to_celsius_positive()

{

    max31855_d.buffer[0] = 0x00;

    max31855_d.buffer[1] = 0x00;

    max31855_d.buffer[2] = 0x7F;

    max31855_d.buffer[3] = 0x00;



    int32_t ret_temp;

    int32_t expected_temp = 127000;

    ret_temp = max31855_int_temp_to_celsius(&max31855_d);

    UnityAssertEqualNumber((UNITY_INT)(UNITY_INT32)((expected_temp)), (UNITY_INT)(UNITY_INT32)((ret_temp)), (

   ((void *)0)

   ), (UNITY_UINT)(102), UNITY_DISPLAY_STYLE_INT32);

}















void test_int_temp_to_celsius_negative()

{

    max31855_d.buffer[0] = 0x00;

    max31855_d.buffer[1] = 0x00;

    max31855_d.buffer[2] = 0xC9;

    max31855_d.buffer[3] = 0x00;

    int32_t ret_temp;

    int32_t expected_temp = -55000;

    ret_temp = max31855_int_temp_to_celsius(&max31855_d);

    UnityAssertEqualNumber((UNITY_INT)(UNITY_INT32)((expected_temp)), (UNITY_INT)(UNITY_INT32)((ret_temp)), (

   ((void *)0)

   ), (UNITY_UINT)(120), UNITY_DISPLAY_STYLE_INT32);

}
