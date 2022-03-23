#include "../header/main.h"
#define TRUE 1

int menu() {
	int i;
	char comando[2];

	system("mode 80, 20 & title SGB [MENU PRINCIPAL]");

	do {
		system("cls");
		for(i = 0; i < 40; i++) putchar('=');
		for(i = 0; i < 40; i++) putchar('=');
		puts("");


		putchar('=');
		for(i = 0; i < 32; i++) putchar(' ');
		printf("MENU PRINCIPAL");
		for(i = 0; i < 32; i++) putchar(' ');
		puts("=");

		for(i = 0; i < 40; i++) putchar('=');
		for(i = 0; i < 40; i++) putchar('=');
		puts("\n\n\n\n");

		puts("\t\tU) UTENTE\n");
		puts("\t\tL) LIVRO\n");
		puts("\t\tE) EMPRESTIMO\n");
		puts("\t\tS) SAIR\n\n");

		printf("\t\t\tCOMANDO >> ");
		scanf("%s", comando);

		if(!strcasecmp(comando, "u") || !strcasecmp(comando, "l") || !strcasecmp(comando, "e") || !strcasecmp(comando, "s"))
			break;
		puts("Opção inválida!");
		espera(0, 0, 1.5);
	} while(TRUE);

	espera(0, 0, 1.89);
	if(!strcasecmp(comando, "u"))
		return 1;
	if(!strcasecmp(comando, "l"))
		return 2;
	if(!strcasecmp(comando, "e"))
		return 3;

	if(!strcasecmp(comando, "s"))
		return 0;
	return -1;
}
