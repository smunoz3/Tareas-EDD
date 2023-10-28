#include <iostream>
#include <string>

using namespace std;

struct heap_node {
    string id;
    int priority;
    string instruction;
};

class tColaP{
    
private:
    heap_node *arr;
    int size;
    int capacity;
    /*****
    *   void reordenar_insert
    ******
    *   Esta función tal como dice el nombre, reordena el arreglo "arr", luego de cada
    *   inserción que se hace, mediante un while para calcular la prioridad del nodo dado
    *   con el nodo padre, para posteriormente cambiarlos si es que no están ordenados, para
    *   cumplir con la propiedad del heap.
    ******
    *   Input:
    *       int i: Es el indice del elemento que se insertó.
    *****
    *   Returns:
    *       No retorna nada debido a que es una función de tipo void.
    *****/
    void reordenar_insert(int i){
        int padre = i / 2; 
        heap_node temp = arr[i];
        while  (i > 1 && arr[padre].priority > temp.priority) {
            arr [i] = arr[padre];
            i = padre;
            padre = i / 2;
        }
        arr [i] = temp;
    }

    /*****
    *   void reordenar_delete
    ******
    *   Esta función reordena el heap luego de cada delete, se compara la prioridad del nodo dado con la
    *   de los hijos, si la prioidad del hijo es menor que la del nodo dado, entonces se intercambian, y así
    *   recursivamente para poder ordenar el heap.
    ******
    *   Input:
    *       int i: Es el indice del elemento que se quiere eliminar.
    *****
    *   Returns:
    *       No retorna nada debido a que es una función de tipo void.
    *****/
    void reordenar_delete(int i){
        int leftChild = 2 * i;
        int rightChild = 2 * i + 1;
        int prioritize = i;
        heap_node temp = arr[i];
        if (leftChild <= size && arr[leftChild].priority < temp.priority){
            prioritize = leftChild;
        }
        if (rightChild <= size && arr[rightChild].priority < arr[prioritize].priority){
            prioritize = rightChild;
        }

        if (prioritize != i) {
            arr[i] = arr[prioritize];
            arr[prioritize]= temp;
            reordenar_delete
    (prioritize);
        }
    }

public:
    tColaP();
    ~tColaP();
    void clearColaP();
    heap_node findMax();
    int sizeColaP();
    void removeMax();
    void insertColaP(string id, int priority, string instruction);
};

/*****
*   tColaP
******
*   Esta función es el constructor tColaP, se crea una cola de prioridad utilizando un arreglo dinamico
*   de tipo struct heap_node, la cola de prioridad se define con capacidad máxima (1000).
******
*   Input:
*       No se requieren de inputs debido a que es el constructor.
******
*   Returns:
*       No retorna nada debido a que es el constructor.
*****/
tColaP::tColaP(){
    heap_node nada;
    size=1; 
    capacity= 1000;
    arr = new heap_node[capacity];
    arr[0]= nada;
}

/*****
*   ~tColaP
******
*   Esta función es el destructor de tColaP, se elimina el arreglo arr, que fue creado con
*   memoria dinámica.
******
*   Input:
*       No se requieren de inputs debido a que es el destructor.
******
*   Returns:
*       No retorna nada debido a que es el destructor.
*****/
tColaP::~tColaP(){
    delete[] arr;
}

/*****
*   void clearColaP
******
*   Esta función borra todos los elementos de la cola de prioridad y la deja vacía, se
*   utiliza un delete y luego se crea la cola de prioridad nuevamente.
******
*   Input:
*       No se requieren de inputs.
******
*   Returns:
*       No retorna nada debido a que es de tipo void.
*****/
void tColaP::clearColaP(){
    delete[] arr;
    size=1;
    arr = new heap_node[capacity]; 
}

/*****
*   heap_node findMax
******
*   Esta función comprueba si está o no vacía la cola, si no está vacía entonces
*   encuentra el elemento de máxima prioridad y lo devuelve.
******
*   Input:
*       No se requieren de inputs.
******
*   Returns:
*       Retorna un struct heap_node vacío si la cola está vacía.
*       Retorna un struct heap_node con la posición del elemento de máxima prioridad si la cola no está vacía.
*****/
heap_node tColaP::findMax(){
    if (size==1){
        cout << "Está vacía la cola" << endl;
        return {"",0,""};
    }
    return arr[1];
}

/*****
*   int sizeColaP
******
*   Esta función calcula el tamaño de la cola de prioridad, se le resta 1
*   a la cola debido a que el primer elemento no cuenta.
******
*   Input:
*       No se requieren de inputs.
******
*   Returns:
*       Retorna el número de elementos de la cola de prioridad.
*****/
int tColaP::sizeColaP(){
    return size-1;
}

/*****
*   void removeMax
******
*   Esta función verifica que la cola si está vacía, luego se le asigna el último
*   elemento del arreglo al nodo que está en la posición 1, después se actualiza el tamaño
*   y se llama a la función reordenar_delete para así poder ordenar el heap luego del delete.
******
*   Input:
*       No se requieren de inputs.
******
*   Returns:
*       No retorna nada debido a que es de tipo void, pero si la cola está vacía se retorna altiro y
*       se muestra un mensaje por pantalla "EStá vacía la cola".
*****/
void tColaP::removeMax(){
    if (size == 1) {
            cout << "Está vacía la cola" << endl;
            return;
        }
        arr[1] = arr[size - 1];
        size--;
        reordenar_delete(1); 
}

/*****
*   void insertColaP
******
*   Esta función verifica si la cola está llena, de no ser así se inserta el elemento en la
*   cola de prioridad, luego se llama la función reordenar_insert, para poder actualizar y
*   reordenar el heap, también se incrementa el tamaño en 1 para actuañizar el tamaño
*   de la cola de prioridad
******
*   Input:
*       No se requieren de inputs.
******
*   Returns:
*       No retorna nada debido a que es de tipo void, pero si la cola está llena se retorna altiro y
*       se muestra un mensaje por pantalla "Está llena la cola".
*****/
void tColaP::insertColaP(string id, int priority, string instruction){
    if (size == capacity) {
            cout << "Está llena la cola" << endl;
            return;
        }
    heap_node nuevo_nodo;
    nuevo_nodo.id = id;
    nuevo_nodo.priority = priority;
    nuevo_nodo.instruction = instruction;
    arr[size] = nuevo_nodo;
    reordenar_insert(size);
    size++;
    return;
}