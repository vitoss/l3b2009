//TODO: mat1 += mat1;

#include "zad03.h"
#include <iostream>

using namespace std;

//Constructors & Destruktors
Matrix::Matrix( unsigned int w , unsigned int k ) : mw(w), mk(k) {
	data = new double* [mw];
	for( unsigned int i=0; i < mw; i++ ) {
		*(data+i) = new double[mk];
	}
}

Matrix::Matrix( const Matrix &mat ): mw(mat.mw), mk (mat.mk ) {
	delete [] data;
	data = new double* [mw];
	for( unsigned int i=0; i < mw; i++ ) {
		*(data+i) = new double[mk];
	}
	for( unsigned int i = 0; i<mw; i++ ) {
		for( unsigned int k = 0; k<mk; k++ ) {
			data[i][k] = mat.data[i][k];
		}
	}
}

Matrix::~Matrix() {
	delete [] data;
}

unsigned int Matrix::getW() const {
	return mw;
}
unsigned int Matrix::getK() const {
	return mk;
}

//Operatory
//W razie pora¿ki zwraca 0 i wyswietla odpowiedni komunikat
double Matrix::operator () ( unsigned int w, unsigned int k ) {
	if( w >= getW() || k > getK() ) {
		cout << "Podano bledny zakres przy odczytywaniu wartosci z macierzy" <<endl;
		return 0;
	}
	return data[w][k];
}
Matrix & Matrix::operator = (const Matrix &mat) {
	if( ((this->getW()) != (mat.getW())) || (this->getK() != mat.getK()) ) {
		cout << "Wymiary macierzy siê nie zgadzaj¹" <<endl;
		return *this;
	}
	for( unsigned int i = 0; i<getW(); i++ ) {
		for( unsigned int k = 0; k<getK(); k++ ) {
			data[i][k] = mat.data[i][k];
		}
	}
	return *this;
}

Matrix &Matrix::operator += (const Matrix &mat ) {
	if( getW() != mat.getW() || getK() != mat.getK() ) {
		cout << "Wymiary macierzy siê nie zgadzaj¹" <<endl;
		return *this;
	}
	for( unsigned int i = 0; i<getW(); i++ ) {
		for( unsigned int k = 0; k<getK(); k++ ) {
			data[i][k] += mat.data[i][k];
		}
	}
	return *this;
}

Matrix &Matrix::operator -= (const Matrix &mat) {
	if( getW() != mat.getW() || getK() != mat.getK() ) {
		cout << "Wymiary macierzy siê nie zgadzaj¹" <<endl;
		return *this;
	}
	for( unsigned int i = 0; i<getW(); i++ ) {
		for( unsigned int k = 0; k<getK(); k++ ) {
			data[i][k] -= mat.data[i][k];
		}
	}
	return *this;
}
Matrix &Matrix::operator + ( ) {
	return *this;	
}//nic nie zmienia
Matrix &Matrix::operator - () {
	for( unsigned int i = 0; i<getW(); i++ ) {
		for( unsigned int k = 0; k<getK(); k++ ) {
			data[i][k] = -data[i][k];
		}
	}
	return *this;	
}//macierz przeciwna

Matrix &Matrix::operator *= ( double r ) {
	for( unsigned int i = 0; i<getW(); i++ ) {
		for( unsigned int k = 0; k<getK(); k++ ) {
			data[i][k] = data[i][k]*r;
		}
	}
	return *this;
}//mnozenie przez skalar

//NIE PRZEMIENNE
Matrix &Matrix::operator *= ( const Matrix &mat) {
	//sprawdzanie wymiarów
	if( getW() != mat.getK() || getK() != mat.getW() ){
		cout << "Niezgodne wymiary!" <<endl;
		return *this;
	}
	double suma = 0;
	for( unsigned int i = 0; i<getW(); i++ ) {
		for( unsigned int k = 0; k<getK(); k++ ) {
			suma = 0;
			for( unsigned int l=0; l<getW(); l++ )
				suma+=data[i][l] * mat.data[l][k];
			data[i][k] = suma;
		}
	}
	return *this;
}


ostream& operator<< (ostream& os, const Matrix &mat) {
	os.precision(3);
	os.width(7);
	for( unsigned int i = 0; i<mat.getW(); i++ ) {
		for( unsigned int k = 0; k<mat.getK(); k++ ) {
			os.width(10);
			os<<mat.data[i][k];
		}
		os << endl;
	}
	return os;
}

