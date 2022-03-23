#ifndef _SUBMENUEMP_H_
#define _SUBMENUEMP_H_

int submenuEmp();
int registraE(Emprestimo * , Utente * , Livro * );
int pesquisaEL(Emprestimo * , Livro * );
int pesquisaEU(Emprestimo * , Utente * );
int eliminaE(Emprestimo * , Livro * );
int mostraE(Emprestimo * , Utente * );

#endif
