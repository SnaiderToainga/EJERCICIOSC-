#include <iostream>
using namespace std;

class Persona {
public:
	string nombre;   // atributo
	
	void saludar() {   // metodo
		cout << "Hola, soy " << nombre << endl;
	}
};

class Estudiante : public Persona {   // herencia
 
public:
	string carrera;   // atributo
	
	void mostrarCarrera(){   // metodo
		cout << "Carrera: " << carrera << endl;
	}
};

int main() {
	
	Estudiante e1;   // objeto
	
	e1.nombre = "Luis";
	e1.carrera = "Software";
	
	e1.saludar();
	e1.mostrarCarrera();
		
	return 0;	
	
}

