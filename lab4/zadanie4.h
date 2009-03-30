#ifndef COMPLEX
#define COMPLEX

#include <iostream>
#include <cmath>
using namespace std;
/** 
 * Klasa przedstawiaj�ca liczb� zespolon�.
 */
class complex {
    void tab_init();
    
    public:
    double re; /**<Zmienna przechowuj�ca cz�� rzeczywist� liczby zespolonej*/
    double im; /**<Zmienna przechowuj�ca cz�� urojon� liczby zespolonej*/
    
    double (complex::*tab_wsk_fun[4])(void); /**< Tablica 4 wska�nik�w do funkcji klasy Complex */
    
    /**
     * Konstruktor domy�lny. Ustawia warto�� liczby zespolonej na (0,0).
     */
    complex(): re(0), im(0) { tab_init(); }
    /**
     * Konstruktor kopiuj�cy.
     */
    complex( const complex& c ) { re=c.re; im=c.im; tab_init(); }
    /**
     * Konstruktor parametryczny.
     * @param r cz�� rzeczywista
     * @param i cz�� urojona
     */
    complex( double r, double i ) { re=r; im=i; tab_init(); }
    
    /**
     * Funkcja zwracaj�ca cz�� rzeczywist� liczby zespolonej.
     * @return Cz�� rzeczywistaj liczby zespolonej.
     */
    double fun1() { return re; }
    /**
     * Funkcja zwracaj�ca cz�� urojon� liczby zespolonej.
     * @return cz�� urojona liczby zespolonej.
     */
    double fun2() { return im; }
    /**
     * Funkcja zwracaj�ca kwadrat modu�u liczby zespolonej.
     * @return Kwadrat modu�u.
     */
    double fun3() { return im*im + re*re; }
    /**
     * Funkcja zwracaj�ca modu� liczby zespolonej.
     * @return Modu� liczby zespolonej.
     */
    double fun4() { return sqrt( fun3() ); }
};

/** 
 * Klasa przechowuj�ca 10 element�w klasy complex.
 */
class tab_complex {
    complex tab_c[10];
    public:
    /**
     * Konstruktor domy�lny.
     */
    tab_complex();
    
    /**
     * Zaprzyja�niony operator wypisania na ekran.
     */
    friend ostream& operator<< (ostream&, tab_complex&);
};
#endif