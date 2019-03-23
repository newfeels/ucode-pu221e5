
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
#include <windows.h>
#include <string.h>

using namespace std;

const int MAX_LONG= 200;
const int NUM_CLOTHES=50;
const int NUM_COL=15;
const char PRENDAS[NUM_CLOTHES][MAX_LONG]={ //prendas que se pueden procesar
    "pants","trainers","shoes","trousers","t-shirt", "shorts","short", "jacket","backpack",
    "ball","gloves","football","sunglasses","socks","sweatshirts","tights","dresse","dresses"
    "skirt"
};
const char COLORS[NUM_COL][MAX_LONG]={//colores de ropa
        "blue","grey","black","white","red","pink","green","multicolour",
        "orange","purple","turquoise","yellow","beige","brown","gold"
};
const char INICIO_URL[MAX_LONG]="start https://www.adidas.co.uk/search?q=";
const char PRECOLOR[MAX_LONG]="%20";
//
bool encontrarPrenda(const char nombreFichero[],char prenda[],char color[],bool& estaColor){
    ifstream f(nombreFichero);
    bool prendaEncontrada = false;
    estaColor=false;
    if (f.is_open()){
        char prendaLeida[MAX_LONG];
        

        f.getline(prendaLeida,MAX_LONG,'\n');
        cout<<"primera lectura";
        while(!f.eof()){
            cout<<prendaLeida<<endl; 
            if (!prendaEncontrada){
                
               for(int i =0; i < NUM_CLOTHES;i++){
                     if(strcmp(PRENDAS[i],prendaLeida)==0&&!prendaEncontrada){
                        prendaEncontrada=true;
                        strcpy(prenda,prendaLeida);
                        cout<<"encontrada prenda"<<endl;
                    }
                }
                
            }
            else{
                cout<<"buscamos color"<<endl;
                for(int i = 0; i<NUM_COL; i++){
                     
                    if (strcmp(COLORS[i],prendaLeida)==0){
                        strcpy(color,prendaLeida);
                        estaColor=true;
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

int main(int numArg, char* args[]){
    char etiquetasFoto[MAX_LONG];
    strcpy(etiquetasFoto,args[1]);
    cout<<etiquetasFoto<<endl;
    char prenda [MAX_LONG];
    char color[MAX_LONG];
    bool estaColor;
    if (encontrarPrenda(etiquetasFoto, prenda, color,estaColor)){
        char link [MAX_LONG];
        cout<<  prenda;

        strcpy(link,INICIO_URL);
        strcat(link,prenda);
        if(estaColor){
            cout << color ;
            strcat(link,PRECOLOR);
            strcat(link,color);
        }
        system(link);
        system("pause");
        
    }
    else{
        cerr << "No se pudo abrir el archivo " << etiquetasFoto << endl;

    }
    return 0;
}


