#pragma once
#include <iostream>
#include <string>
#include <sstream>
#include "Nodo.h"
using namespace std;
class Lista
{

private:
    void agregarRecursivo(Nodo* n, Articulo* dato)
    {
        if (n->siguiente == NULL)
        {
            n->siguiente = new Nodo(dato);
        }
        else
        {
            this->agregarRecursivo(n->siguiente, dato);
        }
    }

    void imprimirRecursivo(Nodo* n, int tipo)
    {
        Nodo* nodo = n;
        string tipo1;
        string tipo2;
        while (nodo != NULL) {
            if (nodo->dato->tipo == 1 && (tipo == 1 || tipo == 0))
            {
                tipo1 = tipo1 + " Id: " + to_string(nodo->dato->id) + " Articulo: " + nodo->dato->nombre + "\n";
            }
            else  if (nodo->dato->tipo == 2 && (tipo == 2 || tipo == 0))
            {
                tipo2 = tipo2 + " Id: " + to_string(nodo->dato->id) + " Articulo: " + nodo->dato->nombre + "\n";
            }
            nodo = nodo->siguiente;
        }
        if (tipo == 1 || tipo == 0)
        {
            cout << "Articulos Deportivos " << std::endl;
            cout << tipo1;
        }
        if (tipo == 2 || tipo == 0)
        {
            cout << "Articulos Tecnologicos " << std::endl;
            cout << tipo2;
        }
    }

    void impuesto(Nodo* n)
    {
        Nodo* nodo = n;
        float totalimp = 0;
        while (nodo != NULL)
        {
            totalimp = nodo->dato->precio * (nodo->dato->impuesto/100);
            nodo->dato->totalt = nodo->dato->precio + totalimp;
        }
    }

    void imprimirTotalRecursivo(Nodo* n)
    {
        Nodo* nodo = n;
        string registros;
        int total = 0;
        cout << "Articulos a facturar " << std::endl;
        while (nodo != NULL) {

            registros = registros + " Id: " + to_string(nodo->dato->id) + " Articulo: " + nodo->dato->nombre + " Cantidad: " + to_string(nodo->dato->cantidad) + " Precio: " + to_string(nodo->dato->precio) + "\n";
            total = total + (nodo->dato->cantidad * nodo->dato->totalt);
            nodo = nodo->siguiente;
        }

        cout << registros;
        cout << "Total a pagar " << std::endl;
        cout << total << std::endl;

    }

    void eliminarRecursivo(Nodo* n, int id)
    {
        if (n == NULL)
        {
            return;
        }
        if (n->dato->id == id && n == this->cabeza)
        {
            Nodo* temporal = this->cabeza;
            if (this->cabeza->siguiente != NULL)
            {
                this->cabeza = this->cabeza->siguiente;
                delete temporal;
            }
            else
            {
                this->cabeza = NULL;
            }
            return;
        }
        if (n->siguiente != NULL && n->siguiente->dato->id == id)
        {
            Nodo* temporal = n->siguiente;
            if (n->siguiente != NULL)
            {
                n->siguiente = n->siguiente->siguiente;
            }
            delete temporal;
        }
        else
        {
            this->eliminarRecursivo(n->siguiente, id);
        }
    }
    bool existeRecursivo(Nodo* n, int id)
    {
        if (n == NULL)
        {
            return false;
        }
        if (n->dato->id == id)
        {
            return true;
        }
        return this->existeRecursivo(n->siguiente, id);
    }

    Articulo* obtenerRecursivo(Nodo* n, int id)
    {
        if (n == NULL)
        {
            return new Articulo();
        }
        if (n->dato->id == id)
        {
            return n->dato;
        }
        return this->obtenerRecursivo(n->siguiente, id);
    }

    bool actualizarRecursivo(Nodo* n, Articulo* dato)
    {
        if (n == NULL)
        {
            return false;
        }
        if (n->dato->id == dato->id)
        {
            n->dato = dato;
            return true;
        }
        return this->actualizarRecursivo(n->siguiente, dato);
    }

public:
    Nodo* cabeza;

    bool eliminar(int id)
    {
        if (existe(id))
        {
            this->eliminarRecursivo(this->cabeza, id);
            return true;
        }
        else {
            cout << "No existe un articulo con Id : " << to_string(id) << std::endl;
            return false;
        }
    }
    bool agregar(Articulo* dato)
    {
        if (!existe(dato->id))
        {
            if (this->cabeza == NULL)
            {
                this->cabeza = new Nodo(dato);
            }
            else
            {
                this->agregarRecursivo(this->cabeza, dato);
            }
            return true;
        }
        else {
            cout << "Ya existe un articulo con Id : " << to_string(dato->id) << std::endl;
            return false;
        }
    }

    void imprimir(int tipo)
    {
        if (tipo <= 2)
        {
            this->imprimirRecursivo(this->cabeza, tipo);
        }
        else {
            cout << "No hay Articulos asociados al Tipo : " << to_string(tipo) << std::endl;
        }
    }
    bool existe(int id)
    {
        return this->existeRecursivo(this->cabeza, id);
    }

    Articulo* obtener(int id)
    {
        return this->obtenerRecursivo(this->cabeza, id);
    }

    bool actualizar(Articulo* dato)
    {
        return this->actualizarRecursivo(this->cabeza, dato);
    }

    bool esVacia()
    {
        return this->cabeza == NULL;
    }

    void imprimirTotal()
    {
    return this->imprimirTotalRecursivo(this->cabeza);
    }

};

