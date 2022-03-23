#include <iostream>
#include <locale.h>

using namespace std;

int main(int argc, char** argv)
{
	setlocale(LC_ALL, "Portuguese");
	int num;
	
	cout << "Insira um número: ";
	cin >> num;
	
	if(num > 0) cout << "\nÉ positivo" << endl;
	else if(num < 0) cout << "\nÉ negativo" << endl;
    else cout << "\nÉ zero" << endl;
		
	return 0;
}