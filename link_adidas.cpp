//BORRADOR
#include <iostream>
#include <fstream>
using namespace std;

const int MAX_LONG_WORD=15;
const int MAX_LONG_FICHERO=30;
struct ropa {
    char clothes[MAX_LONG_WORD];
    char colours[MAX_LONG_WORD];
};


bool asignar (char nombre_fichero[], ropa &ropas){
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
    }
    f.close();
    return abierto;
}


int main (){
    ropa ropas;
    char nombre_fichero[MAX_LONG_FICHERO] = "ropas.txt";
    if (asignar(nombre_fichero,ropas)==true){
        cout << "https://www.adidas.co.uk/search?q=" << ropas.clothes << "&searchcolour=" << ropas.colours << endl;
    }
    else{
        cerr << "something bad has happenned" << endl;
    }
    return 0;
}
