#include "../../header/main.h"

void replaceAll(char * wrd, char wrd1, char wrd2);

int salvarU(Utente * u) {
	FILE * fp;
	char file[] = "Arquivo\\Utente\\utente.txt";
	int i;

	system("if not exist Arquivo\\Utente MKDIR Arquivo\\Utente");

	if((fp = fopen(file, "w")) != NULL) {
		for(i = 0; i < uu; i++) {
			replaceAll(u[i].nome, ' ', '_');
			replaceAll(u[i].morada, ' ', '_');
			if(i != uu - 1)
				fprintf(fp, "%s %s %c %c %i %i %i\n", u[i].nome, u[i].morada, u[i].categoria,
						u[i].genero, u[i].nascimento.dia, u[i].nascimento.mes, u[i].nascimento.ano);
			else
				fprintf(fp, "%s %s %c %c %i %i %i", u[i].nome, u[i].morada, u[i].categoria,
						u[i].genero, u[i].nascimento.dia, u[i].nascimento.mes, u[i].nascimento.ano);
		}
		fflush(fp);
		fclose(fp);
		return 1;
	}
	return 0;
}

int salvarL(Livro * l) {
	FILE * fp;
	char file[] = "Arquivo\\Livro\\livro.txt";
	int i;

	system("if not exist Arquivo\\Livro MKDIR Arquivo\\Livro");

	if((fp = fopen(file, "w")) != NULL) {
		for(i = 0; i < bbr; i++) {
			if(!strcmp(l[i].descricao, ""))
				strcpy(l[i].descricao, "sd");
			replaceAll(l[i].titulo, ' ', '_');
			replaceAll(l[i].descricao, ' ', '_');
			replaceAll(l[i].autor, ' ', '_');
			replaceAll(l[i].ISBN, '-', '_');
			if(i != bbr - 1)
				fprintf(fp, "%s %s %s %s %i %i\n", l[i].titulo, l[i].ISBN,
						l[i].descricao, l[i].autor, l[i].ano, l[i].qtd);
			else fprintf(fp, "%s %s %s %s %i %i", l[i].titulo, l[i].ISBN,
							 l[i].descricao, l[i].autor, l[i].ano, l[i].qtd);
		}
		fflush(fp);
		fclose(fp);
		return 1;
	}
	return 0;
}

int salvarE(Emprestimo * e) {
	FILE * fp;
	char file[] = "Arquivo\\Emprestimo\\emprestimo.txt";
	int i;

	system("if not exist Arquivo\\Emprestimo MKDIR Arquivo\\Emprestimo");

	if((fp = fopen(file, "w")) != NULL) {
		for(i = 0; i < uu; i++)
			if(!strcmp(e[i].nomeUtente, "null") == 0) {
				replaceAll(e[i].nomeUtente, ' ', '_');
				replaceAll(e[i].tituloLivro, ' ', '_');
				if(i != uu - 1)
					fprintf(fp, "%s %s %i %i %i\n", e[i].nomeUtente,
							e[i].tituloLivro, e[i].data.dia, e[i].data.mes, e[i].data.ano);
				else fprintf(fp, "%s %s %i %i %i", e[i].nomeUtente,
								 e[i].tituloLivro, e[i].data.dia, e[i].data.mes, e[i].data.ano);
			} else break;
		fflush(fp);
		fclose(fp);
		return 1;
	}
	return 0;
}
