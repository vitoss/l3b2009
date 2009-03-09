#ifndef PLIK_H
#define PLIK_H

#include <iostream>
using namespace std;
/** String class.
 * Container for array of char's. It behaves like String class.
 * @author	Witold Wasilewski
 * @version 1
 */
class ciag {

	/**
	 * Operator joins ciag object with array of char. For example: A + "fadsfa"
	 * @param	c1	ciag object
	 * @param	c2	pointer to array of char
	 * @return new allocated ciag object with body consist of both arguments.
	 */
	friend ciag operator+( const ciag &, const char * );

	//Overloaded in/out operators
	/** Operator wypisywania na ekran.
	 * @param os	strumie� wyj�cia
	 * @param ciag	referencja do wy�wietlanego ci�gu
	 */
	friend ostream& operator<< (ostream&, const ciag&);
	friend istream& operator>> (istream&, ciag&);
	
    char * str; /**< wska�nik do przechowywanego �a�cucha znakowego */
    int size; /**< Rozmiar �a�cucha ( z nullem ) */	
    static int count; /**< Ilo�� ci�g�w */

    public:
    /**
	 * Sole constructor.
	 * Increase number of objects.
	 */
    ciag();
	
	/**
	 * Parametric constructor.
	 * @param c	pointer to array of chars, it becomes body of ciag.
	 */
    ciag( char * c);
	/**
	 * Copy constructor.
	 */
    ciag( const ciag &c );
	/**
	 * Destructor.
	 */
    ~ciag();

    /**
	 * Casting operator to char *.
	 * For functions like strlen, cout.
	 */
    operator const char *() { return str; }

	/**
	 * Function returning size of string (with null).
	 * @return size of string
	 */
    int dl();
	
	//Overloaded operators.
    ciag &operator=(const char *);
    ciag &operator+=(const char *);
	ciag &operator= (const ciag &c );
	

	/**
	 * Function returning number of ciag' objects
	 */
    static int ile() { return count; }
};

#endif /* PLIK_H */
