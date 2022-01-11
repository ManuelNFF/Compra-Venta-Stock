#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
#include "Clases.h"


//******VENTA********
void cargarCadena(char *pal, int tam){
int i;
    fflush(stdin);
    for(i=0;i<tam;i++){
        pal[i]=cin.get();
    if(pal[i]=='\n') break;
    }
    pal[i]='\0';
    fflush(stdin);
}
bool ValidarIDvent(int ID_Venta){
Venta obj;
int pos=0;
    while(obj.leerEnDiscoVentas(pos)==true){
        if(obj.getIDVent()==ID_Venta){
                return false;
        }
        pos++;
    }
    return true;
}
void CargarVenta(){
Venta reg;
system("cls");
    if(reg.Cargar_Venta()){
            if(reg.grabarEnDiscoVentas()==true){
                cout<<"Registro agregado"<<endl;
            }else{
                cout<<"No se pudo crear el registro"<<endl;
            }
    }
}
bool validarIIBB(float IIBB){
    if(IIBB==2.5 || (IIBB==3 || (IIBB==3.5))){
      return true;
    }else{
        cout<<"El IIBB ingresado no es valido. Por favor, vuelva a intentar."<<endl;
        return false;
        }
}

bool validarDesc(float Descuento){
    if(Descuento <100){
        return true;
    }else{
        cout<<"No se puede facturar importe $0 o menor."<<endl;
        return false;
    }
}
bool validarIVA(float IVA){
    if(IVA==10.5 || IVA==21){
        return true;
    }else{
    cout<<"El IVA ingresado es incorrecto. Por favor, vuelva a intentar."<<endl;
    return false;
    }
}
void MostrarTodasVentas(){
Venta reg;
Cliente aux;
system("cls");
int pos=0, pos2=0;
    while(aux.leerEnDiscoCliente(pos++)){
            pos2=0;
        while(reg.leerEnDiscoVentas(pos2++)){
            if(reg.getID_Cliente()==aux.getIDclint()){
                cout<<"---------------"<<"Venta numero: "<<reg.getIDVent()<<"-----------------"<<endl;
                aux.Mostrar_Cliente();
                reg.Mostrar_Venta();
                cout<<"-----------------------------------------------"<<endl;
                cout<<endl;
                cout<<endl;
            }
        }
    }
}

void MostrarVenta(){
Venta reg;
Cliente aux;
system("cls");
int pos=0, ID_Cliente, pos2=0;
    cout<<"Ingrese ID del cliente: ";
    cin>>ID_Cliente;
    cout<<endl;
    while(aux.leerEnDiscoCliente(pos++)){
        if(aux.getIDclint()==ID_Cliente){
            while(reg.leerEnDiscoVentas(pos2++)){
                if(reg.getID_Cliente()==ID_Cliente){
                    cout<<"---------------"<<"Venta numero: "<<reg.getIDVent()<<"-----------------"<<endl;
                    aux.Mostrar_Cliente();
                    reg.Mostrar_Venta();
                    cout<<"-----------------------------------------------"<<endl;
                    cout<<endl;
                    cout<<endl;
                }
            }
        }
    }
}

float BuscarArticuloPrecio(int ID_Articulo){
Articulo obj;
int pos=0, Precio=0;
    while(obj.leerEnDiscoArticulo(pos)==true){
        if(obj.getIDart()==ID_Articulo){
                Precio=obj.getPrecio();
                return Precio;
        }
        pos++;
    }
    return -1;
}

bool BuscarArticuloStock(int ID_Articulo, float Cantidad){
Articulo obj;
int pos=0;
    while(obj.leerEnDiscoArticulo(pos)==true){
        if(obj.getIDart()==ID_Articulo){
            if(obj.getStock()>=Cantidad){
                    return true;
            }
        }
        pos++;
    }
    return false;
}
bool BuscarArt(int ID_Articulo){
Articulo obj;
int pos=0;
    while (obj.leerEnDiscoArticulo(pos)){
        if(obj.getIDart()==ID_Articulo){
            return  true;
        }
        pos++;
    }
    return false;
}
bool ModStock(int ID_Articulo, float Cantidad, bool VC){
int pos, Stock;
Articulo reg;
pos=BuscarArticuloID(ID_Articulo);
        if(pos==-1){
            cout<<"No se encontro el articulo solicitado"<<endl;
            return false;
            }
    reg.leerEnDiscoArticulo(pos);
    if(VC){
    Stock=reg.getStock()-Cantidad;
    }else{
        Stock=reg.getStock()+Cantidad;
        }
    reg.setStock(Stock);
    if(reg.ModificarArt(pos)==true){
    return true;
    }else {
    return false;
    }
}

