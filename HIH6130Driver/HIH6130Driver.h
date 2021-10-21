/* --------------------------------------------------------------------------------------------------- *
* Khanh Truong - khanhptruong@csu.fullerton.edu
* California State University Fullerton
* Created: FEB 20 2018
*
* Description: Device driver for HIH-6130.
*
* Copyright 2018 
* --------------------------------------------------------------------------------------------------- */

#ifndef HIH6130Driver_h
#define HIH6130Driver_h

#include "Arduino.h"

class HIH6130Driver{
public:
	HIH6130Driver();
	void init();
	void tempHumData(float &ret_temp, float &ret_hum);
private:
	
};

#endif