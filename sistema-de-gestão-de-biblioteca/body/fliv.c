#include "../header/main.h"

void consultaLivro(Livro * livro, char * ISBN) {
	int i, found = 0, j, k;
	char n[strlen(ISBN)];

	system("mode 124, 70 & cls");

	for(j = 0; j < bbr; j++) {
		for(k = 0; k < strlen(ISBN); k++)
			n[k] = livro[j].ISBN[k];
		n[k] = '\0';
		if(!strcasecmp(ISBN, n)) {
			if(found == 0) {
				printf("---------------------------------------------------------------------------------------------");
				printf("--------------------------------------------------------------------------\n");

				putchar('|');
				for(i = 0; i < 0; i++) putchar(' ');
				printf("ID");
				for(i = 0; i < 0; i++) putchar(' ');

				putchar('|');
				for(i = 0; i < 22; i++) putchar(' ');
				printf("Título");
				for(i = 0; i < 22; i++) putchar(' ');

				putchar('|');
				for(i = 0; i < 20; i++) putchar(' ');
				printf("Descrição");
				for(i = 0; i < 20; i++) putchar(' ');

				putchar('|');
				for(i = 0; i < 12; i++) putchar(' ');
				printf("Autor");
				for(i = 0; i < 12; i++) putchar(' ');

				putchar('|');
				for(i = 0; i < 8; i++) putchar(' ');
				printf("ISBN");
				for(i = 0; i < 8; i++) putchar(' ');

				putchar('|');
				for(i = 0; i < 1; i++) putchar(' ');
				printf("Ano");
				for(i = 0; i < 1; i++) putchar(' ');

				putchar('|');
				for(i = 0; i < 1; i++) putchar(' ');
				printf("Qtd");
				for(i = 0; i < 0; i++) putchar(' ');
				printf("|\n");

				printf("-----------------------------------------------------------------------------------------------");
				printf("------------------------------------------------------------------------\n");
				//printf("|Título|Descrição|Autor|Ano |Quantidade|");
			}

			putchar('|');
			for(i = 0; i < (j < 10 ? 1 : (j < 100 && j > 9 ? 0 : 99)); i++) putchar(' ');
			printf("%i", j + 1);
			for(i = 0; i < 0; i++) putchar(' ');

			putchar('|');
			for(i = 0; i < (strlen(livro[j].titulo) % 2 == 0 ? (50 - strlen(livro[j].titulo)) / 2 : (50 - strlen(livro[j].titulo)) / 2 + 1); i++) putchar(' ');
			printf("%s", livro[j].titulo);
			for(i = 0; i < (50 - strlen(livro[j].titulo)) / 2; i++) putchar(' ');

			putchar('|');
			for(i = 0; i < (strlen(livro[j].descricao) % 2 == 0 ? (50 - strlen(livro[j].descricao)) / 2 - 1 : (50 - strlen(livro[j].descricao)) / 2); i++) putchar(' ');
			printf("%s", livro[j].descricao);
			for(i = 0; i < (50 - strlen(livro[j].descricao)) / 2; i++) putchar(' ');

			putchar('|');
			for(i = 0; i < (strlen(livro[j].autor) % 2 == 0 ? (30 - strlen(livro[j].autor)) / 2 - 1 : (30 - strlen(livro[j].autor)) / 2); i++) putchar(' ');
			printf("%s", livro[j].autor);
			for(i = 0; i < (30 - strlen(livro[j].autor)) / 2; i++) putchar(' ');

			putchar('|');
			for(i = 0; i < (strlen(livro[j].ISBN) % 2 == 0 ? (20 - strlen(livro[j].ISBN)) / 2 : (20 - strlen(livro[j].ISBN)) / 2 + 1); i++) putchar(' ');
			printf("%s", livro[j].ISBN);
			for(i = 0; i < (20 - strlen(livro[j].ISBN)) / 2; i++) putchar(' ');

			putchar('|');
			for(i = 0; i < 1; i++) putchar(' ');
			printf("%i", livro[j].ano);
			for(i = 0; i < 0; i++) putchar(' ');

			putchar('|');
			for(i = 0; i < (livro[j].qtd < 10 ? 2 : (livro[j].qtd < 100 && livro[j].qtd > 9 ? 1 : 99)); i++) putchar(' ');
			printf("%i", livro[j].qtd);
			for(i = 0; i < 1; i++) putchar(' ');
			printf("|\n");

			printf("---------------------------------------------------------------------------------------------");
			printf("--------------------------------------------------------------------------\n");

			found++;
		}
	}

	if(found == 0) {
		printf("\n\t\tNenhum livro encontrado!\a\n");
		printf("x----------------------------------------------------x");
	}
}

int registraLivro(Livro * livros, Livro novo) {
	int i;

	if(bb < 61) {
		for(i = 0; i < 60; i++)
			if(!strcmp(livros[i].ISBN, novo.ISBN)) {
				livros[i].qtd++;
				i = -1;
				break;
			} else if(!strcmp(livros[i].ISBN, "null"))
				break;

		if(i < 60 && i != -1) {
			if(!strcmp(livros[i].ISBN, "null"))
				bbr++;
			strcpy(livros[i].titulo, novo.titulo);
			strcpy(livros[i].ISBN, novo.ISBN);
			strcpy(livros[i].descricao, novo.descricao);
			livros[i].ano = novo.ano;
			strcpy(livros[i].autor, novo.autor);
			livros[i].qtd += novo.qtd;

		}
		bb = 0;

		for(i = 0; i < 60; i++)
			bb += livros[i].qtd;
		return 1;
	}
	return 0;
}

void listaLivro(Livro * l) {
	consultaLivro(l, "");
}

int atualizaLivro(Livro * livro, Livro novosdados, int index) {

	if(index > 0 && index < 61 && index <= bbr) {
		strcpy(livro[index - 1].titulo, novosdados.titulo);
		strcpy(livro[index - 1].ISBN, novosdados.ISBN);
		strcpy(livro[index - 1].descricao, novosdados.descricao);
		livro[index - 1].ano = novosdados.ano;
		strcpy(livro[index - 1].autor, novosdados.autor);
		livro[index - 1].qtd = novosdados.qtd;
		return 1;
	}
	return 0;
}

int eliminaLivro(Livro * l, int index) {
	int i, j = bb;
	Livro Null;

	bb -= l[index - 1].qtd;

	if(bb > 0 && index > 0 && index < bbr) {
		strcpy(l[index - 1].titulo, "null");
		strcpy(l[index - 1].ISBN, "null");
		strcpy(l[index - 1].descricao, "null");
		strcpy(l[index - 1].autor, "null");
		l[index - 1].ano = 0;
		l[index - 1].qtd = 0;


		for(i = index - 1; i < j; i++)
			if(!strcmp(l[i + 1].titulo, "null") == 0) {
				Null = l[i];
				l[i] = l[i + 1];
				l[i + 1] = Null;
			} else break;


		bbr--;

		if(bbr == 0)
			return -1;

		return 1;
	}

	return 0;
}

int iniciaLivro(Livro * l) {
	int i;

	bb = bbr = 0;

	for(i = 0; i < 60; i++) {
		strcpy(l[i].titulo, "null");
		strcpy(l[i].ISBN, "null");
		strcpy(l[i].descricao, "null");
		strcpy(l[i].autor, "null");
		l[i].ano = 0;
		l[i].qtd = 0;
	}

	if(abrirL(l)) return 1;

	return 0;
}
