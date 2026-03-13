#include <iostream>
using namespace std;

/*
CLASE BASE
Aquí aplicamos el concepto de CLASE.
La clase Vehiculo representa la información general de un vehículo.
*/
class Vehiculo {

protected:
    string marca;     // tipo de dato primitivo (cadena)
    int anio;         // tipo de dato primitivo (entero)

public:

    // Constructor para inicializar los datos
    Vehiculo(string m, int a){
        marca = m;
        anio = a;
    }

    /*
    POLIMORFISMO
    El método virtual permite que las clases hijas redefinan
    este comportamiento.
    */
    virtual void mostrarInfo(){
        cout << "Marca: " << marca << endl;
        cout << "Anio: " << anio << endl;
    }
};

/*
HERENCIA
La clase Auto hereda de la clase Vehiculo.
Esto significa que Auto reutiliza los atributos y métodos de Vehiculo.
*/
class Auto : public Vehiculo{

private:
    int puertas; 
    
public:

    // Constructor de la clase Auto
    Auto(string m, int a, int p) : Vehiculo(m,a){
        puertas = p;
    }

    /*
    POLIMORFISMO
    Se sobreescribe el método mostrarInfo()
    */
    void mostrarInfo() override{
        cout << "Tipo: Auto" << endl;
        cout << "Marca: " << marca << endl;
        cout << "Anio: " << anio << endl;
        cout << "Puertas: " << puertas << endl;
    }
};

/*
HERENCIA
La clase Moto también hereda de Vehiculo.
*/
class Moto : public Vehiculo{

private:
    int cilindrada;

public:

    Moto(string m, int a, int c) : Vehiculo(m,a){
        cilindrada = c;
    }

    // POLIMORFISMO
    void mostrarInfo() override{
        cout << "Tipo: Moto" << endl;
        cout << "Marca: " << marca << endl;
        cout << "Anio: " << anio << endl;
        cout << "Cilindrada: " << cilindrada << " cc" << endl;
    }
};

int main(){
    
    Vehiculo* vehiculos[3]; //   ARREGLO ESTÁTICO: Se declara un arreglo de tamaño fijo que almacenará vehículos.

    /*
    INSTANCIACIÓN DE OBJETOS
    Aquí se crean objetos de las clases Auto y Moto.
    */
    vehiculos[0] = new Auto("Ford", 2022, 4);
    vehiculos[1] = new Moto("Kawasaki", 2020, 998);
    vehiculos[2] = new Auto("Hyundai", 2022, 2);

    cout << "REGISTRO DE VEHICULOS\n" << endl;

    /*
    POLIMORFISMO
    Aunque el arreglo es de tipo Vehiculo,
    cada objeto ejecuta su propia versión del método mostrarInfo().
    */
    for(int i = 0; i < 3; i++){
    	cout << "\nVehiculo " << i+1 << endl;
        vehiculos[i]->mostrarInfo();
        cout << "---------------------" << endl;
    }

    return 0;
}
