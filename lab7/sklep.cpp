#include "sklep.h"
using namespace std;

void sklep::setName( string n ) {
    //TODO walidacja:
    name = n;
}// + walidacja

ostream & operator<< (ostream &os, const sklep &w) {
    cout << "  " << w.id << "  " << w.name.c_str() << endl;
    return os;
}

istream & operator>> (istream &is, sklep &w) {
    cout << "Podaj nazwe:" << endl;
        //cin >> w.name;
    char temp[150];
    is.ignore(10, '\n');
    is.getline( temp , 150 );
    w.name.assign(temp);   
    return is;
}

sklep::~sklep() {
    
}