#include <iostream>
#include <locale.h>

using namespace std;

int main(int argc, char** argv)
{
	setlocale(LC_ALL, "Portuguese");
	//Data de nascimento
	int diaN, mesN, anoN;
	
	//Data atual
	int diaA, mesA, anoA;
	
	cout << "Insira sobre o teu nascimento o:" << "\n\n\tDia: ";
	cin >> diaN;
	
	cout << "\tM�s: ";
	cin >> mesN;
	
	cout << "\tAno: ";
	cin >> anoN;
	
	cout << "Insira sobre o teu nascimento o:" << "\n\n\tDia: ";
	cin >> diaA;
	
	cout << "\tM�s: ";
	cin >> mesA;
	
	cout << "\tAno: ";
	cin >> anoA;
	
	
	
	//cout << "\n\tDigitaste " << nPar << " n�mero(s) par(es)" << endl;
		
	return 0;
}