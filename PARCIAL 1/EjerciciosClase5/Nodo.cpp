#include <iostream>
using namespace std;

class Nodo {
public:
	int dato;
	Nodo * siguiente;
	
	Nodo(int valor){
		dato = valor;
		siguiente = NULL ;
		
	}
};

int main() {
	
	Nodo*primero = new Nodo(10);
	Nodo*segundo = new Nodo(20);
	Nodo*tercero = new Nodo(30);
	
	primero -> siguiente = segundo;
	segundo -> siguiente = tercero;
	
	cout << primero ->dato <<endl;
	cout << primero ->siguiente-> dato<< endl;
	cout << segundo ->siguiente-> dato<< endl;
	
	return 0;
}

