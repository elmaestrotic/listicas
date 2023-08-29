//
// Created by Alexander on 27/08/2022.
//

#ifndef LISTICAS_LISTA_H
#define LISTICAS_LISTA_H


#include <cstddef>
#include "Nodo.h"
#include <string>
using namespace std;

class Lista {
protected:
    Nodo *primero;//primero es un atributo. Es un puntero de tipo Nodo
    Nodo *anterior;
public:

    Lista();//Constructor de la lista. Al crearse la lista se debe inicializar el puntero *primero (head)  de modo que apunte a NULL

    void crearLista();

    void insertarCabezaLista(string entrada, int entrada2);
    void escribirTexto(string entrada, int entrada2);
    void insertarUltimo(string entrada,int entrada2);
    void verVecinos();
    void organizarAlfab();

    //void ultimo(int entrada);

    void insertarLista(string entrada,int entrada2);

    void insertarLista(Nodo* anterior, string entrada, int entrada2);//especial

    Nodo *buscarLista(string destino);

    void eliminar(string entrada);

    Nodo *getUltimo();

    void visualizar();
    void buscarHuesped();

};


#endif //LISTICAS_LISTA_H
