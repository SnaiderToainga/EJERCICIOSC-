#include <iostream>
using namespace std;

// Definición del nodo (estructura de la pila)
struct Pila {
    int valorDato;
    Pila* siguiente;
};

// Definimos un puntero al nodo (tope de la pila)
typedef Pila* PilaPuntero;

// Función Push (insertar)
void PushElemento(PilaPuntero *tope, int valorDato) {
    PilaPuntero nuevoDato = new Pila(); // reservar memoria

    if (nuevoDato == NULL) {
        cout << "NO EXISTE MEMORIA\n";
    } else {
        nuevoDato->valorDato = valorDato;
        nuevoDato->siguiente = *tope;
        *tope = nuevoDato;
    }
}

// Función Pop (eliminar)
int PopElemento(PilaPuntero *tope) {
    if (*tope == NULL) {
        cout << "La pila esta vacia\n";
        return -1;
    }

    PilaPuntero temporal = *tope;
    int elemento = temporal->valorDato;

    *tope = (*tope)->siguiente;
    delete temporal;

    return elemento;
}

// Mostrar pila
void mostrarPila(PilaPuntero tope) {
    cout << "Contenido de la pila:\n";
    while (tope != NULL) {
        cout << tope->valorDato << endl;
        tope = tope->siguiente;
    }
}

// Función principal
int main() {
    PilaPuntero tope = NULL; // pila vacía

    // Insertar elementos
    PushElemento(&tope, 1);
    PushElemento(&tope, 9);
    PushElemento(&tope, 8);
    PushElemento(&tope, 4);

    mostrarPila(tope);

    // Eliminar elemento
    cout << "Elemento eliminado: " << PopElemento(&tope) << endl;

    mostrarPila(tope);

    return 0;
}
