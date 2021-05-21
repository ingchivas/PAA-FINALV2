#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <string>
#include "autos.h"
using namespace std;

vector <Auto> Storage;

void InvAutos()
{
    ifstream csv("bucket_autos.csv");
    string klinea;
    char coma = ',';
    int cit = 0;
    getline(csv, klinea);
    while (getline(csv, klinea))
    {
        stringstream stream(klinea);
        string marca,modelo, color, status, puertas,ano, kilometraje;
        getline(stream, marca, coma);
        getline(stream, modelo, coma);
        getline(stream, color, coma);
        getline(stream, status, coma);
        getline(stream, puertas, coma);
        getline(stream, ano, coma);
        getline(stream, kilometraje, coma);

        double kmtraje = stod(kilometraje);
        int npuertas = stoi(puertas);
        int anos = stoi(ano);
        bool st = stoi(status);

        Storage.emplace_back();
        Storage[cit].set_marca(marca);
        Storage[cit].set_modelo(modelo);
        Storage[cit].set_color(color);
        Storage[cit].set_status(st);
        Storage[cit].set_puertas(npuertas);
        Storage[cit].set_ano(anos);
        Storage[cit].set_kilometraje(kmtraje);
        cit++;
        }
        csv.close();
    }
    
    