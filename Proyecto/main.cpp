#include <iostream>
#include <cstring>
#include "organiza.h"

//Edgar Alexander Carrizalez Lerín A01024901

/*
Selecciona un algoritmo de ordenamiento adecuado al problema = Buble Sort
Selecciona y usa una estructura lineal adecuada al problema = Lista Ligada
Usa un árbol adecuado para resolver un problema = Arbol binario 
Usa grafos para hacer analisis de información 
Usa un algoritmo de búsqueda en grafos adecuado para resolver un problema
Usa un algoritmo de hashing adecauado para resolver un problema

Implementa mecanismos para consultar información de las estructras correctos = Main. caso 3-5
Implementa mecanismos de lectura de archivos correctos = metodos readlocal
Implementa mecanismos de escritura de archivos correctos = metodos addCp y Addproducto
*/

using namespace std;

int main (){
    list <Producto>tiendas;
    Ubicacion ubi;
    Producto pro;
    string cp1 , lat1 , lon1;
    string ID, vol , dia , mes;
    Ordenamiento tienda;
    tiendas = tienda.readLocal();

    int opc, exit = 0;
    do{
        cout << "Bienvenido a envios Carrizalez \nLe presentamos un numero de funciones a las que puede acceder para cotizar su envio" << endl;
        cout << "------------------------------------\n";
        cout << "1.- Agregar codigo postal \n2.- Buscar codigo postal " << endl;            
        cout << "3.- Mostrar todos los CP y coordenadas  \n4.- Mostrar lista de productos enviados  \n5.- Mostrar productos por volumen " << endl;
        cout << "6.- Agregar producto \n7.- Salir \nIntrodusca opcion: ";

        cin >> opc; 

        switch (opc){
            case 1: //Funciona 
            {
                cout << "<<<<<<<<<<<< Agrega CP >>>>>>>>>>>>" << endl;
                cout << "Introduzca el codigo postal: ";
                cin >> cp1;
                cout << "Introduzca la latitud: ";
                cin >> lat1;
                cout << "Introduzca la longitud: ";
                cin >> lon1;
                Ubicacion ejemplo(cp1 , lat1 , lon1);
                tienda.addCP (ejemplo);
                cout << "------------------------------------\n";
                break;
            }
            case 2: //Funciona 
                cout << "<<<<<<<<<<<< Buscar CP >>>>>>>>>>>>" << endl;
                cout << "Que codigo postal buscas: ";
                cin >> cp1;
                tienda.searchCP(cp1);
                cout << "------------------------------------\n";
                break;
            case 3:
                cout << "<<<<<<<<<<<< Mostrar todos los CP y coordenadas >>>>>>>>>>>>" << endl;
                tienda.showCPList();
                cout << "------------------------------------\n";
                break;
            case 4: //Funciona
                cout << "<<<<<<<<<<<< Mostrar lista de productos >>>>>>>>>>>>" << endl;
                tienda.showP_list();
                cout << "------------------------------------\n";
                break;
            case 5: //Funciona
                cout << "<<<<<<<<<<<< Mostrar  por volumen >>>>>>>>>>>>" << endl;
                cout << tienda.showVol();
                cout << "------------------------------------\n";
                break;
            case 6:{
                cout << "<<<<<<<<<<<< Agregar producto >>>>>>>>>>>>" << endl;
                cout << "Introduzca el volumen: ";
                cin >> vol;
                cout << "Introduzca el día: ";
                cin >> dia;
                cout << "Introduzca la mes: ";
                cin >> mes;
                cout << "Introduzca la ID: ";
                cin >> ID;
                Producto ejemploP (ID , dia , mes , vol);
                tienda.addPro(ejemploP);
                cout << "------------------------------------\n";
                break;}
            case 7: //Funciona
                cout << "<<<<<<<<<<<< Gracias por participar >>>>>>>>>>>>" << endl;
                exit = 1;
                cout << "------------------------------------\n";
                break;
            
            cout << "------------------------------------\n\n";
        } 
    } while (exit == 0);
return 0;
}
