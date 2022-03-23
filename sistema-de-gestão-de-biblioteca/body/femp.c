#include "../header/main.h"

void nomeInicial(char * , char * );
void dataToString(Data, char * );


void consultaEmprestimoU(Emprestimo * lista, Utente * utente, char * nome) {
	int i, found = 0, j, k, e;
	char n[strlen(nome)], date[10], Abb[20];

	system("mode 124, 70 & cls");

	for(e = 0; e < ee; e++) {

		for(k = 0; k < uu; k++) {
			for(j = 0; j < strlen(nome); j++)
				n[j] = utente[k].nome[j];
			n[j] = '\0';
			if(!strcasecmp(nome, n))
				if(!strcasecmp(utente[k].nome, lista[e].nomeUtente)) {
					if(found == 0) {
						printf("\t-------------------------------------------------------------------------------------------\n");

						putchar('\t');
						putchar('|');
						for(i = 0; i < 34; i++) putchar(' ');
						printf("TABELA DOS EMPRÉSTIMOS");
						for(i = 0; i < 33; i++) putchar(' ');

						printf("|\n\t-------------------------------------------------------------------------------------------\n");

						putchar('\t');
						putchar('|');
						for(i = 0; i < 0; i++) putchar(' ');
						printf("ID");
						for(i = 0; i < 0; i++) putchar(' ');

						putchar('|');
						for(i = 0; i < 7; i++) putchar(' ');
						printf("Nome");
						for(i = 0; i < 7; i++) putchar(' ');

						putchar('|');
						for(i = 0; i < 22; i++) putchar(' ');
						printf("Título");
						for(i = 0; i < 22; i++) putchar(' ');

						putchar('|');
						for(i = 0; i < 1; i++) putchar(' ');
						printf("Data do pedido");
						for(i = 0; i < 1; i++) putchar(' ');
						printf("|\n");

						printf("\t-------------------------------------------------------------------------------------------\n");
						//printf("|Título|Descrição|Autor|Ano |Quantidade|");
					}
					putchar('\t');
					putchar('|');
					for(i = 0; i < (e < 10 ? 1 : (e < 100 && j > 9 ? 0 : 99)); i++) putchar(' ');
					printf("%i", e + 1);
					for(i = 0; i < 0; i++) putchar(' ');

					putchar('|');
					nomeInicial(lista[e].nomeUtente, Abb);
					for(i = 0; i < (18 - strlen(Abb)) / 2 + (strlen(Abb) % 2 == 0 ? 0 : 1); i++) putchar(' ');
					printf("%s", Abb);
					for(i = 0; i < (18 - strlen(Abb)) / 2; i++) putchar(' ');

					putchar('|');
					for(i = 0; i < (50 - strlen(lista[e].tituloLivro)) / 2 + (strlen(lista[e].tituloLivro) % 2 == 0 ?  0 : 1); i++) putchar(' ');
					printf("%s", lista[e].tituloLivro);
					for(i = 0; i < (50 - strlen(lista[e].tituloLivro)) / 2; i++) putchar(' ');

					putchar('|');
					dataToString(lista[e].data, date);
					for(i = 0; i < (16 - strlen(date)) / 2; i++) putchar(' ');
					printf("%s", date);
					for(i = 0; i < (16 - strlen(date)) / 2; i++) putchar(' ');
					printf("|\n");

					printf("\t-------------------------------------------------------------------------------------------\n");

					found++;
				}
		}
	}

	if(found == 0) {
		printf("\n\t\tNenhum utente encontrado!\a\n");
		printf("x----------------------------------------------------x");
	}
}

