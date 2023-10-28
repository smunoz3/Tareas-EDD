#include <iostream>
#include <string>
#include "problema2.hpp"

using namespace std;

int main() {
    //Crea el arbol
    tABB treeBB;
    //Se definen nuevas variables que serán utilizadas más adelante
    int postes_encendidos = 0;
    string comando;
    int i;
    //Ver cual comando se realiza, y hacer los llamados
    //a las funciones correspondientes
    while (true) {
        cin >> comando;
        if (comando == "ENCENDER") {
            cin >> i;
            ENCENDER(treeBB,i,postes_encendidos);
        }
        else if (comando == "CUANTOS_ENCENDER") {
            cin >> i;
            CUANTOS_ENCENDER(treeBB,i);
        }
        else if (comando == "PARAR_PROGRAMA") {
            PARAR_PROGRAMA(postes_encendidos);
            break;
        }
    }
    return 0;
}
