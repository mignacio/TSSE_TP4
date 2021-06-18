/* AUTOGENERATED FILE. DO NOT EDIT. */
#ifndef _MOCK_SAPI_H
#define _MOCK_SAPI_H

#include "unity.h"
#include "sapi.h"

/* Ignore the following warnings, since we are copying code */
#if defined(__GNUC__) && !defined(__ICC) && !defined(__TMS470__)
#if __GNUC__ > 4 || (__GNUC__ == 4 && (__GNUC_MINOR__ > 6 || (__GNUC_MINOR__ == 6 && __GNUC_PATCHLEVEL__ > 0)))
#pragma GCC diagnostic push
#endif
#if !defined(__clang__)
#pragma GCC diagnostic ignored "-Wpragmas"
#endif
#pragma GCC diagnostic ignored "-Wunknown-pragmas"
#pragma GCC diagnostic ignored "-Wduplicate-decl-specifier"
#endif

void mock_sapi_Init(void);
void mock_sapi_Destroy(void);
void mock_sapi_Verify(void);




#define gpioInit_IgnoreAndReturn(cmock_retval) gpioInit_CMockIgnoreAndReturn(__LINE__, cmock_retval)
void gpioInit_CMockIgnoreAndReturn(UNITY_LINE_TYPE cmock_line, bool_t cmock_to_return);
#define gpioInit_StopIgnore() gpioInit_CMockStopIgnore()
void gpioInit_CMockStopIgnore(void);
#define gpioInit_ExpectAndReturn(pin, config, cmock_retval) gpioInit_CMockExpectAndReturn(__LINE__, pin, config, cmock_retval)
void gpioInit_CMockExpectAndReturn(UNITY_LINE_TYPE cmock_line, gpioMap_t pin, gpioInit_t config, bool_t cmock_to_return);
typedef bool_t (* CMOCK_gpioInit_CALLBACK)(gpioMap_t pin, gpioInit_t config, int cmock_num_calls);
void gpioInit_AddCallback(CMOCK_gpioInit_CALLBACK Callback);
void gpioInit_Stub(CMOCK_gpioInit_CALLBACK Callback);
#define gpioInit_StubWithCallback gpioInit_Stub
#define gpioRead_IgnoreAndReturn(cmock_retval) gpioRead_CMockIgnoreAndReturn(__LINE__, cmock_retval)
void gpioRead_CMockIgnoreAndReturn(UNITY_LINE_TYPE cmock_line, bool_t cmock_to_return);
#define gpioRead_StopIgnore() gpioRead_CMockStopIgnore()
void gpioRead_CMockStopIgnore(void);
#define gpioRead_ExpectAndReturn(pin, cmock_retval) gpioRead_CMockExpectAndReturn(__LINE__, pin, cmock_retval)
void gpioRead_CMockExpectAndReturn(UNITY_LINE_TYPE cmock_line, gpioMap_t pin, bool_t cmock_to_return);
typedef bool_t (* CMOCK_gpioRead_CALLBACK)(gpioMap_t pin, int cmock_num_calls);
void gpioRead_AddCallback(CMOCK_gpioRead_CALLBACK Callback);
void gpioRead_Stub(CMOCK_gpioRead_CALLBACK Callback);
#define gpioRead_StubWithCallback gpioRead_Stub
#define gpioWrite_IgnoreAndReturn(cmock_retval) gpioWrite_CMockIgnoreAndReturn(__LINE__, cmock_retval)
void gpioWrite_CMockIgnoreAndReturn(UNITY_LINE_TYPE cmock_line, bool_t cmock_to_return);
#define gpioWrite_StopIgnore() gpioWrite_CMockStopIgnore()
void gpioWrite_CMockStopIgnore(void);
#define gpioWrite_ExpectAndReturn(pin, value, cmock_retval) gpioWrite_CMockExpectAndReturn(__LINE__, pin, value, cmock_retval)
void gpioWrite_CMockExpectAndReturn(UNITY_LINE_TYPE cmock_line, gpioMap_t pin, bool_t value, bool_t cmock_to_return);
typedef bool_t (* CMOCK_gpioWrite_CALLBACK)(gpioMap_t pin, bool_t value, int cmock_num_calls);
void gpioWrite_AddCallback(CMOCK_gpioWrite_CALLBACK Callback);
void gpioWrite_Stub(CMOCK_gpioWrite_CALLBACK Callback);
#define gpioWrite_StubWithCallback gpioWrite_Stub
#define gpioToggle_IgnoreAndReturn(cmock_retval) gpioToggle_CMockIgnoreAndReturn(__LINE__, cmock_retval)
void gpioToggle_CMockIgnoreAndReturn(UNITY_LINE_TYPE cmock_line, bool_t cmock_to_return);
#define gpioToggle_StopIgnore() gpioToggle_CMockStopIgnore()
void gpioToggle_CMockStopIgnore(void);
#define gpioToggle_ExpectAndReturn(pin, cmock_retval) gpioToggle_CMockExpectAndReturn(__LINE__, pin, cmock_retval)
void gpioToggle_CMockExpectAndReturn(UNITY_LINE_TYPE cmock_line, gpioMap_t pin, bool_t cmock_to_return);
typedef bool_t (* CMOCK_gpioToggle_CALLBACK)(gpioMap_t pin, int cmock_num_calls);
void gpioToggle_AddCallback(CMOCK_gpioToggle_CALLBACK Callback);
void gpioToggle_Stub(CMOCK_gpioToggle_CALLBACK Callback);
#define gpioToggle_StubWithCallback gpioToggle_Stub
#define spiInit_IgnoreAndReturn(cmock_retval) spiInit_CMockIgnoreAndReturn(__LINE__, cmock_retval)
void spiInit_CMockIgnoreAndReturn(UNITY_LINE_TYPE cmock_line, bool_t cmock_to_return);
#define spiInit_StopIgnore() spiInit_CMockStopIgnore()
void spiInit_CMockStopIgnore(void);
#define spiInit_ExpectAndReturn(spi, cmock_retval) spiInit_CMockExpectAndReturn(__LINE__, spi, cmock_retval)
void spiInit_CMockExpectAndReturn(UNITY_LINE_TYPE cmock_line, spiMap_t spi, bool_t cmock_to_return);
typedef bool_t (* CMOCK_spiInit_CALLBACK)(spiMap_t spi, int cmock_num_calls);
void spiInit_AddCallback(CMOCK_spiInit_CALLBACK Callback);
void spiInit_Stub(CMOCK_spiInit_CALLBACK Callback);
#define spiInit_StubWithCallback spiInit_Stub
#define spiRead_IgnoreAndReturn(cmock_retval) spiRead_CMockIgnoreAndReturn(__LINE__, cmock_retval)
void spiRead_CMockIgnoreAndReturn(UNITY_LINE_TYPE cmock_line, bool_t cmock_to_return);
#define spiRead_StopIgnore() spiRead_CMockStopIgnore()
void spiRead_CMockStopIgnore(void);
#define spiRead_ExpectAndReturn(spi, buffer, bufferSize, cmock_retval) spiRead_CMockExpectAndReturn(__LINE__, spi, buffer, bufferSize, cmock_retval)
void spiRead_CMockExpectAndReturn(UNITY_LINE_TYPE cmock_line, spiMap_t spi, uint8_t* buffer, uint32_t bufferSize, bool_t cmock_to_return);
typedef bool_t (* CMOCK_spiRead_CALLBACK)(spiMap_t spi, uint8_t* buffer, uint32_t bufferSize, int cmock_num_calls);
void spiRead_AddCallback(CMOCK_spiRead_CALLBACK Callback);
void spiRead_Stub(CMOCK_spiRead_CALLBACK Callback);
#define spiRead_StubWithCallback spiRead_Stub
#define spiRead_ReturnThruPtr_buffer(buffer) spiRead_CMockReturnMemThruPtr_buffer(__LINE__, buffer, sizeof(uint8_t))
#define spiRead_ReturnArrayThruPtr_buffer(buffer, cmock_len) spiRead_CMockReturnMemThruPtr_buffer(__LINE__, buffer, cmock_len * sizeof(*buffer))
#define spiRead_ReturnMemThruPtr_buffer(buffer, cmock_size) spiRead_CMockReturnMemThruPtr_buffer(__LINE__, buffer, cmock_size)
void spiRead_CMockReturnMemThruPtr_buffer(UNITY_LINE_TYPE cmock_line, uint8_t* buffer, size_t cmock_size);
#define spiWrite_IgnoreAndReturn(cmock_retval) spiWrite_CMockIgnoreAndReturn(__LINE__, cmock_retval)
void spiWrite_CMockIgnoreAndReturn(UNITY_LINE_TYPE cmock_line, bool_t cmock_to_return);
#define spiWrite_StopIgnore() spiWrite_CMockStopIgnore()
void spiWrite_CMockStopIgnore(void);
#define spiWrite_ExpectAndReturn(spi, buffer, bufferSize, cmock_retval) spiWrite_CMockExpectAndReturn(__LINE__, spi, buffer, bufferSize, cmock_retval)
void spiWrite_CMockExpectAndReturn(UNITY_LINE_TYPE cmock_line, spiMap_t spi, uint8_t* buffer, uint32_t bufferSize, bool_t cmock_to_return);
typedef bool_t (* CMOCK_spiWrite_CALLBACK)(spiMap_t spi, uint8_t* buffer, uint32_t bufferSize, int cmock_num_calls);
void spiWrite_AddCallback(CMOCK_spiWrite_CALLBACK Callback);
void spiWrite_Stub(CMOCK_spiWrite_CALLBACK Callback);
#define spiWrite_StubWithCallback spiWrite_Stub
#define spiWrite_ReturnThruPtr_buffer(buffer) spiWrite_CMockReturnMemThruPtr_buffer(__LINE__, buffer, sizeof(uint8_t))
#define spiWrite_ReturnArrayThruPtr_buffer(buffer, cmock_len) spiWrite_CMockReturnMemThruPtr_buffer(__LINE__, buffer, cmock_len * sizeof(*buffer))
#define spiWrite_ReturnMemThruPtr_buffer(buffer, cmock_size) spiWrite_CMockReturnMemThruPtr_buffer(__LINE__, buffer, cmock_size)
void spiWrite_CMockReturnMemThruPtr_buffer(UNITY_LINE_TYPE cmock_line, uint8_t* buffer, size_t cmock_size);

#if defined(__GNUC__) && !defined(__ICC) && !defined(__TMS470__)
#if __GNUC__ > 4 || (__GNUC__ == 4 && (__GNUC_MINOR__ > 6 || (__GNUC_MINOR__ == 6 && __GNUC_PATCHLEVEL__ > 0)))
#pragma GCC diagnostic pop
#endif
#endif

#endif
