#include "../../header/main.h"

void replaceAll(char * wrd, char wrd1, char wrd2);


int abrirU(Utente * u) {
	FILE * fp;
	Utente arq;
	char file[] = "Arquivo\\Utente\\utente.txt";
	int i = 0;


	if((fp = fopen(file, "r")) != NULL) {
		while(1) {
			if(feof(fp)) break;
			fscanf(fp, "%s %s %c %c %i %i %i", arq.nome, arq.morada, & arq.categoria,
				   & arq.genero, & arq.nascimento.dia, & arq.nascimento.mes,
				   & arq.nascimento.ano);
			replaceAll(arq.nome, '_', ' ');
			replaceAll(arq.morada, '_', ' ');
			if(registraUtente(u, arq))
				i++;
		}
		fclose(fp);
		return 1;
	}
	return 0;
}

int abrirL(Livro * l) {
	FILE * fp;
	Livro arq;
	char file[] = "Arquivo\\Livro\\livro.txt";

	if((fp = fopen(file, "r")) != NULL) {
		while(1) {
			if(feof(fp)) break;
			fscanf(fp, "%s %s %s %s %i %i", arq.titulo, arq.ISBN,
				   arq.descricao, arq.autor, & arq.ano, & arq.qtd);
			replaceAll(arq.titulo, '_', ' ');
			replaceAll(arq.descricao, '_', ' ');
			replaceAll(arq.autor, '_', ' ');
			if(!strcmp(arq.descricao, "sd")) arq.descricao[0] = '\0';
			replaceAll(arq.ISBN, '_', '-');
			registraLivro(l, arq);
		}
		fclose(fp);
		return 1;
	}
	return 0;
}

int abrirE(Emprestimo * e) {
	FILE * fp;
	char file[] = "Arquivo\\Emprestimo\\emprestimo.txt";


	if((fp = fopen(file, "r")) != NULL) {
		while(1 && ee < 60) {
			if(feof(fp)) break;
			fscanf(fp, "%s %s %i %i %i", e[ee].nomeUtente,
				   e[ee].tituloLivro, & e[ee].data.dia, & e[ee].data.mes, & e[ee].data.ano);
			replaceAll(e[ee].nomeUtente, '_', ' ');
			replaceAll(e[ee].tituloLivro, '_', ' ');
			ee++;
		}
		fclose(fp);
		return 1;
	}
	return 0;
}
