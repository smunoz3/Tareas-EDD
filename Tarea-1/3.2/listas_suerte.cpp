#include <iostream>
#include <string>

using namespace std;

int p;

struct Persona {
    string nombre;
    char fecha[11];
    int tamanio_tarjeta;
    int* tarjeta;
    bool quiere_intercambiar;
};


/*****
* int* comprar Tarjeta
******
* La función comprarTarjeta genera una tarjeta del tamaño del nombre en la cual influye el nombre y el dia.
* se hace con un for para recorrer la tarjeta e ir asignandole los valores de la tarjeta.
******
* Input:
*   string nombre: nombre es un string el cual contiene el nombre de la persona que quiere comprar la tarjeta de la suerte.
*   int dia: dia es un entero el cual contiene el dia en el que se compra la tarjeta de la suerte. 
*   int& m: m es una referencia a un entero, es el tamaño del arreglo que se va a retornar.
******
* Returns:
*   Se retorna un arreglo de enteros el cual tiene el mismo largo que el nombre ingresado, en este arreglo, en la posicion i estará el valor que corresponde a la operación nombre[i]%dia. 
*****/

int* comprarTarjeta (string nombre, int dia, int& m){
    m = nombre.length();  
    int* tarjeta= new int[m];
    for (int i=0; i<m; i++){
        tarjeta[i]= nombre[i]%dia;
    }
    return tarjeta;
}


/*****
* void intercambiarTarjeta
******
* La función intercambiarTarjeta recibe dos punteros a structs de tipo Persona y permuta sus tarjetas
* creando dos punteros temporales de tipo entero a las tarjetas de cada persona
* tambien un puntero de tipo entero al tamaño de la persona
* y luego estos se intercambian los tamaños y se le asignan las tarjetas a los punteros previamente mencionados.
******
* Input:
*   Persona* p1: Variable p1 del tipo puntero a el struct Persona, esto me da una persona.
*   Persona* p2: Variable p2 del tipo puntero a el struct Persona, esto me da otra persona.
******
* Returns:
*   No se retorna nada ya que la función es de tipo void.
*****/

void intercambiarTarjeta(Persona* p1, Persona* p2) {     
    int* temp = p1->tarjeta; 
    int* temp_2 = p2->tarjeta;
    int temp_tam = p1->tamanio_tarjeta; 
    p1->tamanio_tarjeta = p2->tamanio_tarjeta; 
    p2->tamanio_tarjeta = temp_tam;
    p1->tarjeta = temp_2;
    p2->tarjeta = temp;
}

/*****
* int puntaje
******
* La función puntaje recibe una persona y le da el puntaje a esa persona sumandolo en un ciclo for
* mediante la fórmula proporcionada en la guía.
******
* Input:
*   Persona* p1: Variable p1 del tipo puntero a el struct Persona.
******
* Returns:
*   Se retorna un valor entero que representa el puntaje de la persona.
*****/

int puntaje(Persona* p1){
    int puntaje;
    puntaje = 0;
    for (int i=0; i<p1->tamanio_tarjeta; i++){
        puntaje += (p1->tarjeta[i])*(p1->fecha[i%10]);
    }
    return puntaje;
}

/*****
* Persona* unDia
******
* La función unDIa primero genera una tarjeta a cada persona, llamando a la funcion comprarTarjeta
* luego se crean dos arreglos para guardar las personas que quieren intercambiar, y las que no
* luego se intercambian las tarjeta en el arreglo de personas que quieren intercambiar usando la funcion intercambiarTarjeta
* luego se crea otro arreglo, y se unen las personas que no quieren intercambiar y las que ya intercambiaron tarjetas
* este arreglo se pasa a un ciclo for en el cual se va llamando a la funcion puntaje
* para asi sacar el ganador
******
* Input:
*   Persona* personas: Variable personas del tipo puntero a el struct Persona, el cual tiene personas dentro.
*   int dia: El dia en el que se compra la tarjeta para cada personas.
******
* Returns:
*   Se retorna la persona que obtuvo más puntaje en las tarjetas.
*****/

