#ifndef SVECT
#define SVECT
#include "zad06v.h"

/** svect class.
 * Klasa reprezentujaca posortowany wektor.
 * @author	Witold Wasilewski
 * @version 1
 */
class svect : public vect {
    /**
     * Funkcja sortuj¹ca zawartoœæ wektora.
     */
    void sort();
    
    public:
    /**
     * Konstruktor kopiuj¹cy.
     */
    svect( const svect& v ): vect(v) {
        sort();
    }
    /**
     * Konstruktor tworz¹cy wektor o zadanej d³ugoœci.
     */
    svect( unsigned int i ): vect(i) {}
    /**
     * Konstruktor wykorzystywany do rzutowania klasy bazowej vect na svect.
     * @param v obiekt klasy vect
     */
    svect( const vect &v ): vect(v) {
        sort();
    }
    
    bool dodaj( double elem);
    friend istream& operator>> (istream& is, svect &sv);
    friend ostream& operator<< (ostream& os, svect &v);
};
#endif