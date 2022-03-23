#ifndef _FUTEN_H_
#define _FUTEN_H_

short uu;

void consultaUtente(Utente * , char * );
int registraUtente(Utente * , Utente);
int atualizaUtente(Utente * , Utente, short);
int eliminaUtente(Utente * , short);
void listaUtente(Utente * );
int iniciaUtente(Utente * );
void limpaUtente(Utente * );

#endif
