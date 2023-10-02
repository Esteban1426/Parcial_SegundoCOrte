#include <iostream>
#include <stdlib.h>
#include <conio.h>

using namespace std;

struct Nodo
{
    int dato;
    Nodo *izquierda;
    Nodo *derecha;
};

Nodo *arbol = NULL;

Nodo *crearNodo(int numero){
    Nodo *nuevoNodo = new Nodo();

    nuevoNodo->dato = numero;
    nuevoNodo->izquierda = NULL;
    nuevoNodo->derecha = NULL;

    return nuevoNodo;
}

void insertarNodo(Nodo *&arbol, int numero){

    if (arbol == NULL)
    {
        Nodo *nuevoNodo = crearNodo(numero);
        arbol = nuevoNodo;
    }else{
        int valorRaiz = arbol->dato;
        if (numero < valorRaiz){
            insertarNodo(arbol->izquierda, numero);
        }else if(numero > valorRaiz){
            insertarNodo(arbol->derecha, numero);
        }else{
            cout<<"El valor ya existe, digite otro numero: ";
            cin>>numero;
            insertarNodo(arbol, numero);
        }
    }
}
    
void PreOrden(Nodo *arbol, int numero){
    if(arbol != NULL){
        for (int i = 0; i < numero; i++)
        {
            cout << " ";
        }
        cout << arbol->dato << "\n";
        PreOrden(arbol->izquierda, numero+1);
        PreOrden(arbol->derecha, numero+1);
    }
}

Nodo* EncontrarHojaMasBaja(Nodo* arbol) {
    if (arbol == NULL) {
        return NULL;
    }

    if (arbol->izquierda == NULL && arbol->derecha == NULL) {
        // Cuando encontramos una hoja, la retornamos
        return arbol;
    }

    Nodo* hoja_izquierda = EncontrarHojaMasBaja(arbol->izquierda);
    Nodo* hoja_derecha = EncontrarHojaMasBaja(arbol->derecha);

    // Comparamos los valores de las hojas izquierda y derecha
    // para determinar cuál es más baja
    if (hoja_izquierda != NULL && hoja_derecha != NULL) {
        if (hoja_izquierda->dato < hoja_derecha->dato) {
            return hoja_izquierda;
        } else {
            return hoja_derecha;
        }
    } else if (hoja_izquierda != NULL) {
        return hoja_izquierda;
    } else {
        return hoja_derecha;
    }
}

void ImprimirHojaMasBaja(Nodo* arbol) {
    Nodo* hoja_mas_baja = EncontrarHojaMasBaja(arbol);
    if (hoja_mas_baja != NULL) {
        cout << "La hoja con el valor mas bajo es: " << hoja_mas_baja->dato << endl;
    } else {
        cout << "No hay hojas en el árbol." << endl;
    }
}


void menu(){
    int opcion, numero;

    do
    {
        cout<<"\t MENU ARBOLES BINARIOS: \n";
        cout<<"Escoja una opcion: \n";
        cout<<"1. INSERTAR NODOS \n";
        cout<<"2. MOSTRAR METODOS DE ORDEN \n";
        cout<<"3. SALIR \n";
        cin>>opcion;

        switch (opcion)
        {
        case 1:
            cout<<"Digite un numero: ";
            cin>>numero;
            insertarNodo(arbol, numero);
            cout<<"\n";
            system("pause");
            break;
        case 2:
            cout<<"Metodo PreOrden : ";
            PreOrden(arbol, numero);
            cout<<"\n";
            system("pause");
        break;
        case 3:
        ImprimirHojaMasBaja(arbol);
        cout << endl;
        system("pause");
        break;

        
        default:
            break;
        }
        system("cls");
    } while (opcion != 4);
    
}

int main(){
    menu();

    getch();
    return 0;
}