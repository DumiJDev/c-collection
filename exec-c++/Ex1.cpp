#include <iostream>
#include <locale.h>

using namespace std;

int main(int argc, char** argv)
{
	setlocale(LC_ALL, "Portuguese");
	int num;
	
	cout << "Insira um n�mero: ";
	cin >> num;
	
	if(num > 10) cout << "\n� maior do que 10" << endl;
		
	return 0;
}