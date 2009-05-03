#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <ctime>


using namespace std;

int main() {
    ofstream plik("towary.txt", ios::out);
    for( int i=0; i<50; i++ ) {
        plik << i << endl << "Towar"<< i << endl<< i*10 <<endl;
    }
    plik.close();

    ofstream plik2("sklepy.txt", ios::out);
    for( int i=0; i<20; i++ ) {
        plik2 << i <<endl << "Sklep"<<i<<endl;
        plik2<< "+" << endl<< "0" << endl << "Filia0" << i << endl << "Adres filii0" <<i<<endl;
        if( i%2 == 0 )
            plik2<< "+" << endl<< "1" <<  endl << "FiliaA" << i << endl << "Adres filiiA" <<i<<endl;
        if( i%3 == 0 )
             plik2<< "+" << endl<< "2" << endl << "FiliaB" << i << endl << "Adres filiiB" <<i<<endl;
        plik2 << "#" << endl;
    }
    plik2.close();

    ofstream plik3("magazyny.txt", ios::out);
    int IMin = 0;
    int IMax = 20;
    srand(time(0));
    int I;
    for( int i = 0; i < 80; i++ ) {
        
        I = IMin + rand() % (IMax - IMin);
        if( (i+1) % 2 == 0 && (i+1)%4!=0 )
            plik3<<0<<";";
        else
            plik3<<I<<";";
        
    }
    plik3.close();
    
    return 0;
}   