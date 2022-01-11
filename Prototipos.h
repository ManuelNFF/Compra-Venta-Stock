#ifndef PROTOTIPOS_H_INCLUDED
#define PROTOTIPOS_H_INCLUDED

void menu_articulo();
void menu_ventas();
void menu_cliente();
void menu_proveedor();
//********* VENTA *********
float BuscarArticuloPrecio(int ID_Articulo);
bool BuscarArticuloStock(int ID_Articulo, float Cantidad);
float Importe(float Precio, int Cantidad, float IVA, float Descuento, float IIBB);
bool ValidarIDvent(int ID_Venta);
bool validarIIBB(float IIBB);
bool validarDesc(float Descuento);
bool validarIVA(float IVA);
void CargarVenta();
void MostrarVenta();
void MostrarTodasVentas();
void cargarCadena(char *pal, int tam);
//*********ARTICULO*********
void AgregarArticulo();
void ListarArticulo();
bool ArticuloID();
bool ValidarIDart(int ID_Articulo);
bool ModStock(int ID_Articulo, float Cantidad, bool VC);
int BuscarArticuloID(int id);
bool BuscarArt(int id);
bool EliminarArticulo();
bool RestaurarArticulo();
void Stock();
bool validarStock(int Stock);
bool validarPrecio(float Precio);
//**********CLIENTE**********
void AgregarCliente();
void ListarClientes();
bool ValidarIDcli(int ID_Cliente);
bool EliminarCliente();
int BuscarClienteID(int id);
bool ModificarCliente();
//*********PROVEEDOR*********
void AgregarProveedor();
void ListarProveedor();
bool ProveedorID();
bool ValidarIDPro(int ID_Articulo);
int BuscarProveedor(int id);
bool ModificarProveedor();
bool EliminarProveedor();
bool RestaurarProveedor();
//**********COMPRAS********
void CargarFactura();
void MostrarFactura(int ID_Prov);
void MostrarTodasFacturas();
int Cant_regProv();
bool ValidarIDcomp(int ID_Compra);
#endif // PROTOTIPOS_H_INCLUDED
