#include <iostream>
#include "Lista.h"

#include <string>
using namespace std;

int main() {
    string valor;
    Nodo *temp;
    bool encontrado = false;
    Lista *l = new Lista();
    l->crearLista();
    l->insertarCabezaLista("Mario Llorente",0);
   // l->visualizar();
    string opc;
    while (true) {
        cout << "\n\nBienvenido al hotel *****\n";
        cout << "Selecciona alguna opción: \n";
        cout << "-> 0. Cerrar.\n";
        cout << "-> 1. Ingresar nuevo huesped.\n";
        cout << "-> 2. Buscar huesped.\n";
        cout << "-> 3. Mostrar lista en orden alfabético.\n";
        cout << "-> 4. Mostrar lista en orden de llegada.\n";
        cout << "-> 5. Consultar vecinos.\n";
        cout << "--> Opción: ";
        cin >> opc;
        if (opc.compare("1")==0) {
            l->crearLista();
        } else if (opc.compare("0")==0) {
            cout << "\n-> Gracias por usar, byee. <-\n";
            break;
        } else if (opc.compare("2")==0) {
            l->buscarHuesped();
        } else if (opc.compare("3")==0) {
            l->organizarAlfab();
        } else if (opc.compare("4")==0) {
            cout << "\n-> Huespedes en orden de llegada <3.\n";
            l->visualizar();
        } else if (opc.compare("5")==0){
            l->verVecinos();
        } else{
            cout << "Opción inválida.\n";
        }



    }
    /*
    cout << "Ingrese el valor a buscar: ";
    cin >> valor;


    temp = l->buscarLista(valor);
    if (temp != NULL) {
        cout << "El valor " << temp->getDataNodo() << " se encuentra en la lista" << endl;
    } else {
        cout << "El valor " << valor << " no se encuentra en la lista" << endl;
    }*/

    return 0;
}
