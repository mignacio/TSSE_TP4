/*=============================================================================
 * Autor: Ignacio Moya, 2021.
 *===========================================================================*/
#include "max31855.h"
#include <string.h>

spiMap_t spi_port = SPI0;

void max31855_init()
{
	spiInit(spi_port);
}

void max31855(max31855_t* device, gpioMap_t chip_select, uint8_t* name_str)
{
	device->cs_pin = chip_select;
	gpioInit(device->cs_pin, GPIO_OUTPUT);
	memset(device->buffer, 0, MAX31855_BUFFER_SIZE);
	strcpy(device->name, name_str);//, MAX31855_BUFFER_SIZE);
}

void max31855_read(max31855_t* device)
{
	gpioWrite(device->cs_pin, OFF);
	spiRead(spi_port, device->buffer, MAX31855_BUFFER_SIZE);
	gpioWrite(device->cs_pin, ON);
 
	int32_t external_temp_raw;
	external_temp_raw = (int32_t)(device->buffer[0] << 6) +
						(int32_t)(device->buffer[1] >> 2);
	if((external_temp_raw & 0x00002000) != 0)
	{
		external_temp_raw |= 0xFFFFC000;//extiendo bit de signo, 1
	}
	else
	{
		external_temp_raw &= 0x3FFF; //extiendo bit de signo, 0
	}
	device->external_temp = external_temp_raw;

	int32_t internal_temp_raw;
	internal_temp_raw |= (int16_t)(device->buffer[3] >> 4);
	internal_temp_raw |= (int16_t)(device->buffer[2] << 4);
	if((internal_temp_raw & 0x800) != 0)
	{
		internal_temp_raw |= 0xF800;//extiendo bit de signo, 1
	}
	else
	{
		internal_temp_raw &= 0x07FF; //extiendo bit de signo, 0
	}

	device->internal_temp = internal_temp_raw;
}

int32_t max31855_ext_temp_to_celsius(max31855_t* device)
{

}

int32_t max31855_int_temp_to_celsius(max31855_t* device)
{
	
}