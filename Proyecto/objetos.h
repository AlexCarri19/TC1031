#ifndef objetos_h
#define objetos_h

//Edgar Alexander Carrizalez Lerín 
//A01024901

#include <string>
#include <string.h> 
#include <iostream> 
#include <math.h>
#include <list>
#include <sstream>   
#include <fstream>
#include <iomanip>

using namespace std;

class Producto {
    private:
        string ID;
        string vol;
        string dia;
        string mes;

    public:
        Producto(): ID("_"),vol("_"), dia("_"), mes ("_"){};
        Producto (string , string , string, string);
        void setter(string , string , string , string);
        string getVol (){return vol;}
        string getID () {return ID;}
        string getDia (){return dia;}
        string getMes (){return mes;}
        void setID (string i){ID = i;}
        string showP ();

    friend class Ubicacion;

};

Producto :: Producto (string id_, string dia_ , string mes_ , string vol_){
    vol = vol_;
    ID = id_;
    dia = dia_;
    mes = mes_;
}

void Producto :: setter (string id_, string dia_ , string mes_ , string vol_ ){
    vol = vol_;
    ID = id_;
    dia = dia_;
    mes = mes_;
}

string Producto :: showP (){
    std::stringstream aux;
    aux << "______________________________" << endl;
    aux << "ID: " << ID << endl;
    aux << "Dia: " << dia << endl;
    aux << "Mes: " << mes << endl;
    aux << "Volumen: " << vol << endl;
    aux << "______________________________" << endl;
    return aux.str();
}

class Ubicacion {
    private:
        string cp; // INT
        string lat; // double
        string lon; // double

    public:
        Ubicacion(): cp("_"),lat("_"), lon("_"){};
        Ubicacion (string , string , string);
        void setter (string , string , string);
        string getCP (){return cp;}
        string getLat () {return lat;}
        string getLon () {return lon;}
        double calcularDistancia ();
        void setCor ();
        string mostrarDatos ();
};

Ubicacion :: Ubicacion (string cp_ , string lat1 , string lon1){
    cp = cp_;
    lat = lat1;
    lon = lon1;
}

void Ubicacion :: setter (string cp_ , string lat1 , string lon1){
    cp = cp_;
    lat = lat1;
    lon = lon1;
}

double Ubicacion :: calcularDistancia (){
    std::stringstream aux;
    double lat0 , lon0;
    lat0 = stod(lat);
    lon0 = stod(lon);
    double lat1 = 19.361111111111, lat2;
    double lon1 = -99.350833333333 , lon2;
    double r = 6357 , count;

    lat2 = lat1 - lat0;
    lon2 = lon1 - lon0;
    count = pow(sin(lat2/2), 2) + cos(lat0)* cos(lat1) * pow(sin(lon2/2), 2);
    count = 2 * atan2(sqrt(count) , sqrt(1-count));
    count = r * count;
    return count;
}

string Ubicacion :: mostrarDatos (){
    std::stringstream aux;
    aux << "___________________________"<< endl;
    aux << "CP: " << cp << endl;
    aux << "Latitud: " << lat << endl;
    aux << "Longitud: " << lon << endl;
    aux << "___________________________" << endl;
    return aux.str();
}

void Ubicacion :: setCor (){
    cout << "Introduce Latitud: ";
    cin >> lat;
    cout << "Introduce longitud: ";
    cin >> lon;
}

template <class T>
class Node {
    private:
        Ubicacion val;
        Node *left , *right;
    
    public:
        Node(Ubicacion);
        Node(Ubicacion, Node<Ubicacion>*, Node<Ubicacion>*);
        void add(Ubicacion);
        bool find(T);
        void findCP(Node<T> *root,int v,std::stringstream &aux)const;
        void findCPUbi(Node<T> *root,string v,std::stringstream &aux)const;

        void modificarUbi();

        friend class BST;
};

template <class T>
Node<T>::Node(Ubicacion val_) : val(val_), left(NULL), right(NULL) {}

template <class T>
void Node <T> :: add (Ubicacion v){
    if (v.getCP() < val.getCP()) {
		if (left != 0) {
			left->add(v);
		} 
        else {
			left = new Node<Ubicacion>(v);
		}
	} 
    else {
		if (right != 0) {
			right->add(val);
		} 
        else {
			right = new Node<Ubicacion>(val);
		}
	}
}

template <class T>
bool Node <T> :: find (T v){
    if (v.getCP() == val.getCP()) {
		return true;
	} 
    else if (v.getCP() < val.getCP()) {
		return (left != 0 && left->find(val));
	} 
    else if (v.getCP() > val.getCP()) {
		return (right != 0 && right->find(val));
	}
    else {
        cout << "Codigo postal inexistente" << endl;
        return false;
    }
}


template <class T>
void Node <T> :: findCP (Node<T> *root,int v,std::stringstream &aux)const{
        stringstream x;
        x << v;
        string s = x.str();
        if(root == NULL){
            aux << "CP inexistente \n";
        }
        if (s == root->val.getCP()) {
            aux << root->val.mostrarDatos();
            return;
        } 
        if ((s <= root->val.getCP()) && (root->left != 0)) {
            findCP(root->left,v,aux);
        } 
        if ((s > root->val.getCP()) && (root->right != 0)) {
            findCP(root->right,v,aux);
        }
}

class BST {
    private:
	Node<Ubicacion> *root;

    public:
        BST();
        bool empty() const;
        void add(Ubicacion);
        void BSTcor();
        bool find(Ubicacion) const;
        string BSTcp (string) const;
        Ubicacion BSTcpU (Ubicacion);

        void remove(Ubicacion);
};

BST::BST() : root(0) {}

void BST::add(Ubicacion v) {
	if (root != 0) {
		if (!root->find(v)) {
			root->add(v);
		}
	} 
    else {
		root = new Node<Ubicacion>(v);
	}
}

string BST::BSTcp(string ves) const {
    int v;
    v = stoi(ves);
    std::stringstream num;
    if (root != 0) {
		if (!empty()) {
		    root ->findCP(root,v,num);;
		}
        return num.str();
	} 
    else {
		num <<"El árbol ésta vacío";
        return num.str();	
	}
}


bool BST::empty() const {
	return (root == 0);
}


#endif