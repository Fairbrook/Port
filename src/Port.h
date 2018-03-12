#ifndef Port_h
#define Port_h

#include <Arduino.h>

class Port{
	public:
		Port(uint8_t, uint8_t ,uint8_t ,uint8_t ,uint8_t ,uint8_t ,uint8_t ,uint8_t );
		void write(uint8_t);
		uint8_t read();
		uint8_t _portPins[8];
};

#endif