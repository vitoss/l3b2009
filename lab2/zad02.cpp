#include "zad02.h"
const int ciagLen = 256;
int ciag::count = 0;
/*
 * operator dodaje do siebie obiekt klasy ciag i dowolny ci�g znakowy np. A + "fda"
 * uwaga na ciekawy spos�b zwracania zmiennej. Zapobiego to usuwaniu zwracanej zmiennej z pami�ci po wyj�ciu z funkcji.
 * Argumenty: c1 -> obiekt klasy ciag, c2 - dowolny wska�nik do �a�cucha znakowego
 * Zwraca: nowy obiekt zalokowany w pami�ci, kt�ry jest suma c1 i c2
 */
ciag operator+( const ciag & c1, const char * c2 ) {
	ciag c;
	c+=c1.str;
	c+=c2;
    return c;
}

/*
 * Operator wypisywania na ekran. W nawiasie d�ugo�� �a�cucha ( z nullem )
 */
ostream& operator << (ostream& os, const ciag& x) {
	os << x.str << " ( " << x.size << " )";
	return os;
}

/*
 * Operator pozwalaj�cy na wygodne wpisywanie ciagu z ekranu.
 * Zmienna ciaglen -> maksymalna d�ugo�� ci�gu
 */
istream& operator >> (istream& is, ciag& x) {
	char temp[ciagLen]; //bufor
	cout << "Podaj zawartosci nowego ciagu znakowego, do " << ciagLen << " znakow"<<endl;
	is.getline( temp, ciagLen );
	x = temp;
	return is; 
}

/*
 * Konstruktor domy�lny, ustawia d�ugo�� �a�cycha na 0
 */
ciag::ciag() : size(0) {
	cout << "Wykonywany kontruktor domyslny" <<endl;
    count++;
}

/*
 * Konstruktor przyjmuj�cy �a�cych znakowy.
 */
ciag::ciag( char * ch ) {
	cout << "Wykonywany kontruktor z parametrem" <<endl;
    size = strlen(ch)+1;
    str = new char[size];
    if( str == NULL ) {
        cout << "Brak pamieci";
        exit(1);
    }
    strcpy( str, ch );
    count++; //zwi�kszanie licznika ilo�ci obiekt�w
}

/*
 * Konstruktor tworz�cy kopi� zadanego obiektu.
 */
ciag::ciag( const ciag &ciag ) {
	cout << "Wykonywany kontruktor kopiujacy" <<endl;
    size  = ciag.size;

    str = new char[size];
    if( str == NULL ) {
        cout << "Brak pamieci";
        exit(1);
    }
    strcpy( str, ciag.str );
	count++;
}

/*
 * Destruktor, zwalnianie pami�ci, zmniejszanie licznika.
 */
ciag::~ciag() {
	cout << "Wykonywany destruktor" <<endl;
	if( size > 0 ) 
		delete [] str;
    count--;
}

/*
 * Funkcja zwracaj�ca d�ugo�� przechowywanego �a�cycha znakowego (z nullem)
 */
int ciag::dl() {
    return size;
}


/*
 * Operator przypisania. Pozwala na A = B; (obiekt klasy ciag jest rzutowany do char *) b�d� A = "fafsad";
 */
ciag &ciag::operator=(const char * ch) {
	if ( size > 0 )	delete [] str;
	size = strlen( ch )+1;
    str = new char[size];
    strcpy( str, ch );
    return *this;
}

ciag &ciag::operator= (const ciag &c ) {
	if ( size > 0 )	delete [] str;
	size = strlen( c.str )+1;
    str = new char[size];
    strcpy( str, c.str );
    return *this;
}

/* 
 * Operator pozwalaj�cy na dodawanie do ko�ca danego obiektu ci�g �a�cucha znakowego, b�d�
 * innego obiektu ci�g zrzutowanego na ten typ, np. A+= B; A+="fdasf";
 */
ciag &ciag::operator+=(const char * ch) {
	//D�ugo�� ci�gu kt�ry dodajemy
	int intTemp = strlen( ch )+1;
	//Dodajemy do pustego ciagu
	if( size <= 0 ) {
		str = new char[intTemp];
		strcpy( str, ch );
		size = intTemp;
	} else if( intTemp >1 ) {
		char * temp;
		temp = new char[size+intTemp];
		strcpy( temp, str );
		strcpy( (temp+size-1), ch );
		size+=intTemp-1;
		delete [] str;
		str = temp;
	}
	return *this;
}
