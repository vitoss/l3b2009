#ifndef COMPLEX
#define COMPLEX

#include <iostream>
#include <cmath>
using namespace std;
/** 
 * Klasa przedstawiaj¹ca liczbê zespolon¹.
 */
class complex {
    void tab_init();
    
    public:
    double re; /**<Zmienna przechowuj¹ca czêœæ rzeczywist¹ liczby zespolonej*/
    double im; /**<Zmienna przechowuj¹ca czêœæ urojon¹ liczby zespolonej*/
    
    double (complex::*tab_wsk_fun[4])(void); /**< Tablica 4 wskaŸników do funkcji klasy Complex */
    
    /**
     * Konstruktor domyœlny. Ustawia wartoœæ liczby zespolonej na (0,0).
     */
    complex(): re(0), im(0) { tab_init(); }
    /**
     * Konstruktor kopiuj¹cy.
     */
    complex( const complex& c ) { re=c.re; im=c.im; tab_init(); }
    /**
     * Konstruktor parametryczny.
     * @param r czêœæ rzeczywista
     * @param i czêœæ urojona
     */
    complex( double r, double i ) { re=r; im=i; tab_init(); }
    
    /**
     * Funkcja zwracaj¹ca czêœæ rzeczywist¹ liczby zespolonej.
     * @return Czêœæ rzeczywistaj liczby zespolonej.
     */
    double fun1() { return re; }
    /**
     * Funkcja zwracaj¹ca czêœæ urojon¹ liczby zespolonej.
     * @return czêœæ urojona liczby zespolonej.
     */
    double fun2() { return im; }
    /**
     * Funkcja zwracaj¹ca kwadrat modu³u liczby zespolonej.
     * @return Kwadrat modu³u.
     */
    double fun3() { return im*im + re*re; }
    /**
     * Funkcja zwracaj¹ca modu³ liczby zespolonej.
     * @return Modu³ liczby zespolonej.
     */
    double fun4() { return sqrt( fun3() ); }
};

/** 
 * Klasa przechowuj¹ca 10 elementów klasy complex.
 */
class tab_complex {
    complex tab_c[10];
    public:
    /**
     * Konstruktor domyœlny.
     */
    tab_complex();
    
    /**
     * ZaprzyjaŸniony operator wypisania na ekran.
     */
    friend ostream& operator<< (ostream&, tab_complex&);
};
#endif