#include <iostream>
#include <locale.h>

using namespace std;

int main(int argc, char** argv)
{
	setlocale(LC_ALL, "Portuguese");
	int num;
	
	cout << "Insira um número: ";
	cin >> num;
	
	if(num > 10) cout << "\nÉ maior do que 10" << endl;
		
	return 0;
}