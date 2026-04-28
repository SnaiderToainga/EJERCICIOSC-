#include<iostream>
using namespace std;

class TreeNode{
public:
    int value;
    TreeNode *left;
    TreeNode *right;

    TreeNode(){
        value = 0;
        left = NULL;
        right = NULL;
    }

    TreeNode(int v){
        value = v;
        left = NULL;
        right = NULL;
    }
}; // ← IMPORTANTE

class BST{
public:
    TreeNode *root;

    BST(){
        root = NULL;
    }

    bool isEmpty(){
        return (root == NULL);
    }

    void insertNode(TreeNode *new_node){
        if(root == NULL){
            root = new_node;
            cout << "Valor insertado como root" << endl;
        } 
        else {
            TreeNode *temp = root;

            while(true){
                if(new_node->value == temp->value){
                    cout << "El valor ya existe" << endl;
                    return;
                }
                else if(new_node->value < temp->value){
                    if(temp->left == NULL){
                        temp->left = new_node;
                        cout << "Valor insertado correctamente" << endl;
                        return;
                    } else {
                        temp = temp->left;
                    }
                }
                else {
                    if(temp->right == NULL){
                        temp->right = new_node;
                        cout << "Valor insertado correctamente" << endl;
                        return;
                    } else {
                        temp = temp->right;
                    }
                }
            }
        }
    }
}; // ← IMPORTANTE

int main(){

    BST arbol;
    int opcion, valor;

    do{
        cout << "\nMENU\n";
        cout << "1. Insertar nodo\n";
        cout << "2. Verificar si el arbol esta vacio\n";
        cout << "0. Salir\n";
        cout << "Opcion: ";
        cin >> opcion;

        switch(opcion){

            case 1:
                cout << "Ingrese un valor: ";
                cin >> valor;
                arbol.insertNode(new TreeNode(valor));
                break;

            case 2:
                if(arbol.isEmpty()){
                    cout << "El arbol esta vacio\n";
                } else {
                    cout << "El arbol NO esta vacio\n";
                }
                break;

            case 0:
                cout << "Saliendo...\n";
                break;

            default:
                cout << "Opcion invalida\n";
        }

    } while(opcion != 0);

    return 0;
}