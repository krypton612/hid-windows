#include <cstring>
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
string ngrok_return(){
    string ngrok_complete;
    char ngrok_work[100];
    ifstream ngrok; 
    ngrok.open("../server/.ubicador", ios::in);
    if (ngrok.fail()) {
        cout<<" Error su servidor esta muerto...";
        exit(1);
    }
    while (!ngrok.eof()) {
        getline(ngrok,ngrok_complete);
        break;
    }
    return ngrok_complete;
}

