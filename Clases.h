#ifndef CLASES_H_INCLUDED
#define CLASES_H_INCLUDED
#include <time.h>
#include <stdio.h>
#include "Prototipos.h"



class Fecha{
    protected:
        int dia, mes, anio;
    public:
        Fecha(int d=0, int m=0, int a=0){
            dia=d;
            mes=m;
            anio=a;
            if(d!=0){
                dia=d;mes=m;anio=a;
            }else{
                time_t tiempo;
                struct tm *tmPtr;
                tiempo = time(NULL);
                tmPtr = localtime(&tiempo);
                anio=tmPtr->tm_year+1900;
                mes=tmPtr->tm_mon+1;
                dia=tmPtr->tm_mday;
            }

        }

    bool setDia(int d){
        if(m==4 || (m==6 || (m==9 || m==11))){
            if(d>0 && d<=30){
                dia=d;
                return true;
            }
            else if(m==2){
                if(a%4=0){
                    if(d>0 && d<=29)
                        dia=d;
                        return true;
                }
                else{
                    if(d>0 && d<=31){
                        dia=d;
                        return true;
                    }
                }
            }
        }
        if (d>0 && d<=31){
            dia=d;
            return true;
        }
            return false;

    }

    bool setMes(int m){
        if(m>0 && m<=12){
            mes=m;
            return true;
        }
            return false;

    }

    bool setAnio(int a){
        if(a>0 && a<=2021){
            anio=a;
            return true;
        }
            return false;
    }

    int getDia(){return dia;}
    int getMes(){return mes;}
    int getAnio(){return anio;}


    void CargarFecha();
    void MostrarFecha();
};


 void Fecha::CargarFecha(){
        int d, m, a;
        cout<<endl;
        cout<<"aaaa/mm/aa: ";
        cin>>d;
        if(!setDia(d)){ cout<<"EL DIA NO ES VALIDO"<<endl;
        return;
        }
        cout<<"Mes: ";
        cin>>m;
        if(!setMes(m)) {cout<<"EL MES NO ES VALIDO"<<endl;
        return;
        }
        cout<<"Anio: ";
        cin>>a;
        if(!setAnio(a)) {cout<<"EL ANIO NO ES VALIDO"<<endl;
        return;
        }
    }
void Fecha::MostrarFecha(){
        cout<<dia<<"/"<<mes<<"/"<<anio<<endl;
    }



class Articulo{
protected:
    int ID_Articulo,Stock, Ideal_Stock;
    float Precio;
    char Nombre_Articulo[40];
    bool Estado;

public:

    bool Cargar_Art();
    void Mostrar_Art();

    void setIDart(int ID){ID_Articulo=ID;}
    void setStock(int s){Stock=s;}
    void setPrecio(int p){Precio=p;}
    void setIdeal_Stock (float is){Ideal_Stock=is;}
    void serNombre_art(const char *NA){strcpy(Nombre_Articulo, NA);}
    void setEstado(bool e){Estado=e;}

    bool getEstado(){return Estado;}
    int getIdeal_Stock(){return Ideal_Stock;}
    int getIDart(){return ID_Articulo;}
    int getStock(){return Stock;}
    float getPrecio(){return Precio;}
    const char *getNombre_art(){return Nombre_Articulo;}

    bool grabarEnDiscoArticulo(){
        FILE *aArt;
        bool grabo;
        aArt=fopen("Articulo.dat", "ab");
        if(aArt==NULL){
            return false;
        }
        grabo=fwrite(this,sizeof *this,1,aArt);
        fclose(aArt);
        return grabo;
    }

    bool leerEnDiscoArticulo(int pos){
        FILE *aArt;
        bool leyo;
        aArt=fopen("Articulo.dat", "rb");
        if(aArt==NULL){
            return false;
        }
        fseek(aArt, pos * sizeof *this,0);
        leyo=fread(this,sizeof *this,1,aArt);
        fclose(aArt);
        return leyo;
    }

     bool ModificarArt(int pos){
        FILE *aArt;
        aArt=fopen("Articulo.dat", "rb+");
        if(aArt==NULL){
            return false;
        }
        fseek(aArt, pos * sizeof *this,0);
        bool escribio=fwrite(this,sizeof *this,1,aArt);
        fclose(aArt);
        return escribio;
    }

};

