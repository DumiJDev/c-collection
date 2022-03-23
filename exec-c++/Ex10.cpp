#include <iostream>
#include <string.h>
#include <locale.h>

using namespace std;

int main(int argc, char** argv)
{
	setlocale(LC_ALL, "Portuguese");
	char nome[15];
	
	cout << "Digite o seu nome: ";
	cin >> nome;
	
	if(!strcmp(nome, "Leonardo")) cout << "\n\n\tNOME CORRETO" << endl;
	else cout << "\n\n\tNOME INCORRETO" << endl;
		
	return 0;
}