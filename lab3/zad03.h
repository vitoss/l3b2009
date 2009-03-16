//Kodowanie cp-1250
/* Zadanie 3 */
#ifndef MAT_H
#define MAT_H

#include <vector>
using namespace std;
/** Matrix class
 * Klasa implementujące podstawowe działania na macierzy.
 * @author	Witold Wasilewski
 * @version 1
 * @date 16.03.2009
 */
class Matrix {
	
	const unsigned int mw; /**< ilość wierszy macierzy */
	const unsigned int mk; /**< ilość kolumn macierzy */
	double ** data; /**< wskaźnik do dwuwymiarowej tablicy zawierającej treść macierzy */
	
	
	/**
	 * Funkcja obliczająca minor danej macierzy.
	 * Powstaje on poprzez wykreślenie jednej kolumny i wiersza. Następnie obliczamy jego wyznacznik (metodą la place) i zwracamy.
	 * Może również służyć do wyznacznia wyznacznika macierzy, wystarczy podać argumenty (-1, -1)
	 * @param l poziom na którym znajduje się funkcja
	 * @param vec wektor przechowujący listę wykreślonych kolumn
	 * @param vec3 numer wykreślonego wiersza
	 * @return wartość minora
	 */
	double minor( unsigned int l, vector<unsigned int> vec, unsigned int vec3 );

	/**
	 * Funkcja obliczająca wyznacznik danej macierzy przy użyciu rozwinięcia Laplace'a.
	 * @param l poziom na którym znajduje się funkcja
	 * @param vec wektor przechowujący listę wykreślonych kolumn
	 * @return wartość wyznacznika
	 */
	double determinant( unsigned int l, vector<unsigned int> vec );
public:
	// ############################//
	//   Konstruktory/Destruktory  //
	//#############################//
	/**
	 * Konstruktor domniemany
	 * @param w ilość wierszy
	 * @param k ilość kolumn
	 */
	Matrix( unsigned int w=1, unsigned int k=1 );
	/**
	 * Konstruktor domniemany
	 * @param w ilość wierszy
	 * @param k ilość kolumn
	 */
	Matrix( const Matrix &mat );

	/**
	 * Destruktor
	 * Zwalnia pamięć pod wskaźnikiem data.
	 */
	~Matrix();

	
	// ##############//
	//   OPERATORY.  //
	//###############//
	/**
	 * Dostęp do dowolnego elementy tablicy, tylko do odczytu
	 * @param w numer wiersza
	 * @param k numer kolumny
	 * @return skopiowaną wartość stojącą na [w][k] polu macierzy, w przypadku porażki zwraca 0
	 */
	double operator () ( unsigned int w, unsigned int k ); 
	/**
	 * Przeładowany operator równości, który kopiuje zawartość danej macierzy do macierzy po lewej stronie.
	 * A = B
	 */
	Matrix &operator = (const Matrix &mat);
	/**
	 * Przeładowany operator, który dodaje odpowiadające sobie elementy macierzy i nadpisuje macierz po lewej stronie.
	 * A += B
	 */
	Matrix &operator += (const Matrix &mat);
	/**
	 * Analogia do +=, odejmujemy odpowiadające sobie elementy macierz
	 * A -= B
	 */
	Matrix &operator -= (const Matrix &mat);
	/**
	 * Przeładowany operator, który nie ma wpływu na macierz.
	 * A = +B
	 */
	Matrix &operator + ();
	/**
	 * Przeładowany operator, zmienia macierz na przeciwną
	 * A = -B
	 */
	Matrix &operator - (); //macierz przeciwna
	/**
	 * Przeładowany operator, który mnoży wszystkie elementy macierzy przez skalar
	 * A *= 5.2
	 * @param r liczba typu double, przez która mnożymy macierz
	 */
	Matrix &operator *= ( double r ); 
	/**
	 * Przeładowany operator, który mnoży macierz przez macierz. Uwaga - nie jest to przemienne działanie.
	 * A *= B != B*=A
	 * @param mat macierz stojąca po prawej stronie mnożenia
	 */
	Matrix &operator *= ( const Matrix &mat );
	

