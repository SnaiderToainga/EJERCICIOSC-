#include <iostream>
using namespace std;

// Definición del nodo
struct Nodo {
    int dato;
    Nodo* siguiente;
};

int main() {
    // Nodo cabecera (lista vacía)
    Nodo* cabeza = NULL;
    Nodo* nuevo;
    int contador, numElemento;
    
    cout << "Ingrese el numero de elementos de la lista: ";
    cin >> numElemento;

    // Ingreso de elementos
    for(contador = 0; contador < numElemento; contador++) {
        cout << "Elemento " << contador + 1 << ": ";
        
        // Crear nuevo nodo
        nuevo = new Nodo();
        cin >> nuevo->dato;

        // Insertar al inicio
        nuevo->siguiente = cabeza;
        cabeza = nuevo;
    }

    // Mostrar lista
    cout << "\nLista de elementos:\n";
    Nodo* actual = cabeza;

    while(actual != NULL) {
        cout << actual->dato << endl;
        actual = actual->siguiente;
    }

    return 0;
}
