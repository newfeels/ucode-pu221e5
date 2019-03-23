#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
#include <windows.h>
#include <string.h>

using namespace std;

const int MAX_LONG= 200;
const int NUM_CLOTHES=25;
const int NUM_COL=15;
const char PRENDAS[NUM_CLOTHES][MAX_LONG]={ //prendas que se pueden procesar
    "pants","trainers","shoes","trousers","t-shirt", "shorts","short", "jacket","backpack",
    "ball","gloves","football","sunglasses","socks","sweatshirts","tights","dresse","dresses",
    "skirt"
};
const char COLORS[NUM_COL][MAX_LONG]={//colores de ropa
        "blue","grey","black","white","red","pink","green","multicolour",
        "orange","purple","turquoise","yellow","beige","brown","gold"
};
const char INICIO_URL[MAX_LONG]="https://www.adidas.co.uk/search?q=";
const char PRECOLOR[MAX_LONG]="%20";
const char POSTGEN[3]="-";
const char GENDER[2][MAX_LONG]={
    "men","women"
};
//
bool encontrarPrenda(const char nombreFichero[],char prenda[],char gen[],bool& estaGen){
    ifstream f(nombreFichero);
    bool prendaEncontrada = false;
    estaGen=false;
    if (f.is_open()){
        char prendaLeida[MAX_LONG];
        f.getline(prendaLeida,MAX_LONG,'\n');
        while(!f.eof()){ 
            if (!prendaEncontrada){
               for(int i =0; i < NUM_CLOTHES;i++){
                     if(strcmp(PRENDAS[i],prendaLeida)==0&&!prendaEncontrada){
                        prendaEncontrada=true;
                        strcpy(prenda,prendaLeida);
                    }
                }
                
            }
            else{
                for(int i = 0; i<2; i++){   
                    if (strcmp(GENDER[i],prendaLeida)==0){
                        strcpy(gen,prendaLeida);
                        estaGen=true;
                        return true;
                    }
                }
            }
            
            f>>prendaLeida;
            
            
        }
        f.close();
        
    }
    else{
        cerr<< "no se abre "<< nombreFichero<<endl;
    }

    return prendaEncontrada;
}

int main(){
    char etiquetasFoto[MAX_LONG]="datos.txt"
    char prenda [MAX_LONG];
    char gen[MAX_LONG];
    bool estaGen;
    if (encontrarPrenda(etiquetasFoto, prenda, gen,estaGen)){
        char link [MAX_LONG];
        strcpy(link,INICIO_URL);
        if(estaGen){
            
            strcat(link,gen);
            strcat(link,POSTGEN);
        }
        strcat(link,prenda);
        ofstream f(url.txt);
        if(f.is_open()){
            f<< link<<endl;
        }
        else{
            cerr<< "No se pudo crear el archivo "<< endl;
        }
        
    }
    else{
        cerr << "No se pudo abrir el archivo " << etiquetasFoto << endl;

    }
    return 0;
}



