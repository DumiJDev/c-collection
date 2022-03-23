#include "../../header/main.h"
#define TRUE 1

int submenuUtente() {
	int i;
	char comando[2];

	system("mode 80, 30 & title SGB [MENU UTENTE]");

	do {
		system("cls");
		for(i = 0; i < 40; i++) putchar('=');
		for(i = 0; i < 40; i++) putchar('=');
		puts("");


		putchar('=');
		for(i = 0; i < 33; i++) putchar(' ');
		printf("MENU UTENTE");
		for(i = 0; i < 34; i++) putchar(' ');
		puts("=");

		for(i = 0; i < 40; i++) putchar('=');
		for(i = 0; i < 40; i++) putchar('=');
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
		puts("\n\t\t\tOpção inválida!\a");
		espera(0, 0, 2);
	} while(TRUE);

	espera(0, 0, .8);
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

int registraU(Utente * u) {

	Utente novo;
	char resp[2];
	int i;

	do {
		system("mode 80, 25 & title SGB [REGISTRAR - UTENTE]");

		do {
			system("cls");
			for(i = 0; i < 80; i++) putchar('=');
			puts("");


			putchar('=');
			for(i = 0; i < 25; i++) putchar(' ');
			printf("REGISTRAR DADOS DO UTENTE");
			for(i = 0; i < 26; i++) putchar(' ');
			puts("=");

			for(i = 0; i < 80; i++) putchar('=');
			puts("\n\n\n\n");

			do {
				printf("\tNOME COMPLETO: ");
				setbuf(stdin, NULL);
				gets(novo.nome);
			} while(!strcmp(novo.nome, ""));

			do {
				printf("\n\tCATEGORIA(D/E/V): ");
				setbuf(stdin, NULL);
				scanf("%c", & novo.categoria);
				if(islower(novo.categoria)) novo.categoria = toupper(novo.categoria);
			} while(novo.categoria != 'D' && novo.categoria != 'E' && novo.categoria != 'V');

			do {
				printf("\n\tGÊNERO(M/F): ");
				setbuf(stdin, NULL);
				scanf("%c", & novo.genero);
				if(islower(novo.genero)) novo.genero = toupper(novo.genero);
			} while(novo.genero != 'M' && novo.genero != 'F');

			do {
				printf("\n\tMORADA: ");
				setbuf(stdin, NULL);
				gets(novo.morada);
			} while(!strcmp(novo.morada, ""));

			do {
				printf("\n\tDATA DE NASCIMENTO(dd/mm/yyyy): ");
				scanf("%i/%i/%i", & novo.nascimento.dia, & novo.nascimento.mes, & novo.nascimento.ano);
			} while(novo.nascimento.dia < 1 || novo.nascimento.dia > 31 || novo.nascimento.mes < 1 || novo.nascimento.mes > 12);

			printf("\n\n\t\t\tDESEJAS AVANÇAR?(S/N): ");
			setbuf(stdin, NULL);
			gets(resp);

		} while(!strcasecmp(resp, "n"));

		if(!registraUtente(u, novo))
			return 0;
		puts("\n\t\t\tREGISTRO COMPLETO!\a");

		printf("\t\tDESEJAS REGISTRAR OUTRO?(S/N) ");
		setbuf(stdin, NULL);
		gets(resp);
	} while(!strcasecmp(resp, "s"));

	return 1;
}

int pesquisaU(Utente * u) {

	char resp[2], nome[30];
	int i;

	do {
		system("mode 80, 20 & title SGB [PESQUISA - UTENTE]");

		system("cls");
		for(i = 0; i < 80; i++) putchar('=');
		puts("");


		putchar('=');
		for(i = 0; i < 27; i++) putchar(' ');
		printf("INSERIR DADOS DO UTENTE");
		for(i = 0; i < 28; i++) putchar(' ');
		puts("=");

		for(i = 0; i < 80; i++) putchar('=');
		puts("\n\n\n\n");

		do {
			printf("\tNOME: ");
			setbuf(stdin, NULL);
			gets(nome);
		} while(!strcmp(nome, ""));

		consultaUtente(u, nome);

		printf("\n\t\tDESEJAS PESQUISAR OUTRO?(S/N) ");
		setbuf(stdin, NULL);
		gets(resp);
	} while(!strcasecmp(resp, "s"));

	return 1;
}

int atualizaU(Utente * u) {

	Utente novo;
	char resp[2];
	int i, idU;

	do {
		system("mode 80, 20 & title SGB [ATUALIZAR - UTENTE]");

		do {
			system("cls");
			for(i = 0; i < 80; i++) putchar('=');
			puts("");


			putchar('=');
			for(i = 0; i < 25; i++) putchar(' ');
			printf("ATUALIZAR DADOS DO UTENTE");
			for(i = 0; i < 26; i++) putchar(' ');
			puts("=");

			for(i = 0; i < 80; i++) putchar('=');
			puts("\n\n\n\n");

			printf("\tID DO UTENTE: ");
			scanf("%i", & idU);

			do {
				printf("\n\tNOME COMPLETO: ");
				setbuf(stdin, NULL);
				gets(novo.nome);
			} while(!strcmp(novo.nome, ""));

			do {
				printf("\n\tCATEGORIA(D/E/V): ");
				scanf("%c", & novo.categoria);
				if(islower(novo.categoria)) novo.categoria = toupper(novo.categoria);
			} while( novo.categoria != 'D' &&  novo.categoria != 'E' && novo.categoria != 'V');

			do {
				printf("\n\tGÊNERO(M/F): ");
				scanf("%c", & novo.genero);
				if(islower(novo.genero)) novo.genero = toupper(novo.genero);
			} while(novo.genero != 'M' && novo.genero != 'F');

			printf("\n\tMORADA: ");
			setbuf(stdin, NULL);
			gets(novo.morada);

			do {
				printf("\n\tDATA DE NASCIMENTO(dd/mm/yyyy): ");
				scanf("%i/%i/%i", & novo.nascimento.dia, & novo.nascimento.mes, & novo.nascimento.ano);
			} while(novo.nascimento.dia < 1 || novo.nascimento.dia > 31 || novo.nascimento.mes < 1 || novo.nascimento.mes > 12);

			printf("\n\n\t\t\tDESEJAS AVANÇAR?(S/N): ");
			setbuf(stdin, NULL);
			gets(resp);

		} while(!strcasecmp(resp, "n"));

		if(!atualizaUtente(u, novo, idU))
			return 0;
		puts("\n\t\t\tATUALIZAÇÃO COMPLETA!\a");


		printf("\t\tDESEJAS ATUALIZAR OUTRO?(S/N) ");
		setbuf(stdin, NULL);
		gets(resp);
	} while(!strcasecmp(resp, "s"));

	return 1;
}

int eliminaU(Utente * u) {

	int i, idU, aux;
	char resp[2];

	system("mode 80, 20 & title SGB [ELIMINAR - UTENTE]");

	do {

		do {
			system("cls");
			for(i = 0; i < 80; i++) putchar('=');
			puts("");


			putchar('=');
			for(i = 0; i < 27; i++) putchar(' ');
			printf("INSERIR DADOS DO UTENTE");
			for(i = 0; i < 28; i++) putchar(' ');
			puts("=");

			for(i = 0; i < 80; i++) putchar('=');
			puts("\n\n\n\n");

			printf("\tID DO UTENTE: ");
			scanf("%i", & idU);

			printf("\n\n\tDESEJAS AVANÇAR?(S/N): ");
			setbuf(stdin, NULL);
			gets(resp);

		} while(!strcasecmp(resp, "n"));

		aux = eliminaUtente(u, idU);

		if(!aux)
			return aux;

		puts("\n\t\t\tELIMINAÇÃO COMPLETA!\a");

		printf("\t\tDESEJAS ELIMINAR OUTRO?(S/N) ");
		setbuf(stdin, NULL);
		gets(resp);
	} while(!strcasecmp(resp, "s"));

	return aux;
}

int mostraU(Utente * u) {
	system("mode 80, 20 & title SGB [LISTA - UTENTE]");
	listaUtente(u);
	system("pause");
	return 1;
}
