#ifndef list_h
#define list_h

#include <iostream>
#include <sstream>
#include <cstring>
#include <string>

using namespace std;

template <class T> class List;
template <class T> class ListIterator;

template <class T>
class Link {
private:
	Link(T);
	T	    v;
	Link<T> *next;
	friend class List<T>;
	friend class ListIterator<T>;   
};

template <class T>
Link<T>::Link(T val) : v(val), next(0) {}

template <class T>
class List {

private:
	Link<T> *h;
	int 	s;

public:
	List();
	void insertion(T);
    void firstInsert(T);
    int search(T);
    void update(int,T);
    T deleteAt(int);
   	string toString();
    bool empty();

	friend class ListIterator<T>;
};

template <class T>
List<T>::List() : h(0), s(0) {};

template <class T>
void List<T>::insertion(T val) {
    Link<T> *newLink, *aux;
    newLink = new Link<T>(val);
	if (empty()) {
		firstInsert(val);
		return;
	}
    else{
	    aux = h;
	    while (aux->next != 0) 
		    aux = aux->next;
        aux->next = newLink;
	}
	newLink->next = 0;
	s++;
}

template <class T>
void List<T>::firstInsert(T val) {
	Link<T> *newLink;
	newLink = new Link<T>(val);
    if(newLink == 0){
        cout<<"OutOfMemory";}
	newLink->next = h;
	h = newLink;
	s++;
}

template <class T>
int List<T>::search(T val)  {
	Link<T> *aux;
	aux = h;
    int pos = 0;
	while (aux != 0) {
		if (aux->v == val) {
			return pos;}
        aux = aux->next;
        pos ++;	
	}
	return -1;
}

template <class T>
void List<T>::update(int pos, T val)  {
	Link<T> *aux;
	aux = h;
    int counter;
    counter = 0;
    while (aux != 0) {
		if (counter == pos) {
            aux->v = val;}
        aux = aux->next;
        counter++;
	}	
}

template <class T>
T List<T>::deleteAt(int pos) {
	T val;
     if (pos == 0){
        Link<T> *aux = h;
        val = aux->v;
	    h = aux->next;
        delete aux; 
    }
    else {
        Link<T> *ant = h;
        Link<T> *aux = ant-> next;
        int index = 1;
        while (aux != 0) {
            if (index == pos) {
                val = aux->v;
                ant->next = aux-> next; 
                delete aux;  
                break;
            }
            ant = ant->next;
            aux = aux->next;
            index ++;
        }     
    } 
	s--;  
    return val;
}

template <class T>
string List<T>::toString() {
	std::stringstream aux;
	Link<T> *p;
	p = h;
	aux << "[";
	while (p != 0) {
		aux << p->v;
		if (p->next != 0) {
			aux << ", ";
		}
		p = p->next;
	}
	aux << "]";
	return aux.str();
}

template <class T>
bool List<T>::empty(){
	return (h == 0);
}


#endif