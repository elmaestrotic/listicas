//
// Created by Alexander on 27/08/2022.
//

#include "Lista.h"
#include "Nodo.h"
#include <iostream>
#include <fstream>
#include <string>
#include <random>
#include <algorithm>
//#include <bits/stdc++.h>
using namespace std;
int cont1=0;
void Lista::Lista::crearLista() {
    if (cont1 == 0) {
        string x;
        string h;
        string a;
        int i;
        int cont = 0;
        ifstream Archivo("hotel.txt");
        while (getline(Archivo, x)) {
            if (cont % 2 == 0) {
                h = x;

            } else {
                a = x;
                i = std::stoi(a);
            }
            if (cont % 2 != 0 && cont > 0) {
                //
                if (cont>1){
                    insertarUltimo(h, i);
                }else{
                    primero = new Nodo(h,i, primero);
                }

            }
            cont++;
        }
        Archivo.close();
        cont1++;
    } else {
        Nodo *n;
        n = primero;
        int cont = 0;
        string nombre;
        int habitacion;
        cin.ignore();
        cout << "Ingrese el nombre: \n";
        getline(cin, nombre);
        cout << "Ingrese la habitacion: \n";
        cin >> habitacion;
        while (n != NULL) {
            if (habitacion == n->getDataNodo2()) {
                cont++;
            }
            n = n->getEnlaceNodo();
        }
        if (cont == 0) {
            //primero = new Nodo(nombre,habitacion, primero);
            insertarUltimo(nombre, habitacion);
            escribirTexto(nombre,habitacion);
            cout << nombre << " en la habitacion " << habitacion << " ha sido ingresado correctamente. \n";
        } else {
            string opc1;
            int habitacion1=habitacion-1;
            int habitacion2=habitacion+1;
            int v2;
            int count=0, cont1=0,cont2=0;
            Nodo *n;
            n = primero;
            while (n != NULL) {
                if (habitacion1 == n->getDataNodo2()) {
                    cont1++;
                }else if(habitacion2==n->getDataNodo2()){
                    cont2++;
                }
                n = n->getEnlaceNodo();
            }
            if(cont1==0 || cont2==0){
                if (cont1==0){
                    cout << "Podemos ofrecerle la habitacion " << habitacion1 << " ¿Desea aceptarla? 1. Si/ 2. No: ";
                    cin >> opc1;
                    if (opc1.compare("1")==0) {
                        insertarUltimo(nombre, habitacion1);
                        escribirTexto(nombre,habitacion1);
                        cout << nombre << " en la habitacion " << habitacion1 << " ha sido ingresado correctamente. \n";
                    } else if (opc1.compare("2")==0) {
                        cout << "Cancelando reserva\n";
                    }

                }else if(cont2==0){
                    cout << "Podemos ofrecerle la habitacion " << habitacion2 << " ¿Desea aceptarla? 1. Si/ 2. No: ";
                    cin >> opc1;
                    if (opc1.compare("1")==0) {
                        insertarUltimo(nombre, habitacion2);
                        escribirTexto(nombre,habitacion2);
                        cout << nombre << " en la habitacion " << habitacion2 << " ha sido ingresado correctamente. \n";
                    } else if (opc1.compare("2")==0) {
                        cout << "Cancelando reserva\n";
                    }
                }
            }else{
                cout << "\nNinguna de las habitaciones vecinas esta vacia. \n";
                Nodo *a;
                a = primero;
                while(true){
                    random_device rd;
                    mt19937 mt(rd());
                    uniform_real_distribution<double> dist(1, 100);
                    v2=dist(mt);
                    while (a != NULL) {
                        if (v2 == a->getDataNodo2()) {
                            count++;
                        }
                        a = a->getEnlaceNodo();
                    }
                    if(count==0){
                        string opc;
                        cout << "Podemos ofrecerle la habitacion " << v2 << " ¿Desea aceptarla? 1. Si/ 2. No: ";
                        cin >> opc;
                        if (opc.compare("1")==0) {
                            insertarUltimo(nombre, v2);
                            escribirTexto(nombre,v2);
                            cout << nombre << " en la habitacion " << v2 << " ha sido ingresado correctamente. \n";
                            break;
                        } else if (opc.compare("2")==0) {
                            cout << "-> Cerrando seleccion.";
                            break;
                        }else{
                            cout << "-> Opción Invalida.";
                            break;
                        }
                    }else{
                        cout << "-> Inténtelo de nuevo.";
                        break;
                    }
                }
            }
        }
    }
}
void Lista::escribirTexto(string nombre, int habi) {
    fstream fileAdd;
    string name ="hotel.txt";
    fileAdd.open( name.c_str(), ios::app);
    fileAdd << nombre << endl;
    fileAdd << habi << endl;
    fileAdd.close();

}

