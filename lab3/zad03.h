/* Zadanie 3 */
#ifndef MAT_H
#define MAT_H

#include <vector>
using namespace std;
/** Matrix class
 * Klasa implementuj�ce podstawowe dzia�ania na macierzy.
 * @author	Witold Wasilewski
 * @version 1
 * @date 16.03.2009
 */
class Matrix {
	
	const unsigned int mw; /**< ilo�� wierszy macierzy */
	const unsigned int mk; /**< ilo�� kolumn macierzy */
	double ** data; /**< wska�nik do dwuwymiarowej tablicy zawieraj�cej tre�� macierzy */
	
	
	/**
	 * Funkcja obliczaj�ca minor danej macierzy.
	 * Powstaje on poprzez wykre�lenie jednej kolumny i wiersza. Nast�pnie obliczamy jego wyznacznik (metod� la place) i zwracamy.
	 * Mo�e r�wnie� s�u�y� do wyznacznia wyznacznika macierzy, wystarczy poda� argumenty (-1, -1)
	 * @param l poziom na kt�rym znajduje si� funkcja
	 * @param vec wektor przechowuj�cy list� wykre�lonych kolumn
	 * @param vec3 numer wykre�lonego wiersza
	 * @return warto�� minora
	 */
	double minor( unsigned int l, vector<unsigned int> vec, unsigned int vec3 );

	/**
	 * Funkcja obliczaj�ca wyznacznik danej macierzy przy u�yciu rozwini�cia Laplace'a.
	 * @param l poziom na kt�rym znajduje si� funkcja
	 * @param vec wektor przechowuj�cy list� wykre�lonych kolumn
	 * @return warto�� wyznacznika
	 */
	double determinant( unsigned int l, vector<unsigned int> vec );
public:
	// ############################//
	//   Konstruktory/Destruktory  //
	//#############################//
	/**
	 * Konstruktor domniemany
	 * @param w ilo�� wierszy
	 * @param k ilo�� kolumn
	 */
	Matrix( unsigned int w=1, unsigned int k=1 );
	/**
	 * Konstruktor domniemany
	 * @param w ilo�� wierszy
	 * @param k ilo�� kolumn
	 */
	Matrix( const Matrix &mat );

	/**
	 * Destruktor
	 * Zwalnia pami�� pod wska�nikiem data.
	 */
	~Matrix();

	
	// ##############//
	//   OPERATORY.  //
	//###############//
	/**
	 * Dost�p do dowolnego elementy tablicy, tylko do odczytu
	 * @param w numer wiersza
	 * @param k numer kolumny
	 * @return skopiowan� warto�� stoj�c� na [w][k] polu macierzy, w przypadku pora�ki zwraca 0
	 */
	double operator () ( unsigned int w, unsigned int k ); 
	/**
	 * Prze�adowany operator r�wno�ci, kt�ry kopiuje zawarto�� danej macierzy do macierzy po lewej stronie.
	 * A = B
	 */
	Matrix &operator = (const Matrix &mat);
	/**
	 * Prze�adowany operator, kt�ry dodaje odpowiadaj�ce sobie elementy macierzy i nadpisuje macierz po lewej stronie.
	 * A += B
	 */
	Matrix &operator += (const Matrix &mat);
	/**
	 * Analogia do +=, odejmujemy odpowiadaj�ce sobie elementy macierz
	 * A -= B
	 */
	Matrix &operator -= (const Matrix &mat);
	/**
	 * Prze�adowany operator, kt�ry nie ma wp�ywu na macierz.
	 * A = +B
	 */
	Matrix &operator + ();
	/**
	 * Prze�adowany operator, zmienia macierz na przeciwn�
	 * A = -B
	 */
	Matrix &operator - (); //macierz przeciwna
	/**
	 * Prze�adowany operator, kt�ry mno�y wszystkie elementy macierzy przez skalar
	 * A *= 5.2
	 * @param r liczba typu double, przez kt�ra mno�ymy macierz
	 */
	Matrix &operator *= ( double r ); 
	/**
	 * Prze�adowany operator, kt�ry mno�y macierz przez macierz. Uwaga - nie jest to przemienne dzia�anie.
	 * A *= B != B*=A
	 * @param mat macierz stoj�ca po prawej stronie mno�enia
	 */
	Matrix &operator *= ( const Matrix &mat );
	

