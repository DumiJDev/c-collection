#ifndef DADOS_H_
#define DADOS_H_


typedef struct {
	int dia;
	int mes;
	int ano;
} Data;

typedef struct {
	char titulo[50];
	char ISBN[20];
	char descricao[50];
	int ano;
	char autor[30];
	int qtd;
} Livro;

typedef struct {
	char nome[30];
	char morada[50];
	char categoria;
	char genero;
	Data nascimento;
} Utente;

typedef struct {
	int num_empre;
	char nomeUtente[30];
	char tituloLivro[50];
	Data data;
} Emprestimo;

#endif
