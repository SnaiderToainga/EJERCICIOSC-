#include <iostream>
#include <queue>
using namespace std;

// Estructura del nodo
struct Nodo {
    int dato;
    Nodo* izquierdo;
    Nodo* derecho;

    Nodo(int valor) {
        dato = valor;
        izquierdo = NULL;
        derecho = NULL;
    }
};

// Función BFS (recorrido por niveles)
void recorridoBFS(Nodo* raiz) {
    if (raiz == NULL) return;

    queue<Nodo*> cola;
    cola.push(raiz);

    while (!cola.empty()) {
        Nodo* actual = cola.front();
        cola.pop();

        cout << actual->dato << " ";

        if (actual->izquierdo != NULL)
            cola.push(actual->izquierdo);

        if (actual->derecho != NULL)
            cola.push(actual->derecho);
    }
}

// Programa principal
int main() {
    // Crear el árbol manualmente
    Nodo* raiz = new Nodo(50);
    raiz->izquierdo = new Nodo(30);
    raiz->derecho = new Nodo(70);

    raiz->izquierdo->izquierdo = new Nodo(20);
    raiz->izquierdo->derecho = new Nodo(40);

    raiz->derecho->izquierdo = new Nodo(60);
    raiz->derecho->derecho = new Nodo(80);

    cout << "Recorrido BFS: ";
    recorridoBFS(raiz);

    return 0;
}