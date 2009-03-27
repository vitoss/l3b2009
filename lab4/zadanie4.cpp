#include <iostream>
#include "zadanie4.h"
#include <cmath>
using namespace std;

class complex {
    public:
    double re,im;
    
    complex(): re(0), im(0) { tab_init(); }
    complex( const complex& c ) { re=c.re; im=c.im; tab_init(); }
    complex( double r, double i ) { re=r; im=i; tab_init(); }
    void tab_init();
    
    double fun1() { return re; }
    double fun2() { return im; }
    double fun3() { return im*im + re*re; }
    double fun4() { return sqrt( fun3() ); }
    
    double (complex::*tab_wsk_fun[4])(void);
};

class tab_complex {
    complex tab_c[10];
    public:
    tab_complex();
    
    friend ostream& operator<< (ostream&, tab_complex&);
};

void complex::tab_init() {
    tab_wsk_fun[0] = &complex::fun1;
    tab_wsk_fun[1] = &complex::fun2;
    tab_wsk_fun[2] = &complex::fun3;
    tab_wsk_fun[3] = &complex::fun4;
}

tab_complex::tab_complex() {
    const double range = 1000.0; //zasiêg zmiennej do generowania losowych liczb
    for( int i=0; i<10; i++ ) {
        tab_c[i].re = (double) (rand() * range / RAND_MAX);
        tab_c[i].im = (double) (rand() * range / RAND_MAX);
    }
}

ostream& operator<< (ostream& os,  tab_complex& ct) {

    double d = 0;
    complex c = ct.tab_c[0];

    for( int i=0;i<10; i++  ) {        
        for( int k=0; k<4; k++ ) {
            os << (ct.tab_c[i].*ct.tab_c[i].tab_wsk_fun[k]) ()<<endl;   
        }
        os << endl;
    }
    return os;
}

int main() {
    tab_complex tc;
    cout << tc;
    return 0;
}