	//OPERATORY WEJŚCIA WYJŚCIA
	friend ostream& operator<< (ostream& os, const Matrix &mat);
	friend ofstream& operator<< (ofstream&, const Matrix &mat);
	friend istream& operator>> (istream&, Matrix &mat);
	friend ifstream& operator>> (ifstream&, Matrix &mat);
	//Operatory globalne - komentarze niżej
	friend Matrix operator+ (const Matrix &mat1, const Matrix &mat2);
	friend Matrix operator- (const Matrix &mat1, const Matrix &mat2);
	friend Matrix operator* (const Matrix &mat1, const Matrix &mat2);
	friend Matrix operator* (const Matrix &mat1, double r);
	friend bool operator== (const Matrix &mat1, const Matrix &mat2);
	friend bool operator!= (const Matrix &mat1, const Matrix &mat2);
	
	
	/**
	 * Funkcja obliczająca wyznacznik macierzy. Macierz musi być kwadratowa.
	 * @return liczba typu double będąca wartością wyznacznika
	 */
	double determinant();
	/**
	 * Funkcja transponująca macierz. 
	 * @return nowa macierz 
	 */
	Matrix transposition(); //~
	/**
	 * Alias dla funkcji tranposition(). 
	 */
	Matrix operator~();
	/**
	 * Funkcja odwracająca macierz. Macierz musi być kwadratowa i posiadać niezerowy wyznacznik.
	 * @return nowa macierz 
	 */
	Matrix reverse( ); 
	/**
	 * Alias dla funkcji tranposition(). 
	 */
	Matrix operator!();

	/**
	 * Funkcja obliczająca minor macierzy.
	 * Wykreślamy jeden wiersz i jedną kolumnę i liczymy z nowej macierzy wyznacznik.
	 * Możliwe licznie wyznacznika (argumenty -1, -1 )
	 * @param w - numer wykreślonego wiersza (od 0)
	 * @param k - numer wykreślonej kolumny (od 0)
	 * @return wartość minora
	 */
	double minor( unsigned int w, unsigned int k );
	/**
	 * Funkcja obliczająca najmniejszą wartość macierzy.
	 * @return minimalną wartość w macierzy
	 */
	double min();
	/**
	 * Funkcja obliczająca największą wartość macierzy.
	 * @return maksymalną wartość w macierzy
	 */
	double max();
	/**
	 * Funkcja sprawdzająca czy macierz jest symetryczna.
	 * Macierz musi być kwadratowa oraz spełniać warunek: [i][k] = [k][i]
	 * @return prawda/fałsz
	 */
	bool isSymetric();



	/**
	 * Funkcja zwraca ilość wierszy.
	 * @return ilość wierszy.
	 */
	unsigned int getW() const;
	/**
	 * Funkcja zwraca ilość kolumn.
	 * @return ilość kolumn.
	 */
	unsigned int getK() const;
	
	/**
	 * Funkcja zwraca nową macierz wypełnioną zerami.
	 * @param w ilość wierszy nowej macierzy
	 * @param k ilość kolumn
	 * @return nowa macierz
	 * @see fillWith
	 */
	static Matrix allZeros( unsigned int w, unsigned int k ); 
	/**
	 * Funkcja zwraca nową macierz wypełnioną zerami.
	 * @param mat macierz z której pobieramy wymiary
	 * @return nowa macierz
	 * @see fillWith
	 */
	static Matrix allZeros( const Matrix &mat ); 
	
	/**
	 * Funkcja zwraca nową macierz wypełnioną jedynkami.
	 * @param w ilość wierszy nowej macierzy
	 * @param k ilość kolumn
	 * @return nowa macierz
	 * @see fillWith
	 */
	static Matrix allOne( unsigned int w, unsigned int k ); 
	/**
	 * Funkcja zwraca nową macierz wypełnioną jedynkami.
	 * @param mat macierz z której pobieramy wymiary
	 * @return nowa macierz
	 * @see fillWith
	 */
	static Matrix allOne( const Matrix &mat ); 
	
	/**
	 * Funkcja zwraca nową macierz posiadającą na przekątnych jedynki, tzw. Macierz jednostkowa.
	 * Musi być kwadratowa.
	 * @param w ilość wierszy/kolumn
	 * @return nowa macierz
	 */
	static Matrix identityMatrix( unsigned int w ); 
	/**
	 * Funkcja zwraca nową macierz posiadającą na przekątnych jedynki, tzw. Macierz jednostkowa.
	 * @param mat macierz z której pobieramy wymiary
	 * @return nowa macierz
	 */
	static Matrix identityMatrix( const Matrix &mat ); 
	
