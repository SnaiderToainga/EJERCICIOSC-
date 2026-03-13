#include <iostream>
using namespace std;

class Vehiculo { //Clase base
public:
    // Atributos
    string marca;
    string modelo;

    // Metodo para mostrar informacion del vehiculo
    void mostrarInfo(){
        cout << "Marca: " << marca << endl;
        cout << "Modelo: " << modelo << endl;
    }

    virtual void encender(){
        cout << "El vehiculo se esta encendiendo..." << endl;
    }
};

class Auto : public Vehiculo { //Clase hija 1
public:
    // Atributo
    int numeroPuertas;

    // Metodo para mostrar informacion del auto
    void mostrarPuertas(){
        cout << "Numero de puertas: " << numeroPuertas << endl;
    }

    // polimorfismo
    void encender() override{
        cout << "El auto se enciende con llave " << endl;
    }
};

class Moto : public Vehiculo { //Clase hija 2
public:
    // Atributo
    int cilindraje;

    // Metodo para mostrar informacion de la moto
    void mostrarCilindraje(){
        cout << "Cilindraje: " << cilindraje << " cc" << endl;
    }

    // polimorfismo
    void encender() override{
        cout << "La moto se enciende con patada." << endl;
    }
};

int main(){
    // Crear objetos
    Auto a1;
    Moto m1;

    // Asignar valores al auto y moto
    a1.marca = "Toyota";
    a1.modelo = "Hilux";
    a1.numeroPuertas = 4;

    m1.marca = "Yamaha";
    m1.modelo = "R15";
    m1.cilindraje = 150;

    // Puntero de tipo Vehiculo (para polimorfismo)
    Vehiculo* v;

    cout << "---- AUTO ----" << endl;

    v = &a1;          // el puntero apunta al objeto Auto
    v->mostrarInfo(); // metodo heredado
    a1.mostrarPuertas();
    v->encender();    // ejecuta el metodo de Auto

    cout << endl;

    cout << "---- MOTO ----" << endl;

    v = &m1;          // ahora apunta al objeto Moto
    v->mostrarInfo(); // metodo heredado
    m1.mostrarCilindraje();
    v->encender();    // ejecuta el metodo de Moto

    return 0;
}
