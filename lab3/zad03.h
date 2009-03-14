/* Zadanie 3 */
#include <vector>
using namespace std;
/**
 * 
 */
class Matrix {
	
	//Rozmiary
	const unsigned int mw;
	const unsigned int mk;
	double ** data;

public:
	//Cont/dest
	Matrix( unsigned int w=1, unsigned int k=1 );
	Matrix( const Matrix &mat );

	~Matrix();

	
	//Overloaded operators.
	//dostêp do dowolnego elementy tablicy, tylko do odczytu
	double operator () ( unsigned int w, unsigned int k ); 
	Matrix & operator = (const Matrix &mat);
	Matrix &operator += (const Matrix &mat);
	
	Matrix &operator -= (const Matrix &mat);
	Matrix &operator + (); //nic nie zmienia
	Matrix &operator - (); //macierz przeciwna
	Matrix &operator *= ( double r ); //mnozenie przez skalar
	Matrix &operator *= ( const Matrix &mat );
	
	friend ostream& operator<< (ostream&, const Matrix &mat);
	friend Matrix operator + (const Matrix &mat1, const Matrix &mat2);
	friend Matrix operator - (const Matrix &mat1, const Matrix &mat2);
	friend Matrix operator * (const Matrix &mat1, const Matrix &mat2);
	friend Matrix operator * (const Matrix &mat1, double r);
	friend bool operator== (const Matrix &mat1, const Matrix &mat2);
	friend bool operator!= (const Matrix &mat1, const Matrix &mat2);
	
	/*friend istream& operator>> (istream&, Matrix &mat);
	

	double determinant( const Matrix &mat ); 
	
	
	Matrix reverse( const Matrix &mat ); //!

	
	
	*/
	double determinant();
	double determinant( unsigned int, vector<unsigned int> );
	Matrix transposition(); //~
	double min();
	double max();
	bool isSymetric();

	unsigned int getW() const;
	unsigned int getK() const;
	
	static Matrix allZeros( unsigned int w, unsigned int k ); //Macierz z samymi zerami na podstawie wymiarów
	static Matrix allZeros( const Matrix &mat ); 
	
	static Matrix allOne( unsigned int w, unsigned int k ); //Macierz z samymi jedynkami na podstawie wymiarów
	static Matrix allOne( const Matrix &mat ); 

	static Matrix identityMatrix( unsigned int w ); //Macierz jednostkowa, musi byæ kwadratowa
	static Matrix identityMatrix( const Matrix &mat ); 

	static Matrix randomMatrix( unsigned int w, unsigned int k ); //Macierz z samymi zerami na podstawie wymiarów
	static Matrix randomMatrix( const Matrix &mat );



	//TODO: OPERACJE NA PLIKACH PRZY POMOCY << >>

	//ustawia dan¹ kolumnê przy pomocy tablicy double, mo¿e byæ wiêcej elementów, nie mniej
	void setColumn( unsigned int colnb, const vector<double> &col );
	//analogia do setColumn
	//void setVerset( unsigned int vernb, vector <double> &ver );

private:
	//Funkcje pomocnicze
	//Funkcja wype³niaj¹ca ca³¹ macierz zadan¹ wartoœci¹ (uwaga, dzia³a na podanej macierzy, niszcz¹c jej zawartoœæ)
	static void fillWith( Matrix &mat, double d );
};

//Wypisywanie na ekran

Matrix operator + (const Matrix &mat1, const Matrix &mat2);
Matrix operator - (const Matrix &mat1, const Matrix &mat2);
Matrix operator * (const Matrix &mat1, const Matrix &mat2);
Matrix operator * (const Matrix &mat1, double r);
bool operator== (const Matrix &mat1, const Matrix &mat2);
bool operator!= (const Matrix &mat1, const Matrix &mat2);
ostream& operator<< (ostream&, const Matrix &mat);
/*istream& operator>> (istream&, Matrix &mat*/
