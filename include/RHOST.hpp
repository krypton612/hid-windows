#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
void initArp(){
    system("arp > ../wind7-eternal/tabla.arp");
}
string coulRHOST(int posicion){
    string RHOST;
    ifstream archivo;
    bool interp;
    archivo.open("../wind7-eternal/tabla.arp", ios::in);
    int aux=1;
    while(!archivo.eof()){
        getline(archivo, RHOST);
        if(aux==posicion){
            archivo>>RHOST;
            
            return RHOST;
        }
        aux=aux+1;
        // Esto imprime siertas partes del codigo qr
    }
    archivo.close();
    return "Error";

}
