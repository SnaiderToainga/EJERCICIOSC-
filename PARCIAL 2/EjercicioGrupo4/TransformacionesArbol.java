//package PARCIAL2 .EjercicioGrupo4;

import java.util.ArrayList;
import java.util.List;

// Estructura básica del Nodo
class Nodo {
    int valor;
    Nodo izquierdo, derecho;

    public Nodo(int valor) {
        this.valor = valor;
        this.izquierdo = null;
        this.derecho = null;
    }
}

public class TransformacionesArbol {

    // ==========================================================
    // 1. TRANSFORMACIÓN ESTRUCTURAL (Cambian la forma)
    // Ejemplo: Rotación simple a la derecha (típica en árboles AVL)
    // ==========================================================
    public static Nodo rotacionDerecha(Nodo y) {
        if (y == null || y.izquierdo == null) return y;

        Nodo x = y.izquierdo;
        Nodo T2 = x.derecho;

        // Realizar rotación
        x.derecho = y;
        y.izquierdo = T2;

        System.out.println(">> Rotacion aplicada: El nodo " + x.valor + " ahora es la nueva raiz del subarbol.");
        return x; // Retorna la nueva raíz
    }

    // ==========================================================
    // 2. TRANSFORMACIÓN REDUCTIVA (Simplifican el árbol)
    // Ejemplo: Poda (Pruning) - Elimina hijos si ambos son hojas con el mismo valor
    // ==========================================================
    public static void aplicarPoda(Nodo nodo) {
        if (nodo == null) return;

        // Recorremos hasta el fondo primero (Postorden)
        aplicarPoda(nodo.izquierdo);
        aplicarPoda(nodo.derecho);

        // Lógica de poda: Si tiene ambos hijos, ambos son hojas y tienen el mismo valor
        if (nodo.izquierdo != null && nodo.derecho != null &&
            esHoja(nodo.izquierdo) && esHoja(nodo.derecho) &&
            nodo.izquierdo.valor == nodo.derecho.valor) {
            
            System.out.println(">> Poda aplicada: Simplificando ramas redundantes con valor " + nodo.izquierdo.valor);
            nodo.valor = nodo.izquierdo.valor; // El padre asume el valor
            nodo.izquierdo = null;             // Se cortan (eliminan) las ramas
            nodo.derecho = null;
        }
    }

    private static boolean esHoja(Nodo nodo) {
        return nodo != null && nodo.izquierdo == null && nodo.derecho == null;
    }

    // ==========================================================
    // 3. TRANSFORMACIÓN DE REPRESENTACIÓN (Cambian el formato)
    // Ejemplo A: Recorridos (Aplanar el árbol a una secuencia)
    // Ejemplo B: Serialización (Convertir a cadena de texto)
    // ==========================================================
    
    // 3A: Aplanar en Preorden
    public static void aplanarPreorden(Nodo nodo, List<Integer> lista) {
        if (nodo == null) return;
        lista.add(nodo.valor);
        aplanarPreorden(nodo.izquierdo, lista);
        aplanarPreorden(nodo.derecho, lista);
    }

    // 3B: Serialización (convierte estructura en cadena para red o almacenamiento)
    // Usamos 'N' para representar nodos nulos.
    public static String serializar(Nodo nodo) {
        if (nodo == null) return "N,";
        return nodo.valor + "," + serializar(nodo.izquierdo) + serializar(nodo.derecho);
    }

    // ==========================================================
    // MAIN: PRUEBAS DE LAS TRANSFORMACIONES
    // ==========================================================
    public static void main(String[] args) {
        System.out.println("--- INICIANDO TRANSFORMACIONES DE ARBOLES ---");

        // Creamos un árbol base
        //        10
        //       /  \
        //      5    15
        //     / \
        //    5   5   <-- Hojas redundantes (ideales para la poda)
        Nodo raiz = new Nodo(10);
        raiz.izquierdo = new Nodo(5);
        raiz.derecho = new Nodo(15);
        raiz.izquierdo.izquierdo = new Nodo(5);
        raiz.izquierdo.derecho = new Nodo(5);

        // 1. Prueba de Representación (Preorden y Serialización)
        System.out.println("\n[3] TRANSFORMACIONES DE REPRESENTACION:");
        
        List<Integer> secuenciaPreorden = new ArrayList<>();
        aplanarPreorden(raiz, secuenciaPreorden);
        System.out.println("- Aplanado (Preorden): " + secuenciaPreorden);
        
        String arbolSerializado = serializar(raiz);
        System.out.println("- Serializacion: " + arbolSerializado);

        // 2. Prueba Reductiva (Poda)
        System.out.println("\n[2] TRANSFORMACION REDUCTIVA:");
        aplicarPoda(raiz);
        System.out.println("- Estado despues de poda (Aplanado): ");
        List<Integer> postPoda = new ArrayList<>();
        aplanarPreorden(raiz, postPoda);
        System.out.println("  " + postPoda);

        // 3. Prueba Estructural (Rotación AVL)
        System.out.println("\n[1] TRANSFORMACION ESTRUCTURAL:");
        // Aplicamos rotación a la derecha sobre la raíz (10)
        raiz = rotacionDerecha(raiz);
        System.out.println("- Estado despues de rotacion (Aplanado): ");
        List<Integer> postRotacion = new ArrayList<>();
        aplanarPreorden(raiz, postRotacion);
        System.out.println("  " + postRotacion);
    }
}