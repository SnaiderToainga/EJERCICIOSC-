#include <iostream>
using namespace std;

class Estudiante {
public:
	string nombre;
	int edad;
	
	void mostrarDatos(){
		cout << "Nombre: " << nombre << endl;
		cout << "Edad: " << edad << endl;
	}
};

int main() {
	
	Estudiante e1;
	e1.nombre = "Snaider";
	e1.edad = 20;
	e1.mostrarDatos()
	
	return 0;
}