float Importe(float Precio, int Cantidad, float IVA, float Descuento, float IIBB){
float Importe_Final=0;
Importe_Final=Cantidad * Precio;
    if(IIBB>0){
        Importe_Final=Importe_Final*(1+(IIBB/100));
           }
    if(IVA>0){
        Importe_Final=Importe_Final*(1+(IVA/100));
            }
      if(Descuento!=0){
            Importe_Final=Importe_Final*((100-Descuento)/100);
    }
    return Importe_Final;
}

//********ARTICULO*******

bool ValidarIDart(int ID_Articulo){
Articulo obj;
int pos=0;
    while(obj.leerEnDiscoArticulo(pos)==true){
        if(obj.getIDart()==ID_Articulo){
                return false;
        }
        pos++;
    }
    return true;
}
void AgregarArticulo(){
Articulo obj;
system("cls");
   if(obj.Cargar_Art()){
        if(obj.grabarEnDiscoArticulo()){
            cout<<"Registro agregado"<<endl;
        }else{
            cout<<"No se pudo crear el registro"<<endl;
        }
   }
}
bool validarStock(int Stock){
    if(Stock<0){
        cout<<"No se puede ingresar stock negativo. Vuelva a intentar."<<endl;
        return false;
    }else{return true;}
}

bool validarPrecio(float Precio){
    if(Precio<0){
            cout<<"No se puede ingresar precio negativo. Vuelva a intentar"<<endl;
            return false;
    }else{return true;}
}

void ListarArticulo(){
Articulo reg;
system("cls");
int pos=0, y=25, x=3;
system("cls");
    while(reg.leerEnDiscoArticulo(pos++)){
        locate(y,x);
        reg.Mostrar_Art();
        locate(y,x+=8);
        }
}


bool ArticuloID(){
Articulo obj;
int pos,id, y=25, x=3;
system("cls");
    cout<< "Ingrese el ID del articulo: ";
    cin>>id;
    pos=BuscarArticuloID(id);
    if(pos==-1){return false;}
    obj.leerEnDiscoArticulo(pos);
    locate(y, x);
    obj.Mostrar_Art();
    locate(y,x+=8);
}

int BuscarArticuloID(int id){
Articulo obj;
int pos=0;
    while(obj.leerEnDiscoArticulo(pos)==true){
        if(obj.getIDart()==id){
                return pos;
        }
        pos++;
    }
    return -1;

}

bool EliminarArticulo(){
int ID_Articulo, pos, id;
Articulo reg;
system("cls");
    cout<<"Ingrese ID del articulo que desea eliminar: ";
    cin>>ID_Articulo;
    id=ID_Articulo;
    pos=BuscarArticuloID(id);
    if(pos==-1){
        cout<<"No existe un artiuclo con ese ID"<<endl;
        return false;
        }
    reg.leerEnDiscoArticulo(pos);
    reg.setEstado(false);
    if(reg.ModificarArt(pos)==true){
     return true;
     cout<< "El articulo se elimino correctamente." <<endl;
     }else {
     return false;
     }
}
bool RestaurarArticulo(){
Articulo reg;
int pos=0, ID;
system("cls");
    cout<<"Ingrese Id del articulo que desea restaurar.";
    cin>>ID;
    while (reg.leerEnDiscoArticulo(pos)){
        if(ID==reg.getIDart()){
            if(reg.getEstado()==false){
                reg.setEstado(true);
                reg.ModificarArt(pos);
                return true;
            }
        }
        pos++;
    }
    return false;
}

