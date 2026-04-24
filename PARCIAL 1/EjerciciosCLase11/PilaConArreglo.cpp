#include <iostream>
using namespace std;

#define TAM 5

int pila[TAM];
int tope = -1;

// PUSH
void push(int valor) {
    if (tope == TAM - 1) {
        cout << "Pila llena\n";
    } else {
        tope++;
        pila[tope] = valor;
        cout << "Push(" << valor << ")\n";
    }
}

// POP
void pop() {
    if (tope == -1) {
        cout << "Pila vacia\n";
    } else {
        cout << "Pop(): " << pila[tope] << endl;
        tope--;
    }
}

// TOP
void top() {
    if (tope == -1) {
        cout << "Pila vacia\n";
    } else {
        cout << "Top(): " << pila[tope] << endl;
    }
}

// Mostrar pila
void mostrar() {
    cout << "Estado de la pila:\n";
    for (int i = tope; i >= 0; i--) {
        cout << pila[i] << endl;
    }
    cout << "----\n";
}

int main() {

    // Simulación de la práctica:
    push(4);
    push(9);
    push(1);
    pop();
    push(7);
    top();

    mostrar();

    return 0;
}
