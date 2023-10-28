#include <iostream>
#include <string>
#include "Comandos.hpp"

using namespace std;

int main() {

    tColaP cola;

    bool flag = true;
    string comando;
    string id;
    int priority;
    string instruccion;
    int n;
    int comandos_enviados;
    int comandos_generados;

    while (flag){
        cin>>comando;

        if (comando == "PUSHCOMMAND"){
            cin>>id;
            cin>>priority;
            getline(cin,instruccion);

            cola.insertColaP(id,priority,instruccion);
            cout << cola.sizeColaP()<< " " << "PENDING"<< endl;

            comandos_generados++;
        }
        
        if (comando == "GET"){
            cin>>n;

            if(cola.sizeColaP()>0){

                cout<<n<<" ";

                string arr_comandos[cola.sizeColaP()];
                int limite = cola.sizeColaP();

                for (int i=0; i<limite; i++){
                    heap_node nodo;
                    nodo = cola.findMax();
                    arr_comandos[i]= nodo.instruction;
                    cout<<nodo.id<<" ";
                    cola.removeMax();
                }
                cout<<"\n";

                for (int i=0; i<limite; i++){
                    cout<<arr_comandos[i]<<endl;
                    comandos_enviados++;
                }
            }else{
                cout<<"0"<<endl;
            }
        }
        
        if (comando == "TERMINATE"){
            cout<<comandos_enviados<<" "<<"SENT"<<" "<<comandos_generados<<" "<<"CREATED"<<endl;
            flag=false;
        }
    }


    return 0;
}

