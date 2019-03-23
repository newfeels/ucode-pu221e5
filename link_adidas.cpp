#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <windows.h>
using namespace std;

<<<<<<< HEAD
const int MAX_LONG_WORD=15;
const int MAX_LONG_FICHERO=30;
struct ropa {
    char clothes[MAX_LONG_WORD];
    char colours[MAX_LONG_WORD];
};

bool asignar (char nombre_fichero[], ropa &ropas){
=======
const int MAX_LONG_WORD=20;
const int MAX_LONG_FICHERO=120;


bool asignar (const char nombre_fichero[], char ropas[],char color[]){
>>>>>>> 82225dde171fbc2a8fb0250ea71cd3b03445d293
    bool abierto = false;
    ifstream f;
    f.open(nombre_fichero);
    if (f.is_open()){
        f >> ropas;
        if (!f.eof()){
            f.ignore(15, '\n');
            f >> color;
            if (!f.eof()){
                abierto = true;
            }
        }
    }
    f.close();
    return abierto;
<<<<<<< HEAD
=======


>>>>>>> 82225dde171fbc2a8fb0250ea71cd3b03445d293
}


int main (){
<<<<<<< HEAD
    ropa ropas;
    char nombre_fichero[MAX_LONG_FICHERO] = "ropas.txt";
    if (asignar(nombre_fichero,ropas)==true){
        cout << "https://www.adidas.co.uk/search?q=" << ropas.clothes << "&searchcolour=" << ropas.colours << endl;
=======
    char primera[MAX_LONG_FICHERO]="start https://www.adidas.co.uk/search?q=";
    char color[MAX_LONG_WORD];char ropa[MAX_LONG_WORD];
    char tercera[MAX_LONG_FICHERO]="%20";

    char nombre_fichero[MAX_LONG_FICHERO]="ropas.txt";
    if (asignar(nombre_fichero,ropa,color)){
         strcat(primera,ropa);
         strcat(tercera, color);
         strcat(primera,tercera);
         cout << primera << endl;
         system(primera);
         system("pause");

>>>>>>> 82225dde171fbc2a8fb0250ea71cd3b03445d293
    }
    else{
        cerr << "something bad has happenned" << endl;
    }
    return 0;
}
