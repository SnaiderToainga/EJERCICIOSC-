#include <iostream>
using namespace std;

#define TAM 5

string cola[TAM];
int frente = 0;
int final = -1;

// ENQUEUE (insertar)
void enqueue(string valor) {
    if (final == TAM - 1) {
        cout << "Cola llena\n";
    } else {
        final++;
        cola[final] = valor;
        cout << "Enqueue(" << valor << ")\n";
    }
}

// DEQUEUE (eliminar)
void dequeue() {
    if (frente > final) {
        cout << "Cola vacia\n";
    } else {
        cout << "Dequeue(): " << cola[frente] << endl;
        frente++;
    }
}

// FRONT (consultar primero)
void front() {
    if (frente > final) {
        cout << "Cola vacia\n";
    } else {
        cout << "Front(): " << cola[frente] << endl;
    }
}

// Mostrar cola
void mostrar() {
    cout << "Estado de la cola:\n";
    for (int i = frente; i <= final; i++) {
        cout << cola[i] << " ";
    }
    cout << "\n----\n";
}

// MAIN
int main() {

    // Simulación de la práctica:
    enqueue("Carlos");
    enqueue("Maria");
    enqueue("Jose");
    dequeue();
    enqueue("Lucia");
    front();

    mostrar();

    return 0;
}
