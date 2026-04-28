#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

// Estructura de los datos del empleado
struct Empleado {
    int codigo;
    string nombre;
    string cargo;
};

// Estructura del Nodo AVL (incluye la "altura")
struct Nodo {
    Empleado dato;
    Nodo* izquierdo;
    Nodo* derecho;
    int altura;

    Nodo(Empleado emp) {
        dato = emp;
        izquierdo = nullptr;
        derecho = nullptr;
        altura = 1; 
    }
};

class ArbolAVL {
private:
    Nodo* raiz;

    // Función auxiliar para obtener la altura de un nodo
    int altura(Nodo* N) {
        if (N == nullptr) return 0;
        return N->altura;
    }

    // Función auxiliar para obtener el factor de balance
    int obtenerBalance(Nodo* N) {
        if (N == nullptr) return 0;
        return altura(N->izquierdo) - altura(N->derecho);
    }

    // Rotación hacia la derecha
    Nodo* rotacionDerecha(Nodo* y) {
        Nodo* x = y->izquierdo;
        Nodo* T2 = x->derecho;

        x->derecho = y;
        y->izquierdo = T2;

        y->altura = max(altura(y->izquierdo), altura(y->derecho)) + 1;
        x->altura = max(altura(x->izquierdo), altura(x->derecho)) + 1;

        return x; 
    }

    // Rotación hacia la izquierda
    Nodo* rotacionIzquierda(Nodo* x) {
        Nodo* y = x->derecho;
        Nodo* T2 = y->izquierdo;

        y->izquierdo = x;
        x->derecho = T2;

        x->altura = max(altura(x->izquierdo), altura(x->derecho)) + 1;
        y->altura = max(altura(y->izquierdo), altura(y->derecho)) + 1;

        return y; 
    }

    // Insertar un nodo y balancear
    Nodo* insertar(Nodo* nodo, Empleado emp) {
        if (nodo == nullptr)
            return new Nodo(emp);

        if (emp.codigo < nodo->dato.codigo)
            nodo->izquierdo = insertar(nodo->izquierdo, emp);
        else if (emp.codigo > nodo->dato.codigo)
            nodo->derecho = insertar(nodo->derecho, emp);
        else {
            cout << "El codigo ya existe.\n";
            return nodo; 
        }

        nodo->altura = 1 + max(altura(nodo->izquierdo), altura(nodo->derecho));
        int balance = obtenerBalance(nodo);

        // Casos de rotación
        if (balance > 1 && emp.codigo < nodo->izquierdo->dato.codigo)
            return rotacionDerecha(nodo);
        if (balance < -1 && emp.codigo > nodo->derecho->dato.codigo)
            return rotacionIzquierda(nodo);
        if (balance > 1 && emp.codigo > nodo->izquierdo->dato.codigo) {
            nodo->izquierdo = rotacionIzquierda(nodo->izquierdo);
            return rotacionDerecha(nodo);
        }
        if (balance < -1 && emp.codigo < nodo->derecho->dato.codigo) {
            nodo->derecho = rotacionDerecha(nodo->derecho);
            return rotacionIzquierda(nodo);
        }

        return nodo; 
    }

    // Encontrar el nodo con el valor mínimo
    Nodo* nodoMinimoValor(Nodo* nodo) {
        Nodo* actual = nodo;
        while (actual->izquierdo != nullptr)
            actual = actual->izquierdo;
        return actual;
    }

    // Eliminar un nodo y balancear
    Nodo* eliminar(Nodo* raiz, int codigo) {
        if (raiz == nullptr) return raiz;

        if (codigo < raiz->dato.codigo)
            raiz->izquierdo = eliminar(raiz->izquierdo, codigo);
        else if (codigo > raiz->dato.codigo)
            raiz->derecho = eliminar(raiz->derecho, codigo);
        else {
            if ((raiz->izquierdo == nullptr) || (raiz->derecho == nullptr)) {
                Nodo* temp = raiz->izquierdo ? raiz->izquierdo : raiz->derecho;
                if (temp == nullptr) { 
                    temp = raiz;
                    raiz = nullptr;
                } else { 
                    *raiz = *temp; 
                }
                delete temp;
            } else {
                Nodo* temp = nodoMinimoValor(raiz->derecho);
                raiz->dato = temp->dato;
                raiz->derecho = eliminar(raiz->derecho, temp->dato.codigo);
            }
        }

        if (raiz == nullptr) return raiz;

        raiz->altura = 1 + max(altura(raiz->izquierdo), altura(raiz->derecho));
        int balance = obtenerBalance(raiz);

        // Casos de rotación para eliminación
        if (balance > 1 && obtenerBalance(raiz->izquierdo) >= 0)
            return rotacionDerecha(raiz);
        if (balance > 1 && obtenerBalance(raiz->izquierdo) < 0) {
            raiz->izquierdo = rotacionIzquierda(raiz->izquierdo);
            return rotacionDerecha(raiz);
        }
        if (balance < -1 && obtenerBalance(raiz->derecho) <= 0)
            return rotacionIzquierda(raiz);
        if (balance < -1 && obtenerBalance(raiz->derecho) > 0) {
            raiz->derecho = rotacionDerecha(raiz->derecho);
            return rotacionIzquierda(raiz);
        }

        return raiz;
    }

