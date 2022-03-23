#include "../header/main.h"

void nomeInicial(char * , char * );
void dataToString(Data, char * );



void consultaUtente(Utente * utente, char nome[]) {
	int i, found = 0, j, k;
	char n[strlen(nome)], Abb[20], date[10], mor[30];

	system("mode 124, 70 & cls");

	for(j = 0; j < uu; j++) {
		for(k = 0; k < strlen(nome); k++)
			n[k] = utente[j].nome[k];
		n[k] = '\0';
		if(!strcasecmp(nome, n)) {
			if(found == 0) {
				printf("\t---------------------------------------------------------------------------------------------");
				printf("---------------\n");

				putchar('\t');
				putchar('|');
				for(i = 0; i < 0; i++) putchar(' ');
				printf("ID");
				for(i = 0; i < 0; i++) putchar(' ');

				putchar('|');
				for(i = 0; i < 13; i++) putchar(' ');
				printf("Nome");
				for(i = 0; i < 13; i++) putchar(' ');

				putchar('|');
				for(i = 0; i < 1; i++) putchar(' ');
				printf("Categoria");
				for(i = 0; i < 2; i++) putchar(' ');

				putchar('|');
				for(i = 0; i < 12; i++) putchar(' ');
				printf("Morada");
				for(i = 0; i < 12; i++) putchar(' ');

				putchar('|');
				for(i = 0; i < 1; i++) putchar(' ');
				printf("Gênero");
				for(i = 0; i < 0; i++) putchar(' ');

				putchar('|');
				for(i = 0; i < 1; i++) putchar(' ');
				printf("Data de Nascimento");
				for(i = 0; i < 1; i++) putchar(' ');
				printf("|\n");

				printf("\t-----------------------------------------------------------------------------------------------");
				printf("-------------\n");
				//printf("|Título|Descrição|Autor|Ano |Quantidade|");
			}
			putchar('\t');
			putchar('|');
			for(i = 0; i < (j < 10 ? 1 : (j < 100 && j > 9 ? 0 : 99)); i++) putchar(' ');
			printf("%i", j + 1);
			for(i = 0; i < 0; i++) putchar(' ');

			putchar('|');
			nomeInicial(utente[j].nome, Abb);
			for(i = 0; i < (30 - strlen(Abb)) / 2 + (strlen(Abb) % 2 == 0 ? 0 : 1); i++) putchar(' ');
			printf("%s", Abb);
			for(i = 0; i < (30 - strlen(Abb)) / 2; i++) putchar(' ');

			putchar('|');
			for(i = 0; i < (10 - strlen((utente[j].categoria == 'E' ? "Estudante" : (utente[j].categoria == 'D' ? "Docente" : "Visitante")))) / 2 + (strlen(utente[j].categoria == 'E' ? "Estudante" : (utente[j].categoria == 'D' ? "Docente" : "Visitante")) % 2 == 0 ? 0 : 1); i++) putchar(' ');
			printf("%s", (utente[j].categoria == 'E' ? "Estudante" : (utente[j].categoria == 'D' ? "Docente" : "Visitante")));
			for(i = 0; i < 2 + (10 - strlen((utente[j].categoria == 'E' ? "Estudante" : (utente[j].categoria == 'D' ? "Docente" : "Visitante")))) / 2; i++) putchar(' ');

			putchar('|');
			nomeInicial(utente[j].morada, mor);
			for(i = 0; i < (30 - strlen(mor)) / 2 + (strlen(mor) % 2 == 0 ?  0 : 1); i++) putchar(' ');
			printf("%s", mor);
			for(i = 0; i < (30 - strlen(mor)) / 2; i++) putchar(' ');

			putchar('|');
			for(i = 0; i < 3; i++) putchar(' ');
			printf("%c", utente[j].genero);
			for(i = 0; i < 3; i++) putchar(' ');

			putchar('|');
			dataToString(utente[j].nascimento, date);
			for(i = 0; i < (20 - strlen(date)) / 2; i++) putchar(' ');
			printf("%s", date);
			for(i = 0; i < (20 - strlen(date)) / 2; i++) putchar(' ');
			printf("|\n");

			printf("\t---------------------------------------------------------------------------------------------");
			printf("---------------\n");

			found++;
		}
	}

	if(found == 0) {
		printf("\n\t\t\tNenhum utente encontrado!\a\n");
		printf("x----------------------------------------------------x");
	}
}

int registraUtente(Utente * utente, Utente novo) {

	if(uu < 100) {
		strcpy(utente[uu].nome, novo.nome);
		utente[uu].categoria = novo.categoria;
		utente[uu].genero = novo.genero;
		strcpy(utente[uu].morada, novo.morada);
		utente[uu].nascimento = novo.nascimento;;
		uu++;
		return 1;
	}
	return 0;
}

int atualizaUtente(Utente * utente, Utente novo, short index) {

	if(index > 0 && index < 101 && index <= uu) {
		strcpy(utente[index - 1].nome, novo.nome);
		strcpy(utente[index - 1].morada, novo.morada);
		utente[index - 1].genero = novo.genero;
		utente[index - 1].categoria = novo.categoria;
		utente[index - 1].nascimento = novo.nascimento;
		return 1;
	}
	return 0;
}

int eliminaUtente(Utente * utente, short index) {
	short i;
	Utente Null;

	if(index > 0 && index < 101 && index <= uu) {
		strcpy(utente[index - 1].nome, "null");
		strcpy(utente[index - 1].morada, "null");
		utente[index - 1].genero = '\0';
		utente[index - 1].categoria = '\0';
		utente[index - 1].nascimento.dia = 0;
		utente[index - 1].nascimento.mes = 0;
		utente[index - 1].nascimento.ano = 0;


		for(i = index - 1; i < uu; i++)
			if(!strcmp(utente[(i + 1) % 100].nome, "null") == 0) {
				Null = utente[i];
				utente[i] = utente[i + 1];
				utente[i + 1] = Null;
			}

		uu--;

		if(uu == 0)
			return -1;

		return 1;
	}
	return 0;
}

void listaUtente(Utente * utente) {
	consultaUtente(utente, "");
}

int iniciaUtente(Utente * utente) {
	int i;

	uu = 0;

	for(i = 0; i < 100; i++) {
		strcpy(utente[i].nome, "null");
		strcpy(utente[i].morada, "null");
		utente[i].genero = '\0';
		utente[i].categoria = '\0';
		utente[i].nascimento.dia = 0;
		utente[i].nascimento.mes = 0;
		utente[i].nascimento.ano = 0;
	}

	if(abrirU(utente)) return 1;

	return 0;
}

void limpaUtente(Utente * lista) {
	iniciaUtente(lista);
}
