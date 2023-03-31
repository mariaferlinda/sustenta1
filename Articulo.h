#include <iostream>
#include <string>
#include <sstream>
using namespace std;
class Articulo
{
private:

   public:
    string nombre;
    int cantidad;
    int id;
    int precio;
    int tipo;//1 -> Deportivo; 2 -> Tecnologico
    int impuesto = 5;
    float totalt;

    Articulo() {}

    int Articulo::ArticuloExtra(){}

    Articulo(string nombre, int cantidad, int id, int precio, int tipo)
    {
        this->nombre = nombre;
        this->cantidad = cantidad;
        this->id = id;
        this->precio = precio;
        this->tipo = tipo;

    }

    int Articulo::ArticuloExtra(string nombre, int cantidad, int id, int precio, int tipo, float totalt)
    {
        this->nombre = nombre;
        this->cantidad = cantidad;
        this->id = id;
        this->precio = precio;
        this->tipo = tipo;
        this->totalt = totalt;
    }
};

