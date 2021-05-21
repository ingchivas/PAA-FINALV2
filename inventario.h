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
        cout << "Status: " << Storage[i].get_status()<< endl;
        cout << "Puertas: " << Storage[i].get_puertas()<< endl;
        cout << "Anio: " << Storage[i].get_ano()<< endl;
        cout << "Kilometraje: " << Storage[i].get_kilometraje()<< endl;
        cout << "-----------------------------------------------" << endl;
    }
}

bool escribirStock(string marca, string modelo, string color, string status, string puertas, string ano, string kilometraje)
{
    ofstream myfile;
    myfile.open("bucket_autos.csv", ios_base::app);
    myfile << endl <<marca << ","<< modelo << ","<< color << ","<< status << ","<< puertas << ","<< ano << ","<< kilometraje;
    myfile.close();
    return true;
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
    cout << "Ingrese el status (0-Disponible 1-Ocupado): " << endl;
    cin >> st;
    cout << "Ingrese el numero de puertas: " << endl;
    cin >> pt;
    cout << "Ingrese el ano aqui owo uwu *se sonroja*: " << endl;
    cin >> an;
    cout << "Ingrese el kilometraje: " << endl;
    cin >> km;
    escribirStock(mc, mo, cl, st, pt, an, km);
}


/*
ofstream myfile("bucket_autos.csv");
    if(myfile.is_open())
    {
        for(int i = 0; i < Storage.size; i++)
        {
            myfile << Storage[i].get_modelo() << "," << Storage[i].get_marca() << "," << Storage[i].get_color() << "," << Storage[i].get_status() << "," << Storage[i].get_puertas() << "," << Storage[i].get_ano() << "," << Storage[i].get_kilometraje()<< endl;
        }
        myfile.close();
        cout << "\nStock actualizado con exito";
    }
*/