#include <iostream>
#include <locale.h>

using namespace std;

int main(int argc, char** argv)
{
	setlocale(LC_ALL, "Portuguese");
	int num;
	
	cout << "Insira um n�mero: ";
	cin >> num;
	
	if(num > 0) cout << "\n� positivo" << endl;
	else if(num < 0) cout << "\n� negativo" << endl;
    else cout << "\n� zero" << endl;
		
	return 0;
}