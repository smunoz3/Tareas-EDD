#include <iostream>
#include <string>

using namespace std;

struct user_struct{
    string id;
    string pass;
};
class Login{
    private:
    string usuario;
    string clave;
    int TAMANIO;
    int numero_elementos;
    float factor_carga;

    user_struct* array_uwu;
    int h(string clave);
    int p(string clave, int i);
    public:
    Login();
    ~Login();
    bool iniciar_sesion(string usuario, string clave);
    bool crear_nuevo_usuario(string usuario, string clave);
    bool cambiar_clave(string usuario, string nueva_clave);

    void insertar(string& usuario, string& clave,user_struct* array_uwu);
    bool buscar(string& usuario);
    bool buscar_clave(string& usuario,string& clave);
    void actualizar_clave(string& usuario,string& nueva_clave);
    void hashing2();
};

/*****
*   Login
******
*   Esta función es el constructor Login, se crea un user_struct con datos vacíos (en blanco)
*   y se crea un arreglo con memoria dinámica de tamaño TAMANIO de tipo user_struct, inicializando
*   todos los elementos del arreglo en vacío (en blanco).
******
*   Input:
*       No se requieren de inputs debido a que es el constructor.
******
*   Returns:
*       No retorna nada debido a que es el constructor.
*****/
Login::Login(){
    TAMANIO=32;
    array_uwu = new user_struct [TAMANIO];
}

/*****
*   ~Login
******
*   Esta función es el destructor de Login, se hace un delete al arreglo.
******
*   Input:
*       No se requieren de inputs debido a que es el constructor.
******
*   Returns:
*       No retorna nada debido a que es el constructor.
*****/
Login::~Login(){
    delete [] array_uwu;
}

/*****
*   bool iniciar_sesion
******
*   Esta función verifica 3 condiciones:
*   1.- Si el usuario no está en el arreglo (Mediante la función buscar) 
*   2.- Si el usuario está en el arreglo y la clave no coincide (Mediante la función buscar y buscar_clave) 
*   3.- Finalmente un else para otro caso.
******
*   Input:
*       string usuario: Es un string que contiene el nombre del usuario a revisar.
*       string clave: Es un string que contiene la clave del usuario a revisar.
******
*   Returns:
*       En caso de que se cumpla la primera condición retorna falso y se imprime por
*       pantalla "El usuario no se encuentra registrado".
*       En caso de que se cumpla la segunda condición se retorna falso y se imprime por
*       pantalla "La clave ingresada no coincide".
*       En el último caso se retorna true y se imprime por pantalla "Sesion iniciada con exito".
*****/
bool Login::iniciar_sesion(string usuario, string clave){
    if (buscar(usuario) == false){
        cout <<"El usuario no se encuentra registrado"<< endl;
        return false;
    }
    if (buscar(usuario) && (buscar_clave(usuario,clave)== false)){
        cout <<"La clave ingresada no coincide"<< endl;
        return false;
    }
    else{
        cout <<"Sesion iniciada con exito"<< endl;
        return true;
    }
}

/*****
*   bool crear_nuevo_usuario
******
*   Esta función verifica 3 condiciones: 
*   1.- Si el usuario está en el arreglo (Mediante la función buscar)
*   2.- Si el usuario no está en el arreglo y el largo de la clave es menor a 8 (Mediante la función buscar) 
*   3.- Finalmente un else para cualquier otro caso, que usa la función insertar.
******
*   Input:
*       string usuario: Es un string que contiene el nombre del usuario a revisar.
*       string clave: Es un string que contiene la clave del usuario a revisar.
******
*   Returns:
*       En caso de que se cumpla la primera condición retorna falso y se imprime por
*       pantalla "El usuario ya se encuentra registrado".
*       En caso de que se cumpla la segunda condición se retorna falso y se imprime por
*       pantalla "La clave debe tener al menos 8 caracteres".
*       En el último caso se retorna true y se imprime por pantalla "Usuario registrado con exito".
*****/
bool Login::crear_nuevo_usuario(string usuario, string clave){
    if (buscar(usuario)){
        cout <<"El usuario ya se encuentra registrado"<< endl;
        return false;
    }
    if ((buscar(usuario)== false) && (clave.length()< 8)){
        cout <<"La clave debe tener al menos 8 caracteres"<< endl;
        return false;
    }
    else{
        insertar(usuario,clave,array_uwu);
        cout <<"Usuario registrado con exito"<< endl;
        return true;
    }
}

