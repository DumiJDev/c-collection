#include "../header/main.h"

void nomeInicial(char * nome, char * out) {
	char Nome[20] = { "" };
	int i, j, nSpace = 0;

	for(i = 0; i < strlen(nome); i++)
		if(isspace(nome[i]))
			nSpace++;

	for(i = 0, j = 0; i < strlen(nome); i++)
		if((isupper(nome[i]) || i == 0 ) && nSpace > 0) {
			Nome[j++] = nome[i];
			Nome[j++] = '.';
			Nome[j++] = ' ';
		} else if(isspace(nome[i]))
			nSpace--;
		else if(nSpace == 0)
			break;

	for(; i < strlen(nome); i++)
		Nome[j++] = nome[i];

	strcpy( out, Nome);
}

void dataToString(Data data, char * out) {
	char NumV[] = "0123456789", date[11];

	if(0 < data.dia && data.dia < 10) {
		date[0] = NumV[0];
		date[1] = NumV[data.dia];
		date[2] = '.';
	} else {
		date[0] = NumV[(data.dia - data.dia % 10) / 10];
		date[1] = NumV[data.dia % 10];
		date[2] = '.';
	}

	if(0 < data.mes && data.mes < 10) {
		date[3] = NumV[0];
		date[4] = NumV[data.mes];
		date[5] = '.';
	} else {
		date[3] = NumV[(data.mes - data.mes % 10) / 10];
		date[4] = NumV[data.mes % 10];
		date[5] = '.';
	}

	date[6] = NumV[(data.ano - data.ano % 1000) / 1000];
	date[7] = NumV[(data.ano % 1000) / 100];
	date[8] = NumV[(data.ano % 1000 % 100) / 10];
	date[9] = NumV[data.ano % 10];
	date[10] = '\0';

	strcpy(out, date);
}

void replaceAll(char * wrd, char wrd1, char wrd2) {
	int i = 0;

	for(i = 0; i < strlen(wrd); i++)
		if(wrd[i] == wrd1)
			wrd[i] = wrd2;
}
