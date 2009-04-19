#ifndef SVECT
#define SVECT
#include "zad06v.h"
class svect : public vect {
    void sort();
    
    public:
    svect( const svect& v );
    svect( unsigned int i );
    svect( const vect &v );
    bool dodaj( double elem);
    friend istream& operator>> (istream& is, svect &sv);
    friend ostream& operator<< (ostream& os, svect &v);
};
#endif