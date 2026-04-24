#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Estructura para cada nodo del árbol
struct Nodo {
    string nombre;           // Nombre del nodo (cargo o persona)
    string tipo;             // "raiz", "intermedio", "hoja"
    vector<Nodo*> hijos;     // Lista de hijos
    Nodo* padre;             // Puntero al nodo padre
    
    // Constructor
    Nodo(string nom, string tip, Nodo* pad = nullptr) {
        nombre = nom;
        tipo = tip;
        padre = pad;
    }
};

// Clase del árbol jerárquico
class ArbolJerarquico {
private:
    Nodo* raiz;  // Puntero a la raíz del árbol
    
public:
    // Constructor
    ArbolJerarquico() {
        raiz = nullptr;
    }
    
    // Crear la raíz del árbol
    void crearRaiz(string nombre) {
        if (raiz == nullptr) {
            raiz = new Nodo(nombre, "raiz");
            cout << "✓ Raíz creada: " << nombre << endl;
        } else {
            cout << "✗ Ya existe una raíz" << endl;
        }
    }
    
    // Agregar un hijo a un nodo padre
    bool agregarNodo(string nombrePadre, string nombreHijo, string tipoHijo) {
        Nodo* padre = buscarNodo(raiz, nombrePadre);
        
        if (padre != nullptr) {
            Nodo* nuevoHijo = new Nodo(nombreHijo, tipoHijo, padre);
            padre->hijos.push_back(nuevoHijo);
            cout << "✓ Nodo '" << nombreHijo << "' agregado bajo '" << nombrePadre << "'" << endl;
            return true;
        } else {
            cout << "✗ No se encontró el nodo padre: " << nombrePadre << endl;
            return false;
        }
    }
    
    // Buscar un nodo por su nombre (recursivo)
    Nodo* buscarNodo(Nodo* actual, string nombre) {
        if (actual == nullptr) return nullptr;
        
        if (actual->nombre == nombre) {
            return actual;
        }
        
        for (Nodo* hijo : actual->hijos) {
            Nodo* encontrado = buscarNodo(hijo, nombre);
            if (encontrado != nullptr) {
                return encontrado;
            }
        }
        return nullptr;
    }
    
    // Mostrar el árbol completo (recursivo)
    void mostrarArbol() {
        if (raiz == nullptr) {
            cout << "El árbol está vacío" << endl;
            return;
        }
        cout << "\n╔════════════════════════════════════╗" << endl;
        cout << "║     ESTRUCTURA DEL ÁRBOL           ║" << endl;
        cout << "╚════════════════════════════════════╝" << endl;
        mostrarNodo(raiz, 0);
    }
    
    // Mostrar un nodo con indentación
    void mostrarNodo(Nodo* nodo, int nivel) {
        if (nodo == nullptr) return;
        
        // Imprimir indentación
        for (int i = 0; i < nivel; i++) {
            cout << "  ";
        }
        
        // Imprimir el nodo según su tipo
        if (nodo->tipo == "raiz") {
            cout << "🌳 " << nodo->nombre << " [RAÍZ]";
        } else if (nodo->tipo == "intermedio") {
            cout << "📁 " << nodo->nombre << " [INTERMEDIO]";
        } else {
            cout << "📄 " << nodo->nombre << " [HOJA]";
        }
        
        if (nodo->hijos.empty() && nodo->tipo != "raiz") {
            cout << " (sin hijos)";
        }
        cout << endl;
        
        // Mostrar hijos recursivamente
        for (Nodo* hijo : nodo->hijos) {
            mostrarNodo(hijo, nivel + 1);
        }
    }
    
