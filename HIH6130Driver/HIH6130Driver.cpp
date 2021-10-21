#include "Arduino.h"
#include "HIH6130Driver.h"
#include <Wire.h>

// HIH6130 I2C address is 0x27(39)
#define Addr 0x27

HIH6130Driver::HIH6130Driver(){
	//do nothing
}

void HIH6130Driver::init(){
	// Initialise I2C communication as MASTER
	Wire.begin();
	// Initialise serial communication, set baud rate = 9600
	delay(300);
}

void HIH6130Driver::tempHumData(float &ret_temp, float &ret_hum){
	unsigned int data[4];
	
	for(int i = 0; i < 3; i++){
		// Start I2C Transmission
		Wire.beginTransmission(Addr);
		// Select data register
		Wire.write(0x00);
		// Stop I2C Transmission
		Wire.endTransmission();

		// Request 4 bytes of data
		Wire.requestFrom(Addr, 4);

		// Read 4 bytes of data
		// humidity msb, humidity lsb, temp msb, temp lsb
		if (Wire.available() == 4){
			data[0] = Wire.read();
			data[1] = Wire.read();
			data[2] = Wire.read();
			data[3] = Wire.read();
		}

		// Convert the data to 14-bits
		float humidity = ((((data[0] & 0x3F) * 256) + data[1]) * 100.0) / 16383.0;
		int temp = ((data[2] * 256) + (data[3] & 0xFC)) / 4;
		float cTemp = (temp / 16384.0) * 165.0 - 40.0;
		float fTemp = cTemp * 1.8 + 32;
		
		ret_temp = fTemp;
		ret_hum = humidity;
		
		delay(1000);
	}
}