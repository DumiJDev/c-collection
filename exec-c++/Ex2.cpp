#include <iostream>
#include <locale.h>

using namespace std;

int main(int argc, char** argv)
{
	setlocale(LC_ALL, "Portuguese");
	int num1, num2;
	
	cout << "Insira dois n�meros" << "\n\n\tnum1: ";
	cin >> num1;
	cout << "\tnum2: ";
	cin >> num2;
	
	if(num1 == num2) cout << "\nOs n�meros digitados s�o iguais" << endl;
	else cout << "\nOs n�meros digitados s�o diferentes" << endl;
		
	return 0;
}