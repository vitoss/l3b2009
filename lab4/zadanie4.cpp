/**
 * @author Witold Wasilewski
 * @date 30.03.2009
 */
#include <iostream>
#include <cmath>
#include "zadanie4.h"
using namespace std;


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
    complex c = ct.tab_c[0];

    for( int i=0;i<10; i++  ) {        
        for( int k=0; k<4; k++ ) {
            os << (ct.tab_c[i].*ct.tab_c[i].tab_wsk_fun[k])()<<endl;   
        }
        os << endl;
    }
    return os;
}
