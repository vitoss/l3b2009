#ifndef PLIK_H
#define PLIK_H
#include <iostream>
using namespace std;
/*Plik nag��wkowy*/
//Maksymalna d�ugo�� ci�gu, z nullem

class ciag {
	//Dodawanie dw�ch ci�g�w
    //friend ciag & operator+( ciag &, ciag & );
	friend ciag operator+( const ciag &, const char * );
	//Prze�adowane operatory dla wej�cia i wyj�cia
	friend ostream& operator<< (ostream&, const ciag&);
	friend istream& operator>> (istream&, ciag&);
	
	//wska�nik do przechowywanego �a�cucha znakowego
    char * str;
	//Rozmiar �a�cucha ( z nullem )
    int size;
	//Ilo�� ci�g�w
    static int count;

    public:
    //Constructors & destructors
    ciag();
    ciag( char * );
    ciag( const ciag & );
    ~ciag();

    //Operator rzutuj�ca na char *
    operator const char *() { return str; }

	//Funkcja zwracaj�ca d�ugo�� ci�gu
    int dl();

	//Prze�adowane operatory
    ciag &operator=(const char *);
    ciag &operator+=(const char *);
	ciag &operator= (const ciag &c );
	

	//Zwraca liczb� obiek�w klasy ciag
    static int ile() { return count; }
};

#endif /* PLIK_H */
