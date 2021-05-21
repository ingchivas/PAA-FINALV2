#include <iostream>
#include <string>
#include "autos.h"
#include "leercsv.h"
#include "inventario.h"
#include "registros.h"

using namespace std;

int main()
{   
    unsigned int opc;
    bool rep = true;
    InvAutos();
    
    //funcion para leer stock
    do
    {
        cout << "\n\nBienvenido a las CARROZAS MAS PETES DEL MUNDO\n"
        << "\nPura chingoneria\n"
        << "\n---Por favor, elija que desea hacer: ---\n"
        << "\n[1] Consultar stock"
        << "\n[2] Actualizar archivo CSV"
        << "\n[3] Registrar una venta"
        << "\n[4] Registrar una compra"
        << "\n[5] Generar un reporte de ventas"
        << "\n[6] Salir del programa"
        << "\nSu opcion: ";

        cin >> opc;
        
        switch (opc)
        {
            case 1:
                cout << "\n\n . . . Generando una consulta de stock . . .\n";
                imprimirStock(Storage);
                break;

            case 2:
                cout << "\n\n . . . Actualizando archivo CSV . . .\n";
                actualizarStock(Storage);
                break;

            case 3:
                cout << "\n\n . . . Registrando venta . . .\n";
                Venta(Storage);
                break;

            case 4:
                cout << "\n\n . . . Registrando compra . . .\n"; 
                Compra(Storage);
                break;

            case 5:
                cout << "\n\n . . . Generando un reporte de ventas . . .\n";
                Reporte(cont_ventas, cont_compras);
                break;

            case 6:
                cout << "\n\n . . . Cerrando el programa . . .";
                cout << "\nGracias por utilizar el programa de la concesionaria!";
                rep = false;
                
                cout << "\nPrograma cerrado con exito.";
                break;

            default :
                cout << "\nOpcion invalida, por favor revise sus datos y vuelva a intentarlo";
                break;  
        }

    } while(rep == true);
    
}