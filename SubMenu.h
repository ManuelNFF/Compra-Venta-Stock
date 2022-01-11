#ifndef SUBMENU_H_INCLUDED
#define SUBMENU_H_INCLUDED

#include "Prototipos.h"
#include "Clases.h"
#include "Funciones.h"




void menu_articulo(){
int posy=0;
hidecursor();
system("cls");
    while(true){
        locate(33,10+posy);
        cout<<(char)62;
        locate(32,10+posy);
        cout<<(char)62<<endl;
        locate(35,7);
        cout<<"ARTICULOS"<<endl;
        locate(35,8);
        cout<<"---------------"<<endl;
        locate(35,10);
        cout<<"1) Agregar articulo"<<endl;
        locate(35,11);
        cout<<"2) Listar todos los articulos"<<endl;
        locate(35,12);
        cout<<"3) Mostrar articulo por ID"<<endl;
        locate(35,13);
        cout<<"4) Stock"<<endl;
        locate(35,14);
        cout<<"5) Eliminar articulo"<<endl;
        locate(35,15);
        cout<<"6) Restaurar articulo"<<endl;
        locate(35,16);
        cout<<"0) Volver al menu principal"<<endl<<endl;

            switch(getkey()){
            case 14:
                    locate(33,10+posy);
                    cout<<" ";
                    locate(32,10+posy);
                    cout<<" "<<endl;
                    posy--; //Arriba
                    if(posy<0){posy=0;}
                break;
            case 15:
                    locate(33,10+posy);
                    cout<<" ";
                    locate(32,10+posy);
                    cout<<" "<<endl;
                    posy++; //Abajo
                    if(posy>6){posy=6;}
                break;
            case 1:
                switch(posy){
                case 0:
                        AgregarArticulo();
                        system("pause");
                        system("cls");
                    break;
                case 1:
                        ListarArticulo();
                        system("pause");
                        system("cls");
                    break;
                case 2:
                        ArticuloID();
                        system("pause");
                        system("cls");
                    break;
                case 3:
                        Stock();
                        system("pause");
                        system("cls");
                    break;
                case 4:
                        if( EliminarArticulo()==true){
                        cout<<"Articulo eliminado"<<endl;}
                        else {cout<<"No se pudo eliminar el articulo"<<endl;}
                        system("pause");
                        system("cls");
                    break;
                case 5:
                        if ( RestaurarArticulo()==true){
                        cout<<"Articulo restaurado"<<endl;}
                        else {cout<< "No se pudo restaurar el articulo"<<endl;}
                        system("pause");
                        system("cls");
                    break;
                case 6:
                        system("cls");
                        return;
                    break;

                default:
                        cout<<"Opcion incorrecta!!!"<<endl;
                        system("pause");
                    break;
            }
        }
    }
}

void menu_ventas(){
int posy=0;
hidecursor();
system("cls");

    while(true){
        locate(33,10+posy);
        cout<<(char)62;
        locate(32,10+posy);
        cout<<(char)62<<endl;
        locate(35,7);
        cout<<"VENTAS"<<endl;
        locate(35,8);
        cout<<"---------------"<<endl;
        locate(35,10);
        cout<<"1) Cargar venta."<<endl;
        locate(35,11);
        cout<<"2) Mostrar todas las ventas."<<endl;
        locate(35,12);
        cout<<"3) Mostrar ventas por cliente."<<endl;
        locate(35,13);
        cout<<"0) Volver al menu principal."<<endl<<endl;

            switch(getkey()){
            case 14:
                    locate(33,10+posy);
                    cout<<" ";
                    locate(32,10+posy);
                    cout<<" "<<endl;
                    posy--; //Arriba
                    if(posy<0){posy=0;}
                break;
            case 15:
                    locate(33,10+posy);
                    cout<<" ";
                    locate(32,10+posy);
                    cout<<" "<<endl;
                    posy++; //Abajo
                    if(posy>3){posy=3;}
                break;
            case 1:
                switch(posy){
                case 0:
                        CargarVenta();
                        system("pause");
                        system("cls");
                    break;
                case 1:
                        MostrarTodasVentas();
                        system("pause");
                        system("cls");
                    break;
                case 2:
                        MostrarVenta();
                        system("pause");
                        system("cls");
                    break;
                case 3:
                        system("cls");
                        return;
                    break;
                default:
                        cout<<"Opcion incorrecta!!!"<<endl;
                        system("pause");
                    break;
            }
        }
    }
}

