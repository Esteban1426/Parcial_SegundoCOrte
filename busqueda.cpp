#include <iostream>

using namespace std;

struct nodo
{
    int num;
    nodo* siguiente;
};

nodo* cabeza = nullptr;
nodo* cola = nullptr;


void Insertar(int valor) {
    nodo* nuevo = new nodo();
    nuevo->num = valor;

    if (cabeza == nullptr) {
        cabeza = nuevo;
        cola = nuevo;
    }
    else {
        cola->siguiente = nuevo;
        cola = nuevo;
    }
}


void mostrar() {
    int contador = 1;

    if (!cabeza) {
        cout << "La lista está vacía, primero debes ingresar valores" << endl;
        return;
    }

    nodo* actual = cabeza;
    do {
        cout << "Nodo numero " << contador << ": " << actual->num << " " << endl;
        actual = actual->siguiente;
        contador++;
    } while (actual != nullptr);
}

int busquedaBinaria(int valor) {
    int posicion = 0;
    nodo* izquierda = cabeza;
    nodo* derecha = cola;

    while (izquierda != derecha && izquierda->num <= derecha->num) {
        nodo* medio = izquierda;
        for (nodo* temp = izquierda->siguiente; temp != nullptr; temp = temp->siguiente) {
            if (temp->num < medio->num) {
                medio = temp;
            }
        }

        if (medio->num == valor) {
            return posicion;
        }
        else if (medio->num < valor) {
            izquierda = medio->siguiente;
        }
        else {
            derecha = medio;
        }

        posicion++;
    }

    return -1;
}

int main() {
    cout << "LISTA ENLAZADA SIMPLE CON BUSQUEDA BINARIA: \n";

    
    Insertar(5);
    Insertar(8);
    Insertar(12);
    Insertar(17);
    Insertar(29);



    cout << "Lista: \n";
    mostrar();

    int elementoABuscar = 12;
    int posicion = busquedaBinaria(elementoABuscar);

    if (posicion != -1) {
        cout << "Elemento " << elementoABuscar << " encontrado en la posición " << posicion << endl;
    }
    else {
        cout << "Elemento " << elementoABuscar << " no encontrado en la lista." << endl;
    }

    return 0;
}