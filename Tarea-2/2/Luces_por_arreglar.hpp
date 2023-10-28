#include <iostream>

// Struct del nodo del arbol binario
struct tNodoArbolBin {
int posicion;
tNodoArbolBin* izq;
tNodoArbolBin* der;
};

//Definición del private y public de la clase tABB
class tABB {
private:
tNodoArbolBin *raiz;
int nElems;

public:
tABB();
~tABB();
void BorrarArbol(tNodoArbolBin* nodo);
void insert(tNodoArbolBin x);      
tNodoArbolBin* insertHelp(tNodoArbolBin* nodo, int valor);
bool find(tNodoArbolBin x);
tNodoArbolBin* findHelp(tNodoArbolBin *nodo, tNodoArbolBin item);
int lower_bound(tNodoArbolBin x);
int lower_boundHelp(tNodoArbolBin* nodo, int valor, int &flag, int &salida);
};

/*****
* Constructor tABB
******
* Esta funcion inicializa la raiz en NULL
* y define que no tiene ningun elemento
******
* Input:
* No se requiere ningun parametro
******
* Returns:
* No retorna nada debido a que es el constructor.
*****/
tABB::tABB() {
raiz = NULL;
nElems = 0;
}

/*****
* Destructor ~tABB
******
* Este ocupa la funcion BorrarArbol para liberar la memoria recursivamente
******
* Input:
* No se requiere ningun parametro
******
* Returns:
* No retorna nada debido a que es el destructor.
*****/
tABB::~tABB() {
    BorrarArbol(raiz);
}

/*****
* void BorrarArbol
******
* Este revisa si el nodo entregado como parametro, esta vacio o no.
* En caso de que este vacio, se llama recursivamente a si mismo con parametros:
* su hijo izquierdo y luego el derecho.
* Y elimina el nodo pasado como parametro.
******
* Input:
* tNodoArbolBin* nodo: nodo el cual se analiza para hacer los borrados.
******
* Returns:
* No retorna nada debido a que es una función del tipo void.
*****/
void tABB::BorrarArbol(tNodoArbolBin* nodo) {
    if (nodo != NULL) {
        BorrarArbol(nodo->izq);
        BorrarArbol(nodo->der);
        delete nodo;
    }
}


/*****
* void insert
******
* Se llama a la funcion insertHelp a la cual se le dan como parametros
* La raiz del arbol y la posicion del nodo x que se quiere insertar.
* Aumenta en 1 el valor del numero de elementos en el arbol
******
* Input:
* tNodoArbolBin x: nodo el cual se inserta en el arbol.
******
* Returns:
* No retorna nada debido a que es una función del tipo void.
*****/
void tABB::insert(tNodoArbolBin x) {
    raiz = insertHelp(raiz, x.posicion);
    nElems = x.posicion + 1;
}

/*****
* tNodoArbolBin* insertHelp
******
* Si el nodo entregado esta vacio, lo inicializa y le da como posicion el valor que se le da como parametro
* Si este existe, se revisa si el valor es mayor o menor a la posicion del nodo.
* Si es menor, se llama a si misma recursivamente por el hijo izquierdo
* Si es mayor, se llama a si misma recursivamente por el hijo derecho
******
* Input:
* tNodoArbolBin* nodo: nodo el cual se compara con valor, o se crea en caso de ser NULL
* int valor: Entero el cual se compara con el nodo, este representa la posicion del nodo
* a crear
******
* Returns:
* tNodoArbolBin*: Este es el nuevo nodo creado en caso de no existir anteriormente.
*****/
tNodoArbolBin* tABB::insertHelp(tNodoArbolBin* nodo, int valor) {
    if (nodo == NULL) {
        tNodoArbolBin* nuevoNodo = new tNodoArbolBin;
        nuevoNodo->posicion = valor;
        nuevoNodo->izq = NULL;
        nuevoNodo->der = NULL;
        return nuevoNodo;
    }
    if (valor < nodo->posicion) {
        nodo->izq = insertHelp(nodo->izq, valor);
    }
    else if (valor > nodo->posicion) {
        nodo->der = insertHelp(nodo->der, valor);
    }
    return nodo;
}

/*****
* bool find
******
* Este revisa si el nodo entregado existe o no con ayuda de la funcion findHelp
******
* Input:
* tNodoArbolBin item: nodo el cual se busca determinar si existe o no.
******
* Returns:
* bool: retorna true en caso de existir y false en caso de no existir.
*****/
bool tABB::find(tNodoArbolBin item) {
    if (findHelp(raiz, item)!=NULL) {
        return true;
    }
    return false;
}

