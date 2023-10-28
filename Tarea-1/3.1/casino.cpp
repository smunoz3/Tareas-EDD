#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int const SERV_DESAYUNO = 0;
int const SERV_ALMUERZO = 1;
int const SERV_ONCE = 2;
int const SERV_CENA = 3;

struct SaldoColaborado{  
    char rut [11];
    int saldo_desayuno;
    int saldo_almuerzo;
    int saldo_once;
    int saldo_cena;
};

/*****
* bool puedeConsumir
******
* La función consulta el rut de un colaborador en el archivo binario para luego ver si tiene el dinero para comprar el servicio
* si tiene dinero lo registra en un archivo ".txt" y retorna true, si no tiene dinero no se le registra en el archivo y retorna falso.
******
* Input:
*   char* rut: rut es un puntero que apunta a una cadena de caracteres.
*   int servicio: servicio es un entero, que dependiendo de su valor es lo que significa, si vale 0 se refiere al desayuno
*   si vale 1 se refiere al almuerzo, si vale 2 se refiere a la cena y si vale 3 se refiere a la cena.
*   string consumos_dias: consumos_dias es un string
*   representa una cadena de caracteres que en este caso es el nombre del archivo sobre el cual queremos escribir.
******
* Returns:
*   bool, Esta función retorna true or false, retorna true si es que el colaborador tiene salgo para recibir ticket de alimentación
*   de lo contrario retorna falso.
*****/
bool puedeConsumir(char* rut, int servicio, string consumos_dia){
    bool retorno;
    retorno = false;
    string rut_string = rut;

    fstream file_binario;
    file_binario.open("saldos.bin",ios::binary| ios::in);
    if (!file_binario.is_open()){
        cout<<"Error \n";exit(1);
    }
    
    ofstream file; 
    file.open(consumos_dia+".txt",ios::app);
    if (!file.is_open()){
        cout<<"Error \n";exit(1);
    }
        
    string comidas_array [4];
    comidas_array[0]="DESAYUNO";comidas_array[1]="ALMUERZO";comidas_array[2]="ONCE";comidas_array[3]="CENA";
    
    int saldo_size;
    file_binario.read((char*)&saldo_size,sizeof(int));

    SaldoColaborado saldo_lectura [saldo_size];
    for (int i=0;i<saldo_size;i++){
        file_binario.read((char*)&saldo_lectura[i],sizeof(SaldoColaborado));
        if (rut_string == saldo_lectura[i].rut){
            if (servicio == SERV_DESAYUNO ){
                if (saldo_lectura[i].saldo_desayuno>0){
                    retorno = true;
                    file <<rut << " " + comidas_array[servicio] + "\n";
                }
            }
            else if (servicio == SERV_ALMUERZO ){
                if (saldo_lectura[i].saldo_almuerzo>0){
                    retorno = true;
                    file <<rut << " " + comidas_array[servicio] + "\n";
                }
            }
            else if (servicio == SERV_ONCE ){
                if (saldo_lectura[i].saldo_once>0){
                    retorno = true;
                    file <<rut << " " + comidas_array[servicio] + "\n";
                }
            }
            else if (servicio == SERV_CENA ){
                if (saldo_lectura[i].saldo_cena>0){
                    retorno = true;
                    file <<rut << " " + comidas_array[servicio] + "\n";
                }
            } 
        }
    }
    cout<<retorno<<endl;
    file.close();
    file_binario.close();
    return retorno;
};

int main(){
    return 0;
}