#include <iostream>
#include <fstream>
#include <string>
#include "problema1.hpp" 
using namespace std;

int main() {
    //Se abre el archivo de entrada.txt
    ifstream txt_entrada;
    txt_entrada.open("secuencias-nucleotidos.txt");
    if (!txt_entrada.is_open()) {
        cout << "Error al abrir el archivo" << endl;
        return -1;
    }
    //Se abre el archivo de salida.txt
    ofstream txt_salida;
    txt_salida.open("secuencias-reconstruidas.txt");
    if (!txt_salida.is_open()) {
        cout << "Error al abrir el archivo" << endl;
        return -1;
    }
    //Se define la lista enlazada.
    tListaNucleotidos lista = tListaNucleotidos(); 
    //Se definen variables y se les asigna valor por el txt de entrada.
    int tam_secuencia;
    string secuencia_base;
    int num_secuencias;
    txt_entrada >> tam_secuencia;
    txt_entrada >> secuencia_base;
    txt_entrada >> num_secuencias;
    //Se definen nuevas variables que serán utilizadas más adelante
    int modificaciones;
    string operacion;
    int posicion;
    char nucleotido;
    char letra;
    string lista_modificada;

    for(int i=0; i<num_secuencias; i++) {
        txt_entrada >> modificaciones;
        //Recorrer el string secuencia_base y hacer inserciones en la lista
        for(int k=0;k<tam_secuencia;k++) {
        letra = secuencia_base[k];
        lista.Inserciones(k,letra);
        }
        for(int j=0; j<modificaciones; j++) {
            txt_entrada >> operacion;
            if(operacion == "INSERTAR") {
                txt_entrada >> posicion;
                txt_entrada >> nucleotido;
                lista.Inserciones(posicion,nucleotido);
            }else if(operacion == "INTERCAMBIAR") {
                txt_entrada >> posicion;
                txt_entrada >> nucleotido;
                lista.Intercambios(posicion,nucleotido);
            }else if(operacion == "BORRAR") {
                txt_entrada >> posicion;
                lista.Borrados(posicion);
            }
        }
        //Recorrer la lista y guardarla en un string
        for(int a=0; a<lista.size_ListaNucleotidos(); a++) {
            lista_modificada = lista_modificada + lista.InfoNodoActual(a);
        }
        //Guardar la lista en el archivo
        txt_salida << lista_modificada << endl;
        lista_modificada = "";
        //Borrar los elementos de la lista para que quede vacia
        lista.BorrarDatos();
    }
    txt_salida.close();
    txt_entrada.close();
    return 0;
}
