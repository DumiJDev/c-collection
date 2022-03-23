#include <iostream>
#include <locale.h>

using namespace std;

int main(int argc, char** argv)
{
	setlocale(LC_ALL, "Portuguese");
	int A, B;
	
	cout << "Insira dois números" << "\n\n\tA: ";
	cin >> A;
	
	cout << "\tB: ";
	cin >> B;
	
	if(A % B == 0) cout << "\nA é divisível por B" << endl;
		
	return 0;
}