void menu_cliente(){
int posy=0;
hidecursor();
system("cls");
    while(true){
        locate(33,10+posy);
        cout<<(char)62;
        locate(32,10+posy);
        cout<<(char)62<<endl;
        locate(35,7);
        cout<<"CLIENTES"<<endl;
        locate(35,8);
        cout<<"---------------"<<endl;
        locate(35,10);
        cout<<"1) Agregar cliente"<<endl;
        locate(35,11);
        cout<<"2) Listar todos los clientes"<<endl;
        locate(35,12);
        cout<<"3) Eliminar cliente"<<endl;
        locate(35,13);
        cout<<"4) Modificar datos cliente."<<endl;
        locate(35,14);
        cout<<"0) Volver al menu principal"<<endl;

            switch(getkey()){
            case 14:
                    locate(33,10+posy);
                    cout<<" ";
                    locate(32,10+posy);
                    cout<<" "<<endl;
                    posy--; //Arriba
                    if(posy<0){posy=0;}
                break;
            case 15:
                    locate(33,10+posy);
                    cout<<" ";
                    locate(32,10+posy);
                    cout<<" "<<endl;
                    posy++; //Abajo
                    if(posy>4){posy=4;}
                break;
            case 1:
                    switch(posy){
                    case 0: AgregarCliente();
                            system("pause");
                            system("cls");
                        break;
                    case 1: ListarClientes();
                          system("pause");
                          system("cls");
                        break;
                    case 2: if( EliminarCliente()==true){
                            cout<<"Cliente eliminado"<<endl;
                            }
                            else {cout<<"No se pudo eliminar el cliente"<<endl;
                            }
                            system("pause");
                            system("cls");
                        break;
                    case 3:
                            ModificarCliente();
                            system("pause");
                            system("cls");
                        break;
                    case 4:
                            system("cls");
                            return;
                        break;
                    default:
                            cout<<"Opcion incorrecta!!!"<<endl;
                            system("pause");
                            system("cls");
                        break;
            }
        }
    }
}

void menu_proveedor(){
int posy=0;
system("cls");
hidecursor();
    while(true){
        locate(33,10+posy);
        cout<<(char)62;
        locate(32,10+posy);
        cout<<(char)62<<endl;
        locate(35,7);
        cout<<"PROVEEDORES"<<endl;
        locate(35,8);
        cout<<"---------------"<<endl;
        locate(35,10);
        cout<<"1) Agregar proveedor."<<endl;
        locate(35,11);
        cout<<"2) Listar todos los proveedores."<<endl;
        locate(35,12);
        cout<<"3) Mostrar proveedor por ID."<<endl;
        locate(35,13);
        cout<<"4) Cargar facturas."<<endl;//facturas
        locate(35,14);
        cout<<"5) Mostrar facturas por proveedor."<<endl;
        locate(35,15);
        cout<<"6) Mostrar todas las faturas."<<endl;
        locate(35,16);
        cout<<"7) Modificar datos del proveedor."<<endl;
        locate(35,17);
        cout<<"8) Eliminar proveedor."<<endl;
        locate(35,18);
        cout<<"9) Restaurar proveedor."<<endl;
        locate(35,19);
        cout<<"0) Volver al menu principal."<<endl<<endl;

           switch(getkey()){
            case 14:
                    locate(33,10+posy);
                    cout<<" ";
                    locate(32,10+posy);
                    cout<<" "<<endl;
                    posy--; //Arriba
                    if(posy<0){posy=0;}
                break;
            case 15:
                    locate(33,10+posy);
                    cout<<" ";
                    locate(32,10+posy);
                    cout<<" "<<endl;
                    posy++; //Abajo
                    if(posy>9){posy=9;}
                break;
                case 1:
                    switch(posy){
                    case 0:
                            AgregarProveedor();
                            system("pause");
                            system("cls");
                        break;
                    case 1:
                            ListarProveedor();
                            system("pause");
                            system("cls");
                        break;
                    case 2:
                            ProveedorID();
                            system("pause");
                            system("cls");
                        break;
                    case 3:
                            CargarFactura();
                            system("pause");
                            system("cls");
                        break;
                    case 4:
                            MostrarFactura();
                            system("pause");
                            system("cls");
                        break;
                    case 5:
                            MostrarTodasFacturas();
                            system("pause");
                            system("cls");
                        break;
                    case 6:
                            ModificarProveedor();
                            system("pause");
                            system("cls");
                        break;
                    case 7:
                        if( EliminarProveedor()==true){
                            cout<<"Proveedor eliminado"<<endl;}
                            else {cout<<"No se pudo eliminar el proveedor"<<endl;}
                            system("pause");
                            system("cls");
                        break;
                    case 8:
                        if ( RestaurarProveedor()==true){
                            cout<<"Proveedor restaurado"<<endl;}
                            else {cout<< "No se pudo restaurar el proveedor"<<endl;}
                            system("pause");
                            system("cls");
                        break;
                    case 9:
                            system("cls");
                            return;
                        break;
                    default:
                            cout<<"Opcion incorrecta!!!"<<endl;
                            system("pause");
                        break;
            }
        }
    }
 }



#endif // SUBMENU_H_INCLUDED
