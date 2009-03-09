#ifndef PLIK_H
#define PLIK_H
#include <iostream>
using namespace std;
/*Plik nag³ówkowy*/
//Maksymalna d³ugoœæ ci¹gu, z nullem

class ciag {
	//Dodawanie dwóch ci¹gów
    //friend ciag & operator+( ciag &, ciag & );
	friend ciag operator+( const ciag &, const char * );
	//Prze³adowane operatory dla wejœcia i wyjœcia
	friend ostream& operator<< (ostream&, const ciag&);
	friend istream& operator>> (istream&, ciag&);
	
	//wskaŸnik do przechowywanego ³añcucha znakowego
    char * str;
	//Rozmiar ³añcucha ( z nullem )
    int size;
	//Iloœæ ci¹gów
    static int count;

    public:
    //Constructors & destructors
    ciag();
    ciag( char * );
    ciag( const ciag & );
    ~ciag();

    //Operator rzutuj¹ca na char *
    operator const char *() { return str; }

	//Funkcja zwracaj¹ca d³ugoœæ ci¹gu
    int dl();

	//Prze³adowane operatory
    ciag &operator=(const char *);
    ciag &operator+=(const char *);
	ciag &operator= (const ciag &c );
	

	//Zwraca liczbê obieków klasy ciag
    static int ile() { return count; }
};

#endif /* PLIK_H */
