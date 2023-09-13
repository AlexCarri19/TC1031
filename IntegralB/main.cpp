#include <iostream>
#include "grafos.h"
using namespace std;

int main(){
    
    Grafo codigos;
    codigos.inicia();
    int opc=1;

    codigos.insertV("1");
    codigos.insertV("2");
    codigos.insertV("3");
    codigos.insertV("4");
    codigos.insertV("5");

    codigos.insertA(codigos.vertex("1"), codigos.vertex("2"), 1500);
    codigos.insertA(codigos.vertex("2"), codigos.vertex("3"), 1500);
    codigos.insertA(codigos.vertex("4"), codigos.vertex("5"), 1500);
    codigos.insertA(codigos.vertex("5"), codigos.vertex("1"), 5000);
    codigos.insertA(codigos.vertex("3"), codigos.vertex("1"), 500);

    do
    {
        cout<<"Esta es una forma de conectar los puntos entre los puntos de entrega \n\n"<<endl;
        cout<<"1. Lista de adyacencia"<<endl;
        cout<<"2. Calcular recorrido corto"<<endl;
        cout<<"3. Salir"<<endl;
        cout<<endl<<"Elija una opcion: ";
        cin>>opc;
        switch(opc){
        case 1:{
            if(codigos.empty()){
                cout<<"El grafo esta vacio"<<endl;
            }
            else{
                codigos.listAdy();
            }
            break;
        }
        case 2:{
            string punto1, punto2;
            if(codigos.empty()){
                cout<<"Vacio"<<endl;
            }
            else
            {
            cout<<"Ingrese el inicio del envio: ";
            cin >> punto1;
            cout<<"Ingrese el fin del envio: ";
            cin >> punto2;
            if(codigos.vertex(punto1) == NULL || codigos.vertex(punto2) == NULL){
                    cout<<"No existe"<<endl;
                }
                else{
                    codigos.route(codigos.vertex(punto1), codigos.vertex(punto2));
                }
            }
            break;
        }
        case 3:
            opc = 0;
    }
}while(opc == 0);
return 0;
}