/*****
* tNodoArbolBin* findHelp
******
* Compara el nodo con la raiz
* Si el nodo entregado no existe, retorna null
* Si existe, lo compara con la raiz del arbol
* Si la posicion del nodo es igual, se ha encontrado el nodo
* Si la posicion es menor, se llama a si misma recursivamente con el hijo izquierdo de la raiz
* Si la posicion es mayor, se llama a si misma recursivamente con el hijo derecho de la raiz
******
* Input:
* tNodoArbolBin *raiz: Raiz del arbol
* tNodoArbolBin item: Nodo que se desea encontrar
******
* Returns:
* tNodoArbolBin*: retorna NULL si no encuentra al item
* y retorna la raiz en caso de encontrar el item
*****/
tNodoArbolBin* tABB::findHelp(tNodoArbolBin *raiz, tNodoArbolBin item) {
    if (raiz == NULL) {
        return NULL;
    }
    if (raiz->posicion == item.posicion) {
        return raiz;
    }
    else {
        return findHelp(raiz->der, item);
    }
}

/*****
* int lower_bound
******
* Busca el primer valor menor o igual a x
* Este llama a lower_boundHelp con la raiz del arbol,
* la posicion del nodo a comparar, un flag y un entero salida
******
* Input:
* tNodoArbolBin x: nodo el cual se da como parametro a lower_boundHelp
******
* Returns:
* int: retorna la posicion del nodo menor.
*****/
int tABB::lower_bound(tNodoArbolBin x) {
    int flag =1;
    int salida = -1;
    return lower_boundHelp(raiz, x.posicion,flag,salida);
}

/*****
* int lower_boundHelp
******
* Se recorre el arbol en inOrden pero desde la derecha, osea
* se elijen los nodos de mayor a menor y asi encontrar el mayor nodo
* del arbol.
******
* Input:
* tNodoArbolBin* nodo: nodo el cual se compara con el valor
* int valor: posicion del nodo el cual se quiere encontrar
* int& flag: es su direccion de memoria, debido a que por la recursividad,
* se busca que el valor de este se mantenga a traves de las
* recursividades de la funcion.
* int& salida: Este tambien es direccion de memoria por la misma razon
* y seria el valor de la posicion buscada
******
* Returns:
* int: posicion del nodo buscado, o -1 en caso de no encontrar.
*****/
int tABB::lower_boundHelp(tNodoArbolBin* nodo, int valor, int& flag,int& salida) {
    if(nodo ==NULL) {
        return -1;
    }
    else {
        lower_boundHelp(nodo->der,valor,flag,salida);
        if ((nodo->posicion <= valor) && (flag==1)) {
            flag = false;
            salida = nodo->posicion;
        }
        lower_boundHelp(nodo->izq,valor,flag,salida);
    }
    return salida;
}

/*****
* void ENCENDER
******
* Se enciende el poste en i.
* Esto se hace añadiendolo a un arbol binario.
* Se crea un nodo con posicion i
* Si el nodo no se encuentra en el arbol (ya esta encendido) no hace nada
* Si no se encuentra, lo añade al arbol.
******
* Input:
* tABB& treeBB: Arbol binario
* int i: posicion que se desea encender
* int& postes_encendidos: numero de postes encendidos y tamaño del arbol.
******
* Returns:
* No retorna nada debido a que es una función del tipo void.
*****/
void ENCENDER(tABB& treeBB,int i, int& postes_encendidos) {
    tNodoArbolBin nodo;
    nodo.posicion = i;
    if (!treeBB.find(nodo)) {
        treeBB.insert(nodo);
        postes_encendidos++;
    }
}

/*****
* void CUANTOS_ENCENDER
******
* Imprime por pantalla cuántos postes están apagados entre la posición i y la posición
* del poste encendido más cercano en una posición menor o igual a i
* Si no hay ninguno, imprime la cantidad de postes apagados entre 0 e i.
* Se crea un nodo con posicion i
* Si este esta encendido, imprime 0
* Si es menor o igual, se llama a lower_bound para encontrar el primer valor menor a i
* Si lo encuentra, se resta la posicion i con la posicion del menor encendido
* Si no lo encuentra, le suma 1 a la posicion.
******
* Input:
* tABB& treeBB: Arbol binario
* int i: posicion que se desea analizar.
******
* Returns:
* No retorna nada debido a que es una función del tipo void.
*****/
void  CUANTOS_ENCENDER(tABB& treeBB, int i) {
    tNodoArbolBin nodo;
    nodo.posicion = i;
    int resultado = 0;
    if (treeBB.find(nodo)) {
        std::cout << resultado << std::endl;
        return;
    }
    int menor_o_igual = treeBB.lower_bound(nodo);
    if (menor_o_igual != -1) {
        resultado = i - menor_o_igual;
    }
    else {
        resultado = i + 1;
    }
    std::cout << resultado << std::endl;
}

/*****
* void PARAR_PROGRAMA
******
* Retorna los numeros de postes encendidos
******
* Input:
* int postes_encendidos: cantidad de postes encendidos
******
* Returns:
* No retorna nada debido a que es una función del tipo void.
*****/
void PARAR_PROGRAMA(int postes_encendidos) {
    std::cout << postes_encendidos << std::endl;
} 