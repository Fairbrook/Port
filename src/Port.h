#ifndef Port_h
#define Port_h

#include <Arduino.h>

class Port{
	public:
		Port(uint8_t, uint8_t*);
		void write(uint8_t);
		uint8_t read();

	private:
		uint8_t* _portPins;
		uint8_t _num;
};

#endif