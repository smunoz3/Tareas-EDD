#include <iostream>
using namespace std;

struct tNodoArbolBin {
    int posicion;
    bool encendido;
    tNodoArbolBin* izq;
    tNodoArbolBin* der;
};

class tABB {
private:
    tNodoArbolBin* raiz; // puntero al nodo raíz del ABB
    int nElems; // cantidad de elementos en el ABB

public:
    tABB();
    ~tABB();
    void BorrarArbol(tNodoArbolBin* nodo);
    void insert(int x); // Corregido: tipo de dato int
    bool find(int x); // Corregido: tipo de dato int
    int lower_bound(int x); // Corregido: tipo de dato int
};

tABB::tABB() {
    raiz = nullptr;
    nElems = 0;
}

tABB::~tABB() {
    BorrarArbol(raiz);
}

void tABB::BorrarArbol(tNodoArbolBin* nodo) {
    if (nodo != nullptr) {
        BorrarArbol(nodo->izq);
        BorrarArbol(nodo->der);
        delete nodo;
    }
}

void tABB::insert(int x) {
    if (find(x)) {
        std::cout << "Elemento ya ingresado" << std::endl;
        return;
    }

    tNodoArbolBin* nuevoNodo = new tNodoArbolBin();
    nuevoNodo->posicion = x;
    nuevoNodo->encendido = false;
    nuevoNodo->izq = nullptr;
    nuevoNodo->der = nullptr;

    if (raiz == nullptr) {
        raiz = nuevoNodo;
        nElems = 1;
        return;
    }

    tNodoArbolBin* actual = raiz;
    while (true) {
        if (x < actual->posicion) {
            if (actual->izq == nullptr) {
                actual->izq = nuevoNodo;
                nElems++;
                return;
            }
            actual = actual->izq;
        }
        else {
            if (actual->der == nullptr) {
                actual->der = nuevoNodo;
                nElems++;
                return;
            }
            actual = actual->der;
        }
    }
}

bool tABB::find(int x) {
    tNodoArbolBin* actual = raiz;
    while (actual != nullptr) {
        if (x == actual->posicion) {
            return true; // Elemento encontrado
        }
        else if (x < actual->posicion) {
            actual = actual->izq;
        }
        else {
            actual = actual->der;
        }
    }
    return false; // Elemento no encontrado
}

int tABB::lower_bound(int x) {
    tNodoArbolBin* actual = raiz;
    int result = -1; // Valor por defecto si no se encuentra ningún valor menor o igual

    while (actual != nullptr) {
        if (x >= actual->posicion) {
            result = actual->posicion; // Actualizar el resultado más reciente
            actual = actual->der; // Buscar en el subárbol derecho para encontrar un valor mayor
        }
        else {
            actual = actual->izq; // Buscar en el subárbol izquierdo para encontrar un valor menor o igual
        }
    }

    return result;
}

void ENCENDER(tABB& treeBB, int i, int& postes_encendidos) {
    if (!treeBB.find(i)) {
        treeBB.insert(i);
        postes_encendidos++;
    }
}

void CUANTOS_ENCENDER(tABB& treeBB, int i, int& postes_encendidos) {
    int result = 0;

    if (treeBB.find(i)) {
        std::cout<<"hola ??"<<std::endl;
        std::cout << result << std::endl;
        return;
    }

    int menor_o_igual = treeBB.lower_bound(i);
    if (menor_o_igual != -1) {
        std::cout<<"hola migger??"<<std::endl;
        result = i - menor_o_igual;
    } else {
        std::cout<<"hola migger_2.0??"<<std::endl;
        result = i + 1 - postes_encendidos;
    }

    std::cout << result << std::endl;
}

void PARAR_PROGRAMA(int postes_encendidos) {
    std::cout << postes_encendidos << std::endl;
    
    exit(0);
}

/*****
* TipoFunción NombreFunción
******
* Resumen Función
******
* Input:
* tipoParámetro NombreParámetro : Descripción Parámetro
* .......
******
* Returns:
* TipoRetorno, Descripción retorno
*****/

/* 
int cercano = treeBB.lower_bound(i);
            if (cercano == -1){
                cout<<i+1<<endl;
            }
            else {
                int count = i - cercano;
                cout<<count <<endl;
            } */