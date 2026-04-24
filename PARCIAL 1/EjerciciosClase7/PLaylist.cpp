#include <iostream>
#include <string>
using namespace std;

// ?? Nodo doble
template <typename T>
class NodoDoble {
public:
    T info;
    NodoDoble<T>* next;
    NodoDoble<T>* prev;

    NodoDoble(T valor) {
        info = valor;
        next = NULL;
        prev = NULL;
    }
};

// ?? Lista doble (Playlist)
template <typename T>
class ListaDoble {
private:
    NodoDoble<T>* head;
    NodoDoble<T>* tail;

public:
    ListaDoble() {
        head = NULL;
        tail = NULL;
    }

    bool estaVacia() {
        return head == NULL;
    }

    // ?? Agregar al final
    void agregarCancionFinal(T valor) {
        NodoDoble<T>* nuevo = new NodoDoble<T>(valor);

        if (estaVacia()) {
            head = tail = nuevo;
        } else {
            tail->next = nuevo;
            nuevo->prev = tail;
            tail = nuevo;
        }
    }

    // ?? Insertar después
    bool insertarDespuesCancionActual(T buscado, T valor) {
        NodoDoble<T>* actual = head;

        while (actual != NULL && actual->info != buscado) {
            actual = actual->next;
        }

        if (actual == NULL) return false;

        NodoDoble<T>* nuevo = new NodoDoble<T>(valor);

        nuevo->next = actual->next;
        nuevo->prev = actual;

        if (actual->next != NULL) {
            actual->next->prev = nuevo;
        } else {
            tail = nuevo;
        }

        actual->next = nuevo;
        return true;
    }

    // ?? Eliminar
    bool eliminarCancion(T valor) {
        NodoDoble<T>* actual = head;

        while (actual != NULL && actual->info != valor) {
            actual = actual->next;
        }

        if (actual == NULL) return false;

        if (head == tail) {
            head = tail = NULL;
        } else if (actual == head) {
            head = head->next;
            head->prev = NULL;
        } else if (actual == tail) {
            tail = tail->prev;
            tail->next = NULL;
        } else {
            actual->prev->next = actual->next;
            actual->next->prev = actual->prev;
        }

        delete actual;
        return true;
    }

    // ?? Mostrar inicio ? fin
    void mostrarPlaylistInicioFin() {
        NodoDoble<T>* aux = head;

        cout << "\nPlaylist (Inicio -> Fin):\n";
        while (aux != NULL) {
            cout << aux->info << " <-> ";
            aux = aux->next;
        }
        cout << "NULL\n";
    }

    // ?? Mostrar fin ? inicio
    void mostrarPlaylistFinInicio() {
        NodoDoble<T>* aux = tail;

        cout << "\nPlaylist (Fin -> Inicio):\n";
        while (aux != NULL) {
            cout << aux->info << " <-> ";
            aux = aux->prev;
        }
        cout << "NULL\n";
    }
};

// ?? MAIN con menú
int main() {

    ListaDoble<string> canciones;
    int opcion;
    string nombre, referencia;

    do {
        cout << "\n--- MENU PLAYLIST ---\n";
        cout << "1. Agregar cancion final\n";
        cout << "2. Insertar despues de una cancion\n";
        cout << "3. Eliminar cancion\n";
        cout << "4. Mostrar playlist (inicio -> fin)\n";
        cout << "5. Mostrar playlist (fin -> inicio)\n";
        cout << "6. Salir\n";
        cout << "Opcion: ";
        cin >> opcion;

        cin.ignore(); // limpiar buffer

        switch (opcion) {
            case 1:
                cout << "Ingrese nombre de la cancion: ";
                getline(cin, nombre);
                canciones.agregarCancionFinal(nombre);
                break;

            case 2:
                cout << "Cancion de referencia: ";
                getline(cin, referencia);
                cout << "Nueva cancion: ";
                getline(cin, nombre);

                if (canciones.insertarDespuesCancionActual(referencia, nombre))
                    cout << "Insertado correctamente\n";
                else
                    cout << "No se encontro la cancion\n";
                break;

            case 3:
                cout << "Cancion a eliminar: ";
                getline(cin, nombre);

                if (canciones.eliminarCancion(nombre))
                    cout << "Eliminado correctamente\n";
                else
                    cout << "No se encontro la cancion\n";
                break;

            case 4:
                canciones.mostrarPlaylistInicioFin();
                break;

            case 5:
                canciones.mostrarPlaylistFinInicio();
                break;

        }

    } while (opcion != 6);

    return 0;
}
