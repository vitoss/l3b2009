#ifndef VECT
#define VECT
#include <iostream>

using namespace std;

class vect {
    protected:
    unsigned int size;
    double * arr;
    
    public:
    
    //Konstruktory
    vect(): size(0) {}
    vect( unsigned int size, double * arr );
    vect( unsigned int size );
    vect( const vect& v );
    //Destruktor
    ~vect();
    
    //Operator przypisania
    vect &operator = ( vect & v );
    
    double & operator[]( unsigned int index );
    
    unsigned int get_size() { return size; }
    void set_size( unsigned int size );
    
    bool dodaj( double elem );
    
    friend bool operator== (const vect &v1, const vect &v2);
    friend bool operator!= (const vect &v1, const vect &v2) { return !(v1==v2); }
    
    
    friend ostream& operator<< (ostream& os, const vect &v);
    friend istream& operator>> (istream&, vect &v);
};
#endif