void Stock(){
Articulo reg;
int pos=0;
system("cls");
    while(reg.leerEnDiscoArticulo(pos++)){
        cout<<"------------Articulo: "<<reg.getNombre_art()<<"-------------"<<endl;
        cout<<"Stock actual: "<<reg.getStock()<<endl;
        cout<<"Stock ideal: "<<reg.getIdeal_Stock()<<endl;
        cout<<"----------------------------------------"<<endl;
    }
}

//**********CLIENTE**********

void AgregarCliente(){
Cliente aux;
system("cls");
    if(aux.Cargar_Cliente()){
        if(aux.grabarEnDiscoCliente()){
            cout<<"Cliente agregado"<<endl;
        }else{
            cout<<"No se pudo agregar el cliente"<<endl;
        }
    }
}

void ListarClientes(){
Cliente aux;
int pos=0, y=25, x=3;
system("cls");
    while(aux.leerEnDiscoCliente(pos++)==true){
        locate(y, x);
        aux.Mostrar_Cliente();
        locate(y,x+=8);
    }
}

bool ValidarIDcli(int ID_Cliente){
Cliente aux;
int pos=0;
    while(aux.leerEnDiscoCliente(pos)==true){
        if(aux.getIDclint()==ID_Cliente){
                return false;
        }
        pos++;
    }
    return true;
}

int BuscarClienteID(int id){
Cliente obj;
int pos=0;
    while(obj.leerEnDiscoCliente(pos)==true){
        if(obj.getIDclint()==id){
                return pos;
        }
        pos++;
    }
    return -1;

}

bool EliminarCliente(){
int ID_Cliente, pos, id;
Cliente obj;
system("cls");
    cout<<"Ingrese ID del cliente que desea eliminar: ";
    cin>>ID_Cliente;
    id=ID_Cliente;
    pos=BuscarClienteID(id);
    if(pos==-1){
        cout<<"No existe cliente con ese ID"<<endl;
        return false;
        }
    obj.leerEnDiscoCliente(pos);
    obj.setEstadoP(false);
    obj.setEstadoC(false);
    if(obj.ModificarEstadoCliente(pos)==true){
     return true;
     cout<< "El cliente se elimino correctamente." <<endl;
     }else {
     return false;
     }
}
bool ModificarCliente(){
int id, pos=-1, posx=0;
char Tel[30],Email[40];
Cliente reg;
bool modifico;
system("cls");
    while(pos==-1){
    locate(10,5);
    cout<<"MODIFICAR DATOS DE CLIENTE"<<endl;
    locate(5,6);
    cout<<"------------------------------------"<<endl;
    locate(0,7);
    cout << "ID del cliente a modificar: "<<endl;
    gotoxy(30,7);
    cin >>id;
    pos=BuscarClienteID(id);
    if(pos==-1){
            cout<<"No se encontro un cliente con ese ID"<<endl;
            system("pause");
            system("cls");
            }
    }
    reg.leerEnDiscoCliente(pos);
    reg.Mostrar_Cliente();
    cout<<endl;
        while(true){
        locate(4,18+posx);
        cout<<(char)62;
        locate(3,18+posx);
        cout<<(char)62<<endl;
        locate(1,17);
        cout<<"Modificar:"<<endl;
        locate(5,18);
        cout<<"1) Telefono"<<endl;
        locate(5,19);
        cout<<"2) Email" <<endl;

            switch(getkey()){
                    case 14:
                            locate(4,18+posx);
                            cout<<" ";
                            locate(3,18+posx);
                            cout<<" "<<endl;
                            posx--; //Arriba
                            if(posx<0){posx=0;}
                        break;
                    case 15:
                            locate(4,18+posx);
                            cout<<" ";
                            locate(3,18+posx);
                            cout<<" "<<endl;
                            posx++; //Abajo
                            if(posx>1){posx=1;}
                        break;
                    case 1:
                        switch(posx){
                            case 0:
                                    locate(5,21);
                                    cout<<"Ingrese nuevo telefono: " <<endl;
                                    gotoxy(30,21);
                                    cargarCadena(Tel, 30);
                                    reg.setTel(Tel);
                                    modifico=reg.ModificarEstadoCliente(pos);
                                    cout<<"Telefono modificado correctamente."<<endl;
                                    return modifico;

                                break;
                            case 1:
                                    locate(5,21);
                                    cout<<"Ingrese nuevo email: " <<endl;
                                    gotoxy(27,21);
                                    cargarCadena(Email, 40);
                                    reg.setEmail(Email);
                                    modifico=reg.ModificarEstadoCliente(pos);
                                    cout<<"Email modificado correctamente."<<endl;
                                    return modifico;
                                break;
                            default:
                                    cout<<"Opcion incorrecta!!!"<<endl;
                                    system("cls");
                                    return false;
                                break;

                        }
            }
        }
    }


