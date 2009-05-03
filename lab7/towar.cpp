#include <iostream>
#include <string>
#include "towar.h"
using namespace std;

void towar::setName( string n ) {
    //TODO walidacja:
    name = n;
}// + walidacja

ostream & operator<< (ostream &os, const towar &w) {
    cout << "  " << w.id << "  " << w.name.c_str() << "    "<< w.price << endl;
    return os;
}

istream & operator>> (istream &is, towar &w) {
    cout << "Podaj nazwe:" << endl;
    //cin >> w.name;
    char temp[150];
    is.ignore(10, '\n');
    is.getline( temp , 150 );
    w.name.assign(temp);
    
    cout << "Podaj domyslna cene:" << endl;
    cin >> w.price;
    return is;
}