#include <iostream>
#include <locale.h>

using namespace std;

int main(int argc, char** argv)
{
	setlocale(LC_ALL, "Portuguese");
	double A, B, C, media;
	
	cout << "Insira dois números\n\n";
	cout << "\tNota 1: ";
	cin >> A;
	
	cout << "\tNota 2: ";
	cin >> B;
	
	cout << "\tNota 3: ";
	cin >> C;	
	
	A *= 2;
	B *= 3;
	C *= 5;
	
	media = (A + B + C) / 10;
	
	cout << "Media: "  << media << endl;
		
	return 0;
}