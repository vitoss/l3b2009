/* Zadanie 3 */
#ifndef MAT_H
#define MAT_H

#include <vector>
using namespace std;
/** Matrix class
 * Klasa implementuj¹ce podstawowe dzia³ania na macierzy.
 * @author	Witold Wasilewski
 * @version 1
 * @date 16.03.2009
 */
class Matrix {
	
	const unsigned int mw; /**< iloœæ wierszy macierzy */
	const unsigned int mk; /**< iloœæ kolumn macierzy */
	double ** data; /**< wskaŸnik do dwuwymiarowej tablicy zawieraj¹cej treœæ macierzy */
	
	
	/**
	 * Funkcja obliczaj¹ca minor danej macierzy.
	 * Powstaje on poprzez wykreœlenie jednej kolumny i wiersza. Nastêpnie obliczamy jego wyznacznik (metod¹ la place) i zwracamy.
	 * Mo¿e równie¿ s³u¿yæ do wyznacznia wyznacznika macierzy, wystarczy podaæ argumenty (-1, -1)
	 * @param l poziom na którym znajduje siê funkcja
	 * @param vec wektor przechowuj¹cy listê wykreœlonych kolumn
	 * @param vec3 numer wykreœlonego wiersza
	 * @return wartoœæ minora
	 */
	double minor( unsigned int l, vector<unsigned int> vec, unsigned int vec3 );

	/**
	 * Funkcja obliczaj¹ca wyznacznik danej macierzy przy u¿yciu rozwiniêcia Laplace'a.
	 * @param l poziom na którym znajduje siê funkcja
	 * @param vec wektor przechowuj¹cy listê wykreœlonych kolumn
	 * @return wartoœæ wyznacznika
	 */
	double determinant( unsigned int l, vector<unsigned int> vec );
public:
	// ############################//
	//   Konstruktory/Destruktory  //
	//#############################//
	/**
	 * Konstruktor domniemany
	 * @param w iloœæ wierszy
	 * @param k iloœæ kolumn
	 */
	Matrix( unsigned int w=1, unsigned int k=1 );
	/**
	 * Konstruktor domniemany
	 * @param w iloœæ wierszy
	 * @param k iloœæ kolumn
	 */
	Matrix( const Matrix &mat );

	/**
	 * Destruktor
	 * Zwalnia pamiêæ pod wskaŸnikiem data.
	 */
	~Matrix();

	
	// ##############//
	//   OPERATORY.  //
	//###############//
	/**
	 * Dostêp do dowolnego elementy tablicy, tylko do odczytu
	 * @param w numer wiersza
	 * @param k numer kolumny
	 * @return skopiowan¹ wartoœæ stoj¹c¹ na [w][k] polu macierzy, w przypadku pora¿ki zwraca 0
	 */
	double operator () ( unsigned int w, unsigned int k ); 
	/**
	 * Prze³adowany operator równoœci, który kopiuje zawartoœæ danej macierzy do macierzy po lewej stronie.
	 * A = B
	 */
	Matrix &operator = (const Matrix &mat);
	/**
	 * Prze³adowany operator, który dodaje odpowiadaj¹ce sobie elementy macierzy i nadpisuje macierz po lewej stronie.
	 * A += B
	 */
	Matrix &operator += (const Matrix &mat);
	/**
	 * Analogia do +=, odejmujemy odpowiadaj¹ce sobie elementy macierz
	 * A -= B
	 */
	Matrix &operator -= (const Matrix &mat);
	/**
	 * Prze³adowany operator, który nie ma wp³ywu na macierz.
	 * A = +B
	 */
	Matrix &operator + ();
	/**
	 * Prze³adowany operator, zmienia macierz na przeciwn¹
	 * A = -B
	 */
	Matrix &operator - (); //macierz przeciwna
	/**
	 * Prze³adowany operator, który mno¿y wszystkie elementy macierzy przez skalar
	 * A *= 5.2
	 * @param r liczba typu double, przez która mno¿ymy macierz
	 */
	Matrix &operator *= ( double r ); 
	/**
	 * Prze³adowany operator, który mno¿y macierz przez macierz. Uwaga - nie jest to przemienne dzia³anie.
	 * A *= B != B*=A
	 * @param mat macierz stoj¹ca po prawej stronie mno¿enia
	 */
	Matrix &operator *= ( const Matrix &mat );
	