    // LÓGICA DE BÚSQUEDA AÑADIDA
    Nodo* buscar(Nodo* nodo, int codigo) {
        if (nodo == nullptr || nodo->dato.codigo == codigo) {
            return nodo;
        }
        if (codigo < nodo->dato.codigo) {
            return buscar(nodo->izquierdo, codigo);
        } else {
            return buscar(nodo->derecho, codigo);
        }
    }

    void mostrarEmpleado(Nodo* nodo) {
        cout << "Codigo: " << nodo->dato.codigo 
             << " | Nombre: " << nodo->dato.nombre 
             << " | Cargo: " << nodo->dato.cargo << endl;
    }

    // Recorrido inorden para verificar el árbol
    void inorden(Nodo* nodo) {
        if (nodo != nullptr) {
            inorden(nodo->izquierdo);
            cout << "Codigo: " << nodo->dato.codigo 
                 << " | Nombre: " << nodo->dato.nombre 
                 << " | Cargo: " << nodo->dato.cargo 
                 << " (Balance: " << obtenerBalance(nodo) << ")" << endl;
            inorden(nodo->derecho);
        }
    }

public:
    ArbolAVL() {
        raiz = nullptr;
    }

    void insertarEmpleado(Empleado emp) {
        raiz = insertar(raiz, emp);
        cout << "Empleado insertado y arbol balanceado.\n";
    }

    void eliminarEmpleado(int codigo) {
        raiz = eliminar(raiz, codigo);
        cout << "Operacion de eliminacion completada.\n";
    }

    // FUNCIÓN PÚBLICA DE BÚSQUEDA AÑADIDA
    void buscarEmpleado(int codigo) {
        Nodo* resultado = buscar(raiz, codigo);
        if (resultado != nullptr) {
            cout << "\n--- Empleado encontrado ---\n";
            mostrarEmpleado(resultado);
            cout << "---------------------------\n";
        } else {
            cout << "\nError: Empleado no encontrado.\n";
        }
    }

    void mostrarInorden() {
        if (raiz == nullptr) {
            cout << "El arbol esta vacio.\n";
            return;
        }
        cout << "\n--- Lista de Empleados (Inorden) ---\n";
        inorden(raiz);
        cout << "------------------------------------\n";
    }
};

int main() {
    ArbolAVL arbol;
    int opcion;

    do {
        cout << "\n===== MENU ARBOL AVL EMPRESARIAL =====\n";
        cout << "1. Insertar empleado\n";
        cout << "2. Eliminar empleado\n";
        cout << "3. Buscar empleado\n";
        cout << "4. Mostrar empleados (Inorden con factor de balance)\n";
        cout << "0. Salir\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        if (opcion == 1) {
            Empleado emp;
            cout << "Codigo: ";
            cin >> emp.codigo;
            cin.ignore();
            cout << "Nombre: ";
            getline(cin, emp.nombre);
            cout << "Cargo (Ej. Gerente de Recursos Humanos): ";
            getline(cin, emp.cargo);
            
            arbol.insertarEmpleado(emp);
        }
        else if (opcion == 2) {
            int codigo;
            cout << "Ingrese el codigo del empleado a eliminar: ";
            cin >> codigo;
            arbol.eliminarEmpleado(codigo);
        }
        else if (opcion == 3) {
            int codigo;
            cout << "Ingrese el codigo a buscar: ";
            cin >> codigo;
            arbol.buscarEmpleado(codigo);
        }
        else if (opcion == 4) {
            arbol.mostrarInorden();
        }

    } while (opcion != 0);

    return 0;
}