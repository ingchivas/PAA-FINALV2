#pragma once

#include <iostream>
#include <string>
#include <ctime>
#include "autos.h"

using namespace std;

int cont_ventas = 0, cont_compras = 0;

void Venta(vector <Auto> Storage)
{
    string mod;
    bool err = false;
    do
    {
        err = false;
        cout << "Ingrese el modelo que se va a vender: " << endl;
        cin >> mod;
        int index = -1;
        for(int i = 0; i < Storage.size(); i++)
        {
            if (Storage[i].get_modelo() == mod)
            {
                index = i;
                err == false;
            }
        }
        if(index == -1)
        {
            cout << "Modelo no registrado, revise sus datos y vuelva a intentarlo" << endl;
            err = true;
        }
        else
        {
            if(Storage[index].get_status() == 0)
            {
                cout << "Vehiculo disponible, realizando pedido . . ." << endl;
                cont_ventas++;
            }
            else 
            {
                cout << "El vehiculo no se encuentra disponible en el momento" << endl;
            }
        }
    } while (err == true);
    char op;
    cout << "Desea registrar otra venta? S/N" << endl;
    cin >> op;
    if(tolower(op) == 's')
    {
        Venta(Storage);
    }
    else
    {
        cout << "Ventas registradas existosamente, regresando al programa principal" << endl;
    }
}

void Compra(vector <Auto> Storage)
{
    string mod;
    bool err = false;
    do
    {
        err = false;
        cout << "Ingrese el modelo que se va a comprar: " << endl;
        cin >> mod;
        int index = -1;
        for(int i = 0; i < Storage.size(); i++)
        {
            if (Storage[i].get_modelo() == mod)
            {
                index = i;
                err == false;
            }
        }
        if(index == -1)
        {
            cout << "Modelo no registrado, revise sus datos y vuelva a intentarlo" << endl;
            err = true;
        }
        else
        {
            if(Storage[index].get_status() == 1)
            {
                cout << "Vehiculo validado, generando compra . . ." << endl;
                cont_compras++;
            }
            else 
            {
                cout << "La concesionaria ya posee stock de este vehiculo" << endl;
            }
        }
    } while (err == true);
    char op;
    cout << "Desea registrar otra compra? S/N" << endl;
    cin >> op;
    if(tolower(op) == 's')
    {
        Compra(Storage);
    }
    else
    {
        cout << "Compras registradas existosamente, regresando al programa principal" << endl;
    }
}

string Tiempo()
{
    time_t tt;
    struct tm * ti;
    time (&tt);
    ti = localtime(&tt);

    return asctime(ti);
}

int cont = 0;

void Reporte(int ventas, int compras)
{
    cout << "-----------------------------------------" << endl;
    cout << "Ventas exitosas: " << ventas << " ventas" << endl;
    cout << "Compras exitosas: " << compras << " compras" << endl;
    cout << "-----------------------------------------" << endl;

    ofstream reg;
    
    string scont = to_string(cont);
    string filename = "reporte_" + scont + ".txt";
    reg.open(filename);
    reg << "-----------------------------------------" << endl;
    reg << "Hora de generación del reporte:" <<" " << Tiempo();
    reg << "Ventas exitosas: " << ventas << " ventas" << endl;
    reg << "Compras exitosas: " << compras << " compras" << endl;
    reg << "-----------------------------------------" << endl;
    cont++;
    reg.close();
}