    // Contar nodos por tipo
    void contarNodos() {
        if (raiz == nullptr) {
            cout << "El árbol está vacío" << endl;
            return;
        }
        
        int contRaiz = 0, contIntermedio = 0, contHoja = 0;
        contarNodosRecursivo(raiz, contRaiz, contIntermedio, contHoja);
        
        cout << "\n╔════════════════════════════════════╗" << endl;
        cout << "║         RESUMEN DEL ÁRBOL          ║" << endl;
        cout << "╚════════════════════════════════════╝" << endl;
        cout << "🌳 Raíces: " << contRaiz << endl;
        cout << "📁 Nodos intermedios: " << contIntermedio << endl;
        cout << "📄 Hojas: " << contHoja << endl;
        cout << "📊 Total de nodos: " << (contRaiz + contIntermedio + contHoja) << endl;
    }
    
    void contarNodosRecursivo(Nodo* nodo, int& raiz, int& intermedio, int& hoja) {
        if (nodo == nullptr) return;
        
        if (nodo->tipo == "raiz") raiz++;
        else if (nodo->tipo == "intermedio") intermedio++;
        else if (nodo->tipo == "hoja") hoja++;
        
        for (Nodo* hijo : nodo->hijos) {
            contarNodosRecursivo(hijo, raiz, intermedio, hoja);
        }
    }
    
    // Destructor para liberar memoria
    ~ArbolJerarquico() {
        liberarMemoria(raiz);
        cout << "\n🧹 Memoria liberada correctamente" << endl;
    }
    
    void liberarMemoria(Nodo* nodo) {
        if (nodo == nullptr) return;
        
        for (Nodo* hijo : nodo->hijos) {
            liberarMemoria(hijo);
        }
        delete nodo;
    }
};

// Función con el ejemplo predefinido basado en la imagen
void ejemploPredefinido() {
    cout << "\n";
    cout << "╔════════════════════════════════════════════════════╗" << endl;
    cout << "║     EJEMPLO: ESTRUCTURA JERÁRQUICA DE EMPRESA      ║" << endl;
    cout << "╚════════════════════════════════════════════════════╝" << endl;
    
    ArbolJerarquico empresa;
    
    cout << "\n--- CONSTRUYENDO EL ÁRBOL ---" << endl;
    
    // Crear la estructura según el ejemplo de la imagen
    empresa.crearRaiz("EMPRESA");
    cout << endl;
    
    empresa.agregarNodo("EMPRESA", "Gerente General", "intermedio");
    cout << endl;
    
    empresa.agregarNodo("Gerente General", "Gerente de Ventas", "intermedio");
    empresa.agregarNodo("Gerente General", "Gerente de TI", "intermedio");
    empresa.agregarNodo("Gerente General", "Gerente de Recursos Humanos", "intermedio");
    cout << endl;
    
    empresa.agregarNodo("Gerente de Ventas", "Juan Pérez (Vendedor)", "hoja");
    empresa.agregarNodo("Gerente de Ventas", "María López (Vendedora)", "hoja");
    empresa.agregarNodo("Gerente de Ventas", "Carlos Gómez (Vendedor)", "hoja");
    cout << endl;
    
    empresa.agregarNodo("Gerente de TI", "Ana Martínez (Programadora)", "hoja");
    empresa.agregarNodo("Gerente de TI", "Luis Rodríguez (Soporte)", "hoja");
    empresa.agregarNodo("Gerente de TI", "Laura Sánchez (DBA)", "hoja");
    cout << endl;
    
    empresa.agregarNodo("Gerente de Recursos Humanos", "Pedro Jiménez (Reclutador)", "hoja");
    empresa.agregarNodo("Gerente de Recursos Humanos", "Sofía Ramírez (Capacitadora)", "hoja");
    
    // Mostrar el árbol completo
    empresa.mostrarArbol();
    
    // Mostrar el resumen de nodos
    empresa.contarNodos();
    
    cout << "\n╔════════════════════════════════════════════════════╗" << endl;
    cout << "║  ✓ Árbol construido exitosamente según el ejemplo  ║" << endl;
    cout << "╚════════════════════════════════════════════════════╝" << endl;
}

int main() {
    // Ejecutar el ejemplo predefinido
    ejemploPredefinido();
    
    cout << "\nPresiona Enter para salir...";
    cin.get();
    
    return 0;
}