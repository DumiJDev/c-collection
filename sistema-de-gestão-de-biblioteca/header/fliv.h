#ifndef _FLIV_H_
#define _FLIV_H_

int bb, bbr;

void consultaLivro(Livro * , char * );
int registraLivro(Livro * , Livro);
void listaLivro(Livro * );
int atualizaLivro(Livro * , Livro, int);
int eliminaLivro(Livro * , int);
int iniciaLivro(Livro * );

#endif
