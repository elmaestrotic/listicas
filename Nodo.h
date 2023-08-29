//
// Created by Alexander on 27/08/2022.
//

#ifndef LISTICAS_NODO_H
#define LISTICAS_NODO_H
#include <string>
using namespace std;


class Nodo {
protected:
    string dato;
    int dato2;
    Nodo *enlace;
public:
    Nodo(string t, int h);

    Nodo(string p ,int h, Nodo *n);

    string getDataNodo() const;
    int getDataNodo2() const;

    Nodo *getEnlaceNodo() const;


    void ponerEnlace(Nodo *sgte);

};

#endif //LISTICAS_NODO_H