//********PROVEEDORES********

void AgregarProveedor(){
Proveedor obj;
system("cls");
    if(obj.Cargar_Prov()){
        if(obj.grabarEnDiscoProveedor()){
            cout<<"Registro agregado"<<endl;
        }else{
            cout<<"No se pudo crear el registro"<<endl;
        }
    }
}

void ListarProveedor(){
Proveedor obj;
int pos=0, y=25, x=3;
system("cls");
    while(obj.leerEnDiscoProveedor(pos++)){
        locate(y, x);
        obj.Mostrar_Prov();
        locate(y,x+=8);
        }
}

bool ValidarIDPro(int ID_Proveedor){
Proveedor obj;
int pos=0;
    while(obj.leerEnDiscoProveedor(pos)==true){
        if(obj.getIDprov()==ID_Proveedor){
                return false;
        }
        pos++;
    }
    return true;
}

bool ProveedorID(){
Proveedor obj;
int pos,id, y=25, x=3;
system("cls");
    cout<< "Ingrese el ID del proveedor: ";
    cin>>id;
    pos=BuscarProveedor(id);
    if(pos==-1){return false;}
    obj.leerEnDiscoProveedor(pos);
    locate(y, x);
    obj.Mostrar_Prov();
    locate(y,x+=8);
}

 int BuscarProveedor(int id){
Proveedor obj;
int pos=0;
    while(obj.leerEnDiscoProveedor(pos)==true){
        if(obj.getIDprov()==id){
                return pos;
        }
        pos++;
    }
    return -1;
}
bool ModificarProveedor(){
int id, pos=-1, posx=0;
char Tel[30],Email[40];
Proveedor reg;
bool modifico;
system("cls");
while(pos==-1){
    locate(10,5);
    cout<<"MODIFICAR DATOS PROVEEDOR"<<endl;
    locate(5,6);
    cout<<"------------------------------------"<<endl;
    locate(0,7);
    cout << "ID del proveedor a modificar: ";
    gotoxy(31,7);
    cin >>id;
    pos=BuscarProveedor(id);
    if(pos==-1){
        cout<<"No se encontro un proveedor con ese ID"<<endl;
        system("pause");
        system("cls");
    }
}
    reg.leerEnDiscoProveedor(pos);
    reg.Mostrar_Prov();
    cout<<endl;
    while(true){
        locate(4,18+posx);
        cout<<(char)62;
        locate(3,18+posx);
        cout<<(char)62<<endl;
        locate(1,17);
        cout<<"Modificar:"<<endl;
        locate(5,18);
        cout<<"1) Telefono"<<endl;
        locate(5,19);
        cout<<"2) Email" <<endl;

    switch(getkey()){
         case 14:
                            locate(4,18+posx);
                            cout<<" ";
                            locate(3,18+posx);
                            cout<<" "<<endl;
                            posx--; //Arriba
                            if(posx<0){posx=0;}
                        break;
                    case 15:
                            locate(4,18+posx);
                            cout<<" ";
                            locate(3,18+posx);
                            cout<<" "<<endl;
                            posx++; //Abajo
                            if(posx>1){posx=1;}
                        break;
                    case 1:
                        switch(posx){
                            case 0:
                                    locate(5,21);
                                    cout<<"Ingrese nuevo telefono: " <<endl;
                                    gotoxy(30,21);
                                    cargarCadena(Tel, 30);
                                    reg.setTel(Tel);
                                    modifico=reg.ModificarEstadoPro(pos);
                                    cout<<"Telefono modificado correctamente."<<endl;
                                    return modifico;
                                break;
                            case 1:
                                    locate(5,21);
                                    cout<<"Ingrese nuevo email: " <<endl;
                                    gotoxy(27,21);
                                    cargarCadena(Email, 40);
                                    reg.setEmail(Email);
                                    modifico=reg.ModificarEstadoPro(pos);
                                    cout<<"Email modificado correctamente."<<endl;
                                    return modifico;
                                break;
                            default:
                                    cout<<"Opcion incorrecta!!!"<<endl;
                                    system("cls");
                                    return false;
                                break;

                        }
            }
        }
    }

