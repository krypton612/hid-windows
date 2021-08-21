#include <iostream>
#include <curses.h>
using namespace std;
void info();
int serverCurses(){
    int tecla;
    /* Inicializar la operacion de ncurses */ 
    initscr ();
    printw (" [!] Si decea Salir precione Y si usara server vnc precione X  [!] ...");
    /* Recibir teclas en modo sin buferes (es decir, sin esperar a que se                    * pulse ENTER) */
    cbreak ();
    tecla = getch ();
    endwin ();
    info();
    return tecla;
}
void info(){
    system("neofetch --config ../tmp/config.conf --ascii_distro windows7");    
}
int main(){
    serverCurses();
    return 0;
}
