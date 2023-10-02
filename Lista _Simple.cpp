#include <iostream>

using namespace std;

struct nodo
{
    int num;
    nodo* siguiente;
};

nodo* cabeza = nullptr;
nodo* cola = nullptr;


void intercambiar(nodo* a, nodo* b) {
    int temp = a->num;
    a->num = b->num;
    b->num = temp;
}


nodo* particion(nodo* cabeza, nodo* cola) {
    int pivot = cola->num;
    nodo* i = cabeza->siguiente;

    for (nodo* j = cabeza; j != cola; j = j->siguiente) {
        if (j->num < pivot) {
            intercambiar(i, j);
            i = i->siguiente;
        }
    }

    intercambiar(i, cola);
    return i;
}
void mostrar() {
    int contador = 1;

    if (!cabeza) {
        cout << "La lista está vacia, primero debes ingresar valores" << endl;
        return;
    }

    nodo* actual = cabeza;
    while (actual != nullptr) {
        cout << "Nodo numero " << contador << ": " << actual->num << " " << endl;
        actual = actual->siguiente;
        contador++;
    }
}

void quicksort(nodo* cabeza, nodo* cola) {
    if (cabeza && cola && cabeza != cola && cabeza != cola->siguiente) {
        nodo* pivot = particion(cabeza, cola);
        quicksort(cabeza, pivot);
        quicksort(pivot->siguiente, cola);
    }
    cout << "Lista ordenada: \n";
}


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



int main() {
    int opcion;
    char continuar = 'y';
    do {
        cout << " Ingresa el numero correspondiente a la opcion que desees: " << endl;
        cout << " 1. Ingresar valores a los nodos " << endl << " 2. Ordenar la lista " << endl << " 3. Salir del programa " << endl;
        cout << " Respuesta: ";
        cin >> opcion;

        switch (opcion) {
            case 1: {
                int valor;
                do {
                    cout << "Ingrese un numero (Nota: Si quieres salir ingresa numero 0): " << endl;
                    cin >> valor;
                    if (valor != 0) {
                        Insertar(valor);
                    }
                } while (valor != 0);

                cout << "Lista Simple: " << endl;
                mostrar();

                cout << "Deseas Continuar con el programa (y / n) en minúsculas: " << endl;
                cin >> continuar;
                break;
            }

case 2: {
    if (cabeza != nullptr) {
        cout << "Lista original: \n";
        mostrar();

        quicksort(cabeza->siguiente, cola);

        cout << "Lista ordenada: \n";
        mostrar();
    } else {
        cout << "La lista está vacia. Debes ingresar valores antes de ordenarla." << endl;
    }
    break;
}
// ...


            case 3: {
                continuar = 'n'; // Salir del programa
                break;
            }

            default: {
                cout << "Opcion no valida" << endl;
                break;
            }
        }
    } while (continuar != 'n');

    nodo* actual = cabeza;
    while (actual != nullptr) {
        nodo* siguiente = actual->siguiente;
        delete actual;
        actual = siguiente;
    }

    cout << "Fin.." << endl;
    return 0;
}