//Funkcje pomocnicze
//ustawia dan¹ kolumnê przy pomocy tablicy double, mo¿e byæ wiêcej elementów, nie mniej
void Matrix::setColumn( unsigned int colnb, const vector <double> &col ) {
	
	if( getW() > col.size() || getK() <= colnb ) {
		cout << "Za krotka tablica do inicjalizacji lub zly numer kolumny" <<endl;
	} else {
		for( unsigned int i = 0; i<getW(); i++ ) {
			data[i][colnb] = col[i];
		}
	}
}
//analogia do setColumn 
/*
void Matrix::setVerset( unsigned int vernb, double * ver ) {
	size_t size_of_ver = (sizeof ver)/(sizeof ver[0]);
	if( getW() >= vernb || getK() >= size_of_ver ) {
		cout << "Za krotka tablica do inicjalizacji lub zly numer wiersza" <<endl;
	} else {
		for( unsigned int i = 0; i<getW(); i++ ) {
			data[vernb][i] = ver[i];
		}
	}
}*/

Matrix operator + (const Matrix &mat1, const Matrix &mat2) {
	if( mat1.getW() != mat2.getW() || mat1.getK() != mat2.getK() ){
		cout << "Niezgodne wymiary! Zwracam pierwsz¹ macierz." <<endl;
		return mat1;
	} 
	Matrix mat( mat1 );
	mat+=mat2;
	return mat;
}
//NIEPRZEMIENNY
Matrix operator - (const Matrix &mat1, const Matrix &mat2) {
	if( mat1.getW() != mat2.getW() || mat1.getK() != mat2.getK() ){
		cout << "Niezgodne wymiary! Zwracam pierwsz¹ macierz." <<endl;
		return mat1;
	} 
	Matrix mat(mat1);
	Matrix::fillWith(mat, 0);
	mat-=mat2;
	return mat;
}

Matrix operator * (const Matrix &mat1, const Matrix &mat2) {
	if( mat1.getW() != mat2.getW() || mat1.getK() != mat2.getK() ){
		cout << "Niezgodne wymiary! Zwracam pierwsz¹ macierz." <<endl;
		return mat1;
	} 
	Matrix mat(mat1);
	mat*=mat2;
	return mat;
}

Matrix operator * ( const Matrix &mat1, double r ) {
	Matrix mat(mat1);
	mat *= r;
	cout << mat << endl;
	cout << r << endl;
	return mat;
}

bool operator == (const Matrix &mat1, const Matrix &mat2) {
	if( mat1.getW() != mat2.getW() || mat1.getK() != mat2.getK() ){
		cout << "Niezgodne wymiary!" <<endl;
		return false;
	} 
	for( unsigned int i = 0; i<mat1.getW(); i++ ) {
		for( unsigned int k = 0; k<mat1.getK(); k++ ) {
			if( mat1.data[i][k] != mat2.data[i][k] ) 
				return false;
		}
	}
	return true;
}
bool operator != (const Matrix &mat1, const Matrix &mat2) {
	return !(mat1==mat2);
}


//STATYCZNE
Matrix Matrix::allZeros( unsigned int w, unsigned int k ) {
	Matrix mat(w,k);
	Matrix::fillWith(mat, 0);
	return mat;
}
Matrix Matrix::allZeros( const Matrix &mat ) {
	return Matrix::allZeros(mat.mw, mat.mk);
}

Matrix Matrix::allOne( unsigned int w, unsigned int k ) {
	Matrix mat(w,k);
	Matrix::fillWith(mat, 1);
	return mat;
}
Matrix Matrix::allOne( const Matrix &mat ) {
	return Matrix::allOne(mat.mw, mat.mk);
}
Matrix Matrix::identityMatrix( unsigned int w ) {
	Matrix mat(w,w);
	Matrix::fillWith( mat, 0 );
	for(unsigned int i=0; i<w; i++ ) {
		mat.data[i][i] = 1;
	}
	return mat;
}
Matrix Matrix::identityMatrix( const Matrix &mat ) {
	if( mat.mw != mat.mk ) {
		cout << "macierz jednostkowa musi byc kwadratowa!";
		return Matrix();
	}
	return Matrix::identityMatrix( mat.mw );
}

//TODO: lepszy range
Matrix Matrix::randomMatrix( unsigned int w, unsigned int k ) {
	Matrix mat(w,k);
	double range = 1000.0;
	for( unsigned int i = 0; i<w; i++ ) {
		for( unsigned int r = 0; r<k; r++ ) {
			mat.data[i][r] = (double) (rand() * range / RAND_MAX);
		}
	}
	return mat;
}

Matrix Matrix::randomMatrix( const Matrix &mat ) {
	return Matrix::randomMatrix( mat.mw, mat.mk );
}

//POMOCNICZE
void Matrix::fillWith( Matrix &mat, double d ) {
	for( unsigned int i=0; i<mat.getW(); i++ ) {
		for( unsigned int k=0; k<mat.getK(); k++ ) {
			mat.data[i][k] = d;
		}
	}
}