/*****
*   bool cambiar_clave
******
*   Esta función verifica 3 condiciones:
*   1.- Si el usuario no está en el arreglo (Mediante la función buscar)
*   2.- Si el usuario está en el arreglo y el largo de la nueva clave es menor a 8 (Mediante la función buscar)
*   3.- Finalmente un else para cualquier otro caso, que usa la función actualizar_clave.
******
*   Input:
*       string usuario: Es un string que contiene el nombre del usuario a revisar.
*       string nueva_clave: Es un string que contiene la nueva clave del usuario a revisar.
******
*   Returns:
*       En caso de que se cumpla la primera condición retorna falso y se imprime por
*       pantalla "El usuario no se encuentra registrado".
*       En caso de que se cumpla la segunda condición se retorna falso y se imprime por
*       pantalla "La clave debe tener al menos 8 caracteres".
*       En el último caso se retorna true y se imprime por pantalla "Clave actualizada con exito".
*****/
bool Login::cambiar_clave(string usuario, string nueva_clave){
    if (buscar(usuario) == false){
        cout <<"El usuario no se encuentra registrado"<< endl;
        return false;
    }
    if (buscar(usuario) == true && nueva_clave.length() < 8){
        cout<<"La clave debe tener al menos 8 caracteres"<<endl;
        return false;
    }
    else{
        actualizar_clave(usuario,nueva_clave);
        cout<<"Clave actualizada con exito"<<endl;
        return true;
    }
}

/*****
*   int h
******
*   Esta función es la función del hashing, la posición de la clave se define como el largo de esta misma.
******
*   Input:
*       string clave: Es el nombre del usuario al que se le realizará el hashing.
******
*   Returns:
*       Se retorna un entero sum, el cual contiene el largo de la "clave".
*****/
int Login::h(string clave){
    int sum;
    sum = clave.length();
    return sum;
}

/*****
*   int p
******
*   Esta función es la función de resolución de colisiones, consiste en sumarle el número de colisiones
*   a el largo de la clave.
******
*   Input:
*       string clave: Es el nombre del usuario al que se le está realizando el hashing.
*       int i: El número de veces que ha colisionado.
******
*   Returns:
*       Se retorna un entero suma, el cual contiene el largo de la "clave" sumado con el número de colisiones.
*****/
int Login::p(string clave, int i){
    int suma;
    suma = clave.length()+i;
    return suma;
}

/*****
*   void insertar
******
*   Esta función inserta un usuario en el hashing cerrado, se incrementa el contador del numero de elementos
*   luego se calcula el factor de carga y se verifica que no sea mayor a 0.7 porque si no se debe llamar a la
*   función hashing2, siguiendo con el código se crea una variable auxiliar de tipo user_struct al que se le asignan
*   en sus campos el usuario y la clave, luego se hace un while ue verifica si la posición pos está vacía, si esto
*   es cierto, entonces se introduce en la posición pos, de lo contrario, se ocupa la resolución de colisiones y
*   se vuelve a evaluar hasta que pueda entrar en la tabla de hashing.
******
*   Input:
*       string& usuario: Es una referencia al usuario que se está insertando, para poder manipularlo.
*       string& clave: Es una referencia a la clave del usuario que se está insertando, para poder manipularla.
*       user_struct* array_uwu: Es un puntero a un arreglo de tipo user_struct que permite modificar los elementos
*       del arreglo.
******
*   Returns:
*       No retorna nada debido a que es de tipo void.
*****/
void Login::insertar(string& usuario, string& clave, user_struct* array_uwu) {
    numero_elementos++;
    factor_carga = (numero_elementos*1.0)/(TAMANIO*1.0);
    if (factor_carga >0.7){
        numero_elementos--;
        hashing2();
    }
    user_struct aux,aux2;
    aux.id = usuario;
    aux.pass = clave;
    int contador_colision = 0;
    int pos = h(usuario) % TAMANIO;
    while (true){
        if (array_uwu[pos].id == ""){
            array_uwu[pos]=aux;
            break;
        }
        contador_colision++;
        pos = (h(usuario)+ p(usuario,contador_colision))%TAMANIO;
    }
}

/*****
*   bool buscar
******
*   Esta función realiza una búsqueda en el arreglo iniciando con un contador de colisiones
*   y se va recalculando la posición a medida que se va buscando, se va evaluando si es que la palabra 
*   está o no en el arreglo.
******
*   Input:
*       string& palabra: Es la referencia a la palabra que se debe buscar en el arreglo.
******
*   Returns:
*       Retorna falso si es que no está en el arreglo y verdadero si es que si se encuentra.
*****/
bool Login::buscar(string& palabra){
    int contador_colision = 0;
    int pos = h(palabra) % TAMANIO;
    while (true){
        if (array_uwu[pos].id == palabra){
            return true;
        }
        contador_colision++;
        pos = (h(palabra)+ p(palabra,contador_colision))%TAMANIO;
        if (array_uwu[pos].id == ""){
            return false;
        }
    }
}