bool Articulo::Cargar_Art(){
    locate(10,5);
    cout<<"AGREGAR NUEVO ARTICULO"<<endl;
    locate(0,6);
    cout<<"----------------------------------------"<<endl<<endl;
    showcursor();
    cout<<"Ingrese ID del producto: "<<endl;
    cout<<"Ingrese nombre del articulo: "<<endl;
    cout<<"Ingrese precio: $"<<endl;
    cout<<"Ingrese cantidad de stock disponible: "<<endl;
    cout<<"Ingrese stock ideal: "<<endl;

  gotoxy(26,8);
  cin>>ID_Articulo;
    if(ValidarIDart(ID_Articulo)==true){
    gotoxy(30,9);
    cargarCadena(Nombre_Articulo, 40);
    gotoxy(18,10);
    cin>>Precio;
        if(validarPrecio(Precio)){
        gotoxy(39,11);
        cin>>Stock;
            if(validarStock(Stock)){
            gotoxy(22,12);
            cin>>Ideal_Stock;
            Estado=true;
            return true;
            }else{return false;}
        }else{return false;}
    }else{
        system("cls");
        cout<<"El ID ingresado ya se encuentra en uso. Por favor, vuelva a intentar. "<<endl;
        return false;
         }
}

void Articulo::Mostrar_Art(){
    if(Estado==true){
        cout<<"ID del producto: "<<ID_Articulo<<endl;
        cout<<"\t"<<"Nombre: "<<Nombre_Articulo<<endl;
        cout<<"\t"<<"Precio: $"<<Precio<<endl;
        cout<<"\t"<<"Stock: "<<Stock<<endl;
        cout<<"\t"<<"Stock ideal: "<<Ideal_Stock<<endl;
    }
}

class Persona{
protected:
    char Razon_Social[40], Email[40], Cuil[30], Telefono[30];
    bool EstadoP;

public:
    void Cargar();
    void Mostrar();

    void setCuil(const char *c){strcpy(Cuil, c);}
    void setTel(const char *t){strcpy(Telefono, t);}
    void setRsocial(const char *rs){strcpy(Razon_Social, rs);}
    void setEmail(const char *e){strcpy(Email, e);}
    void setEstadoP(bool e){EstadoP=e;}

    const char *getCuil(){return Cuil;}
    const char *getTel(){return Telefono;}
    const char *getRsocial(){return Razon_Social;}
    const char *getEmail(){return Email;}
    bool getEstadoP(){return EstadoP;}

};

void Persona::Cargar(){
    locate(0,10);
    cout<<"Ingrese razon social: "<<endl;
    locate(0,11);
    cout<<"Ingrese CUIL: "<<endl;
    locate(0,12);
    cout<<"Ingrese telefono de contacto: "<<endl;
    locate(0,13);
    cout<<"Ingrese email: "<<endl;

    gotoxy(23,10);
    cargarCadena(Razon_Social, 40);
    gotoxy(15,11);
    cargarCadena(Cuil, 30);
    gotoxy(31,12);
    cargarCadena(Telefono, 30);
    gotoxy(16,13);
    cargarCadena(Email, 40);
    EstadoP=true;
}
void Persona::Mostrar(){
    cout<<"\t"<<"Razon social: "<<Razon_Social<<endl;
    cout<<"\t"<<"CUIL: "<<Cuil<<endl;
    cout<<"\t"<<"Telefono: "<<Telefono<<endl;
    cout<<"\t"<<"Email: "<<Email<<endl;
}

class Proveedor: public Persona{
protected:
    int ID_Proveedor;
    char Alias[20];
    bool Estado;

public:
    bool Cargar_Prov();
    void Mostrar_Prov();

    void setID_prov(int ID){ID_Proveedor=ID;}
    void setAlias(const char *a){strcpy(Alias, a);}
    void setEstado(bool e){Estado=e;}

    int getIDprov(){return ID_Proveedor;}
    const char *getAlias(){return Alias;}
    bool getEstado(){return Estado;}

    bool grabarEnDiscoProveedor(){
        FILE *aProv;
        bool grabo;
        aProv=fopen("Proveedores.dat", "ab");
        if(aProv==NULL){
            return false;
            }
        grabo=fwrite(this,sizeof *this,1,aProv);
        fclose(aProv);
        return grabo;
    }