void Lista::buscarHuesped() {
    string opc;
    Nodo *n;
    int k = 0;
    n = primero;
    string nombre;
    int hab, cont=0;
    cout << "Buscar huesped: ";
    cout << "Desea ingresar el nombre o la habitacion del usuario? 1. Nombre / 2. Habitacion: ";
    cin >> opc;
    if (opc.compare("1")==0) {
        cin.ignore();
        cout << "Ingrese el nombre del huesped a buscar: ";
        getline(cin,nombre);
        while (n != NULL) {
            if(nombre.compare(n->getDataNodo())==0){
                cout << "\nHuesped encontrado!: ";
                cout << "\nNombre del huesped: "<<n->getDataNodo();
                cout << "\nNumero de habitacion: "<< n->getDataNodo2() ;
                cont++;
            }
            n = n->getEnlaceNodo();
        }
    } else if (opc.compare("2")==0) {
        cout << "Ingrese el numero de la habitacion a buscar: ";
        cin >> hab;
        while (n != NULL) {
            if(hab==n->getDataNodo2()){
                cout << "\nHabitacion encontrada!: ";
                cout << "\nNombre del huesped: "<<n->getDataNodo();
                cout << "\nNumero de habitacion: "<< n->getDataNodo2() ;
                cont++;
            }
            n = n->getEnlaceNodo();
        }

    }else{
        cout << "Opción invalida.\n";
        buscarHuesped();
    }if(cont==0){
        cout <<"\n----> No se ha encontrado el huesped. <----\n";
    }
}



Lista::Lista() { primero = NULL; }//inicializamos el puntero primero con NULL al momento de crear la lista, es decir este es el puntero head cuando se crea la lista}

void Lista::insertarCabezaLista(string entrada, int entrada2) {
    Nodo *nuevo;
    nuevo = new Nodo(entrada, entrada2);
    nuevo->ponerEnlace(primero); // enlaza nuevo con primero
    primero = nuevo; // mueve primero y apunta al nuevo nodo
}

void Lista::insertarUltimo(string entrada, int entrada2) {
    Nodo *ultimo = this->getUltimo();//seobtine la dirmem del último nodo
    ultimo->ponerEnlace(new Nodo(entrada,entrada2));//se crea el nuevo nodo con el valor de entrada
}

Nodo *Lista::getUltimo() {
    Nodo *n = primero;
    if (n == NULL) throw "Error, lista vacía";
    while (n->getEnlaceNodo() != NULL) n = n->getEnlaceNodo();
    return n;
}

void Lista::insertarLista(Nodo *anterior, string entrada, int entrada2) {
    Nodo *nuevo;
    nuevo = new Nodo(entrada, entrada2);
    nuevo->ponerEnlace(anterior->getEnlaceNodo());
    anterior->ponerEnlace(nuevo);
}
void Lista::verVecinos(){
    int hab,vec1,vec2, cont1,cont2;
    Nodo *n;
    n=primero;
    cout << "\nIngresa el numero de la habitacion del huesped a buscar los vecinos: \n";
    cin >> hab;
    vec1=hab-1;
    vec2=hab+1;
    while (n != NULL) {
        if(vec1==n->getDataNodo2()){
            cout << "\nNombre del vecino: "<< n->getDataNodo() <<"\nHabitación: "<<n->getDataNodo2()<<"\n";
            cont1++;
        }else if(vec2==n->getDataNodo2()){
            cout << "\nNombre del vecino: "<< n->getDataNodo() <<"\nHabitación: "<<n->getDataNodo2()<<"\n";
            cont2++;
        }
        n = n->getEnlaceNodo();
    }
    if(cont1==0 || cont2==0){
        cout << "\n---> No tiene vecinos <--- \n";
    }
}


Nodo *Lista::buscarLista(string destino) {
    Nodo *temp;
    for (temp = primero; temp != NULL; temp = temp->getEnlaceNodo()) {
        if (destino == temp->getDataNodo()) {
            return temp;
        }
    }
    return NULL;
}
void Lista::organizarAlfab(){
    vector<string> lista{};
    Nodo *n;
    n = primero;
    int cont=0;
    while (n != NULL) {
        lista.push_back(n->getDataNodo());
        n = n->getEnlaceNodo();
    }
    sort(lista.begin(), lista.end());
    Nodo *a;
    cout << "\n---> Lista en orden alfabetico <---\n";
    while(true){
        a = primero;
        while (a != NULL) {
            if(lista[cont].compare(a->getDataNodo())==0){
                cout <<"\n---> "<< a->getDataNodo() << " - " << a->getDataNodo2();
                cont++;
            }
            a = a->getEnlaceNodo();
        }
       if(cont==lista.size()){
            break;
       }
    }
}


void Lista::visualizar() {
    Nodo *n;
    int k = 0;
    n = primero;
    while (n != NULL) {
        char c;
        k++;
        c = (k % 15 != 0 ? ' ' : '\n');
        cout <<"\n---> " << n->getDataNodo() <<" - "<< n->getDataNodo2() << c;
        n = n->getEnlaceNodo();
    }

}
void Lista::eliminar(string entrada) {
    Nodo *actual, *anterior;
    bool encontrado;
    actual = primero;
    anterior = NULL;
    encontrado = false;
    // búsqueda del nodo y del anterior
    while ((actual != NULL) && !encontrado) {
        encontrado = (actual->getDataNodo() == entrada);
        if (!encontrado) {
            anterior = actual;
            actual = actual->getEnlaceNodo();
        }
    }

    // enlace del nodo anterior con el siguiente
    if (actual != NULL) {
        // distingue entre cabecera y resto de la lista
        if (actual == primero) {
            primero = actual->getEnlaceNodo();
        } else {
            anterior->ponerEnlace(actual->getEnlaceNodo());
        }
        delete actual;
    }
}
