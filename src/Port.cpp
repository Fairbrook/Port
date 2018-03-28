#include <Arduino.h>
#include "Port.h"


/*
*Asigna los pines que van a funcionar como un solo puerto
*En el arreglo de pines la posición 0 es el bit más significativo y 
*la posición 7 es el bit menos significativo
*@param num numero de pines que se van a declarar como un solo puerto
*@param pins arreglo de pines que se van a declarar como un solo puerto*
*/
Port::Port(uint8_t num, uint8_t* pins){
	this->_portPins = new uint8_t[num];

	for(int i=0; i<num; i++){
	    this->_portPins[i]=pins[i];
	}
	
	this->_num = num;
}


/*
*Asigna el valor determinado en el puerto
*@param value el valor a escribir en el puerto
*/
void Port::write(uint8_t value){
	for(uint8_t i=0; i<this->_num; i++){
	    pinMode(this->_portPins[i], OUTPUT);
	}

	for(uint8_t i=0; i<this->_num; i++){
	    if((value & 0x80)==0x80)digitalWrite(this->_portPins[i], HIGH);
	    else if((value & 0x80)==0)digitalWrite(this->_portPins[i], LOW);
	    value = value << 1;
	}
}

/*
*Devuelve el valor que hay en el puerto
*Es importante tener todos los pines en nivel alto o bajo
*si no esta conectado alguno puede producir mediciones 
*incorrectas
*@return el valor leido
*/
uint8_t Port::read(){
	uint8_t result=0;
	uint8_t aux=0x80;

	for(uint8_t i=0; i<this->_num; i++){
	    pinMode(this->_portPins[i], INPUT);
	}

	for(uint8_t i=0; i<this->_num; i++){
	    result += digitalRead(_portPins[i])* aux;
	    aux = aux >> 1;
	}
	return result;
}