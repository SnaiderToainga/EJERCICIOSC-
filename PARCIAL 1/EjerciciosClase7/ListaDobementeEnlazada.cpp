#include <iostream>
using namespace std;

// Definición del nodo
struct Nodo {
    int dato;
    Nodo* siguiente;
    Nodo* anterior;
};

// Insertar al inicio
void insertarInicio(Nodo*& lista, int valor) {
    Nodo* nuevo = new Nodo();
    nuevo->dato = valor;

    nuevo->siguiente = lista;
    nuevo->anterior = NULL;

    if (lista != NULL) {
        lista->anterior = nuevo;
    }

    lista = nuevo;
}

// Buscar elemento
void buscar(Nodo* lista, int valor) {
    Nodo* actual = lista;
    int posicion = 0;
    bool encontrado = false;

    while (actual != NULL) {
        if (actual->dato == valor) {
            cout << "Elemento encontrado en la posicion: " << posicion << endl;
            encontrado = true;
            break;
        }
        actual = actual->siguiente;
        posicion++;
    }

    if (!encontrado) {
        cout << "Elemento no encontrado\n";
    }
}

// Mostrar lista
void mostrar(Nodo* lista) {
    Nodo* actual = lista;

    while (actual != NULL) {
        cout << actual->dato << " <-> ";
        actual = actual->siguiente;
    }
    cout << "NULL\n";
}

int main() {
    Nodo* lista = NULL;
    int opcion, valor;
    char seleccion = 's';

    do {
    	
        cout << "\n1. Insertar elemento al inicio\n";
        cout << "2. Buscar elemento\n";
        cout << "3. Mostrar lista\n";
        cout << "4. Salir\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                seleccion = 's';
                while (seleccion == 's' || seleccion == 'S') {
                    cout << "Ingrese el valor: ";
                    cin >> valor;
                    insertarInicio(lista, valor);
                    cout << "Desea seguir ingresando (s/n): ";
                    cin >> seleccion;
                }
                break;

            case 2:
                cout << "Ingrese valor a buscar: ";
                cin >> valor;
                buscar(lista, valor);
                break;

            case 3:
                cout << "Lista:\n";
                mostrar(lista);
                break;

            case 4:
                cout << "Saliendo...\n";
                break;

            default:
                cout << "Opcion invalida\n";
        }

    } while (opcion != 4);

    return 0;
}