	//OPERATORY WEJŒCIA WYJŒCIA
	friend ostream& operator<< (ostream& os, const Matrix &mat);
	friend ofstream& operator<< (ofstream&, const Matrix &mat);
	friend istream& operator>> (istream&, Matrix &mat);
	friend ifstream& operator>> (ifstream&, Matrix &mat);
	//Operatory globalne - komentarze ni¿ej
	friend Matrix operator+ (const Matrix &mat1, const Matrix &mat2);
	friend Matrix operator- (const Matrix &mat1, const Matrix &mat2);
	friend Matrix operator* (const Matrix &mat1, const Matrix &mat2);
	friend Matrix operator* (const Matrix &mat1, double r);
	friend bool operator== (const Matrix &mat1, const Matrix &mat2);
	friend bool operator!= (const Matrix &mat1, const Matrix &mat2);
	
	
	/**
	 * Funkcja obliczaj¹ca wyznacznik macierzy. Macierz musi byæ kwadratowa.
	 * @return liczba typu double bêd¹ca wartoœci¹ wyznacznika
	 */
	double determinant();
	/**
	 * Funkcja transponuj¹ca macierz. 
	 * @return nowa macierz 
	 */
	Matrix transposition(); //~
	/**
	 * Alias dla funkcji tranposition(). 
	 */
	Matrix operator~();
	/**
	 * Funkcja odwracaj¹ca macierz. Macierz musi byæ kwadratowa i posiadaæ niezerowy wyznacznik.
	 * @return nowa macierz 
	 */
	Matrix reverse( ); 
	/**
	 * Alias dla funkcji tranposition(). 
	 */
	Matrix operator!();

	/**
	 * Funkcja obliczaj¹ca minor macierzy.
	 * Wykreœlamy jeden wiersz i jedn¹ kolumnê i liczymy z nowej macierzy wyznacznik.
	 * Mo¿liwe licznie wyznacznika (argumenty -1, -1 )
	 * @param w - numer wykreœlonego wiersza (od 0)
	 * @param k - numer wykreœlonej kolumny (od 0)
	 * @return wartoœæ minora
	 */
	double minor( unsigned int w, unsigned int k );
	/**
	 * Funkcja obliczaj¹ca najmniejsz¹ wartoœæ macierzy.
	 * @return minimaln¹ wartoœæ w macierzy
	 */
	double min();
	/**
	 * Funkcja obliczaj¹ca najwiêksz¹ wartoœæ macierzy.
	 * @return maksymaln¹ wartoœæ w macierzy
	 */
	double max();
	/**
	 * Funkcja sprawdzaj¹ca czy macierz jest symetryczna.
	 * Macierz musi byæ kwadratowa oraz spe³niaæ warunek: [i][k] = [k][i]
	 * @return prawda/fa³sz
	 */
	bool isSymetric();



	/**
	 * Funkcja zwraca iloœæ wierszy.
	 * @return iloœæ wierszy.
	 */
	unsigned int getW() const;
	/**
	 * Funkcja zwraca iloœæ kolumn.
	 * @return iloœæ kolumn.
	 */
	unsigned int getK() const;
	
	/**
	 * Funkcja zwraca now¹ macierz wype³nion¹ zerami.
	 * @param w iloœæ wierszy nowej macierzy
	 * @param k iloœæ kolumn
	 * @return nowa macierz
	 * @see fillWith
	 */
	static Matrix allZeros( unsigned int w, unsigned int k ); 
	/**
	 * Funkcja zwraca now¹ macierz wype³nion¹ zerami.
	 * @param mat macierz z której pobieramy wymiary
	 * @return nowa macierz
	 * @see fillWith
	 */
	static Matrix allZeros( const Matrix &mat ); 
	
	/**
	 * Funkcja zwraca now¹ macierz wype³nion¹ jedynkami.
	 * @param w iloœæ wierszy nowej macierzy
	 * @param k iloœæ kolumn
	 * @return nowa macierz
	 * @see fillWith
	 */
	static Matrix allOne( unsigned int w, unsigned int k ); 
	/**
	 * Funkcja zwraca now¹ macierz wype³nion¹ jedynkami.
	 * @param mat macierz z której pobieramy wymiary
	 * @return nowa macierz
	 * @see fillWith
	 */
	static Matrix allOne( const Matrix &mat ); 
	
	/**
	 * Funkcja zwraca now¹ macierz posiadaj¹c¹ na przek¹tnych jedynki, tzw. Macierz jednostkowa.
	 * Musi byæ kwadratowa.
	 * @param w iloœæ wierszy/kolumn
	 * @return nowa macierz
	 */
	static Matrix identityMatrix( unsigned int w ); 
	/**
	 * Funkcja zwraca now¹ macierz posiadaj¹c¹ na przek¹tnych jedynki, tzw. Macierz jednostkowa.
	 * @param mat macierz z której pobieramy wymiary
	 * @return nowa macierz
	 */
	static Matrix identityMatrix( const Matrix &mat ); 
	
