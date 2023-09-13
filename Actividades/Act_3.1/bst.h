#ifndef bst_h
#define bst_h

//Edgar Alexander Carrizalez Lerín A01024901
//25 de noviembre 2021

#include <string>
#include <sstream>
#include <iostream>

template <class T> class BST;

template <class T>
class Node {
private:
	T value;
	Node *l, *r;

	Node<T>* succesor();
    

public:
	Node(T);
	Node(T, Node<T>*, Node<T>*);
	void add(T);
	bool find(T);
	void remove(T);
	void removeC();
	std::string antesesor(T,Node<T>);	
    void inorder(std::stringstream&) const;
	void preorder(std::stringstream&) const;
    void postorder(std::stringstream&) const;
    void lBL(int,std::stringstream&) const;
    int maxD();
    void printAncestors(std::stringstream &aux,T val);

	friend class BST<T>;
};

template <class T>
Node<T>::Node(T val) : value(val), l(0), r(0) {}

template <class T>
Node<T>::Node(T val, Node<T> *l1, Node<T> *r1)
	: value(val), l(l1), r(r1) {}

template <class T>
void Node<T>::add(T val) {
	if (val < value) {
		if (l != 0) {
			l->add(val);
		} else {
			l = new Node<T>(val);
		}
	} else {
		if (r != 0) {
			r->add(val);
		} else {
			r = new Node<T>(val);
		}
	}
}

template <class T>
bool Node<T>::find(T val) {
	if (val == value) {
		return true;
	} else if (val < value) {
		return (l != 0 && l->find(val));
	} else if (val > value) {
		return (r != 0 && r->find(val));
	}
}

template <class T>
void Node<T>::remove(T val) {
	Node<T> * succ, *old;

	if (val < value) {
		if (l != 0) {
			if (l->value == val) {
				old = l;
				if(old->l != 0 && old->r != 0){
					succ = l->succesor();
					if (succ != 0) {
						succ->l = old->l;
						succ->r = old->r;
					}
					l = succ;
				} else if (old->r != 0){
						l = old->r;
				} else if (old->l != 0){ 
						l = old->l;
				} else {
						l = 0;
				}
				delete old;
			} else {
				l->remove(val);
			}
		}
	} else if (val > value) {
		if (r != 0) {
			if (r->value == val) {
				old = r;
				if(old->l != 0 && old->r != 0){
					succ = r->succesor();
					if (succ != 0) {
						succ->l = old->l;
						succ->r = old->r;
					}
					r = succ;
				} else if (old->r != 0){
					r = old->r;
				} else if (old->l != 0){
					r = old->l;
				} else { 
					r = 0;
				}
					delete old;
			} else {
				r->remove(val);
			}
		}
	}
}

template <class T>
void Node<T>::removeC() {
	if (l != 0) {
		l->removeC();
		delete l;
		l = 0;
	}
	if (r != 0) {
		r->removeC();
		delete r;
		r = 0;
	}
}

template <class T>
void Node<T>::inorder(std::stringstream &aux) const {
	if (l != 0) {
		l->inorder(aux);
	}
	if (aux.tellp() != 1) {
		aux << " ";
	}
	aux << value;
	if (r != 0) {
		r->inorder(aux);
	}
}

template <class T>
void Node<T>::preorder(std::stringstream &aux) const {
	aux << value;
	if (l != 0) {
		aux << " ";
		l->preorder(aux);
	}
	if (r != 0) {
		aux << " ";
		r->preorder(aux);
	}
}

template <class T>
void Node<T>::postorder(std::stringstream &aux) const {
    	
	if (l != 0) {
		l->postorder(aux);
        aux<<" ";
	}
   	if (r != 0) {
		r->postorder(aux);
        aux<<" ";
	}
    aux << value;
}


template <class T>
void Node<T>::lBL(int level_no,std::stringstream &aux) const {
	if (level_no == 1) {
		if(aux.tellp() != 1){
			aux<< " ";
		}
        aux << value;
	    
    } 
	level_no --;
	if (l != 0){
		l->lBL( level_no ,aux);	
	}
	if (r != 0){
		r->lBL(level_no,aux);		
	}	
       
}



template <class T>
int Node<T>::maxD() {
	int l1 =1 , r1 = 1, level = 0;
	if (l != 0)
		l1 = l->maxD() + 1;
	if (r != 0)
		r1 = r->maxD() + 1;
	if(l1 > r1)
		level = l1;
	else
		level = r1;
	return level;
}


