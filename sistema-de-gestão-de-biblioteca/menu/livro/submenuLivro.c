#include "../../header/main.h"
#define TRUE 1

int submenuLivro() {
	int i;
	char comando[2];

	system("mode 80, 30 & title SGB [MENU LIVRO]");

	do {
		system("cls");
		for(i = 0; i < 80; i++) putchar('=');
		puts("");


		putchar('=');
		for(i = 0; i < 34; i++) putchar(' ');
		printf("MENU LIVRO");
		for(i = 0; i < 34; i++) putchar(' ');
		puts("=");

		for(i = 0; i < 80; i++) putchar('=');
		puts("\n\n\n\n");

		puts("\t\tR) REGISTRAR\n");
		puts("\t\tP) PESQUISAR\n");
		puts("\t\tA) ATUALIZAR DADOS\n");
		puts("\t\tE) ELIMINAR DADOS\n");
		puts("\t\tT) VER TODOS\n");
		puts("\t\tV) VOLTAR AO MENU PRINCIPAL\n");
		puts("\t\tS) SAIR\n\n");

		printf("\t\t\tCOMANDO >> ");
		scanf("%s", comando);

		if(!strcasecmp(comando, "R") || !strcasecmp(comando, "P") || !strcasecmp(comando, "A") || !strcasecmp(comando, "E") || !strcasecmp(comando, "T") || !strcasecmp(comando, "V") || !strcasecmp(comando, "S"))
			break;
		puts("\n\t\t\tOpção inválida!\a");;
		espera(0, 0, .8);
	} while(TRUE);

	espera(0, 0, 1.89);
	if(!strcasecmp(comando, "R"))
		return 1;
	if(!strcasecmp(comando, "P"))
		return 2;
	if(!strcasecmp(comando, "A"))
		return 3;
	if(!strcasecmp(comando, "E"))
		return 4;
	if(!strcasecmp(comando, "T"))
		return 5;
	if(!strcasecmp(comando, "V"))
		return -1;
	if(!strcasecmp(comando, "S"))
		return 0;

	exit(0);
}

int registraL(Livro * l) {

	Livro novo;
	char resp[2];
	int i;


	do {
		system("mode 80, 26 & title SGB [REGISTRO - LIVRO]");

		do {
			system("cls");
			for(i = 0; i < 80; i++) putchar('=');
			puts("");


			putchar('=');
			for(i = 0; i < 27; i++) putchar(' ');
			printf("INSERIR DADOS DO LIVRO ");
			for(i = 0; i < 28; i++) putchar(' ');
			puts("=");

			for(i = 0; i < 80; i++) putchar('=');
			puts("\n\n\n\n");

			do {
				printf("\tTITULO: ");
				setbuf(stdin, NULL);
				gets(novo.titulo);
			} while(!strcmp(novo.titulo, ""));

			do {
				printf("\n\tISBN: ");
				setbuf(stdin, NULL);
				gets(novo.ISBN);
			} while(!strcmp(novo.ISBN, ""));

			do {
				printf("\n\tAUTOR: ");
				setbuf(stdin, NULL);
				gets(novo.autor);
			} while(!strcmp(novo.autor, ""));

			printf("\n\tDESCRIÇÃO: ");
			setbuf(stdin, NULL);
			gets(novo.descricao);

			printf("\n\tDATA DE LANÇAMENTO: ");
			scanf("%i", & novo.ano);

			do {
				printf("\n\tQUANTIDADE: ");
				scanf("%i", & novo.qtd);
			} while(novo.qtd < 1 || novo.qtd > 60);

			printf("\n\n\tDESEJAS AVANÇAR?(S/N): ");
			setbuf(stdin, NULL);
			gets(resp);

		} while(!strcasecmp(resp, "n"));

		if(!registraLivro(l, novo))
			return 0;

		puts("\nREGISTRO COMPLETO!\a");

		printf("DESEJAS INSERIR OUTRO?(S/N) ");
		setbuf(stdin, NULL);
		gets(resp);
	} while(!strcasecmp(resp, "s"));

	return 1;
}

