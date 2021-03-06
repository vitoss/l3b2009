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
 * Klasa przedstawiająca towar w bazie danych.
 */
class towar : public DBObject  {
	double price; /**< domyślna cena, ustawiana tylko przy tworzeniu towaru. */

	public:
    wektor<filia*> shops; /**< filie gdzie towar jest dostepny */

    /**
     * Konstruktor domyślny.
     */
    towar(){};
    /**
     * Konstruktor parametryczny.
     * @param i identyfikator (unikalny) obiektu.
     * @param n nazwa towaru
     * @param c domyślna cena towaru
     */
    towar::towar( int i,string n, double c ): DBObject(i,n), price(c) {}
    //~towar(); //usuwa wszystkie kopie po sklepach :p
    
    /**
     * Funkcja zwracająca cenę towaru.
     * @return cena towaru (double)
     */
    double getPrice() { return price; }
    
    /**
     * Funkcja ustawiająca nazwe towaru
     * @param n nowa nazwa towaru
     */
    void setName( string n ); //+walidacja
    /**
     * Funkcja ustawiająca cenę towaru
     * @param d nowa cena towaru
     */
    void setPrice( double d ) { price = d; }
    
    /**
     * Zaprzyjażniowa funkcja wypisująca towar na ekran
     * @param os referencja strumienia
     * @param w referencja obiektu klasy towar
     */
    friend ostream & operator<< (ostream &os, const towar &w);
    /**
     * Zaprzyjaźniona funkcja wczytująca nowy towar ze standardowego wejścia.
     * @param is referencja strumienia
     * @param w referencja obiektu klasy towar
     */
    friend istream & operator>> (istream &is, towar &w);
};
#endif