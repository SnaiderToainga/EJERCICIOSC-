#include <iostream>
using namespace std;

struct Nodo {
    int dato;
    Nodo* siguiente;
};

// Crear lista circular
Nodo* crearLista(int n) {
    Nodo *inicio = NULL, *temp = NULL, *nuevo;

    for (int i = 1; i <= n; i++) {
        nuevo = new Nodo();
        nuevo->dato = i;

        if (inicio == NULL) {
            inicio = nuevo;
            inicio->siguiente = inicio;
            temp = inicio;
        } else {
            temp->siguiente = nuevo;
            nuevo->siguiente = inicio;
            temp = nuevo;
        }
    }
    return inicio;
}

// Problema de Josephus
void josephus(int n, int k) {
    Nodo* inicio = crearLista(n);
    Nodo* actual = inicio;
    Nodo* anterior = NULL;

    cout << "Orden de eliminacion: ";

    while (actual->siguiente != actual) {
        // Avanzar k-1 veces
        for (int i = 1; i < k; i++) {
            anterior = actual;
            actual = actual->siguiente;
        }

        // Eliminar nodo
        cout << actual->dato << " ";

        anterior->siguiente = actual->siguiente;
        delete actual;

        actual = anterior->siguiente;
    }

    cout << "\nSuperviviente: " << actual->dato << endl;
}

int main() {
    cout << "Caso 1: n = 5, k = 2\n";
    josephus(5, 2);

    cout << "\nCaso 2: n = 7, k = 3\n";
    josephus(7, 3);

    return 0;
}