int pesquisaL(Livro * l) {

	char resp[2], isbn[20];
	int i;

	do {
		system("mode 80, 26 & title SGB [REGISTRO - LIVRO]");

		do {
			system("cls");
			for(i = 0; i < 80; i++) putchar('=');
			puts("");


			putchar('=');
			for(i = 0; i < 27; i++) putchar(' ');
			printf("INSERIR DADOS DO LIVRO ");
			for(i = 0; i < 28; i++) putchar(' ');
			puts("=");

			for(i = 0; i < 80; i++) putchar('=');
			puts("\n\n\n\n");

			printf("\n\tISBN: ");
			setbuf(stdin, NULL);
			gets(isbn);

			printf("\n\n\tDESEJAS AVANÇAR?(S/N): ");
			setbuf(stdin, NULL);
			gets(resp);

		} while(!strcasecmp(resp, "n"));

		consultaLivro(l, isbn);

		printf("DESEJAS PESQUISAR OUTRO?(S/N) ");
		setbuf(stdin, NULL);
		gets(resp);
	} while(!strcasecmp(resp, "s"));

	return 1;
}

int atualizaL(Livro * l) {

	char resp[2];
	int idL, i;
	Livro novo;

	do {
		system("mode 80, 26 & title SGB [ATUALIZA - LIVRO]");

		do {
			system("cls");
			for(i = 0; i < 80; i++) putchar('=');
			puts("");


			putchar('=');
			for(i = 0; i < 27; i++) putchar(' ');
			printf("INSERIR DADOS DO LIVRO ");
			for(i = 0; i < 28; i++) putchar(' ');
			puts("=");

			for(i = 0; i < 80; i++) putchar('=');
			puts("\n\n\n\n");

			printf("\tID DO LIVRO: ");
			scanf("%i", & idL);

			printf("\n\tTITULO: ");
			setbuf(stdin, NULL);
			gets(novo.titulo);

			printf("\n\tISBN: ");
			setbuf(stdin, NULL);
			gets(novo.ISBN);

			printf("\n\tAUTOR: ");
			setbuf(stdin, NULL);
			gets(novo.autor);

			printf("\n\tDESCRIÇÃO: ");
			setbuf(stdin, NULL);
			gets(novo.descricao);

			printf("\n\tDATA DE LANÇAMENTO: ");
			scanf("%i", & novo.ano);

			printf("\n\tQUANTIDADE: ");
			scanf("%i", & novo.qtd);

			printf("\n\n\tDESEJAS AVANÇAR?(S/N): ");
			setbuf(stdin, NULL);
			gets(resp);

		} while(!strcasecmp(resp, "n"));

		if(!atualizaLivro(l, novo, idL))
			return 0;

		puts("\nREGISTRO COMPLETO!\a");

		printf("DESEJAS INSERIR OUTRO?(S/N) ");
		setbuf(stdin, NULL);
		gets(resp);
	} while(!strcasecmp(resp, "s"));

	return 1;
}

int eliminaL(Livro * l) {
	int i, idL, aux;
	char resp[2];

	do {
		system("mode 80, 26 & title SGB [ELIMINAR - LIVRO]");

		do {
			system("cls");
			for(i = 0; i < 80; i++) putchar('=');
			puts("");


			putchar('=');
			for(i = 0; i < 27; i++) putchar(' ');
			printf("INSERIR DADOS DO LIVRO");
			for(i = 0; i < 28; i++) putchar(' ');
			puts("=");

			for(i = 0; i < 80; i++) putchar('=');
			puts("\n\n\n\n");

			printf("\tID DO LIVRO: ");
			scanf("%i", & idL);

			printf("\n\n\tDESEJAS AVANÇAR?(S/N): ");
			setbuf(stdin, NULL);
			gets(resp);

		} while(!strcasecmp(resp, "n"));

		aux = eliminaLivro(l, idL);

		if(!aux)
			return aux;
		puts("\nELIMINAÇÃO COMPLETA!\a");

		printf("DESEJAS ELIMINAR OUTRO?(S/N) ");
		setbuf(stdin, NULL);
		gets(resp);
	} while(!strcasecmp(resp, "s"));

	return aux;
}

int mostraL(Livro * l) {
	listaLivro(l);
	system("pause");
	return 1;
}
