#include <iostream>
#include <queue>
#include <list>
#include <stack>
using namespace std;

// Modelo de datos
struct Solicitud {
    string cedula;
    string nombre;
    string motivo;
};

// Función para atender solicitud
void atenderSolicitud(queue<Solicitud>& pendientes,
                      list<Solicitud>& atendidos,
                      stack<Solicitud>& recientes) {

    if (pendientes.empty()) {
        cout << "No hay solicitudes pendientes\n";
        return;
    }

    Solicitud actual = pendientes.front();
    pendientes.pop();

    atendidos.push_back(actual);
    recientes.push(actual);

    cout << "Atendiendo a: " << actual.nombre << endl;
}

// Mostrar pendientes
void mostrarPendientes(queue<Solicitud> pendientes) {
    if (pendientes.empty()) {
        cout << "No hay pendientes\n";
        return;
    }

    cout << "Pendientes:\n";
    while (!pendientes.empty()) {
        cout << pendientes.front().nombre << endl;
        pendientes.pop();
    }
}

// Mostrar atendidos
void mostrarAtendidos(list<Solicitud> atendidos) {
    cout << "Historial de atendidos:\n";
    for (auto s : atendidos) {
        cout << s.nombre << endl;
    }
}

// Mostrar reciente
void mostrarReciente(stack<Solicitud> recientes) {
    if (recientes.empty()) {
        cout << "No hay recientes\n";
    } else {
        cout << "Ultimo atendido: " << recientes.top().nombre << endl;
    }
}

int main() {
    queue<Solicitud> pendientes;
    list<Solicitud> atendidos;
    stack<Solicitud> recientes;

    int op;
    Solicitud s;

    do {
        cout << "\n--- MENU ---\n";
        cout << "1. Registrar solicitud\n";
        cout << "2. Atender solicitud\n";
        cout << "3. Ver pendientes\n";
        cout << "4. Ver atendidos\n";
        cout << "5. Ver ultimo atendido\n";
        cout << "0. Salir\n";
        cin >> op;

        switch(op) {
            case 1:
                cout << "Cedula: ";
                cin >> s.cedula;
                cout << "Nombre: ";
                cin >> s.nombre;
                cout << "Motivo: ";
                cin >> s.motivo;

                pendientes.push(s);
                break;

            case 2:
                atenderSolicitud(pendientes, atendidos, recientes);
                break;

            case 3:
                mostrarPendientes(pendientes);
                break;

            case 4:
                mostrarAtendidos(atendidos);
                break;

            case 5:
                mostrarReciente(recientes);
                break;
        }

    } while(op != 0);

    return 0;
}