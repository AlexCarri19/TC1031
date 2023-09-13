#ifndef dlist_h_
#define dlist_h_

#include <iostream>
#include <sstream>
#include <cstring>
#include <string>

template <class T> class List;
template <class T> class ListIterator;

using namespace std;

template <class T> class DList;
template <class T> class DListIterator;

template <class T>
class DLink {
private:
	DLink(T);
	DLink(T, DLink<T>*, DLink<T>*);
	
	T	    val;
	DLink<T> *pre;
	DLink<T> *next;

	friend class DList<T>;
	friend class DListIterator<T>;
};

template <class T>
DLink<T>::DLink(T val1) : val(val1), pre(0), next(0) {}

template <class T>
DLink<T>::DLink(T val1, DLink *prev, DLink* next1) : val(val1), pre(prev), next(next1) {}

template <class T>
class DList {
public:

	DList();
	void insertion(T);
    int search(T);
    void update(int,T);
    T removeFirst();
    T deleteAt(int);
   	string toStringBackward();
    string toStringForward();
    bool empty();
	

private:
	DLink<T> *head;
	DLink<T> *tail;
	int 	 size;

	friend class ListIterator<T>;
};

template <class T>
DList<T>::DList() : head(0), tail(0), size(0) {}

template <class T>
void DList<T>::insertion(T val1) {
    DLink<T> *newLink;

	newLink = new DLink<T>(val1);
	if (newLink == 0) {
		cout<<"OutOfMemory";
	}
	if (empty()) {
		head = newLink;
		tail = newLink;
	} else {
		tail->next = newLink;
		newLink->pre = tail;
		tail = newLink;
	}
	size++;
}

template <class T>
int DList<T>::search(T val1)  {
	DLink<T> *aux;
	aux = head;
    int pos = 0;
	while (aux != 0) {
		if (aux->val == val1) {
			return pos;
		}
        aux = aux->next;
        pos ++;	 
	}
	return -1;
}

template <class T>
void DList<T>::update(int pos, T val)  {
     DLink<T> *aux;
	DLink<T> *auxhead;
    DLink<T> *auxtail;
    aux = head;
	auxhead = head;
    auxtail = tail;
    int counter = 0;
    int mid; 
    mid = size/2;
    while (aux != 0) {
		if (counter == pos) {
            aux->val = val;	
		}
        aux = aux->next;
        counter++;
	}
}

template <class T>
T DList<T>::removeFirst() {
	T val;
	DLink<T> *p;
	if (empty()) {
		cout<<"NoSuchElement";
	}
	p = head;
	val = p->val;
	if (head == tail) {
		head = 0;
		tail = 0;
	} else {
		head = p->next;
		p->next->pre = 0;
	}
	delete p;
	size--;
	return val;
}

template <class T>
T DList<T>::deleteAt(int index) {
    int pos;
	T val;
	DLink<T> *p;
	if (index < 0 || index >= size) {
		cout<<"IndexOutOfBounds";
	}
	if (index == 0) {
		return removeFirst();
	}
    p = head;
	pos = 0;
	while (pos != index) {
		p = p->next;
		pos++;
	}
    if (p->next != 0) {
		p->next->pre = p->pre;
	}
	val = p->val;
	p->pre->next = p->next;
	size--;
	delete p;
	return val;
}

template <class T>
	string DList<T>::toStringForward()  {
		stringstream aux;
		DLink<T> *p;
		p = head;
		aux << "[";
		while (p != 0) {
			aux << p->val;
			if (p->next != 0) {
				aux << ", ";
			}
			p = p->next;
		}
		aux << "]";
		return aux.str();
	}

template <class T>
string DList<T>::toStringBackward() {
std::stringstream aux;
DLink<T> *p;
p = tail;
aux << "[";
while (p != 0) {
	aux << p->val;
	if (p->pre != 0) {
		aux << ", ";
	}
	p = p->pre;
}
aux << "]";
return aux.str();
}

template <class T>
bool DList<T>::empty() {
	return (head == 0 && tail == 0);
}

#endif