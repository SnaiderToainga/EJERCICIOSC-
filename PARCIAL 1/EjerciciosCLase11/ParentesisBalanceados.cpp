#include <iostream>
#include <stack>
using namespace std;

// Función para mostrar la pila
void mostrarPila(stack<char> p) {
    cout << "Pila: ";
    if (p.empty()) {
        cout << "VACIA";
    } else {
        while (!p.empty()) {
            cout << p.top() << " ";
            p.pop();
        }
    }
    cout << endl;
}

// Función principal del algoritmo
bool parentesisBalanceados(string expresion) {
    stack<char> pila;

    cout << "\nProceso paso a paso:\n";

    for (int i = 0; i < expresion.length(); i++) {
        char c = expresion[i];

        cout << "\nLeyendo: " << c << endl;

        if (c == '(') {
            pila.push(c);
            cout << "Accion: PUSH\n";
        } 
        else if (c == ')') {
            if (pila.empty()) {
                cout << "Error: no hay '(' para cerrar\n";
                return false;
            }
            pila.pop();
            cout << "Accion: POP\n";
        }

        mostrarPila(pila);
    }

    if (pila.empty()) {
        return true;
    } else {
        return false;
    }
}

int main() {
    string expresion;

    cout << "Ingrese una expresion: ";
    cin >> expresion;

    bool resultado = parentesisBalanceados(expresion);

    cout << "\nResultado final:\n";
    if (resultado) {
        cout << "Verdadero (Balanceado)" << endl;
    } else {
        cout << "Falso (No balanceado)" << endl;
    }

    return 0;
}
