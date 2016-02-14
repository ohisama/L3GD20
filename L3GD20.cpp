#include "L3GD20.h"
#include <SPI.h>

byte L3GD20::read(byte reg)
{
	byte ret = 0;
	digitalWrite(cs_pin, LOW);
	SPI.transfer(reg | L3GD20_RW);
	ret = SPI.transfer(0);
	digitalWrite(cs_pin, HIGH);
	return ret;
}
void L3GD20::write(byte reg, byte val)
{
	digitalWrite(cs_pin, LOW);
	SPI.transfer(reg);
	SPI.transfer(val);
	digitalWrite(cs_pin, HIGH);
}
void L3GD20::begin(void)
{
	pinMode(cs_pin, OUTPUT);
	digitalWrite(cs_pin, HIGH);
	SPI.begin();
	SPI.setBitOrder(MSBFIRST);
	SPI.setClockDivider(SPI_CLOCK_DIV8);
	while (0xD4 != read(L3GD20_WHOAMI))
	{
	};
	write(L3GD20_CTRL1, B00001111);
}

