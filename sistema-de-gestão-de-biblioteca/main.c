#include "header/main.h"


int main(int argc, char * * argv) {
	setlocale(LC_ALL, "");

	Livro livro[60];
	Utente utente[100];
	Emprestimo emprestimo[60];

	int consU = 0, consL = 0, consE = 0, auxU, auxL, auxE;

	if(iniciaLivro(livro)) consL = 1;
	if(iniciaUtente(utente)) consU = 1;
	if(iniciaEmprestimo(emprestimo)) consE = 1;

	Home:
	switch(menu()) {
	case 1:
		UTENTE:
		switch(submenuUtente()) {
		case 1:
			if(registraU(utente))
				consU = 1;
			goto UTENTE;
			break;
		case 2:
			if(consU) {
				if(pesquisaU(utente)) goto UTENTE;
				else printf("\n\t\t\tOcorreu algum erro!");
			} else
				printf("\n\n\t\t\tSem algum registo de utente!\a");
			espera(0, 0, .3);
			goto UTENTE;
			break;
		case 3:
			if(consU) {
				if(atualizaU(utente)) goto UTENTE;
				else printf("\n\t\t\tOcorreu algum erro!");
			} else
				printf("\n\n\t\t\tSem algum registo de utente!\a");
			espera(0, 0, .3);
			goto UTENTE;
			break;
		case 4:
			if(consU) {
				auxU = eliminaU(utente);
				if(auxU == 1) goto UTENTE;
				else if(auxU == -1) consU = 0;
				else printf("\n\t\t\tOcorreu algum erro!");
			} else
				printf("\n\n\t\t\tSem algum registo de utente!\a");
			espera(0, 0, .3);
			goto UTENTE;
			break;
		case 5:
			if(consU) {
				if(mostraU(utente)) goto UTENTE;
				else printf("\n\t\t\tOcorreu algum erro!");
			} else
				printf("\n\n\t\t\tSem algum registo de utente!\a");
			espera(0, 0, .3);
			goto UTENTE;
			break;
		case 0:
			goto EXIT;
		default:
			goto Home;
			break;
		}
		break;
	case 2:
		LIVRO:
		switch(submenuLivro()) {
		case 1:
			if(registraL(livro))
				consL = 1;
			goto LIVRO;
			break;
		case 2:
			if(consL) {
				if(pesquisaL(livro)) goto LIVRO;
				else printf("\n\t\t\tOcorreu algum erro!");
			} else
				printf("\n\n\t\t\tSem algum registo de livro!\a");
			espera(0, 0, .3);
			goto LIVRO;
			break;
		case 3:
			if(consL) {
				if(atualizaL(livro)) goto LIVRO;
				else printf("\n\t\t\tOcorreu algum erro!");
			} else
				printf("\n\n\t\t\tSem algum registo de livro!\a");
			espera(0, 0, .3);
			goto LIVRO;
			break;
		case 4:
			if(consL) {
				auxL = eliminaL(livro);
				if(auxL == 1) goto LIVRO;
				else if(auxL == -1) consL = 0;
				else printf("\n\t\t\tOcorreu algum erro!");
			} else
				printf("\n\n\t\t\tSem algum registo de livro!\a");
			espera(0, 0, .3);
			goto LIVRO;
			break;
		case 5:
			if(consL) {
				if(mostraL(livro)) goto LIVRO;
				else printf("\n\t\t\tOcorreu algum erro!");
			} else
				printf("\n\n\t\t\tSem algum registo de livro!\a");
			espera(0, 0, .3);
			goto LIVRO;
			break;
		case 0:
			goto EXIT;
		default:
			goto Home;
			break;
		}

		break;
	case 3:
		EMPRESTIMO:
		switch(submenuEmp()) {
		case 1:
			if(consU * consL) {
				if(registraE(emprestimo, utente, livro))
					consE = 1;
				else printf("\n\t\t\tOcorreu algum erro!");
			}

			if(!consU) {
				printf("\n\n\t\t\tSem algum registo de utente!\a");
				espera(0, 0, .3);
			}
			if(!consL) {
				printf("\n\n\t\t\tSem algum registo de livro!\a");
				espera(0, 0, .3);
			}
			goto EMPRESTIMO;
			break;
		case 2:
			if(consE * consU) {
				if(pesquisaEU(emprestimo, utente)) goto EMPRESTIMO;
				else printf("\n\t\t\tOcorreu algum erro!");
			} else
				printf("\n\n\t\t\tSem algum registo de emprestimo!\a");
			espera(0, 0, .3);
			goto EMPRESTIMO;
			break;
		case 3:
			if(consE * consL) {
				if(pesquisaEL(emprestimo, livro)) goto EMPRESTIMO;
				else printf("\n\t\t\tOcorreu algum erro!");
			} else
				printf("\n\n\t\t\tSem algum registo de emprestimo!\a");
			espera(0, 0, .3);
			goto EMPRESTIMO;
			break;
		case 4:
			if(consE * consL) {
				auxE = eliminaE(emprestimo, livro);
				if(auxE == 1) goto EMPRESTIMO;
				else if(auxE == -1) consE = 0;
				else printf("\n\t\t\tOcorreu algum erro!");
			} else
				printf("\n\n\t\t\tSem algum registo de emprestimo!\a");
			espera(0, 0, .3);
			goto EMPRESTIMO;
			break;
		case 5:
			if(consE * consU) {
				if(mostraE(emprestimo, utente)) goto EMPRESTIMO;
				else printf("\n\t\t\tOcorreu algum erro!");
			} else
				printf("\n\n\t\t\tSem algum registo de emprestimo!\a");
			espera(0, 0, .3);
			goto EMPRESTIMO;
			break;
		case 0:
			goto EXIT;
		default:
			goto Home;
		}
		break;
	case 0:
		goto EXIT;
	default:
		goto Home;
		break;
	}
	EXIT:
	if(consU) salvarU(utente);
	if(consL) salvarL(livro);
	if(consE) salvarE(emprestimo);

	return 0;
}

