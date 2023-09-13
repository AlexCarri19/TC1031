#include <iostream>
#include <string>

using namespace std;

/*
Realiza un programa que calculé la sumatora de 1 hasta n y llame a tres funciones:

//sumaIterativa

Descripción: Calcule la sumatoria de 1 hasta n con un metodo iterativo.

Entrada: Un entero positivo (n)

Salida: La sumatoria de 1 hasta n

Precondición: n es un entero positivo

Postcondición: Nada

//sumaRecursiva

Descripción: Calcule la sumatoria de 1 hasta n con un metodo recursivo.

Entrada: Un entero positivo (n)

Salida: La sumatoria de 1 hasta n

Precondición: n es un entero positivo

Postcondición: Nada

//sumaDirecta

Descripción: Calcule la sumatoria de 1 hasta n con un metodo matemático directo (sin ciclos, ni recursión).

Entrada: Un entero positivo (n)

Salida: La sumatoria de 1 hasta n

Precondición: n es un entero positivo

Postcondición: Nada
*/

class functions {
    public: 
        int sumaIterativa(int n);
        int sumaRecursiva(int n);
        int sumaDirecta(int n);
};

int functions :: sumaIterativa (int n){
    int acum = 0;
    int i = 1;
    if (1 <= n){
        for(i ; i <= n ; i++){
            acum = acum + i ;
        }
        return acum;
    }
    else {
        return 0;
    }
}

int functions :: sumaRecursiva (int n){
    if (n > 1){
        return n + sumaRecursiva (n - 1);
    }
    else if (n == 1){
        return 1;
    }
    else {
        return 0;
    }
}

int functions :: sumaDirecta (int n){
    if (n >= 1){
        n = n*(n+1)/2;
        return n;
    }

    else{
        return 0;
    }
}