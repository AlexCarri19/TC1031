#ifndef heap_h
#define heap_h

#include <string>
#include <sstream>
#include <iostream>
#include <cstring>


using namespace std;

template <class T>
class Heap {
private:
	T *data;
	 int t;
	 int c;
	 int parent(int) const;
	 int left(int) const;
	 int right(int) const;
	void heapify(int);
	void swap(int, int);
public:
	Heap(int);
	~Heap();
    void push(int);
    void pop();
    T top();
	bool empty() const;
    int size();
	bool full() const;
	void clear(); 
	std::string toString() const;
};

template <class T>
bool Heap<T>::full() const {
	return (c == t);
}

template <class T>
int Heap<T>::parent(int pos) const {
	return (pos - 1) / 2;
}

template <class T>
int Heap<T>::left(int pos) const {
	return ((2 * pos) + 1);
}


template <class T>
int Heap<T>::right(int pos) const {
	return ((2 * pos) + 2);
}


template <class T>
void Heap<T>::swap(int i, int j) {
	T aux = data[i];
	data[i] = data[j];
	data[j] = aux;
}

template <class T>
void Heap<T>::heapify(int pos) {
	int l1 = left(pos);
	int r1 = right(pos);
	int min = pos;
	if (l1 <= c && data[l1] < data[min]) {
		min = l1;
	}
	if (r1 <= c && data[r1] < data[min]) {
		min = r1;
	}
	if (min != pos) {
		swap(pos, min);
		heapify(min);
	}
}

template <class T>
Heap<T>::Heap( int sze) {
	t = sze;
	data = new T[t];
	if (data == 0) {
		cout << "OutOfMemory" ;
	}
	c = 0;
}

template <class T>
Heap<T>::~Heap() {
	delete [] data; data = 0;
	t = 0; c = 0;
}


template <class T>
void Heap<T>::push(int val) {
	int pos;
	if (full()) {
		cout << "Overflow";
	}
	pos = c;
	c++;
	while (pos > 0 && val < data[parent(pos)]) {
		data[pos] = data[parent(pos)];
		pos = parent(pos);
	}
	data[pos] = val;
}


template <class T>
void Heap<T>::pop() {
	if (empty()) {
		cout <<  "NoSuchElement";
	}
   	data[0] = data[--c];
	heapify(0);	
}


template <class T>
T Heap<T>::top() {
	if(c != 0){
        return data[0];
    }
    return -1;
}

template <class T>
bool Heap<T>::empty() const {
	return (c == 0);
}

template <class T>
int Heap<T>::size() {
	return c;
}

template <class T>
void Heap<T>::clear() {
	c = 0;
}

template <class T>
std::string Heap<T>::toString() const {
	std::stringstream aux;
	aux << "[";	for (int i = 0; i < c; i++) {
		if (i != 0) {
			aux << " ";
		} aux << data[i];
	} aux << "]";
	return aux.str();
}

#endif