#include <iostream>

using namespace std;

// Estructura base en C++
struct Nodo {
    int decision; 
    Nodo *izq, *der;
    bool esHoja;
    
    // Constructor auxiliar para facilitar la creación del árbol en el main
    Nodo(int d, bool hoja = false) {
        decision = d;
        izq = nullptr;
        der = nullptr;
        esHoja = hoja;
    }
};

void aplicarPoda(Nodo* &raiz) {
    // Caso base: si el nodo es nulo o ya es una hoja, no hay nada que podar aquí
    if (raiz == nullptr || raiz->esHoja) return;

    // 1. Recursión para llegar a las ramas finales (Postorden)
    aplicarPoda(raiz->izq);
    aplicarPoda(raiz->der);

    // 2. Lógica de Poda: Si ambos hijos son hojas y tienen la misma decisión
    // Nota: Se valida que izq y der no sean nulos para evitar errores de segmentación
    if (raiz->izq != nullptr && raiz->der != nullptr && 
        raiz->izq->esHoja && raiz->der->esHoja && 
        raiz->izq->decision == raiz->der->decision) {
        
        int valorFinal = raiz->izq->decision;

        // Liberar memoria de los hijos
        delete raiz->izq;
        delete raiz->der;
        
        // Actualizar el nodo padre
        raiz->izq = raiz->der = nullptr;
        raiz->esHoja = true;
        raiz->decision = valorFinal;
        
        cout << "Nodo podado y simplificado. Nueva decision del padre: " << raiz->decision << endl;
    }
}

// Función auxiliar para imprimir el árbol y verificar la poda
void imprimirArbol(Nodo* raiz, string prefijo = "") {
    if (raiz == nullptr) return;
    cout << prefijo << "- Decision: " << raiz->decision 
         << " (Es hoja: " << (raiz->esHoja ? "Si" : "No") << ")" << endl;
    imprimirArbol(raiz->izq, prefijo + "  L");
    imprimirArbol(raiz->der, prefijo + "  R");
}

int main() {
    cout << "--- ESTADO INICIAL DEL ARBOL ---" << endl;
    // Creamos un nodo padre que NO es hoja
    Nodo* raiz = new Nodo(0, false); 
    
    // Le asignamos dos hijos que SI son hojas y tienen la misma decisión (ej. 5)
    raiz->izq = new Nodo(5, true);
    raiz->der = new Nodo(5, true);
    
    imprimirArbol(raiz);

    cout << "\n--- APLICANDO PODA ---" << endl;
    aplicarPoda(raiz);

    cout << "\n--- ESTADO FINAL DEL ARBOL ---" << endl;
    imprimirArbol(raiz);

    // Limpieza final de memoria
    if(raiz != nullptr) delete raiz;

    return 0;
}