void consultaEmprestimoL(Emprestimo * lista, Livro * livro, char * titulo) {
	int i, found = 0, j, k, e;
	char n[strlen(titulo)], date[10], Abb[20];

	system("mode 124, 70 & cls");

	for(e = 0; e < ee; e++) {

		for(k = 0; k < uu; k++) {
			for(j = 0; j < strlen(titulo); j++)
				n[j] = livro[k].titulo[j];
			n[j] = '\0';
			if(!strcasecmp(titulo, n))
				if(!strcasecmp(livro[k].titulo, lista[e].tituloLivro)) {
					if(found == 0) {
						putchar('\t');
						putchar('|');
						for(i = 0; i < 0; i++) putchar(' ');
						printf("ID");
						for(i = 0; i < 0; i++) putchar(' ');

						putchar('|');
						for(i = 0; i < 7; i++) putchar(' ');
						printf("Nome");
						for(i = 0; i < 7; i++) putchar(' ');

						putchar('|');
						for(i = 0; i < 22; i++) putchar(' ');
						printf("Título");
						for(i = 0; i < 22; i++) putchar(' ');


						putchar('|');
						for(i = 0; i < 1; i++) putchar(' ');
						printf("Data do pedido");
						for(i = 0; i < 1; i++) putchar(' ');
						printf("|\n");

						printf("\t-------------------------------------------------------------------------------------------\n");
						//printf("|Título|Descrição|Autor|Ano |Quantidade|");
					}
					putchar('\t');
					putchar('|');
					for(i = 0; i < (e < 10 ? 1 : (e < 100 && j > 9 ? 0 : 99)); i++) putchar(' ');
					printf("%i", e + 1);
					for(i = 0; i < 0; i++) putchar(' ');

					putchar('|');
					nomeInicial(lista[e].nomeUtente, Abb);
					for(i = 0; i < (18 - strlen(Abb)) / 2 + (strlen(Abb) % 2 == 0 ? 0 : 1); i++) putchar(' ');
					printf("%s", Abb);
					for(i = 0; i < (18 - strlen(Abb)) / 2; i++) putchar(' ');

					putchar('|');
					for(i = 0; i < (50 - strlen(lista[e].tituloLivro)) / 2 + (strlen(lista[e].tituloLivro) % 2 == 0 ?  0 : 1); i++) putchar(' ');
					printf("%s", lista[e].tituloLivro);
					for(i = 0; i < (50 - strlen(lista[e].tituloLivro)) / 2; i++) putchar(' ');

					putchar('|');
					dataToString(lista[e].data, date);
					for(i = 0; i < (16 - strlen(date)) / 2; i++) putchar(' ');
					printf("%s", date);
					for(i = 0; i < (16 - strlen(date)) / 2; i++) putchar(' ');
					printf("|\n");

					printf("\t-------------------------------------------------------------------------------------------\n");

					found++;
				}
		}
	}

	if(found == 0) {
		printf("\n\t\tNenhum utente encontrado!\a\n");
		printf("x----------------------------------------------------x");
	}
}

int registraEmprestimo(Emprestimo * emprestimo, Utente * utentes,
					   Livro * livros, Data data, short indexU, short indexL) {
	int i;
	if(ee < 61 && livros[indexL - 1].qtd > 0) {
		strcpy(emprestimo[ee].nomeUtente, utentes[indexU - 1].nome);
		strcpy(emprestimo[ee].tituloLivro, livros[indexL - 1].titulo);
		emprestimo[ee].data = data;
		for(i = 0; i < bb; i++)
			if(!strcmp(livros[indexL - 1].ISBN, livros[i].ISBN))
				livros[i].qtd--;
		ee++;
		return 1;
	} else if(ee > 59) {
		printf("Já não há livros!\a");
		espera(0, 0, .5);
	} else {
		printf("Livro indisponível!\a");
		espera(0, 0, .5);
	}
	return 0;
}

int eliminaEmprestimo(Emprestimo * emprestimo, Livro * l, short index) {
	short i;
	Emprestimo Null;

	if(ee > 1) {
		for(i = 0; i < bbr; i++)
			if(!strcasecmp(l[i].titulo, emprestimo[index - 1].tituloLivro))
				l[i].qtd++;


		strcpy(emprestimo[index - 1].nomeUtente, "null");
		strcpy(emprestimo[index - 1].tituloLivro, "null");
		emprestimo[index - 1].data.dia = 0;
		emprestimo[index - 1].data.mes = 0;
		emprestimo[index - 1].data.ano = 0;




		for(i = index - 1; i < ee; i++)
			if(!strcmp(emprestimo[i + 1].nomeUtente, "null") == 0) {
				Null = emprestimo[i];
				emprestimo[i] = emprestimo[i + 1];
				emprestimo[i + 1] = Null;
			}

		ee--;

		if(ee == -1)
			return -1;

		return 1;
	}

	return 0;
}

void listaEmprestimo(Emprestimo * lista, Utente * utente) {
	consultaEmprestimoU(lista, utente, "");
}

int iniciaEmprestimo(Emprestimo * lista) {
	int i;

	ee = 0;


	for(i = 0; i < 60; i++) {
		strcpy(lista[i].nomeUtente, "null");
		strcpy(lista[i].tituloLivro, "null");
		lista[i].data.dia = 0;
		lista[i].data.mes = 0;
		lista[i].data.ano = 0;
	}

	if(abrirE(lista)) return 1;

	return 0;
}

void limpaEmprestimo(Emprestimo * lista) {
	iniciaEmprestimo(lista);
}
