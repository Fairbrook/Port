#include <Port.h>

Port miPuerto(7,6,5,4,3,2,1,0);
byte recorrido = 0x80;

void setup()
{
	miPuerto.write(0);
}

void loop()
{
	for(int i=0; i<8; i++){
	    miPuerto.write(recorrido);
	    recorrido = recorrido >> 1;
	    delay(2000);
	}
}