	/**
	 * Funkcja zwraca now¹ macierz wype³nion¹ losowymi wartoœciami.
	 * @param w iloœæ wierszy nowej macierzy
	 * @param k iloœæ kolumn
	 * @return nowa macierz
	 */
	static Matrix randomMatrix( unsigned int w, unsigned int k );
	/**
	 * Funkcja zwraca now¹ macierz wype³nion¹ losowymi wartoœciami.
	 * @param mat macierz z której pobieramy wymiary
	 * @return nowa macierz
	 */
	static Matrix randomMatrix( const Matrix &mat );

	/**
	 * Wype³nia dan¹ kolumnê wartoœciami.
	 * @param colnb numer wype³nianej kolumny
	 * @param col wektor zawieraj¹cy wartoœci,  mo¿e byæ ich wiêcej.
	 */
	void setColumn( unsigned int colnb, const vector<double> &col );
	//analogia do setColumn
	//void setVerset( unsigned int vernb, vector <double> &ver );

private:
	//Funkcje pomocnicze
	/**
	 * Funkcja wype³niaj¹ca ca³¹ macierz zadan¹ wartoœci¹.
	 * Uwaga, dzia³a na podanej macierzy, niszcz¹c jej zawartoœæ.
	 * @param mat macierz na której dzia³amy
	 * @param d wartoœæ, któr¹ wype³niamy macierz
	 */
	static void fillWith( Matrix &mat, double d );
	/**
	 * Funkcja rezerwuj¹ca pamiêæ dla naszej macierzy.
	 */
	void initialization();
};


/**
 * Dodawanie do siebie dwóch macierzy. Elementy stoj¹ce na odpowiadaj¹cych pozycjach s¹ sumowane.
 * @param mat1, mat2 dane macierze.
 * @return now¹ macierz wynikowa.
 */
Matrix operator + (const Matrix &mat1, const Matrix &mat2);
/**
 * Odejmowanie do siebie dwóch macierzy. Elementy stoj¹ce na odpowiadaj¹cych pozycjach s¹ odejmowane.
 * @param mat1, mat2 dane macierze.
 * @return now¹ macierz wynikowa.
 */
Matrix operator - (const Matrix &mat1, const Matrix &mat2);
/**
 * Mno¿enie dwóch macierzy. Uwaga, dzia³anie nie przemienne.
 * @param mat1, mat2 dane macierze.
 * @return now¹ macierz wynikowa.
 */
Matrix operator * (const Matrix &mat1, const Matrix &mat2);
/**
 * Mno¿enie macierzy przez skalar.
 * @param mat1 dana macierz
 * @param r liczba typu double, przez która mno¿ymy dan¹ macierz
 * @return now¹ macierz wynikowa.
 */
Matrix operator * (const Matrix &mat1, double r);

/**
 * Operator porównania dwóch macierzy. 
 * Równoœæ zachodzi, gdy macierze maj¹ te same wymiary i odpowiadaj¹ce sobie elementy s¹ równe.
 * @param mat1, mat2 dane macierze.
 * @return prawda/fa³sz
 */
bool operator== (const Matrix &mat1, const Matrix &mat2);

/**
 * Operator nierównoœci dwóch macierzy. Przeciwieñstwo ==.
 * @param mat1, mat2 dane macierze.
 * @return prawda/fa³sz
 */
bool operator!= (const Matrix &mat1, const Matrix &mat2);


//Operatory wejœcia wyjœcia
/**
 * Prze³adowany operator, który wyœwietla macierz na ekran.
 * @param os strumieñ wyjœcia.
 * @param mat macierz, która chcemy wypisaæ na ekran.
 * @return referencjê do strumienia
 */
ostream& operator<< (ostream&, const Matrix &mat);
/**
 * Prze³adowany operator, który pobiera macierz z pliku.
 * @param os strumieñ wejœcia.
 * @param mat referencja do docelowej macierzy.
 * @return referencja do strumienia
 */
ifstream& operator>> (ifstream&, Matrix &mat);
/**
 * Prze³adowany operator, który wpisuje macierz do pliku.
 * Ró¿ni siê bardziej kompaktow¹ form¹ zapisu.
 * @param os strumieñ wyjœcia.
 * @param mat macierz, która chcemy wypisaæ na ekran.
 * @return referencja do strumienia
*/
ofstream& operator<< (ofstream&, const Matrix &mat);
/**
 * Funkcja wczutuj¹ca macierz przy pomocy klawiatury.
 * @param is standardowy strumieñ wejœcia
 * @param mat referencja dla naszej docelowej macierzy
 */
istream& operator>> (istream& is, Matrix &mat);

#endif