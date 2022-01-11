#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include "rlutil.h"
///ALUMNOS: MANUEL NAHUN FERNANDEZ FRAGA, MACARENA MARQUEZ

using namespace rlutil;
using namespace std;

#include "Prototipos.h"
#include "Clases.h"
#include "Funciones.h"
#include "SubMenu.h"


int main(){
int posx=0;
hidecursor();
system("cls");
    while(true){
        locate(33,8+posx);
        cout<<(char)62;
        locate(32,8+posx);
        cout<<(char)62<<endl;
        locate(35,7);
        cout<<"-------------El Bolson------------"<<endl;
        locate(35,8);
        cout<<"1. Articulos"<<endl;
        locate(35,9);
        cout<<"2. Ventas"<<endl;
        locate(35,10);
        cout<<"3. Clientes"<<endl;
        locate(35,11);
        cout<<"4. Proveedores"<<endl;
        locate(35,12);
        cout<<"0. Salir"<<endl;
        locate(35,13);
        cout<<"-----------------------------------"<<endl;

            switch(getkey()){
            case 14:
                    locate(33,8+posx);
                    cout<<" ";
                    locate(32,8+posx);
                    cout<<" "<<endl;
                    posx--; //Arriba
                    if(posx<0){posx=0;}
                break;
            case 15:
                    locate(33,8+posx);
                    cout<<" ";
                    locate(32,8+posx);
                    cout<<" "<<endl;
                    posx++; //Abajo
                    if(posx>4){posx=4;}
                break;
            case 1: //enter
                switch(posx){
                case 0:
                        menu_articulo();
                    break;
                case 1:
                        menu_ventas();
                    break;
                case 2:
                        menu_cliente();
                    break;
                case 3:
                        menu_proveedor();
                    break;
                case 4:
                        system("cls");
                        cout<< "Gracias por usar nuestro programa."<<endl;
                        return 0;
                    break;
                default:
                        cout<<"Opcion incorrecta!!!"<<endl;
                        system("pause");
                    break;
        }
    }
}

return 0;
}