Persona* unDia(Persona* personas, int dia){  
    for(int i=0; i<p; i++){
        int largo_nombre;
        largo_nombre = personas[i].nombre.length();
        personas[i].tarjeta = comprarTarjeta(personas[i].nombre, dia, largo_nombre); //Aca se le da una tarjeta a cada persona
    }
    Persona* personas_intercambio = new Persona[p];
    Persona* personas_no_intercambio = new Persona[p];
    int c =0;
    int no_cambio = 0;
    for (int i= 0; i<p; i++){
        if (personas[i].quiere_intercambiar == 1){
            personas_intercambio[c].tarjeta = personas[i].tarjeta;
            personas_intercambio[c].quiere_intercambiar = personas[i].quiere_intercambiar;
            personas_intercambio[c].tamanio_tarjeta = personas[i].tamanio_tarjeta;
            personas_intercambio[c].nombre = personas[i].nombre;
            for (int j=0;j<11;j++){
                personas_intercambio[c].fecha[j] = *personas[j].fecha;
            }
            c++;
        } else{
            personas_no_intercambio[no_cambio].tarjeta = personas[i].tarjeta;
            personas_no_intercambio[no_cambio].quiere_intercambiar = personas[i].quiere_intercambiar;
            personas_no_intercambio[no_cambio].tamanio_tarjeta = personas[i].tamanio_tarjeta;
            personas_no_intercambio[no_cambio].nombre = personas[i].nombre;
            for (int j=0;j<11;j++){
                personas_no_intercambio[no_cambio].fecha[j] = *personas[j].fecha;
            }
            no_cambio++;
        }
    }
    //intercambiar tarjetas

    for (int i=1;i<=c;i++){
 
        int min = (personas_intercambio[i-1].tamanio_tarjeta <personas_intercambio[i].tamanio_tarjeta) ? personas_intercambio[i-1].tamanio_tarjeta : personas_intercambio[i].tamanio_tarjeta;
        for (int j=0;j<min;j++){
            if (personas_intercambio[i-1].tarjeta[j]==personas_intercambio[i].tarjeta[j]){
                intercambiarTarjeta(&personas_intercambio[i-1] , &personas_intercambio[i] );
                personas_intercambio[i-1].quiere_intercambiar = false;
            }
        }
    }
    int x =0;
    int y = 0;
    Persona* personas_total = new Persona[p];
    for (int i =0;i<p;i++){
        if (i<c){    
            personas_total[i] = personas_intercambio[x];
            x ++;
        }
        else{
            personas_total[i] = personas_no_intercambio[y];
            y++;   
        }
    }

    Persona* ganador;
    int puntos_max =0;
    for (int i=0;i<p;i++){
        int a = puntaje(&personas_total[i]);
        if(a>puntos_max){
            puntos_max = a;
            ganador = &personas_total[i];
        }

    } 

    return ganador;
}

/*****
* void variosDias
******
* La función variosDias llama a la funcion unDia la cual retorna el ganador
* luego imprime por pantalla el nombre, fecha de nacimiento y puntaje de dicho ganador.
* Input:
*   Persona* personas: Variable personas del tipo puntero a el struct Persona, el cual tiene personas dentro.
*   int cant_dias: Variable cant_dias del tipo entero que tiene la cantidad de dias yotales a realizar.
******
* Returns:
*   No se retorna nada ya que la función es de tipo void.
*****/

void variosDias (Persona* personas, int cant_dias){ 
    Persona* ganador;
    for (int i=1; i<=cant_dias; i++){
        ganador = unDia(personas,i);
        cout << ganador->nombre << " " << ganador->fecha << " " << puntaje(ganador) << endl;
    } 
}


int main(){
    return 0;
}