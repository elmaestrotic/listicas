//
// Created by Alexander on 27/08/2022.
//
#include "Nodo.h"
#include <string>
using namespace std;


Nodo::Nodo(string t, int h)
{
    dato = t;
    dato2 = h;
    enlace = 0; // 0 es el puntero NULL en C++
}
Nodo::Nodo(string d, int h, Nodo* n) // crea el nodo y lo enlaza a n
{
    dato = d;
    dato2 = h;
    enlace = n;
}

string Nodo::getDataNodo( ) const
{
    return  dato;
}
int Nodo::getDataNodo2( ) const
{
    return dato2;
}

Nodo *Nodo::getEnlaceNodo( ) const
{
    return enlace;
}

void Nodo:: ponerEnlace(Nodo* sgte)
{
    enlace = sgte;
}