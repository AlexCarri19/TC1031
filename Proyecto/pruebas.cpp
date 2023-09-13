#include <iostream>
#include <cstring>
#include <ctime>
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

void delay(int secs) {
  for(int i = (time(NULL) + secs); time(NULL) != i; time(NULL));
}

int main (){
    list <Producto>tiendas;
    Ubicacion ubi;
    Producto pro;
    string cp1 , lat1 , lon1;
    string ID, vol , dia , mes;
    Ordenamiento tienda;
    tiendas = tienda.readLocal();
/*
                cout << "<<<<<<<<<<<< Agrega CP >>>>>>>>>>>>" << endl;
                cout << "Introduzca el codigo postal: ";
                cp1 = "5471";
                cout << "Introduzca la latitud: ";
                lat1 = "19.488888";
                cout << "Introduzca la longitud: ";
                lon1 = "19.455655";
                Ubicacion ejemplo(cp1 , lat1 , lon1);
                tienda.addCP (ejemplo);
                cout << "------------------------------------\n";*/
delay (1);
                cout << "<<<<<<<<<<<< Buscar CP >>>>>>>>>>>>" << endl;
                cout << "Que codigo postal buscas: ";
                cp1 = "46000" ;
                cout<<tienda.searchCP(cp1);
                cout << "------------------------------------\n";
delay (1);/*
                cout << "<<<<<<<<<<<< Mostrar todos los CP y coordenadas >>>>>>>>>>>>" << endl;
                tienda.showCPList();
                cout << "------------------------------------\n";
delay (1);
                cout << "<<<<<<<<<<<< Mostrar lista de productos >>>>>>>>>>>>" << endl;
                tienda.showP_list();
                cout << "------------------------------------\n";
delay (1);

                cout << "<<<<<<<<<<<< Mostrar  por volumen >>>>>>>>>>>>" << endl;
                cout << tienda.showVol();
                cout << "------------------------------------\n";
delay (1);
                cout << "<<<<<<<<<<<< Agregar producto >>>>>>>>>>>>" << endl;
                cout << "Introduzca el volumen: ";
                vol = "4500";
                cout << "Introduzca el día: ";
                dia = "25";
                cout << "Introduzca la mes: ";
                mes = "2";
                cout << "Introduzca la ID: ";
                ID = "20";
                Producto ejemploP (ID , dia , mes , vol);
                tienda.addPro(ejemploP);
                cout << "------------------------------------\n";
delay (2);

                cout << "<<<<<<<<<<<< Gracias por participar >>>>>>>>>>>>" << endl;
                cout << "------------------------------------\n";

            
            cout << "------------------------------------\n\n";
*/
return 0;
}
