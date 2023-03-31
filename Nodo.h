#pragma once
#include <cstddef>
#include "Articulo.h"
class Nodo
{
public:
    Articulo* dato;
    Nodo* siguiente;
    Nodo(Articulo* dato)
    {
        this->dato = dato;
        this->siguiente = NULL;
    }
};

