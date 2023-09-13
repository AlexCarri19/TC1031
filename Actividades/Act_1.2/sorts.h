#ifndef sorts_h
#define sorts_h

#include <iostream>
#include <sstream>
#include <vector>
#include <list>

using namespace std;

/*
ordenaSeleccion

ordenaBurbuja

ordenaMerge
Descripción:Ordene en forma ascendente los datos con el método de Merge
Entrada: Un vector con los n numeros
Salida: Nada
Precondición: El vector debe contener los n números
Postcondición: El vector contendrá los datos ya ordenados

busqSecuencial

busqBinaria
*/

template <class T>

class Sorts {
    private:
        void swamp (vector<T>& , int , int);
        
        int bb_aux (vector<T> , int , int , int);

        void mergeSplit(vector<T>& , vector<T>& , int , int);
        void copiarV(vector<T>& , vector<T>&, int , int);
        void mergeV(vector<T>& , std::vector<T>&, int , int , int);

    public:
        void ordenaSeleccion (vector<T>&);
        void ordenaBurbuja (vector<T>&);
        void ordenaMerge (vector<T>&);

        int busqSecuencial (const vector<T> , int);
        int busqBinaria (const vector<T> , int);

        
};

template <class T>

void Sorts<T> :: mergeSplit(vector<T>& vecA, vector<T>& vecB , int l , int h){
    int m;
    if ((h - l) < 1){
        return;
    }
    m = (h + l)/2;
    mergeSplit(vecA , vecB , l , m);
    mergeSplit(vecA , vecB , m + 1, h);
    mergeV (vecA , vecB , l , m , h);
    copiarV (vecA , vecB , l , h);
}

template <class T>

void Sorts<T> :: copiarV(vector<T>& vecA, vector<T>& vecB , int x , int y){
    for (int i = x; i<= y ; i++){
        vecA[i] = vecB[i];
    }
}

template <class T>

void Sorts<T> :: mergeV(vector<T>& vecA , vector<T>& vecB , int l , int m , int h){
    int i = l;
    int j = m;
    int k = l;

    while (i <= m &&j <= h) { 
		if (vecA[i] < vecA[j]) {
			vecB[k] = vecA[i];
			i++;
		} 
        else {
			vecB[k] = vecA[j];
			j++;
		}
		k++;
	}
	if (i > m) {
		for (; j <= h; j++) {
			vecB[k++] = vecA[j];
		}
	} 
    else {
		for (; i <= m; i++) {
			vecB[k++] = vecA[i];
		}
	}

}

template <class T>

void Sorts<T> :: swamp (vector<T> &vec , int x , int y){
    T auxiliar;
    auxiliar = vec[x];
    vec[x] = vec[y];
    vec[y] = auxiliar;
}

template <class T>

int Sorts<T> :: bb_aux (vector<T> vec , int l , int h , int x){
    int m;
    if (l < h){
        m = (h - l)/2;
        if (x == vec[m]){
            return m;
        }
        else if (x < vec[m]){
            return bb_aux(vec , l , m -1 , x);
        }
        else if (x > vec[m]){
            return bb_aux(vec , m + 1 , h , x);
        }
    }
    return -1;
}

template <class T>

void Sorts<T> :: ordenaSeleccion (vector<T> &vec){
    for (int i = 0; i < vec.size() -1 ; i++){
        int minimo;
        minimo = i;
        for (int j = i + 1 ; j < vec.size(); j++){
            if (vec[j] < vec[minimo]){
                minimo = j;
            }
        }
        swamp(vec , i , minimo);
    }
}

template <class T>

void Sorts<T> :: ordenaBurbuja (vector<T> &vec){
    for (int i = 0; i < vec.size() ; i++){
        for (int j = i + 1 ; j < vec.size () ; j++){
            if (vec[j] < vec[i]){
                swamp (vec , i , j);
            }
        }
    }
}

template <class T>

void Sorts<T> :: ordenaMerge (vector<T> &vec){
    vector<T> t(vec.size());
    mergeSplit(vec , t , 0 , vec.size()-1);
}

template <class T>

int Sorts<T> :: busqSecuencial (const vector<T> vect , int x){
    vector<T> vec(vect);
    for (int i = 0; i < vec.size() ; i++){
        if (vec[i] == x){
            return i;
        }
    }
    return -1;
}

template <class T>

int Sorts<T> :: busqBinaria (const vector<T> vect , int x){
   vector <T> vec(vect);
   return bb_aux (vec , 0 , vec.size()-1 , x);
}

#endif