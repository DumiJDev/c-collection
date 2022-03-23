#include <iostream>
#include <locale.h>

using namespace std;

int main(int argc, char** argv)
{
	setlocale(LC_ALL, "Portuguese");
	int num1, num2;
	
	cout << "Insira dois números" << "\n\n\tnum1: ";
	cin >> num1;
	cout << "\tnum2: ";
	cin >> num2;
	
	if(num1 == num2) cout << "\nOs números digitados são iguais" << endl;
	else cout << "\nOs números digitados são diferentes" << endl;
		
	return 0;
}