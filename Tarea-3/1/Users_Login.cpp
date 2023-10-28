#include <iostream>
#include <string>
#include "Users_Login.hpp"

using namespace std;

int main() {
    Login clase; 
    while (true) {
        string comando;
        cin >> comando;
        if (comando == "INICIAR_SESION") {
            string user,password;
            cin >> user;
            cin >> password;
            INICIAR_SESION(clase, user, password);
        } 
        else if (comando == "REGISTRAR") {
            string user,password;
            cin >> user;
            cin >> password;
            REGISTRAR(clase, user, password);
        }
        else if (comando == "ACTUALIZAR") {
            string user,password;
            cin >> user;
            cin >> password;
            ACTUALIZAR(clase, user, password);
        }
        else if (comando == "FINALIZAR") { 
            FINALIZAR();
        }
    }
    return 0;
}