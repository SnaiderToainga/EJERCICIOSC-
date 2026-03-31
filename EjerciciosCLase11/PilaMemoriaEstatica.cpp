#include <iostream>
using namespace std;

#define TAMANIO 100

// Definicion de la estructura Pila
struct Pila {
    int tope;
    int elementosPila[TAMANIO];
};

// Funcion para insertar (Push)
void PushElemento(Pila *pila, int valorDato) {
    if (pila->tope == TAMANIO - 1) {
        cout << "La pila esta llena\n";
    } else {
        pila->tope++;
        pila->elementosPila[pila->tope] = valorDato;
    }
}

// Funcion para eliminar (Pop)
int PopElemento(Pila *pila) {
    if (pila->tope == -1) {
        cout << "La pila esta vacia\n";
        return -1;
    } else {
        int valor = pila->elementosPila[pila->tope];
        pila->tope--;
        return valor;
    }
}

// Verificar si está llena
bool LlenarPila(Pila pila) {
    return (pila.tope == TAMANIO - 1);
}

// Verificar si esta vacia
bool VaciarPila(Pila pila) {
    return (pila.tope == -1);
}

// Mostrar pila
void mostrarPila(Pila pila) {
    cout << "Contenido de la pila:\n";
    for (int i = pila.tope; i >= 0; i--) {
        cout << pila.elementosPila[i] << endl;
    }
}

// Funcion principal
int main() {
    Pila pila;
    pila.tope = -1; // Inicializar pila vacia

    // Insertar elementos
    PushElemento(&pila, 8);
    PushElemento(&pila, 4);
    PushElemento(&pila, 10);

    mostrarPila(pila);

    // Eliminar elemento
    cout << "Elemento eliminado: " << PopElemento(&pila) << endl;

    mostrarPila(pila);

    return 0;
}
