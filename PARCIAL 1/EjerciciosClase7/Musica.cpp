#include <iostream>
using namespace std;

struct Nodo {
    string cancion;
    Nodo* next;
    Nodo* prev;
};

// Función para crear un nodo
Nodo* crearNodo(string nombre) {
    Nodo* nuevo = new Nodo();
    nuevo->cancion = nombre;
    nuevo->next = nuevo->prev = nullptr;
    return nuevo;
}

// Conectar nodos de forma circular doble
void conectar(Nodo* n1, Nodo* n2) {
    n1->next = n2;
    n2->prev = n1;
}

int main() {
    // Crear nodos
    Nodo* c1 = crearNodo("Cancion 1");
    Nodo* c2 = crearNodo("Cancion 2");
    Nodo* c3 = crearNodo("Cancion 3");
    Nodo* c4 = crearNodo("Cancion 4");

    // Conectar en forma doble
    conectar(c1, c2);
    conectar(c2, c3);
    conectar(c3, c4);

    // Hacerla circular
    c4->next = c1;
    c1->prev = c4;

    // Recorrer hacia adelante
    Nodo* actual = c1;
    cout << "Avanzando:" << endl;
    for(int i = 0; i < 6; i++) { // más vueltas para ver circularidad
        cout << actual->cancion << endl;
        actual = actual->next;
    }

    // Recorrer hacia atrás
    cout << "\nRetrocediendo:" << endl;
    for(int i = 0; i < 6; i++) {
        actual = actual->prev;
        cout << actual->cancion << endl;
    }

    return 0;
}
