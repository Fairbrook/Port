#include <Arduino.h>
#include "Port.h"

Port::Port(uint8_t a, uint8_t b,uint8_t c,uint8_t d,uint8_t e ,uint8_t f,uint8_t g, uint8_t h){
	this->_portPins[0] = a;
	this->_portPins[1] = b;
	this->_portPins[2] = c;
	this->_portPins[3] = d;
	this->_portPins[4] = e;
	this->_portPins[5] = f;
	this->_portPins[6] = g;
	this->_portPins[7] = h;
}

void Port::write(uint8_t value){
	for(uint8_t i=0; i<8; i++){
	    pinMode(this->_portPins[i], OUTPUT);
	}

	for(uint8_t i=0; i<8; i++){
	    if((value & 0x80)==1)digitalWrite(this->_portPins[i], HIGH);
	    else if((value & 0x80)==0)digitalWrite(this->_portPins[i], LOW);
	    value = value << 1;
	}
}

uint8_t Port::read(){
	uint8_t result=0;
	uint8_t aux=0x80;

	for(uint8_t i=0; i<8; i++){
	    pinMode(this->_portPins[i], INPUT);
	}

	for(uint8_t i=0; i<8; i++){
	    result += _portPins[i] * aux;
	    aux = aux >> 1;
	}
	return result;
}