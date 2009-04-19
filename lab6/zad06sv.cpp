#include <iostream>
#include "zad06sv.h"

using namespace std;

int compare (const void * a, const void * b)
{
  return (int)( *(double*)a - *(double*)b );
}
void svect::sort() {
    qsort( arr, size, sizeof(double), compare );
}

svect::svect( const svect& v ): vect(v) {
sort();
}

svect::svect( unsigned int i ): vect(i) {}
svect::svect( const vect &v ): vect(v) {
sort();
}

bool svect::dodaj( double elem ) {
    vect::dodaj(elem);
    sort();
    return true;
}

istream& operator>> (istream& is, svect &v) {
    cout<<"Prosze podac wspolrzedne wektora.( "<< v.size<< " liczb)" <<endl;
    for( unsigned int i=0; i<v.size; i++ ) {
        cin>>v.arr[i];
    }
    v.sort();
    return is;
    //Nie mo¿na u¿yæ tej wersji z powodu konstruktora kopiuj¹cego który tworzy nowe wektor i dopiero wtedy...
    //A mo¿e rzutowanie?
    /*cin>>(vect)sv;
    sv.sort();
    return is;*/
}


ostream& operator<< (ostream& os, svect &v) {
    v.sort();
    cout<<(vect)v;
    return os;
    
}