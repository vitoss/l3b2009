#include "filia.h"
#include "wektor.h"
#include "towar.h"
using namespace std;

//filia::filia( unsigned int i, string Name, string adr): DBObject(i,Name) {
//    adress = adr;
//
//}

//filia::filia( string adr, sklep & skl, wektor<towar> tow ) {
//    adress = adr;
//    matka = &skl;
//    //towary = tow;
//}

void filia::setName( string n ) {
    //TODO walidacja:
    name = n;
}// + walidacja

filia::~filia() {
}
ostream & operator<< (ostream &os, const filia &w) {
    cout << "  " << w.id << "  " << w.name.c_str() << endl;
    return os;
}

istream & operator>> (istream &is, filia &w) {
    cout << "Podaj nazwe (150 znakow):" << endl;
        //cin >> w.name;
    char temp[150];
    is.ignore(10, '\n');
    is.getline( temp , 150 );
    w.name.assign(temp);    


    cout << "Podaj adres (250):" << endl;
    char temp2[250];
    is.ignore(10, '\n');
    is.getline( temp2 , 250 );
    w.adress.assign(temp2); 

    return is;
}
