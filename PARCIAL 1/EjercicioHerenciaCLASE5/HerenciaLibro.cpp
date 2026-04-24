#include <iostream> 

using namespace std; 

 

// Crear la clase libro 

class Libro { 

public: 

//Atributos de la clase 

 string titulo; 

 string autor; 

 int anio; 

 

//Creamos el metodo  

 void mostrarDatos(){ 

cout << "Titulo: " << titulo << endl; 

cout << "Autor: " << autor << endl; 

cout << "Anio: " << anio << endl; 

 

} 

}; 

 

int main() { 

 

//Creamos el objeto para la clase Libro 

Libro l1; 

 

 l1.titulo = "Don quijote de la mancha"; 

 l1.autor = "Miguel de Cervantes"; 

 l1.anio = 1605; 

 

//Llamar al metodo 

 l1.mostrarDatos(); 

 

 return 0; 

} 

 
