#include <iostream>
#include <locale.h>

using namespace std;

int main(int argc, char** argv)
{
	setlocale(LC_ALL, "Portuguese");
	int num;
	
	cout << "Insira um número: ";
	cin >> num;
	
	if(num % 2 == 0) cout << "O número digitados é par" << endl;
	else cout << "O número digitados é ímpar" << endl;
		
	return 0;
}