/*****
*   bool buscar_clave
******
*   Esta función realiza una búsqueda en el arreglo al igual que la función buscar, solo que aquí 
*   se va evaluando si es que la clave que recibe es la misma que está  registrada con el usuario.
******
*   Input:
*       string& usuario: Es la referencia a el usuario al que se le verificará si las claves son iguales o no.
*       string& clave: Es la referencia a la clave que se está buscando evaluar.
******
*   Returns:
*       Retorna falso si es que nlas claves no coinciden y retorna true si es que las claves coinciden.
*****/
bool Login::buscar_clave(string& usuario,string& clave){
    int pos = h(usuario)%TAMANIO;
    int colision = 0;
    while (array_uwu[pos].id != usuario){
        colision ++;
        pos = (h(usuario)+ p(usuario,colision))%TAMANIO;
    }
    if (array_uwu[pos].pass == clave){
        return true;
    }
    return false;
}

/*****
*   void actualizar_clave
******
*   Esta función actualiza la clave del usuario en el arreglo, mediante una búsqueda en el arreglo hasta
*   encontrar la posición donde está el usuario y actualizar la clave.
******
*   Input:
*       string& usuario: Es la referencia a el usuario que se le quiere cambiar la clave.
*       string& nueva_clave: Es la referencia a la nueva clave que se quiere para el usuario.
******
*   Returns:
*       No retorna nada debido a que es del tipo void.
*****/
void Login::actualizar_clave(string& usuario,string& nueva_clave){
    int pos = h(usuario)%TAMANIO;
    int colision = 0;
    while (array_uwu[pos].id != usuario){
        colision ++;
        pos = (h(usuario)+ p(usuario,colision))%TAMANIO;
    }
    array_uwu[pos].pass=nueva_clave;
}

/*****
*   void hashing2
******
*   Esta función se llama cuando el factor de carga es mayor a 0.7, lo que hace es duplicar el tamaño del arreglo
*   actualizar el factor de carga y luego introducir los elementos en el nuevo arreglo que se crea con memoria 
*   dinámica, se hace delete en el antiguo y se re-define como el nuevo arregló que se creó.
******
*   Input:
*       No requiere de parámetros.
******
*   Returns:
*       No retorna nada debido a que es del tipo void.
*****/
void Login::hashing2() {
    int limite = TAMANIO;
    TAMANIO = TAMANIO * 2;
    int numero_elementos = 0;
    factor_carga = (float)numero_elementos/TAMANIO;
    user_struct* nuevoArreglo = new user_struct[TAMANIO];
    for (int i =0;i<limite;i++){
        if(array_uwu[i].id != ""){
            insertar(array_uwu[i].id,array_uwu[i].pass,nuevoArreglo);
        }
    }
    delete[] array_uwu;
    array_uwu = nuevoArreglo;
}

/*****
*   void INICIAR_SESION
******
*   Esta función llama a la función iniciar_sesión mediante la clase. (Se llama desde el main)
******
*   Input:
*       Login& clase: Referenciade la clase Login que se usa para poder llamar la función iniciar_sesion.
*       string user: Usuario con el que se quiere iniciar sesión en la función iniciar_sesion.
*       string password: Contraseña del usuario que iniciará sesión en la función iniciar_sesion.
******
*   Returns:
*       No retorna nada debido a que es del tipo void.
*****/

void INICIAR_SESION(Login& clase, string user, string password){
    clase.iniciar_sesion(user,password);
}

/*****
*   void REGISTRAR
******
*   Esta función llama a la función crear_nuevo_usuario mediante la clase. (Se llama desde el main)
******
*   Input:
*       Login& clase: Referenciade la clase Login que se usa para poder llamar la función crear_nuevo_usuario.
*       string user: Nombre de usuario con el que se quiere crear la cuenta en la función crear_nuevo_usuario.
*       string password: Contraseña del usuario que se creará una cuenta en la función crear_nuevo_usuario.
******
*   Returns:
*       No retorna nada debido a que es del tipo void.
*****/  
void REGISTRAR(Login& clase, string user, string password){
    clase.crear_nuevo_usuario(user,password);
}

/*****
*   void ACTUALIZAR
******
*   Esta función llama a la función cambiar_clave mediante la clase. (Se llama desde el main)
******
*   Input:
*       Login& clase: Referenciade la clase Login que se usa para poder llamar la función cambiar_clave.
*       string user: Usuario al que se le va a actualizar la contraseña en la función cambiar_clave.
*       string password: Contraseña nueva del usuario que se usará en la función cambiar_clave.
******
*   Returns:
*       No retorna nada debido a que es del tipo void.
*****/  
void ACTUALIZAR(Login& clase, string user, string password){
    clase.cambiar_clave(user,password);
}

/*****
*   void FINALIZAR
******
*   Esta función finaliza el programa. (Se llama desde el main)
******
*   Input:
*       No requiere de ningún parámetro.
******
*   Returns:
*       No retorna nada debido a que es del tipo void.
*****/  
void FINALIZAR(){
    exit(0);
}