    bool leerEnDiscoProveedor(int pos){
        FILE *aProv;
        bool leyo;
        aProv=fopen("Proveedores.dat", "rb");
        if(aProv==NULL){
            return false;
            }
        fseek(aProv, pos * sizeof *this,0);
        leyo=fread(this,sizeof *this,1,aProv);
        fclose(aProv);
        return leyo;
    }

     bool ModificarEstadoPro(int pos){
        FILE *pPro;
        pPro=fopen("Proveedores.dat", "rb+");
        if(pPro==NULL){
            return false;
            }
        fseek(pPro, pos * sizeof *this,0);
        bool escribio=fwrite(this,sizeof *this,1,pPro);
        fclose(pPro);
        return escribio;
    }

};

bool Proveedor::Cargar_Prov(){
    locate(10,5);
    cout<<"AGREGAR NUEVO PROVEEDOR"<<endl;
    locate(0,6);
    cout<<"----------------------------------------"<<endl<<endl;
    showcursor();
    cout<<"Ingrese ID de proveedor: "<<endl;
    cout<<"Ingrese alias: "<<endl;
    gotoxy(26,8);
    cin>>ID_Proveedor;
    if(ValidarIDPro(ID_Proveedor)==true){
        gotoxy(16,9);
        cargarCadena(Alias, 20);
        Persona::Cargar();
        cout<<endl;
        Estado=true;
        return true;
        }else{
            system("cls");
            cout<<"El ID ingresado ya se encuentra en uso. Por favor, vuelva a intentar. "<<endl;
        return false;
        }

}


void Proveedor::Mostrar_Prov(){
    if(Estado==true){
        cout<<"ID proveedor: "<<ID_Proveedor<<endl;
        cout<<"\t"<<"Alias: "<<Alias<<endl;
        Persona::Mostrar();
        cout<<endl;
    }
}


class Cliente:public Persona{
    protected:
    int ID_Cliente;
    char Alias[20];
    bool EstadoC;
public:
    bool Cargar_Cliente();
    void Mostrar_Cliente();

    void setID_clint(int ID){ID_Cliente=ID;}
    void setAlias(const char *a){strcpy(Alias, a);}
    void setEstadoC(bool e){EstadoC=e;}

    int getIDclint(){return ID_Cliente;}
    const char *getAlias(){return Alias;}
    bool getEstadoC(){return EstadoC;}


    bool grabarEnDiscoCliente(){
            FILE *aClint;
            bool grabo;
            aClint=fopen("Clientes.dat", "ab");
            if(aClint==NULL){
                return false;
            }
            grabo=fwrite(this,sizeof *this,1,aClint);
            fclose(aClint);
            return grabo;
    }
    bool leerEnDiscoCliente(int pos){
        FILE *aClint;
        bool leyo;
        aClint=fopen("Clientes.dat", "rb");
        if(aClint==NULL){
            return false;
        }
        fseek(aClint, pos * sizeof *this,0);
        leyo=fread(this,sizeof *this,1,aClint);
        fclose(aClint);
        return leyo;

    }

    bool ModificarEstadoCliente(int pos){
        FILE *pCli;
        pCli=fopen("Clientes.dat", "rb+");
        if(pCli==NULL){
            return false;
            }
        fseek(pCli, pos * sizeof *this,0);
        bool escribio=fwrite(this,sizeof *this,1,pCli);
        fclose(pCli);
        return escribio;
    }
};

bool Cliente::Cargar_Cliente(){
    locate(10,5);
    cout<<"AGREGAR NUEVO CLIENTE"<<endl;
    locate(0,6);
    cout<<"----------------------------------------"<<endl<<endl;
    showcursor();
    cout<<"Ingrese ID de cliente: "<<endl;
    cout<<"Ingrese alias: "<<endl;
    gotoxy(24,8);
    cin>>ID_Cliente;
    if(ValidarIDcli(ID_Cliente)==true){
        gotoxy(16,9);
        cargarCadena(Alias, 20);
        Persona::Cargar();
        EstadoC=true;
        return true;
        }
       else{
            system("cls");
            cout<<"El ID ingresado ya se encuentra en uso. Por favor, vuelva a intentar.";
        return false;
        }
}