	//OPERATORY WEJ�CIA WYJ�CIA
	friend ostream& operator<< (ostream& os, const Matrix &mat);
	friend ofstream& operator<< (ofstream&, const Matrix &mat);
	friend istream& operator>> (istream&, Matrix &mat);
	friend ifstream& operator>> (ifstream&, Matrix &mat);
	//Operatory globalne - komentarze ni�ej
	friend Matrix operator+ (const Matrix &mat1, const Matrix &mat2);
	friend Matrix operator- (const Matrix &mat1, const Matrix &mat2);
	friend Matrix operator* (const Matrix &mat1, const Matrix &mat2);
	friend Matrix operator* (const Matrix &mat1, double r);
	friend bool operator== (const Matrix &mat1, const Matrix &mat2);
	friend bool operator!= (const Matrix &mat1, const Matrix &mat2);
	
	
	/**
	 * Funkcja obliczaj�ca wyznacznik macierzy. Macierz musi by� kwadratowa.
	 * @return liczba typu double b�d�ca warto�ci� wyznacznika
	 */
	double determinant();
	/**
	 * Funkcja transponuj�ca macierz. 
	 * @return nowa macierz 
	 */
	Matrix transposition(); //~
	/**
	 * Alias dla funkcji tranposition(). 
	 */
	Matrix operator~();
	/**
	 * Funkcja odwracaj�ca macierz. Macierz musi by� kwadratowa i posiada� niezerowy wyznacznik.
	 * @return nowa macierz 
	 */
	Matrix reverse( ); 
	/**
	 * Alias dla funkcji tranposition(). 
	 */
	Matrix operator!();

	/**
	 * Funkcja obliczaj�ca minor macierzy.
	 * Wykre�lamy jeden wiersz i jedn� kolumn� i liczymy z nowej macierzy wyznacznik.
	 * Mo�liwe licznie wyznacznika (argumenty -1, -1 )
	 * @param w - numer wykre�lonego wiersza (od 0)
	 * @param k - numer wykre�lonej kolumny (od 0)
	 * @return warto�� minora
	 */
	double minor( unsigned int w, unsigned int k );
	/**
	 * Funkcja obliczaj�ca najmniejsz� warto�� macierzy.
	 * @return minimaln� warto�� w macierzy
	 */
	double min();
	/**
	 * Funkcja obliczaj�ca najwi�ksz� warto�� macierzy.
	 * @return maksymaln� warto�� w macierzy
	 */
	double max();
	/**
	 * Funkcja sprawdzaj�ca czy macierz jest symetryczna.
	 * Macierz musi by� kwadratowa oraz spe�nia� warunek: [i][k] = [k][i]
	 * @return prawda/fa�sz
	 */
	bool isSymetric();



	/**
	 * Funkcja zwraca ilo�� wierszy.
	 * @return ilo�� wierszy.
	 */
	unsigned int getW() const;
	/**
	 * Funkcja zwraca ilo�� kolumn.
	 * @return ilo�� kolumn.
	 */
	unsigned int getK() const;
	
	/**
	 * Funkcja zwraca now� macierz wype�nion� zerami.
	 * @param w ilo�� wierszy nowej macierzy
	 * @param k ilo�� kolumn
	 * @return nowa macierz
	 * @see fillWith
	 */
	static Matrix allZeros( unsigned int w, unsigned int k ); 
	/**
	 * Funkcja zwraca now� macierz wype�nion� zerami.
	 * @param mat macierz z kt�rej pobieramy wymiary
	 * @return nowa macierz
	 * @see fillWith
	 */
	static Matrix allZeros( const Matrix &mat ); 
	
	/**
	 * Funkcja zwraca now� macierz wype�nion� jedynkami.
	 * @param w ilo�� wierszy nowej macierzy
	 * @param k ilo�� kolumn
	 * @return nowa macierz
	 * @see fillWith
	 */
	static Matrix allOne( unsigned int w, unsigned int k ); 
	/**
	 * Funkcja zwraca now� macierz wype�nion� jedynkami.
	 * @param mat macierz z kt�rej pobieramy wymiary
	 * @return nowa macierz
	 * @see fillWith
	 */
	static Matrix allOne( const Matrix &mat ); 
	
	/**
	 * Funkcja zwraca now� macierz posiadaj�c� na przek�tnych jedynki, tzw. Macierz jednostkowa.
	 * Musi by� kwadratowa.
	 * @param w ilo�� wierszy/kolumn
	 * @return nowa macierz
	 */
	static Matrix identityMatrix( unsigned int w ); 
	/**
	 * Funkcja zwraca now� macierz posiadaj�c� na przek�tnych jedynki, tzw. Macierz jednostkowa.
	 * @param mat macierz z kt�rej pobieramy wymiary
	 * @return nowa macierz
	 */
	static Matrix identityMatrix( const Matrix &mat ); 
	
