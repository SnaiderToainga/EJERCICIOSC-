#include <iostream>
using namespace std;

int main(){
	
	int notas[5] = {8, 9, 7, 10, 6};
	int suma = 0;
	float promedio;
	
	for (int i = 0; i < 5; i++){
		
		cout << "Nota " << i+1 << ": " << notas[i] << endl;
		suma = suma + notas[i];
	}
	
	promedio = suma / 5.0;
	
	cout << "Promedio: " << promedio << endl;

	return 0;
}
