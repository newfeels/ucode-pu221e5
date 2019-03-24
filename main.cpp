#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
#include <string.h>

using namespace std;

const int MAX_LONG= 200;                            //numero maximo de caracteres
const int NUM_CLOTHES=25;                           // tamaño de la base de datos de prendas
const int NUM_COL=15;                               // tamaño de la base de datos de colores
const char PRENDAS[NUM_CLOTHES][MAX_LONG]={         //prendas que se pueden procesar
    "pants","trainers","shoe","shoes","trousers","t-shirt", "shorts","short", "jacket","backpack",
    "ball","gloves","football","sunglasses","socks","sweatshirts","tights","dresse","dresses",
    "skirt"
};
const char COLORS[NUM_COL][MAX_LONG]={              //colores de ropa
        "blue","grey","black","white","red","pink","green","multicolour",
        "orange","purple","turquoise","yellow","beige","brown","gold"
};
const char INICIO_URL[MAX_LONG]="https://www.adidas.co.uk/search?q=";//pagina principal de adidas
const char PRECOLOR[MAX_LONG]="%20";                //codigo de colores
const char POSTGEN[3]="-";
const char GENDER[2][MAX_LONG]={                    //genero
    "men","women"
};
//pre: prenda y gen tienen MAX_LONG componentes
//post :si existe una o mas etiqueta en <nombreFichero> perteneciente a PRENDA, prenda toma
//ese valor, si se encuentra esta y aparece una etiqueta de genero esta se guarda en gen, y esta,Gen
//toma valor true, si no este es false, devuelve true si se ha encotrado una etiqueta que pertenece a
//PRENDA en nombreFichero y false si no se ha encontrado o no se pudo leer
bool encontrarPrenda(const char nombreFichero[],char prenda[],char gen[],bool& estaGen){
    ifstream f(nombreFichero);//abres el fichero
    bool prendaEncontrada = false;
    estaGen=false;

    if (f.is_open()){
        char prendaLeida[MAX_LONG];
        f.getline(prendaLeida,MAX_LONG,'\n');       //primera lectura

        while(!f.eof()){                            //mientras sigua habiendo etiquetas
            if (!prendaEncontrada){
               for(int i =0; i < NUM_CLOTHES;i++){  //buscas prendas entre las etiquetas
                     if(strcmp(PRENDAS[i],prendaLeida)==0&&!prendaEncontrada){
                        prendaEncontrada=true;
                        strcpy(prenda,prendaLeida);
                    }
                }
            }
            else{
                for(int i = 0; i<2; i++){           //buscas genero entre las etiquetas
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

// pre:..
//post: se ha intentado abrir un achivo "datos.txt" con el formato <etiqueta>{"/n" <etiqueta>},
//si se ha abierto se busca en el si contien una linea igual a algun componente de PRENDAS,
//si se encuentra busca una linea igual a algun componente de
int main(){
    char etiquetasFoto[MAX_LONG]="datos.txt";   //archivo donde se guardan las etiquetas
    char prenda [MAX_LONG];
    char gen[MAX_LONG];
    bool estaGen;
    char link [MAX_LONG]=" ";                   // creamos un vector para guardar el link que vamos a crear

    if (encontrarPrenda(etiquetasFoto, prenda, gen,estaGen)){
        strcpy(link,INICIO_URL);

        if(estaGen){

            strcat(link,gen);
            strcat(link,POSTGEN);
        }
        strcat(link,prenda);
    }

    ofstream f("url.txt");                      //creas un archivo con el link

    if(f.is_open()){
        f<< link<<endl;
    }

    f.close();
    return 0;
}