	/**
	 * Funkcja zwraca now� macierz wype�nion� losowymi warto�ciami.
	 * @param w ilo�� wierszy nowej macierzy
	 * @param k ilo�� kolumn
	 * @return nowa macierz
	 */
	static Matrix randomMatrix( unsigned int w, unsigned int k );
	/**
	 * Funkcja zwraca now� macierz wype�nion� losowymi warto�ciami.
	 * @param mat macierz z kt�rej pobieramy wymiary
	 * @return nowa macierz
	 */
	static Matrix randomMatrix( const Matrix &mat );

	/**
	 * Wype�nia dan� kolumn� warto�ciami.
	 * @param colnb numer wype�nianej kolumny
	 * @param col wektor zawieraj�cy warto�ci,  mo�e by� ich wi�cej.
	 */
	void setColumn( unsigned int colnb, const vector<double> &col );
	//analogia do setColumn
	//void setVerset( unsigned int vernb, vector <double> &ver );

private:
	//Funkcje pomocnicze
	/**
	 * Funkcja wype�niaj�ca ca�� macierz zadan� warto�ci�.
	 * Uwaga, dzia�a na podanej macierzy, niszcz�c jej zawarto��.
	 * @param mat macierz na kt�rej dzia�amy
	 * @param d warto��, kt�r� wype�niamy macierz
	 */
	static void fillWith( Matrix &mat, double d );
	/**
	 * Funkcja rezerwuj�ca pami�� dla naszej macierzy.
	 */
	void initialization();
};


/**
 * Dodawanie do siebie dw�ch macierzy. Elementy stoj�ce na odpowiadaj�cych pozycjach s� sumowane.
 * @param mat1, mat2 dane macierze.
 * @return now� macierz wynikowa.
 */
Matrix operator + (const Matrix &mat1, const Matrix &mat2);
/**
 * Odejmowanie do siebie dw�ch macierzy. Elementy stoj�ce na odpowiadaj�cych pozycjach s� odejmowane.
 * @param mat1, mat2 dane macierze.
 * @return now� macierz wynikowa.
 */
Matrix operator - (const Matrix &mat1, const Matrix &mat2);
/**
 * Mno�enie dw�ch macierzy. Uwaga, dzia�anie nie przemienne.
 * @param mat1, mat2 dane macierze.
 * @return now� macierz wynikowa.
 */
Matrix operator * (const Matrix &mat1, const Matrix &mat2);
/**
 * Mno�enie macierzy przez skalar.
 * @param mat1 dana macierz
 * @param r liczba typu double, przez kt�ra mno�ymy dan� macierz
 * @return now� macierz wynikowa.
 */
Matrix operator * (const Matrix &mat1, double r);

/**
 * Operator por�wnania dw�ch macierzy. 
 * R�wno�� zachodzi, gdy macierze maj� te same wymiary i odpowiadaj�ce sobie elementy s� r�wne.
 * @param mat1, mat2 dane macierze.
 * @return prawda/fa�sz
 */
bool operator== (const Matrix &mat1, const Matrix &mat2);

/**
 * Operator nier�wno�ci dw�ch macierzy. Przeciwie�stwo ==.
 * @param mat1, mat2 dane macierze.
 * @return prawda/fa�sz
 */
bool operator!= (const Matrix &mat1, const Matrix &mat2);


//Operatory wej�cia wyj�cia
/**
 * Prze�adowany operator, kt�ry wy�wietla macierz na ekran.
 * @param os strumie� wyj�cia.
 * @param mat macierz, kt�ra chcemy wypisa� na ekran.
 * @return referencj� do strumienia
 */
ostream& operator<< (ostream&, const Matrix &mat);
/**
 * Prze�adowany operator, kt�ry pobiera macierz z pliku.
 * @param os strumie� wej�cia.
 * @param mat referencja do docelowej macierzy.
 * @return referencja do strumienia
 */
ifstream& operator>> (ifstream&, Matrix &mat);
/**
 * Prze�adowany operator, kt�ry wpisuje macierz do pliku.
 * R�ni si� bardziej kompaktow� form� zapisu.
 * @param os strumie� wyj�cia.
 * @param mat macierz, kt�ra chcemy wypisa� na ekran.
 * @return referencja do strumienia
*/
ofstream& operator<< (ofstream&, const Matrix &mat);
/**
 * Funkcja wczutuj�ca macierz przy pomocy klawiatury.
 * @param is standardowy strumie� wej�cia
 * @param mat referencja dla naszej docelowej macierzy
 */
istream& operator>> (istream& is, Matrix &mat);

#endif