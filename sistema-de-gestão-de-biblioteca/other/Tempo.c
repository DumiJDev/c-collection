#include "../header/main.h"

void espera(int Hora, int min, float seg) {
	int tempo = clock();

	while(clock() - tempo < (Hora * 3600 + min * 60 + seg) * 1000);
}

Data hoje(void) {
	time_t tempo;
	struct tm * Time;
	Data d;


	time( & tempo);
	Time = localtime( & tempo);

	d.dia = Time->tm_mday;
	d.mes = Time->tm_mon + 1;
	d.ano = Time->tm_year + 1900;

	return d;
}

Data data(int dia, int mes, int ano) {
	Data d;
	d.dia = dia;
	d.mes = mes;
	d.ano = ano;

	return d;
}
