#ifndef FILIA_H
#define FILIA_H
#include <iostream>
#include <string>
#include "DBObject.h"
#include "sklep.h"
#include "towar.h"
#include "wektor.h"
using namespace std;

class sklep;
class towar;
/** Klasa filia.
 * Przechowuje informacje o filii oraz towarach, kt�re si� w niej znajduj�.
 */
class filia : public DBObject {
	
	string adress; /**< Adres filii. */ 
	
	
    public:
    wektor<towar> towary; /**< towary obecne w filii */
	sklep * matka; /**< wska�nik do sklepu matki */
	
    /** 
     * Konstruktor domy�lny.
     */
    filia() {}
    /** 
     * Konstruktor parametryczny.
     * @param i identyfikator obiektu
     * @param Name nazwa filii
     * @param adr adres filii
     */
    filia( unsigned int i, string Name, string adr ): adress(adr), DBObject( i, Name ) {}
    /** 
     * Konstruktor parametryczny.
     * @param i identyfikator obiektu
     * @param Name nazwa filii
     * @param adr adres filii
     * @param skl refenrencja do sklepu-matki
     */
    filia( unsigned int i, string Name, string adr, sklep & skl ): adress(adr), matka( &skl ), DBObject( i, Name ) {
        
    }
    
    ~filia();

    /** 
     * Ustawia nazw� filii.
     */
    void setName( string ); //+walidacja
    /** 
     * Zwraca adres filii.
     */
    string getAdress() { return adress; }
	/** 
     * Operator wypisania na ekran.
     */
	friend ostream & operator<< (ostream &os, const filia &w);
    /** 
     * Operator wczytywania filii (nazwa, adres) z klawiatury.
     */
    friend istream & operator>> (istream &is, filia &w);
};
#endif