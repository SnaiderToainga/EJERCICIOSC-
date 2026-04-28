#include <iostream>
#include <string>
#include <stack>
#include <sstream>

using namespace std;

// Estructura del nodo
struct Nodo {
    string valor; // Puede guardar un número ("5") o un operador ("+")
    Nodo* izquierdo;
    Nodo* derecho;

    Nodo(string val) {
        valor = val;
        izquierdo = nullptr;
        derecho = nullptr;
    }
};

class ArbolExpresion {
private:
    Nodo* raiz;

    // Función auxiliar para saber si un texto es operador
    bool esOperador(string token) {
        return (token == "+" || token == "-" || token == "*" || token == "/");
    }

    // Función recursiva que viaja por el árbol resolviendo las operaciones
    double evaluarRecursivo(Nodo* nodo) {
        // Caso Base: Si es una hoja (un número), lo convertimos a decimal y lo retornamos
        if (!esOperador(nodo->valor)) {
            return stod(nodo->valor); // stod() convierte de string a double
        }

        // Si es un operador, primero evaluamos sus ramas izquierda y derecha
        double valorIzq = evaluarRecursivo(nodo->izquierdo);
        double valorDer = evaluarRecursivo(nodo->derecho);

        // Luego aplicamos la operación matemática correspondiente
        if (nodo->valor == "+") return valorIzq + valorDer;
        if (nodo->valor == "-") return valorIzq - valorDer;
        if (nodo->valor == "*") return valorIzq * valorDer;
        if (nodo->valor == "/") {
            if (valorDer == 0) {
                cout << "Error: Division por cero detectada." << endl;
                return 0;
            }
            return valorIzq / valorDer;
        }
        return 0;
    }

    // Recorrido inorden para imprimir la expresión con paréntesis
    void inorden(Nodo* nodo) {
        if (nodo != nullptr) {
            if (esOperador(nodo->valor)) cout << "( ";
            inorden(nodo->izquierdo);
            cout << nodo->valor << " ";
            inorden(nodo->derecho);
            if (esOperador(nodo->valor)) cout << ") ";
        }
    }

public:
    ArbolExpresion() {
        raiz = nullptr;
    }

    // Construye el árbol utilizando una Pila
    void construirDesdePostfija(string expresion) {
        stack<Nodo*> pila;
        stringstream ss(expresion);
        string token;

        // Lee la expresión separada por espacios
        while (ss >> token) {
            if (!esOperador(token)) {
                // Si es un número, se convierte en un nuevo nodo sin hijos a la pila
                pila.push(new Nodo(token));
            } else {
                // Si es operador, sacamos los últimos dos números de la pila para que sean sus hijos
                Nodo* nodoOperador = new Nodo(token);
                
                // ¡El orden importa! El primero en salir es el derecho, el segundo el izquierdo
                Nodo* hijoDer = pila.top(); pila.pop();
                Nodo* hijoIzq = pila.top(); pila.pop();

                nodoOperador->derecho = hijoDer;
                nodoOperador->izquierdo = hijoIzq;

                // Metemos el "mini-árbol" resuelto de vuelta a la pila
                pila.push(nodoOperador);
            }
        }
        // Al terminar, el árbol completo quedó como único elemento en la pila
        if (!pila.empty()) {
            raiz = pila.top();
        }
    }

    void evaluar() {
        if (raiz == nullptr) {
            cout << "El arbol esta vacio." << endl;
            return;
        }
        cout << "Resultado matematico: " << evaluarRecursivo(raiz) << endl;
    }

    void mostrarExpresion() {
        if (raiz == nullptr) return;
        cout << "Expresion legible (Inorden): ";
        inorden(raiz);
        cout << endl;
    }
};

int main() {
    ArbolExpresion arbol;
    int opcion;
    string postfija;

    do {
        cout << "\n===== ARBOL DE EXPRESIONES ARITMETICAS =====\n";
        cout << "1. Ingresar nueva expresion (Notacion Postfija)\n";
        cout << "2. Mostrar expresion legible (Inorden)\n";
        cout << "3. Evaluar resultado\n";
        cout << "0. Salir\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;
        cin.ignore(); // Limpiar el buffer de entrada

        if (opcion == 1) {
            cout << "\n[NOTA: Separe cada numero y operador con un espacio]\n";
            cout << "Ejemplo para hacer (5 + 3) * 2, ingrese: 5 3 + 2 *\n";
            cout << "Ingrese la expresion postfija: ";
            getline(cin, postfija);
            
            arbol.construirDesdePostfija(postfija);
            cout << "Arbol construido exitosamente.\n";
        }
        else if (opcion == 2) {
            arbol.mostrarExpresion();
        }
        else if (opcion == 3) {
            arbol.evaluar();
        }

    } while (opcion != 0);

    return 0;
}