void Cliente::Mostrar_Cliente(){
    if(EstadoC==true){
        cout<<"ID cliente: "<<ID_Cliente<<endl;
        cout<<"\t"<<"Alias: "<<Alias<<endl;
        Persona::Mostrar();
    }
}


   class Venta{
protected:
    int ID_Articulo, ID_Cliente, Cantidad, ID_Venta;
    float IVA, Precio, ImporteFinal, Descuento, IIBB;
    bool Estado, VC;
public:
    bool Cargar_Venta();
    void Mostrar_Venta();
    void setID_Articulo(int ida){ID_Articulo=ida;}
    void setID_Cliente(int idc){ID_Cliente=idc;}
    void setCantidad(int c){Cantidad=c;}
    void setDescuento(float d){Descuento=d;}
    void setImporteFinal(float iF){ImporteFinal=iF;}
    void setPrecio(float p){Precio=p;}
    void setIVA(float iva){IVA=iva;}
    void setEstado(bool e){Estado=e;}
    void setVC(bool vc){VC=vc;}
    void setIIBB(float iibb){IIBB=iibb;}
    float getIIBB(){return IIBB;}
    bool getVC(){return VC;}
    int getIDVent(){return ID_Venta;}
    int getID_Articulo(){return ID_Articulo;}
    int getID_Cliente(){return ID_Cliente;}
    int getCantidad(){return Cantidad;}
    float getDescuento(){return Descuento;}
    float getPrecio(){return Precio;}
    float getImporteFinal(){return ImporteFinal;}
    float getIVA(){return IVA;}
    bool getEStado(){return Estado;}
    bool grabarEnDiscoVentas(){
            FILE *aVent;
            bool grabo;
            aVent=fopen("Ventas.dat", "ab");
            if(aVent==NULL){
                return false;
            }
            grabo=fwrite(this,sizeof *this,1,aVent);
            fclose(aVent);
            return grabo;
    }
    bool leerEnDiscoVentas(int pos){
        FILE *aVent;
        bool leyo;
        aVent=fopen("Ventas.dat", "rb");
        if(aVent==NULL){
            return false;
        }
        fseek(aVent, pos * sizeof *this,0);
        leyo=fread(this,sizeof *this,1,aVent);
        fclose(aVent);
        return leyo;
        }
};

bool Venta::Cargar_Venta(){
    VC=true;
    IIBB=0;
    ImporteFinal=0;
    showcursor();
    cout<<"Ingrese numero de venta: ";
    cin>>ID_Venta;
    if(ValidarIDvent(ID_Venta)){
        cout<<endl;
        cout<<"Ingrese ID de cliente: ";
        cin>>ID_Cliente;
        cout<<endl;
        if(BuscarClienteID(ID_Cliente)!=-1){
            cout<<"Ingrese IVA (%10,5-%21): % ";
            cin>>IVA;
            if(validarIVA(IVA)){
                cout<<endl;
                cout<<"Ingrese descuento: % ";
                cin>>Descuento;
                if(validarDesc(Descuento)){
                    cout<<endl;
                    cout<<"Ingrese ID de articulo: ";
                    cin>>ID_Articulo;
                    while(ID_Articulo!=0){
                        Precio=BuscarArticuloPrecio(ID_Articulo);
                        cout<<"\t""\t" "precio: "<<"$"<<Precio;
                        cout<<endl;
                        cout<<"Igrese cantidad: ";
                        cin>>Cantidad;
                            if(BuscarArticuloStock(ID_Articulo, Cantidad)==true){
                                ModStock(ID_Articulo, Cantidad, VC);
                                cout<<endl;
                                }else{
                                    cout<<"No hay stock suficiente."<<endl;}
                        ImporteFinal+=Importe(Precio, Cantidad, IVA, Descuento, IIBB);
                        cout<<"Para finalizar ingrese 0"<<endl;
                        cout<<"Ingrese ID de articulo: ";
                        cin>>ID_Articulo;
                    }
                        cout<<"Importe final: $"<<ImporteFinal<<endl;
                        return true;
                }else{return false;}
            }else{return false;}
                system("pause");
        }else{cout<<"No se encontro cliente con ese ID"<<endl;
                return false;
                }
    }else{cout<<"El ID ingresado ya se encuentra en uso."<<endl;
        return false;
        }
}

void Venta::Mostrar_Venta(){
cout<<"Importe final: $"<<getImporteFinal();
cout<<endl;
}


