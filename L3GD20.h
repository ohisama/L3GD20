#ifndef L3GD20_H
#define L3GD20_H
#include <Arduino.h>

#define L3GD20_WHOAMI		0x0F
#define L3GD20_START		0x0F
#define L3GD20_CTRL1		0x20
#define L3GD20_CTRL2		0x21
#define L3GD20_CTRL3		0x22
#define L3GD20_CTRL4		0x23
#define L3GD20_CTRL5		0x24
#define L3GD20_X_L			0x28
#define L3GD20_X_H			0x29
#define L3GD20_Y_L			0x2A
#define L3GD20_Y_H			0x2B
#define L3GD20_Z_L			0x2C
#define L3GD20_Z_H			0x2D
#define L3GD20_RW 			0x80
#define L3GD20_MS 			0x40

class L3GD20
{
public:
	L3GD20(uint8_t cs) : cs_pin(cs)
	{
	};
	void begin(void);
	byte read(byte reg);
	void write(byte reg, byte val);
private:
	uint8_t cs_pin;
};
#endif
