#pragma once;

#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <string>
#include "autos.h"

void Ficha(vector <Auto> Storage)
{
    string mod;
    bool err = false;
    do
    {
        err = false;
        cout << "Ingrese el modelo para imprimir su ficha tecnica: " << endl;
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
            ofstream ficha;
            ficha.open("ficha_promocional.txt");
            ficha << "-----------------------------------------------" << endl;
            ficha << "Modelo: " << Storage[index].get_modelo() << endl;
            ficha << "Marca: " << Storage[index].get_marca()<< endl;
            ficha << "Color: " << Storage[index].get_color()<< endl;
            (Storage[index].get_status() == '0')? ficha << "Status: Disponible"<< endl : ficha << "Status: No disponible"<< endl;
            ficha << "Puertas: " << Storage[index].get_puertas()<< endl;
            ficha << "Anio: " << Storage[index].get_ano()<< endl;
            ficha << "Kilometraje: " << Storage[index].get_kmt() << endl;
            ficha << "-----------------------------------------------" << endl;
            ficha.close();
            cout << "Ficha generada con exito. " << endl;
        }
    } while (err == true);
    char op;
    cout << "Desea generar otra ficha? S/N" << endl;
    cin >> op;
    if(tolower(op) == 's')
    {
        Ficha(Storage);
    }
    else
    {
        cout << "Fichas generadas existosamente, regresando al programa principal" << endl;
    }
}