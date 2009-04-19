#include "zad06v.h"
#include <iostream>

using namespace std;

vect::vect( unsigned int s, double * newArray ): size(s) {
    arr = new double[s];
    for( int i=0; i<s; i++ ) {
        arr[i] = newArray[i];
    }
}
 vect::vect( unsigned int s ): size(s) {
    arr = new double[s];
}

vect::vect( const vect& v ) {
    size = v.size;
    
    arr = new double[size];
    for( int i=0; i<size; i++ ) {
        arr[i] = v.arr[i];
    }
}

vect::~vect() {
    delete[] arr;
}

vect & vect::operator= ( vect & v ) {
    set_size( v.size );
    for( int i=0; i<size; i++ ) {
        arr[i] = v.arr[i];
    }
    return *this;
}

double & vect::operator[]( unsigned int index ) {
    //z³y index
    if( index >= size )
    {
        cout << "Z³y index!";
        return arr[0];
    }
        
    return arr[index];
}

//jeœli jest mniej elementów to wype³niamy 0
void vect::set_size( unsigned int s ) {
    if( s == size )
        return;
        
    double * tempArr = new double[s];    
    if( s < size )
    {
        for(int i =0; i<s; i++)
            tempArr[i] = arr[i];
        delete[] arr;
        arr = tempArr;
    }    
    else
    {
        for(int i =0; i<size; i++)
            tempArr[i] = arr[i];
        for(int i = size; i<s; i++ )
           tempArr[i] = 0;
       
        if( size > 0 )
            delete[] arr;
        arr = tempArr;
    }
    size = s;        
}

bool vect::dodaj( double elem ) {
    size++;
    double * tempArray = new double[size]; 
    for(int i=0; i<size-1; i++ )
        tempArray[i] = arr[i];
    tempArray[size-1] = elem;
    delete[] arr;
    arr = tempArray;
    return true;
}
ostream& operator<< (ostream& os, const vect &v) {
    cout << "[";
    for( int i=0; i<v.size; i++ ) {
        cout << " " << v.arr[i];
    }
    cout<< " ]"<<endl;
    return os;
}
istream& operator>> (istream& is, vect &v) {
    cout<<"Prosze podac wspolrzedne wektora.( "<< v.size<< " liczb) [ l1, l2, l3... ]" <<endl;
    for( int i=0; i<v.size; i++ ) {
        cin>>v.arr[i];
    }
    return is;
}

bool operator== (const vect &v1, const vect &v2) {
    if( v1.size != v2.size ) 
        return false;
    
    for( int i=0; i<v1.size;i++ ) {
        if( v1.arr[i] != v2.arr[i] )
            return false;
    }
    return true;
}