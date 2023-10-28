#include <iostream>
#include <string>

// Struct del nodo en la lista enlazada
struct tNodo {
    char nucleotido;
    tNodo* sig;
};

//Definición del private y public de la clase tListaNucleotidos
class tListaNucleotidos {
private:
    tNodo* head;
    tNodo* tail;
    tNodo* curr;
    int listSize;
    int pos;

public:
    tListaNucleotidos();
    ~tListaNucleotidos();
    void moveToPos(int i);
    void Inserciones(int i, char n);
    void Borrados(int i);
    void Intercambios(int i, char n);
    void BorrarDatos();
    char InfoNodoActual(int i);
    int size_ListaNucleotidos();
};

/*****
* Constructor tListaNucleotidos
******
* Esta función, crea una lista vacía y la inicializa en la posición cero
* con sus respectivos punteros.
******
* Input:
* No es requerido ningún parámetro.
******
* Returns:
* No retorna nada debido a que es el constructor.
*****/
tListaNucleotidos::tListaNucleotidos() {
    head = tail = curr = new tNodo;
    listSize = 0;
    pos = 0;
}

/*****
* Destructor ~tListaNucleotidos
******
* La función como bien dice el nombre, destruye la lista, eliminando cada nodo
* desde el inicio de la lista.
******
* Input:
* No es requerido ningún parámetro.
******
* Returns:
* No retorna nada debido a que es el destructor.
*****/
tListaNucleotidos::~tListaNucleotidos() {
    curr = head;
    while (curr != NULL) {
        tNodo* next = curr->sig;
        delete curr;
        curr = next;
    }
}

/*****
* void moveToPos
******
* Recibe una posición a la que se quiere mover en la lista, 
* modificando el curr y la pos actual a la deseada.
******
* Input:
* int i: Este entero es la posición hacia la que se quiere mover el
* curr en la lista.
******
* Returns:
* No retorna nada debido a que es una función del tipo void.
*****/
void tListaNucleotidos::moveToPos(int i) {
    int j;
    if (i < 0 || i > listSize) {
        return ;
    }
    curr = head;
    pos = 0;
    if (i == 0) {
        return;
    } ;
    for (j = 0; j < i; j++ ) {
        curr = curr->sig;
        pos++;
    }
    return;
}

/*****
* void Inserciones
******
* Esta función utiliza dentro de esta misma, la función moveToPos, 
* se dirige al nodo anterior al que va a ser insertado el
* elemento y luego se realizan operaciones con los nodos para insertar este
* elemento en la posición correspondiente.
******
* Input:
* int i: Posición en la que se quiere insertar el elemento.
* char n: Elemento que será insertado en la lista enlazada.
******
* Returns:
* No retorna nada debido a que es una función del tipo void.
*****/
void tListaNucleotidos::Inserciones(int i, char n) {
    if (i < 0 || i > listSize) {
        return;
    }
    if (i == 0) {
        tNodo* aux = new tNodo;
        aux->nucleotido = n;
        aux->sig = head;
        head = aux;
        if (listSize == 0) {
            tail = aux;
        }
        listSize++;
        return;
    }
    moveToPos(i-1);
    tNodo* aux = new tNodo;
    aux->nucleotido = n;
    aux->sig = curr->sig;
    curr->sig = aux;
    if (curr->sig == NULL) {
        tail = aux;
    }
    listSize++;
    return;
}

/*****
* void Borrados
******
* Sigue la misma lógica que la función Inserciones
* También utiliza la función moveToPos,
* solo que en esta función, se elimina el elemento que está en la posición
* i de la lista enlazada.
******
* Input:
* int i: Posición en la que se quiere borrar el elemento de la lista enlazada.
******
* Returns:
* No retorna nada debido a que es una función del tipo void.
*****/
void tListaNucleotidos::Borrados(int i) {
    if (i < 0 || i >= listSize) {
        return;
    }
    if (i == 0) {
        tNodo* nodoBorrado = head;
        head = head->sig;
        if (head == NULL) {
            tail = NULL;
        }
        delete nodoBorrado;
        listSize--;
        return;
    }
    moveToPos(i-1);
    tNodo* nodoAnterior = curr;
    if (nodoAnterior->sig == NULL) {
        return;
    }
    tNodo* nodoBorrado = nodoAnterior->sig;
    nodoAnterior->sig = nodoBorrado->sig;
    if (nodoBorrado == tail) {
        tail = nodoAnterior;
    }
    delete nodoBorrado;
    listSize--;
    return;
}

/*****
* void Intercambios
******
* Esta función intercambia el elemento que está en la posición i por 
* el nuevo elemento n que se quiere introducir a la lista enlazada.
******
* Input:
* int i: Posición en donde se quiere realizar el intercambio.
* char n: El nuevo elemento que se quiere introducir en la posición i.
******
* Returns:
* No retorna nada debido a que es una función del tipo void.
*****/
void tListaNucleotidos::Intercambios(int i, char n) {
    if (i < 0 || i >= listSize) {
        return;
    }
    moveToPos(i);
    if (curr == NULL) {
        return;
    }
    curr->nucleotido = n;
    return;
}

/*****
* void BorrarDatos
******
* Esta función se basa en el destructor de tListaNucleotidos, se borran
* todos los elementos desde el head, y luego el tamaño de la lista y la pos
* se asignan al valor 0.
******
* Input:
* No es requerido ningún parámetro.
******
* Returns:
* No retorna nada debido a que es una función del tipo void.
*****/
void tListaNucleotidos::BorrarDatos() {
    curr = head;
    while (curr != NULL) {
        tNodo* next = curr->sig;
        delete curr;
        curr = next;
    }
    head = tail = curr = new tNodo; 
    listSize = 0;
    pos = 0;
}

/*****
* char InfoNodoActual
******
* Función que llama a moveToPos en la posición i, que es en la pos,
* en la que se quiere saber el elemento que se encuentra ahí.
******
* Input:
* int i: Posición en la cual se quiere obtener el elemento en la lista enlazada.
******
* Returns:
* Se retorna el elemento que está en la posición i.
*****/
char tListaNucleotidos::InfoNodoActual(int i) {
    moveToPos(i);
    return curr->nucleotido;
}

/*****
* int size_ListaNucleotidos
******
* Función que usa la operación listSize, para obtener el tamaño de la lista
******
* Input:
* No es requerido ningún parámetro.
******
* Returns:
* Se retorna un entero el cual contiene el tamaño de la lista.
*****/
int tListaNucleotidos::size_ListaNucleotidos() {
    return listSize;
}