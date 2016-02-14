#include <SPI.h>
#include <L3GD20.h>

L3GD20 gyro(10);// cs
void setup()
{
	Serial.begin(115200);
	Serial.print("start\t");
	gyro.begin();
	Serial.println(" ok!");
}
void loop()
{
	short X, Y, Z;
	float x, y, z;
	X = gyro.read(L3GD20_X_H);
	x = X = (X << 8) | gyro.read(L3GD20_X_L);
	Y = gyro.read(L3GD20_Y_H);
	y = Y = (Y << 8) | gyro.read(L3GD20_Y_L);
	Z = gyro.read(L3GD20_Z_H);
	z = Z = (Z << 8) | gyro.read(L3GD20_Z_L);
	x *= 0.00875;
	y *= 0.00875;
	z *= 0.00875;
	Serial.print(X);
	Serial.print("\t");
	Serial.print(Y);
	Serial.print("\t");
	Serial.print(Z);
	Serial.print("\t");
	Serial.print(x);
	Serial.print("\t");
	Serial.print(y);
	Serial.print("\t");
	Serial.println(z);
	delay(10);
}