template <class T>
void Node<T>:: printAncestors(std::stringstream &aux,T val)
{
  
	if(val< value){
		if(l  != 0){
			if(aux.tellp() != 1){
			 aux << " ";
			}
			aux << value;
			l->printAncestors(aux,val);
		}
	}
	else if (val> value){
		if(r != 0){
			if(aux.tellp() != 1){
			 aux << " ";
			}
			aux << value;
			r->printAncestors(aux,val);
		}

	}

}

template <class T>
Node<T>* Node<T>::succesor() {
	Node<T> *l1, *r1;

	l1 = l;
	r1 = r;

	if (r->l == 0) {
		r = r->r;
		r1->r = 0;
		return r;
	}

	Node<T> *parent, *child;
	parent = r;
	child = r->l;
	while (child->l != 0) {
		parent = child;
		child = child->l;
	}
	parent->l = child->r;
	child->r = 0;
	return child;
}


template <class T>
class BST {
private:
	Node<T> *root;

public:
	BST();
	~BST();
	bool empty() const;
	void add(T);
	bool find(T) const;
	void remove(T);
	void removeAll();


	std::string inorder() const;
	std::string preorder() const;
    std::string postorder() const;
    std::string lBL() const;


    void print_level(Node<T>* ,int,std::stringstream &);
    std::string visit() const;

    int height();
    std::string ancestors(T);
	
    bool printAncestors(std::stringstream &aux,T, Node<T>*);
    int findLevel(Node<T>*, int, T );
    int whatlevelamI(T);
	void lBL(int,std::stringstream&) const;
};

template <class T>
BST<T>::BST() : root(0) {}

template <class T>
BST<T>::~BST() {
	removeAll();
}

template <class T>
bool BST<T>::empty() const {
	return (root == 0);
}

template<class T>
void BST<T>::add(T val) {
	if (root != 0) {
		if (!root->find(val)) {
			root->add(val);
		}
	} else {
		root = new Node<T>(val);
	}
}

template <class T>
bool BST<T>::find(T val) const {
	if (root != 0) {
		return root->find(val);
	} else {
		return false;
	}
}

template <class T>
void BST<T>::remove(T val) {
	if (root != 0) {
		if (val == root->value) {
			Node<T> *succ = root->succesor();
			if (succ != 0) {
				succ->l = root->l;
				succ->r = root->r;
			}
			delete root;
			root = succ;
		} else {
			root->remove(val);
		}
	}
}

template <class T>
void BST<T>::removeAll() {
	if (root != 0) {
		root->removeC();
	}
	delete root;
	root = 0;
}


template <class T>
std::string BST<T>::inorder() const {
	std::stringstream aux;

	aux << "[";
	if (!empty()) {
		root->inorder(aux);
	}
	aux << "]";
	return aux.str();
}

template <class T>
std::string BST<T>::preorder() const {
	std::stringstream aux;

	aux << "[";
	if (!empty()) {
		root->preorder(aux);
	}
	aux << "]";
	return aux.str();
}

template <class T>
std::string BST<T>::postorder() const {
	std::stringstream aux;

	aux << "[";
	if (!empty()) {
		root->postorder(aux);
	}
	aux << "]";
	return aux.str();
}

template <class T>
std::string BST<T>::lBL() const {
	std::stringstream aux;
    int level = root->maxD();
	
	aux << "[";
	if (!empty()) {
        for (int i = 1; i <= level; i++) {
           root->lBL(i, aux);
		   
        }

	}
	aux << "]";
	return aux.str();
}

template <class T>
std::string BST<T>::visit() const {
	std::stringstream aux;
    aux << preorder();
    aux << "\n";
    aux << inorder();
    aux << "\n";
    aux << postorder();
    aux << "\n";
    aux << lBL();
	return aux.str();
}


template <class T>
int BST<T>::height() {
    
   return root->maxD();
     
}


template <class T>
std::string BST<T>:: ancestors(T val){
    std::stringstream aux;
    
	if (find(val) == true){
		aux << "[";
    	if (!empty()) {
			root->printAncestors(aux,val);
			
		}
		aux << "]";
	}
	else{
		aux << "[]";
	}
   
    return aux.str();
}


template <class T>
int BST<T>:: findLevel(Node<T>* root, int level, T val){
    
        if(root == NULL)
            return -1;
        if(root->value == val)
            return level;
        if(root->l == NULL && root->r == NULL)
            return -1;
        int levelLeft = findLevel(root->l, level+1,val);
        int levelRight = findLevel(root->r, level+1,val);
        if(levelLeft == -1)
            return levelRight;
        else
            return levelLeft;
}


template <class T>
int BST<T>:: whatlevelamI(T val){
    int level = 1;
    return findLevel(root,level,val);
}


#endif