class Compras{
protected:
    int ID_Compra, ID_Prov, ID_Art, Cant;
    float IVA, IIBB, Precio, ImporteFinal, Descuento;
    Fecha Fechafac;
    bool VC;
public:
    bool Cargar_Factura();
    void Mostrar_Factura();
    int setIDcompra(int idc){ID_Compra=idc;}
    float setIVA(float iva){IVA=iva;}
    float setIIBB(float iibb){IIBB=iibb;}
    int setIDporv(int idp){ID_Prov=idp;}
    float setPrecio(float p){Precio=p;}
    void setImporteFinal(float iFc){ImporteFinal=iFc;}
    void setFechafac(Fecha fec){Fechafac=fec;}
    int setCant(int c){Cant=c;}
    int setID(int id){ID_Art=id;}
    bool setVC(bool vc){VC=vc;}
    float setDescuento(float d){Descuento=d;}
    float getDescuento(){return Descuento;}
    bool getVC(){return VC;}
    int getCant(){return Cant;}
    int getID(){return ID_Art;}
    int getIDcompra(){return ID_Compra;}
    float getIVA(){return IVA;}
    float getIIBB(){return IIBB;}
    int getIDprov(){return ID_Prov;}
    float getPrecio(){return Precio;}
    float getImporteFinal(){return ImporteFinal;}
    Fecha getFechafac(){return Fechafac;}
    bool grabarEnDiscoFacturas(){
            FILE *aFact;
            bool grabo;
            aFact=fopen("Facturas.dat", "ab");
            if(aFact==NULL){
                return false;
            }
            grabo=fwrite(this,sizeof *this,1,aFact);
            fclose(aFact);
            return grabo;
    }
    bool leerEnDiscoFacturas(int pos){
        FILE *aFact;
        bool leyo;
        aFact=fopen("Facturas.dat", "rb");
        if(aFact==NULL){
            return false;
        }
        fseek(aFact, pos * sizeof *this,0);
        leyo=fread(this,sizeof *this,1,aFact);
        fclose(aFact);
        return leyo;
        }
    };

bool Compras::Cargar_Factura(){
    VC=false;
    showcursor();
    cout<<"Ingrese numero de factura: ";
    cin>>ID_Compra;
    if(ValidarIDcomp(ID_Compra)){
    cout<<endl;
    cout<<"Ingrese fecha: ";
    Fechafac.CargarFecha();
    cout<<"Ingrese ID del proveedor: ";
    cin>>ID_Prov;
    if(BuscarProveedor(ID_Prov!=-1)){
    cout<<endl;
        if(BuscarProveedor(ID_Prov)!=-1){
        cout<<"Ingrese IVA: %";
        cin>>IVA;
        if(validarIVA(IVA)){
            cout<<endl;
            cout<<"Ingrese IIBB (%2.5, %3, %3.5): %";
            cin>>IIBB;
                if(validarIIBB(IIBB)){
                    cout<<endl;
                    cout<<"Ingrese descuento: ";
                    cin>>Descuento;
                    if(validarDesc(Descuento)){
                        cout<<"Ingrese ID de articulo: ";
                        cin>>ID_Art;
                        ImporteFinal=0;
                            while(ID_Art!=0){
                                cout<<"Cantidad: ";
                                cin>>Cant;
                                    if(BuscarArt(ID_Art)){
                                    ModStock(ID_Art, Cant, VC);
                                    }
                            cout<<endl;
                            cout<<"Ingrese precio: $";
                            cin>>Precio;
                            cout<<endl;
                            ImporteFinal+=Importe(Precio, Cant, IVA, Descuento, IIBB);
                            cout<<"Ingrese ID de articulo(ingrese 0 para finalizar la carga): ";
                            cin>>ID_Art;
                            }
                            cout<<"Importe Final: $"<<ImporteFinal<<endl;
                            return true;
                        }else{return false;}
                    }else{return false;}
                }else{return false;}
            }else{return false;}
    }else{cout<<"No se encontro proveedor con ese ID."<<endl;
            return false;
            }
    }else{cout<<"El id ingresado ya se encuentra en uso."<<endl;
            return false;
            }
}

void Compras::Mostrar_Factura(){
cout<<"ID de compra: "<<ID_Compra<<endl;
cout<<"Fecha: ";Fechafac.MostrarFecha(); cout<<endl;
cout<<"Importe Final: $"<<ImporteFinal<<endl;
}


#endif // CLASES_H_INCLUDED
