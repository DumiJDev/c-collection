#ifndef _FEMP_H_
#define _FEMP_H_

short ee;

void consultaEmprestimoU(Emprestimo * , Utente * , char * );
void consultaEmprestimoL(Emprestimo * , Livro * , char * );
int registraEmprestimo(Emprestimo * , Utente * , Livro * , Data, short, short);
int eliminaEmprestimo(Emprestimo * , Livro * , short);
void listaEmprestimo(Emprestimo * , Utente * );
int iniciaEmprestimo(Emprestimo * );
void limpaEmprestimo(Emprestimo * );

#endif
