#ifndef grafo_h
#define grafo_h

#include <iostream>
#include <queue>
#include <list>
#include <stack>


using namespace std; 

class Arista;

class Vertice{
    public:
        Vertice *s; 
        Arista *a; 
        string nombre; 

        friend class Grafo; 
}; 

class Arista {
    public: 
        Arista *s; 
        Vertice *a; 
        int peso; 

        friend class Grafo; 
};

class Grafo {
    Vertice *h;
    public: 
        void inicia(); 
        bool empty(); 
        int tam(); 
        Vertice *vertex(string nombre); 
        void route(Vertice *origen, Vertice *destino); 
        void insertA(Vertice *origen, Vertice *destino, int peso); 
        void insertV(string nombre); 
        void listAdy(); 
};

void Grafo :: inicia(){
    h = NULL; 
}

int Grafo :: tam(){
    int cont = 0; 
    Vertice *aux; 
    aux = h; 
    while (aux != NULL){
        cont ++;
        aux = aux -> s; 
    }
    return cont; 
}

void Grafo :: insertV(string nombre){
    Vertice *nuevo = new Vertice; 
    nuevo -> nombre = nombre; 
    nuevo -> s = NULL; 
    nuevo -> a = NULL; 
    if (empty()){ 
        h = nuevo; 
    }
    else {
        Vertice *aux; 
        aux = h; 
        while (aux -> s != NULL){
            aux = aux -> s; 
        }
        aux -> s = nuevo; 
    }
}

Vertice *Grafo :: vertex(string nombre){
    Vertice *aux; 
    aux = h; 
    while (aux != NULL){
        if (aux -> nombre == nombre){
            return aux; 
        }
        aux = aux -> s; 
    }
    return NULL; 
}

void Grafo :: insertA(Vertice *origen, Vertice *destino, int peso){
    Arista *new1 = new Arista; 
    new1 -> peso = peso; 
    new1 -> s = NULL; 
    new1 -> a = NULL; 

    Arista *aux; 
    aux = origen -> a; 

    if(aux == NULL){
        origen -> a = new1;
        new1 -> a = destino; 
    }

    else {
        while(aux -> s != NULL)
        {
            aux = aux -> s; 
        }
        aux -> s = new1; 
        new1 -> a = destino; 
    }
}

void Grafo :: route(Vertice *origen, Vertice *destino){

    Vertice *verticeActual, *destinoActual; 
    Arista *aux; 
    int b, b1, b3 = 0; 
    typedef pair<Vertice*, Vertice*> VerticeVertice; 
    queue<Vertice*> tail; 
    stack<VerticeVertice> pila; 
    list<Vertice*> lista; 
    list<Vertice*> :: iterator i; 

    tail.push(origen); 
    while (!tail.empty()){
        b = 0; 
        verticeActual = tail.front(); 
        tail.pop(); 

        for (i = lista.begin(); i!=lista.end(); i++){
            if(verticeActual == *i){
                b = 1;
            }
        }

        if(b==0){
            if(verticeActual == destino){
                b3=1; 
                destinoActual = destino; 
                while (!pila.empty()){
                    cout<<destinoActual -> nombre << "<-"; 
                    while(!pila.empty() && pila.top().second != destinoActual){
                        pila.pop();}
                    if(!pila.empty()){
                        destinoActual = pila.top().first;}
                }
            }
            lista.push_back(verticeActual); 
            aux = verticeActual -> a; 
            while (aux != NULL){
                for(i = lista.begin(); i!=lista.end(); i++){
                    if(aux->a == *i){
                        b1 = 1; }
                    }
                if(b1 == 0){
                    tail.push(aux->a); 
                    pila.push(VerticeVertice(verticeActual, aux->a )); 
                }
                aux = aux -> s; 
            }
        }
    }
    if(b3==0){
        cout<<"No hay transporte"<<endl; }
}

void Grafo :: listAdy(){

    Vertice *vAux; 
    Arista *aAux; 

    vAux = h; 
    while(vAux != NULL){
        cout<<vAux->nombre<<"->"; 
        aAux = vAux -> a; 
        while(aAux != NULL){
            cout<<aAux->a->nombre<<"->"; 
            aAux = aAux -> s; 
        }
        vAux = vAux -> s; 
        cout<<endl; 
    }
}

bool Grafo :: empty(){
    if (h==NULL){
        return true; 
    }
    return false; 
}

#endif 