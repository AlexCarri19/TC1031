#ifndef hash_h
#define hash_h

#include <string>
#include <sstream>

template <class Key, class Value>
class Table {
private:
	unsigned int (*function) (const Key);
	unsigned int size;
	unsigned int count;

	Key *keys;
	Key initialValue;
	Value *values;

	long indexOf(const Key) const;

public:
	Table(unsigned int, Key, unsigned int (*f) (const Key));
	~Table();
	bool full() const;
	bool put(Key, Value);
	bool contains(const Key) const;
    void crear(); 
	Value get(const Key);
	void clear();
	std::string toString() const;
};

template <class Key, class Value>
Table<Key, Value>::Table(unsigned int sze, Key init, unsigned int (*f) (const Key)) {
	size = sze;
	keys = new Key[size];

	initialValue = init;
	for (unsigned int i = 0; i < size; i++) {
		keys[i] = init;
	}

	values = new Value[size];
	for (int i = 0; i  < sze; i++){
        values[i] = 0;
    }

	function = f;
	count = 0;
}

template <class Key, class Value>
Table<Key, Value>::~Table() {
	delete [] keys;
	keys = 0;
	delete [] values;
	values = 0;
	size = 0;
	function = 0;
	count = 0;
}

template <class Key, class Value>
bool Table<Key, Value>::full() const {
	return (count > size);
}

template <class Key, class Value>
long Table<Key, Value>::indexOf(const Key k) const {
	unsigned int i, start;

	start = i = function(k) % size;
	do {
		if (keys[i] == k) {
			return i;
		}
		i = (i + 1) % size;
	} while (start != i);
	return -1;
}

template <class Key, class Value>
bool Table<Key, Value>::put(Key k, Value v) {
	unsigned int i, start;
	long pos;


	pos = indexOf(k);
	if (pos != -1) {
		values[pos] = v;
		return true;
	}

	start = i = function(k) % size;
	do {
		if (keys[i] == initialValue) {
			keys[i] = k;
			values[i] = v;
			count++;
			return true;
		}
		i = (i + 1) % size;
	} while (start != i);
	return false;
}

template <class Key, class Value>
bool Table<Key, Value>::contains(const Key k) const {
	long pos;

	pos = indexOf(k);
	return (pos != -1);
}

template <class Key, class Value>
Value Table<Key, Value>::get(const Key k) {
	unsigned int i, start;
	long pos;

	pos = indexOf(k);
	if (pos != -1) {
		return values[pos];
	}
}

template <class Key, class Value>
void Table<Key, Value>::clear() {
	count = 0;
	for (unsigned int i = 0; i < size; i++) {
		keys[i] = initialValue;
	}
}

template <class Key, class Value>
std::string Table<Key, Value>::toString() const {
	std::stringstream aux;

	for (unsigned int i = 0; i < size; i++) {
		aux << "[ " << i << ", " << keys[i] << ", " << values[i] << "]\n";
	}
	return aux.str();
}

template <class Key, class Value>
void Table<Key, Value>::crear(){
    
    put(string("PE"), 11);
    put(string("PA"), 18);
    put(string("PV"), 7);
    put(string("LC"), 20);
    put(string("PM"), 15);
    put(string("SC"), 16);
    put(string("PN"), 23);
    put(string("MP"), 14);
    put(string("PL"), 12);
    put(string("SR"), 10);
}

#endif 