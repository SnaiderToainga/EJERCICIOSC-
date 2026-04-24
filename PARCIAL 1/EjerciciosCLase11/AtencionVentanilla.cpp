#include <iostream>
#include <queue>
using namespace std;

// Función para mostrar la cola
void mostrarCola(queue<string> q) {
    cout << "Cola actual: ";
    if (q.empty()) {
        cout << "VACIA";
    } else {
        while (!q.empty()) {
            cout << q.front() << " ";
            q.pop();
        }
    }
    cout << endl;
}

// Procedimiento: llega un cliente
void clienteLlega(queue<string> &cola, string nombre) {
    cola.push(nombre); // ENQUEUE
    cout << nombre << " en fila." << endl;
    mostrarCola(cola);
}

// Procedimiento: atender cliente
void atenderSiguiente(queue<string> &cola) {
    if (cola.empty()) {
        cout << "No hay clientes." << endl;
    } else {
        string cliente = cola.front(); // FRONT
        cola.pop(); // DEQUEUE
        cout << "Atendiendo a: " << cliente << endl;
        mostrarCola(cola);
    }
}

int main() {
    queue<string> colaClientes;

    cout << "=== Simulacion Ventanilla ===\n\n";

    // Simulación como en el ejemplo
    clienteLlega(colaClientes, "Ana");
    clienteLlega(colaClientes, "Luis");
    clienteLlega(colaClientes, "Pedro");

    cout << endl;

    atenderSiguiente(colaClientes);
    atenderSiguiente(colaClientes);

    cout << endl;

    clienteLlega(colaClientes, "Maria");

    cout << endl;

    atenderSiguiente(colaClientes);
    atenderSiguiente(colaClientes);
    atenderSiguiente(colaClientes); // caso sin clientes

    return 0;
}