	/**
	 * Funkcja zwraca nową macierz wypełnioną losowymi wartościami.
	 * @param w ilość wierszy nowej macierzy
	 * @param k ilość kolumn
	 * @return nowa macierz
	 */
	static Matrix randomMatrix( unsigned int w, unsigned int k );
	/**
	 * Funkcja zwraca nową macierz wypełnioną losowymi wartościami.
	 * @param mat macierz z której pobieramy wymiary
	 * @return nowa macierz
	 */
	static Matrix randomMatrix( const Matrix &mat );

	/**
	 * Wypełnia daną kolumnę wartościami.
	 * @param colnb numer wypełnianej kolumny
	 * @param col wektor zawierający wartości,  może być ich więcej.
	 */
	void setColumn( unsigned int colnb, const vector<double> &col );
	//analogia do setColumn
	//void setVerset( unsigned int vernb, vector <double> &ver );

private:
	//Funkcje pomocnicze
	/**
	 * Funkcja wypełniająca całą macierz zadaną wartością.
	 * Uwaga, działa na podanej macierzy, niszcząc jej zawartość.
	 * @param mat macierz na której działamy
	 * @param d wartość, którą wypełniamy macierz
	 */
	static void fillWith( Matrix &mat, double d );
	/**
	 * Funkcja rezerwująca pamięć dla naszej macierzy.
	 */
	void initialization();
};


/**
 * Dodawanie do siebie dwóch macierzy. Elementy stojące na odpowiadających pozycjach są sumowane.
 * @param mat1, mat2 dane macierze.
 * @return nową macierz wynikowa.
 */
Matrix operator + (const Matrix &mat1, const Matrix &mat2);
/**
 * Odejmowanie do siebie dwóch macierzy. Elementy stojące na odpowiadających pozycjach są odejmowane.
 * @param mat1, mat2 dane macierze.
 * @return nową macierz wynikowa.
 */
Matrix operator - (const Matrix &mat1, const Matrix &mat2);
/**
 * Mnożenie dwóch macierzy. Uwaga, działanie nie przemienne.
 * @param mat1, mat2 dane macierze.
 * @return nową macierz wynikowa.
 */
Matrix operator * (const Matrix &mat1, const Matrix &mat2);
/**
 * Mnożenie macierzy przez skalar.
 * @param mat1 dana macierz
 * @param r liczba typu double, przez która mnożymy daną macierz
 * @return nową macierz wynikowa.
 */
Matrix operator * (const Matrix &mat1, double r);

/**
 * Operator porównania dwóch macierzy. 
 * Równość zachodzi, gdy macierze mają te same wymiary i odpowiadające sobie elementy są równe.
 * @param mat1, mat2 dane macierze.
 * @return prawda/fałsz
 */
bool operator== (const Matrix &mat1, const Matrix &mat2);

/**
 * Operator nierówności dwóch macierzy. Przeciwieństwo ==.
 * @param mat1, mat2 dane macierze.
 * @return prawda/fałsz
 */
bool operator!= (const Matrix &mat1, const Matrix &mat2);


//Operatory wejścia wyjścia
/**
 * Przeładowany operator, który wyświetla macierz na ekran.
 * @param os strumień wyjścia.
 * @param mat macierz, która chcemy wypisać na ekran.
 * @return referencję do strumienia
 */
ostream& operator<< (ostream&, const Matrix &mat);
/**
 * Przeładowany operator, który pobiera macierz z pliku.
 * @param os strumień wejścia.
 * @param mat referencja do docelowej macierzy.
 * @return referencja do strumienia
 */
ifstream& operator>> (ifstream&, Matrix &mat);
/**
 * Przeładowany operator, który wpisuje macierz do pliku.
 * Różni się bardziej kompaktową formą zapisu.
 * @param os strumień wyjścia.
 * @param mat macierz, która chcemy wypisać na ekran.
 * @return referencja do strumienia
*/
ofstream& operator<< (ofstream&, const Matrix &mat);
/**
 * Funkcja wczutująca macierz przy pomocy klawiatury.
 * @param is standardowy strumień wejścia
 * @param mat referencja dla naszej docelowej macierzy
 */
istream& operator>> (istream& is, Matrix &mat);

#endif