#include <iostream>
#include <string>
#include "exp.hpp"

using namespace std;

int main() {
    tABB treeBB;
    int postes_encendidos = 0;

    while (true) {
        string comando;
        cin >> comando;

        if (comando == "ENCENDER") {
            int i;
            cin >> i;
            ENCENDER(treeBB, i, postes_encendidos);
        } else if (comando == "CUANTOS_ENCENDER") {
            int i;
            cin >> i;
            CUANTOS_ENCENDER(treeBB, i, postes_encendidos);
        } else if (comando == "PARAR_PROGRAMA") {
            PARAR_PROGRAMA(postes_encendidos);
        }
    }

    return 0;
}

// g++ exp.cpp exp.hpp -o exp -Wall
// ./exp

// cd 2

//Se añade -g para ocupar el valgrind
// g++ -g Luces_por_arreglar.cpp -g Luces_por_arreglar.hpp -o Luces -Wall
// ./Luces
//valgrind --leak-check=yes ./Luces

//Se añade -g para ocupar el valgrind
//g++ -g Secuancia_de_Nucleotidos.cpp  -g Secuancia_de_Nucleotidos.hpp -o nucleogods -Wall
//./nucleogods < secuencias-nucleotidos.txt
//valgrind --leak-check=yes ./nucleogods