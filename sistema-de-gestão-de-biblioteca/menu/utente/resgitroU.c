
int resgistraU(Utente * u) {

	char resp[2], nome[30], gen[2], cat[2], mor[50];
	int dia, mes, ano, i;

	system("mode 80, 20 & title SGB [RESGISTRO - UTENTE]");

	do {
		system("cls");
		for(i = 0; i < 40; i++) putchar('=');
		for(i = 0; i < 40; i++) putchar('=');
		puts("");


		putchar('=');
		for(i = 0; i < 27; i++) putchar(' ');
		printf("INSERIR DADOS DO UTENTE");
		for(i = 0; i < 28; i++) putchar(' ');
		puts("=");

		for(i = 0; i < 40; i++) putchar('=');
		for(i = 0; i < 40; i++) putchar('=');
		puts("\n\n\n\n");

		printf("\tNOME: ");
		setbuf(stdin, NULL);
		gets(nome);

		do {
			printf("\tCATEGORIA(D/E/V): ");
			scanf("%s", cat);
		} while(!strcasecmp(cat, "d") == 0 && !strcasecmp(cat, "e") == 0 && !strcasecmp(cat, "v") == 0);

		do {
			printf("\tGÊNERO(M/F): ");
			scanf("%s", gen);
		} while(!strcasecmp(gen, "m") == 0 && !strcasecmp(gen, "f") == 0);
		
		printf("\tMORADA: ");
		setbuf(stdin, NULL);
		gets(mor);
		
		printf("\tDATA DE NASCIMENTO(dd/mm/yyyy): ");
		scanf("%i/%i/%i", &dia, &mes, &ano);
		
		printf("\n\n\tDESEJAS AVANÇAR?(S/N): ");
		setbuf(stdin, NULL);
		gets(resp);

	} while(!strcasecmp(resp, "s"));
	registraUtente(u, nome, cat[0], mor, data(dia, mes, ano), gen[0]);
	
	return 0;
}
