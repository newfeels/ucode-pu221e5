#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <windows.h>
using namespace std;

const int MAX_LONG_WORD=20;
const int MAX_LONG_FICHERO=120;


bool asignar (const char nombre_fichero[], char ropas[],char color[]){
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


}
int main (){
    char primera[MAX_LONG_FICHERO]="start https://www.adidas.co.uk/search?q=";
    char color[MAX_LONG_WORD];char ropa[MAX_LONG_WORD];
    char tercera[MAX_LONG_FICHERO]="&searchcolour=";

    char nombre_fichero[MAX_LONG_FICHERO]="ropas.txt";
    if (asignar(nombre_fichero,ropa,color)){
         strcat(primera,ropa);
         strcat(tercera, color);
         strcat(primera,tercera);
         cout << primera << endl;
         system(primera);
         system("pause");

    }
    else{
        cerr << "something bad has happenned" << endl;
    }
    return 0;
}
