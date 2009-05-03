#ifndef TOWAR_H
#define TOWAR_H
#include "DBObject.h"
#include "wektor.h"
#include "filia.h"
#include <iostream>
#include <string>
using namespace std;

class filia;
/** Klasa towar.
 * Klasa przedstawiaj¹ca towar w bazie danych.
 */
class towar : public DBObject  {
	double price; /**< domyœlna cena, ustawiana tylko przy tworzeniu towaru. */

	public:
    wektor<filia*> shops; /**< filie gdzie towar jest dostepny */

    /**
     * Konstruktor domyœlny.
     */
    towar(){};
    /**
     * Konstruktor parametryczny.
     * @param i identyfikator (unikalny) obiektu.
     * @param n nazwa towaru
     * @param c domyœlna cena towaru
     */
    towar::towar( int i,string n, double c ): DBObject(i,n), price(c) {}
    //~towar(); //usuwa wszystkie kopie po sklepach :p
    
    /**
     * Funkcja zwracaj¹ca cenê towaru.
     * @return cena towaru (double)
     */
    double getPrice() { return price; }
    
    /**
     * Funkcja ustawiaj¹ca nazwe towaru
     * @param n nowa nazwa towaru
     */
    void setName( string n ); //+walidacja
    /**
     * Funkcja ustawiaj¹ca cenê towaru
     * @param d nowa cena towaru
     */
    void setPrice( double d ) { price = d; }
    
    /**
     * Zaprzyja¿niowa funkcja wypisuj¹ca towar na ekran
     * @param os referencja strumienia
     * @param w referencja obiektu klasy towar
     */
    friend ostream & operator<< (ostream &os, const towar &w);
    /**
     * ZaprzyjaŸniona funkcja wczytuj¹ca nowy towar ze standardowego wejœcia.
     * @param is referencja strumienia
     * @param w referencja obiektu klasy towar
     */
    friend istream & operator>> (istream &is, towar &w);
};
#endif