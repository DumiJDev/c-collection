#include <iostream>
#include <locale.h>

using namespace std;

int main(int argc, char** argv)
{
	setlocale(LC_ALL, "Portuguese");
	int num;
	
	cout << "Insira um n�mero: ";
	cin >> num;
	
	if(num % 2 == 0) cout << "O n�mero digitados � par" << endl;
	else cout << "O n�mero digitados � �mpar" << endl;
		
	return 0;
}