#ifndef SKLEP_H
#define SKLEP_H
#include <iostream>
#include "DBObject.h"
#include "filia.h"
#include "wektor.h"
using namespace std;

class filia;
/** 
 * Klasa sklep.
 * Przechowuje podstawowe informacje o sklepie.
 */
class sklep : public DBObject {	
	
    public:
    wektor<filia> filie; /**< Lista filii podlegaj¹cych sklepowi */
	
    /** 
     * Konstruktor domyœlny.
     */
    sklep() {}
    /** 
     * Konstruktor parametryczny.
     * @param i identyfikator obiektu.
     * @param Name nazwa sklepu
     */
    sklep( unsigned int i, string Name ) : DBObject( i, Name ){}
    ~sklep();
    /** 
     * Ustawia nazwê sklepu
     */
    void setName( string ); //+walidacja
	/** 
     * Operator wypisania na ekran.
     */
    friend ostream & operator<< (ostream &os, const sklep &w);
    /** 
     * Operator wczytania z klawiatury.
     */
    friend istream & operator>> (istream &is, sklep &w);
};

#endif;