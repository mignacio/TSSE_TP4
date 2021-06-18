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

    gpioWrite_CMockIgnoreAndReturn(32, 0);

    uint8_t aux_buffer[4] = {0xA, 0xB, 0xC, 0xD};



    spiRead_CMockExpectAndReturn(35, 0, aux_buffer, 4, 0);

    spiRead_CMockReturnMemThruPtr_buffer(36, aux_buffer, 4 * sizeof(*aux_buffer));

    max31855_read(&max31855_d);



    UnityAssertEqualIntArray(( const void*)((aux_buffer)), ( const void*)((max31855_d.buffer)), (UNITY_UINT32)((4)), (

   ((void *)0)

   ), (UNITY_UINT)(39), UNITY_DISPLAY_STYLE_UINT8, UNITY_ARRAY_TO_ARRAY);

}
