#include <iostream>
#include <locale.h>

using namespace std;

int main(int argc, char** argv)
{
	setlocale(LC_ALL, "Portuguese");
	int A, B, aux;
	
	cout << "Insira dois números" << "\n\n\tA: ";
	cin >> A;
	
	cout << "\tB: ";
	cin >> B;
	
	if(A > B) {
		aux = A;
		A = B;
		B = aux;
	}
	
	cout << "Resultado: "  << A << " " << B << endl;
		
	return 0;
}