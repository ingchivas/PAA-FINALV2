#pragma once

#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <string>
#include "autos.h"
using namespace std;

void imprimirStock(vector<Auto> Storage)
{
    for(int i=0;i<Storage.size();i++)
    {
        cout << "-----------------------------------------------" << endl;
        cout << "Auto " << i+1 <<  endl;
        cout << "Modelo: " << Storage[i].get_modelo() << endl;
        cout << "Marca: " << Storage[i].get_marca()<< endl;
        cout << "Color: " << Storage[i].get_color()<< endl;
        (Storage[i].get_status() == '0')? cout << "Status: Disponible"<< endl : cout << "Status: No disponible"<< endl;
        cout << "Puertas: " << Storage[i].get_puertas()<< endl;
        cout << "Anio: " << Storage[i].get_ano()<< endl;
        cout << "Kilometraje: " << Storage[i].get_kmt() << endl;
        cout << "-----------------------------------------------" << endl;
    }
}

bool _escribirStock(string marca, string modelo, string color, string status, string puertas, string ano, string kilometraje)
{
    ofstream myfile;
    myfile.open("bucket_autos.csv", ios_base::app);
    myfile << endl << marca << ","<< modelo << ","<< color << ","<< status << ","<< puertas << ","<< ano << ","<< kilometraje;
    myfile.close();
    return true;
}

void _anadirStock(string marca, string modelo, string color, string status, string puertas, string ano, string kilometraje)
{
    double kmtraje = stod(kilometraje);
    int npuertas = stoi(puertas);
    int anos = stoi(ano);
    bool st = stoi(status);

    Storage.emplace_back();
    int index = Storage.size() - 1;
    
    Storage[index].set_modelo(modelo);
    Storage[index].set_marca(marca);
    Storage[index].set_color(color);
    Storage[index].set_status(st);
    Storage[index].set_puertas(npuertas);
    Storage[index].set_ano(anos);
    Storage[index].set_kmt(kmtraje);
}


void actualizarStock(vector <Auto> Storage)
{
    string mc, mo, cl, st, pt, an, km;
    cout << "Ingrese la marca: " << endl;
    cin >> mc;
    cout << "Ingrese el modelo: " << endl;
    cin >> mo;
    cout << "Ingrese el color: " << endl;
    cin >> cl; 
    do
    {
        cout << "Ingrese el status (0-Disponible 1-Ocupado): " << endl;
        cin >> st;
        if(stoi(st) > 2)
        {
            cout << "El automovil solo puede estar 0-Disponible o 1-Ocupado" << endl;
        }
    }while(stoi(st) > 2);

    do
    {
        cout << "Ingrese el numero de puertas: " << endl;
        cin >> pt;
        if(stoi(pt) < 2)
        {
            cout << "El numero de puertas registradas deben ser minimo 2" << endl;
        }
    }while(stoi(pt) < 2);

    do 
    {
        cout << "Ingrese el anio: " << endl;
        cin >> an;
        if(stoi(an) < 0)
        {
            cout <<  "El anio introducido no es valido";
        }
    }while(stoi(an) < 0);

    do 
    {
        cout << "Ingrese el kilometraje: " << endl;
        cin >> km;
        if(stoi(km) < 0)
        {
            cout <<  "El kilometraje introducido no es valido";
        }
    }while(stoi(km) < 0);
    
    _escribirStock(mc, mo, cl, st, pt, an, km);
    _anadirStock(mc, mo, cl, st, pt, an, km);
}