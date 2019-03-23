//BORRADOR
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <windows.h>
using namespace std;

const int MAX_LONG_WORD=15;
const int MAX_LONG_FICHERO=30;
struct ropa {
    char clothes[MAX_LONG_WORD];
    char colours[MAX_LONG_WORD];
    
};

bool asignar (char nombre_fichero[], ropa ropas){
    bool abierto = false;
    ifstream f;
    f.open(nombre_fichero);
    if (f.is_open()){
        f >> ropas.clothes;
        if (!f.eof()){
            f.ignore(15, '\n');
            f >> ropas.colours;
            if (!f.eof()){
                abierto = true;
        }
    }
    return abierto;
    f.close;

}
int main (){
    char primera[MAX_LONG_FICHERO]="https://www.adidas.co.uk/search?q=";
    
    char tercera[MAX_LONG_FICHERO]="&searchcolour=";
    
    char nombre_fichero[MAX_LONG_FICHERO]="";
    if (asignar(nombre_fichero,ropa ropas)==true){
         strcat(primera,ropas.clothes);
         strcat(segunda, ropas.colours);
         strcat(primera,segunda);
         system(primera);

    }
    else{
        cerr << "something bad has happenned" << endl;
    }
    return 0;
}