bool EliminarProveedor(){
int ID_Proveedor, pos, id;
Proveedor obj;
system("cls");
    cout<<"Ingrese ID del proveedor que desea eliminar: ";
    cin>>ID_Proveedor;
    id=ID_Proveedor;
    pos=BuscarProveedor(id);
    if(pos==-1){
        cout<<"No existe un proveedor con ese ID"<<endl;
        return false;
        }
    obj.leerEnDiscoProveedor(pos);
    obj.setEstadoP(false);
    obj.setEstado(false);
    if(obj.ModificarEstadoPro(pos)==true){
     return true;
     cout<< "El proveedor se elimino correctamente." <<endl;
     }else {
     return false;
     }
}

bool RestaurarProveedor(){
Proveedor obj;
int pos=0, ID;
system("cls");
    cout<<"Ingrese el ID de proveedor que desea restaurar: ";
    cin>>ID;
    while (obj.leerEnDiscoProveedor(pos)){
        if(ID==obj.getIDprov()){
            if(obj.getEstado()==false){
                obj.setEstadoP(true);
                obj.setEstado(true);
                obj.ModificarEstadoPro(pos);
                return true;
            }
        }
            pos++;
    }
    return false;
}

// *************COMPRAS*********************
void Cargar_Fecha(){
Fecha aux;
system("cls");
    aux.CargarFecha();
    cout<<endl;
}
void Mostrar_Fecha(){
Fecha aux;
system("cls");
    aux.MostrarFecha();
    cout<<endl;
}
bool ValidarIDcomp(int ID_Compra){
Compras obj;
int pos=0;
    while(obj.leerEnDiscoFacturas(pos)==true){
        if(obj.getIDcompra()==ID_Compra){
                return false;
        }
        pos++;
    }
    return true;
}
void CargarFactura(){
Compras aux;
system("cls");
    if(aux.Cargar_Factura()){
        if(aux.grabarEnDiscoFacturas()==true){
            cout<<"Registro agregado"<<endl;
        }else{
            cout<<"No se pudo crear el registro"<<endl;
        }
    }
}
void MostrarTodasFacturas(){
Compras reg;
Proveedor aux;
int pos=0, pos2=0;
system("cls");
    while(aux.leerEnDiscoProveedor(pos++)){
        pos2=0;
        while(reg.leerEnDiscoFacturas(pos2++)){
            if(reg.getIDprov()==aux.getIDprov()){
                cout<<"---------------"<<"Compra: "<<reg.getIDcompra()<<"-----------------"<<endl;
                aux.Mostrar_Prov();
                reg.Mostrar_Factura();
                cout<<endl;
                cout<<"-----------------------------------------------"<<endl<<endl;

            }
        }
    }
}
void MostrarFactura(){
Compras reg;
Proveedor aux;
int pos=0, ID_Prov, pos2=0;
system("cls");
    cout<<"Ingrese ID del proveedor: ";
    cin>>ID_Prov;
    cout<<endl;
    while(aux.leerEnDiscoProveedor(pos++)){
        if(aux.getIDprov()==ID_Prov){
            while(reg.leerEnDiscoFacturas(pos2++)){
                if(reg.getIDprov()==ID_Prov){
                    cout<<"---------------"<<"Compra: "<<reg.getIDcompra()<<"-----------------"<<endl;
                    aux.Mostrar_Prov();
                    reg.Mostrar_Factura();
                    cout<<endl;
                    cout<<"-----------------------------------------------"<<endl;
                    cout<<endl;
                    cout<<endl;
                }
            }
        }
    }
}




#endif // FUNCIONES_H_INCLUDED

