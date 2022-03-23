#include "../../header/main.h"
#define TRUE 1

int submenuEmp() {
	int i;
	char comando[2];

	system("mode 80, 30 & title SGB [MENU EMPRESTIMO]");

	do {
		system("cls");
		for(i = 0; i < 80; i++) putchar('=');
		puts("");


		putchar('=');
		for(i = 0; i < 31; i++) putchar(' ');
		printf("MENU EMPRESTIMO");
		for(i = 0; i < 32; i++) putchar(' ');
		puts("=");

		for(i = 0; i < 80; i++) putchar('=');
		puts("\n\n\n\n");

		puts("\t\tR) REGISTRAR\n");
		puts("\t\tU) PESQUISAR POR UTENTE\n");
		puts("\t\tL) PESQUISAR POR LIVRO\n");
		puts("\t\tE) ELIMINAR DADOS\n");
		puts("\t\tT) VER TODOS\n");
		puts("\t\tV) VOLTAR AO MENU PRINCIPAL\n");
		puts("\t\tS) SAIR\n\n");

		printf("\t\t\tCOMANDO >> ");
		scanf("%s", comando);

		if(!strcasecmp(comando, "R") || !strcasecmp(comando, "U") || !strcasecmp(comando, "L") || !strcasecmp(comando, "E") || !strcasecmp(comando, "T") || !strcasecmp(comando, "V") || !strcasecmp(comando, "S"))
			break;
		puts("\n\t\t\tOpção inválida!\a");
		espera(0, 0, 2);
	} while(TRUE);

	espera(0, 0, .8);
	if(!strcasecmp(comando, "R"))
		return 1;
	if(!strcasecmp(comando, "U"))
		return 2;
	if(!strcasecmp(comando, "L"))
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

int registraE(Emprestimo * e, Utente * u, Livro * l) {

	char resp[2];
	int i, idU, idL;

	do {
		system("mode 80, 20 & title SGB [REGISTRO - EMPRESTIMO]");

		do {
			system("cls");
			for(i = 0; i < 80; i++) putchar('=');
			puts("");


			putchar('=');
			for(i = 0; i < 25; i++) putchar(' ');
			printf("INSERIR DADOS DO EMPRESTIMO");
			for(i = 0; i < 26; i++) putchar(' ');
			puts("=");

			for(i = 0; i < 80; i++) putchar('=');
			puts("\n\n\n\n");

			printf("\tID DO UTENTE: ");
			scanf("%i", & idU);

			printf("\n\tID DO LIVRO: ");
			scanf("%i", & idL);

			printf("\n\n\tDESEJAS AVANÇAR?(S/N): ");
			setbuf(stdin, NULL);
			gets(resp);

		} while(!strcasecmp(resp, "n"));

		if(!registraEmprestimo(e, u, l, hoje(), idU, idL))
			return 0;

		puts("\nREGISTRO COMPLETO!\a");

		printf("DESEJAS INSERIR OUTRO?(S/N)");
		setbuf(stdin, NULL);
		gets(resp);
	} while(!strcasecmp(resp, "s"));

	return 1;
}

int pesquisaEL(Emprestimo * e, Livro * l) {

	char resp[2], titulo[30];
	int i;

	do {
		system("mode 80, 20 & title SGB [PESQUISA - EMPRESTIMO]");

		system("cls");
		for(i = 0; i < 80; i++) putchar('=');
		puts("");

		putchar('=');
		for(i = 0; i < 25; i++) putchar(' ');
		printf("INSERIR DADOS DO EMPRESTIMO");
		for(i = 0; i < 26; i++) putchar(' ');
		puts("=");

		for(i = 0; i < 80; i++) putchar('=');
		puts("\n\n\n\n");

		printf("\tTITULO: ");
		setbuf(stdin, NULL);
		gets(titulo);

		consultaEmprestimoL(e, l, titulo);

		printf("\nDESEJAS PESQUISAR OUTRO?(S/N)");
		setbuf(stdin, NULL);
		gets(resp);
	} while(!strcasecmp(resp, "s"));

	return 1;
}

int pesquisaEU(Emprestimo * e, Utente * u) {

	char resp[2], nome[30];
	int i;

	do {
		system("mode 80, 20 & title SGB [PESQUISA - EMPRESTIMO]");

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

		printf("\tNOME: ");
		setbuf(stdin, NULL);
		gets(nome);


		consultaEmprestimoU(e, u, nome);

		printf("\nDESEJAS PESQUISAR OUTRO?(S/N)");
		setbuf(stdin, NULL);
		gets(resp);
	} while(!strcasecmp(resp, "s"));

	return 1;
}


int eliminaE(Emprestimo * e, Livro * l) {

	int i, idE, aux;
	char resp[2];

	do {
		system("mode 80, 20 & title SGB [ELIMINAR - EMPRESTIMO]");

		do {
			system("cls");
			for(i = 0; i < 80; i++) putchar('=');
			puts("");


			putchar('=');
			for(i = 0; i < 27; i++) putchar(' ');
			printf("INSERIR DADOS DO EMPRESTIMO");
			for(i = 0; i < 28; i++) putchar(' ');
			puts("=");

			for(i = 0; i < 80; i++) putchar('=');
			puts("\n\n\n\n");

			printf("\tID DO UTENTE: ");
			scanf("%i", & idE);

			printf("\n\n\tDESEJAS AVANÇAR?(S/N): ");
			setbuf(stdin, NULL);
			gets(resp);

		} while(!strcasecmp(resp, "n"));

		aux = eliminaEmprestimo(e, l, idE);

		if(!aux)
			return aux;
		puts("\nELIMINAÇÃO COMPLETA!\a");

		printf("DESEJAS ELIMINAR OUTRO?(S/N)");
		setbuf(stdin, NULL);
		gets(resp);
	} while(!strcasecmp(resp, "s"));

	return aux;
}
int mostraE(Emprestimo * e, Utente * u) {
	listaEmprestimo(e, u);
	system("pause");
	return 1;
}
