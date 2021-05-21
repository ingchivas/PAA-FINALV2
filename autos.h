#pragma once
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Auto
{
    private:
        string marca;
        string modelo;
        string tipo;
        string color;
        bool status;
        int puertas;
        int ano;
        double kilometraje;

    public:
        Auto();
        ~Auto();
        // SETTERS
        void set_marca(string);
        void set_modelo(string);
        void set_tipo(string);
        void set_color(string);
        void set_status(bool);
        void set_puertas(int);
        void set_ano(int);
        void set_kilometraje(double);
        //GETTERS
        string get_marca();
        string get_modelo();
        string get_tipo();
        string get_color();
        bool get_status();
        int get_puertas();
        int get_ano();
        double get_kilometraje();
};
Auto::~Auto(){}
Auto::Auto(){}

// -------------------------------------SETTERS-------------------------------


void Auto::set_marca(string mrc)
{
    marca = mrc;
}
void Auto::set_modelo(string mod)
{
    modelo = mod;
}
void Auto::set_tipo(string tip)
{
    tipo = tip;
}
void Auto::set_color(string col)
{
    color = col;
}
void Auto::set_status(bool st)
{
    status = st;
}
void Auto::set_puertas(int npuertas)
{
    puertas = npuertas;
}
void Auto::set_ano(int an)
{
    ano = an;
}
void Auto::set_kilometraje(double km)
{
    kilometraje = km;
}

// -------------------------------------GETTERS-------------------------------

string Auto::get_marca()
{
    return marca;
}
string Auto::get_modelo()
{
    return modelo;
}
string Auto::get_tipo()
{
    return tipo;
}
string Auto::get_color()
{
    return color;
}
bool Auto::get_status()
{
    return status;
}
int Auto::get_puertas()
{
    return puertas;
}
int Auto::get_ano()
{
    return ano;
}
double Auto::get_kilometraje()
{
    return kilometraje;
}
