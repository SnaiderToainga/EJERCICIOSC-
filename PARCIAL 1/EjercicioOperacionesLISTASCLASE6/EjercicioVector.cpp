#include <iostream>
#include <vector>
using namespace std;

class Evento {

private:
    vector<string> asistentes;

public:

    // Insertar asistente
    void insertar(string nombre) {
        asistentes.push_back(nombre);
        cout << "Asistente agregado correctamente\n";
    }

    // Eliminar asistente
    void eliminar(string nombre) {

        for(int i = 0; i < asistentes.size(); i++) {

            if(asistentes[i] == nombre) {

                asistentes.erase(asistentes.begin() + i);

                cout << "Asistente eliminado\n";
                return;
            }
        }

        cout << "Asistente no encontrado\n";
    }

    // Buscar asistente
    void buscar(string nombre) {

        for(int i = 0; i < asistentes.size(); i++) {

            if(asistentes[i] == nombre) {

                cout << "Asistente encontrado en posicion: " << i << endl;
                return;
            }
        }
        cout << "Asistente no encontrado\n";
    }

    // Mostrar asistentes
    void mostrar() {

        if(asistentes.empty()) {

            cout << "No hay asistentes registrados\n";
            return;
        }

        cout << "\nLista de asistentes:\n";

        for(int i = 0; i < asistentes.size(); i++) {

            cout << i+1 << ". " << asistentes[i] << endl;
        }
    }
    // Tamaño de la lista
    void size() {

        cout << "Numero de asistentes: " << asistentes.size() << endl;
    }
};

int main() {

    Evento evento;
    int opcion;
    string nombre;

    do {
        cout << "\n===== SISTEMA DE EVENTOS =====\n";
        cout << "1. Agregar asistente\n";
        cout << "2. Eliminar asistente\n";
        cout << "3. Buscar asistente\n";
        cout << "4. Mostrar asistentes\n";
        cout << "5. Numero de asistentes\n";
        cout << "6. Salir\n";

        cout << "Seleccione una opcion: ";
        cin >> opcion;
        cin.ignore(); 

        switch(opcion) {
        case 1:
            cout << "Ingrese nombre del asistente: ";
            getline(cin, nombre);

            evento.insertar(nombre);
            break;

        case 2:
            cout << "Ingrese nombre del asistente a eliminar: ";
            getline(cin, nombre);

            evento.eliminar(nombre);
            break;

        case 3:
            cout << "Ingrese nombre a buscar: ";
            getline(cin, nombre);

            evento.buscar(nombre);

            break;

        case 4:
            evento.mostrar();
            break;

        case 5:
            evento.size();
            break;

        case 6:
            cout << "Saliendo del sistema...\n";
            break;

        default:
            cout << "Opcion invalida\n";
        }

    } while(opcion != 6);
    return 0;
}

