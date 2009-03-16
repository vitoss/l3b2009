//Kodowanie cp-1250
#include "zad03.h"
#include <iostream>
#include <fstream>
#include <algorithm> //algorytm sortowania

using namespace std;

//Constructors & Destruktors
Matrix::Matrix( unsigned int w , unsigned int k ) : mw(w), mk(k) {
	initialization();
}

Matrix::Matrix( const Matrix &mat ): mw(mat.mw), mk (mat.mk ) {
	delete [] data;
	initialization();

	for( unsigned int i = 0; i<mw; i++ ) {
		for( unsigned int k = 0; k<mk; k++ ) {
			data[i][k] = mat.data[i][k];
		}
	}
}

void Matrix::initialization() {
	data = new double* [mw];
	for( unsigned int i=0; i < mw; i++ ) {
		*(data+i) = new double[mk];
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
	if( w >= mw || k > mk ) {
		cout << "Podano bledny zakres przy odczytywaniu wartosci z macierzy" <<endl;
		return 0;
	}
	return data[w][k];
}

Matrix & Matrix::operator = (const Matrix &mat) {
	if( *this == mat ) return *this; // w celu zapobiegniêciu zbêdnej pracy A = A

	if( ((this->mw) != (mat.mw)) || (this->mk != mat.mk) ) {
		cout << "Wymiary macierzy siê nie zgadzaj¹" <<endl;
		return *this;
	}
	for( unsigned int i = 0; i<mw; i++ ) {
		for( unsigned int k = 0; k<mk; k++ ) {
			data[i][k] = mat.data[i][k];
		}
	}
	return *this;
}

Matrix &Matrix::operator += (const Matrix &mat ) {
	if( mw != mat.mw || mk != mat.mk ) {
		cout << "Wymiary macierzy siê nie zgadzaj¹" <<endl;
		return *this;
	}
	for( unsigned int i = 0; i<mw; i++ ) {
		for( unsigned int k = 0; k<mk; k++ ) {
			data[i][k] += mat.data[i][k];
		}
	}
	return *this;
}

Matrix &Matrix::operator -= (const Matrix &mat) {
	/* Wersja harpagan:
	if( mw != mat.mw || mk != mat.mk ) {
		cout << "Wymiary macierzy siê nie zgadzaj¹" <<endl;
		return *this;
	}
	for( unsigned int i = 0; i<mw; i++ ) {
		for( unsigned int k = 0; k<mk; k++ ) {
			data[i][k] -= mat.data[i][k];
		}
	}*/
	//Wersja smart, ale musimy skopiowaæ zawartoœæ mat (które jest const).
	//DRY, ale za to wolniejsze?
	Matrix temp(mat);
	temp = mat;
	(*this)+=(-(temp));
	return *this;
}

//nic nie zmienia
Matrix &Matrix::operator + ( ) {
	return *this;	
}

//macierz przeciwna
Matrix &Matrix::operator - () {
	for( unsigned int i = 0; i<mw; i++ ) {
		for( unsigned int k = 0; k<mk; k++ ) {
			data[i][k] = -data[i][k];
		}
	}
	return *this;	
}

//mnozenie przez skalar
Matrix &Matrix::operator *= ( double r ) {
	for( unsigned int i = 0; i<mw; i++ ) {
		for( unsigned int k = 0; k<mk; k++ ) {
			data[i][k] = data[i][k]*r;
		}
	}
	return *this;
}

//NIE PRZEMIENNE
Matrix &Matrix::operator *= ( const Matrix &mat) {
	//sprawdzanie wymiarów
	if( mw != mat.mk || mk != mat.mw ){
		cout << "Niezgodne wymiary!" <<endl;
		return *this;
	}
	double suma = 0;
	for( unsigned int i = 0; i<mw; i++ ) {
		for( unsigned int k = 0; k<mk; k++ ) {
			suma = 0;
			for( unsigned int l=0; l<mw; l++ )
				suma+=data[i][l] * mat.data[l][k];
			data[i][k] = suma;
		}
	}
	return *this;
}


ostream& operator<< (ostream& os, const Matrix &mat) {
	os.precision(3);
	os.width(7);
	for( unsigned int i = 0; i<mat.mw; i++ ) {
		for( unsigned int k = 0; k<mat.mk; k++ ) {
			os.width(10);
			os<<mat.data[i][k];
		}
		os << endl;
	}
	return os;
}
//dla pliku
ofstream& operator<< (ofstream &os, const Matrix &mat) {
	//wymiary
	os.operator<<(mat.mw);
	os<<",";
	os.operator<<(mat.mk);
	os<<endl;
	os.precision(6);
	for( unsigned int i = 0; i<mat.mw; i++ ) {
		for( unsigned int k = 0; k<mat.mk-1; k++ ) {
			os.operator<<(mat.data[i][k]);
			os<<" ";
		}
		os.operator<<(mat.data[i][mat.mw-1]);
		os << endl;
	}
	return os;
}

istream& operator>> (istream& is, Matrix &mat) {
	cout << "Rozpoczêto procedure wcztywania macierzy z klawiatury"<<endl;
	cout << "Wymiary macierzy to: " << mat.mw << "x" << mat.mk<<endl;
	char * temp;
	const int ts =  (mat.getK())*2; //przewidywany rozmiar bufora
	temp = new char[ts];
	
	for( unsigned int i = 0; i<mat.mw; i++ ) {
		cout << "Proszê podaæ " << mat.mk << " wartoœci typu double oddzielonych spacjami. ("<<i<<" wiersz)"<<endl;
		for( unsigned int k = 0; k<mat.mk; k++ ) {
			cin >> mat.data[i][k];
		}
	}
	return is;
}

ifstream& operator>> (ifstream &is, Matrix &mat) {

	for( unsigned int i = 0; i<mat.mw; i++ ) {
		for( unsigned int k = 0; k<mat.mk; k++ ) {
			is.operator>>(mat.data[i][k]);
		}
	}
	return is;
}

//Funkcje pomocnicze
//ustawia dan¹ kolumnê przy pomocy tablicy double, mo¿e byæ wiêcej elementów, nie mniej
void Matrix::setColumn( unsigned int colnb, const vector <double> &col ) {
	
	if( mw > col.size() || mk <= colnb ) {
		cout << "Za krotka tablica do inicjalizacji lub zly numer kolumny" <<endl;
	} else {
		for( unsigned int i = 0; i<mw; i++ ) {
			data[i][colnb] = col[i];
		}
	}
}
//analogia do setColumn 
/*
void Matrix::setVerset( unsigned int vernb, double * ver ) {
	size_t size_of_ver = (sizeof ver)/(sizeof ver[0]);
	if( mw >= vernb || mk >= size_of_ver ) {
		cout << "Za krotka tablica do inicjalizacji lub zly numer wiersza" <<endl;
	} else {
		for( unsigned int i = 0; i<mw; i++ ) {
			data[vernb][i] = ver[i];
		}
	}
}*/

Matrix operator + (const Matrix &mat1, const Matrix &mat2) {
	if( mat1.mw != mat2.mw || mat1.mk != mat2.mk ){
		cout << "Niezgodne wymiary! Zwracam pierwsz¹ macierz." <<endl;
		return mat1;
	} 
	Matrix mat( mat1 );
	mat+=mat2;
	return mat;
}
//NIEPRZEMIENNY
Matrix operator - (const Matrix &mat1, const Matrix &mat2) {
	if( mat1.mw != mat2.mw || mat1.mk != mat2.mk ){
		cout << "Niezgodne wymiary! Zwracam pierwsz¹ macierz." <<endl;
		return mat1;
	} 
	Matrix mat(mat1);
	Matrix::fillWith(mat, 0);
	mat-=mat2;
	return mat;
}

Matrix operator * (const Matrix &mat1, const Matrix &mat2) {
	if( mat1.mw != mat2.mw || mat1.mk != mat2.mk ){
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
	if( mat1.mw != mat2.mw || mat1.mk != mat2.mk ){
		cout << "Niezgodne wymiary!" <<endl;
		return false;
	} 
	for( unsigned int i = 0; i<mat1.mw; i++ ) {
		for( unsigned int k = 0; k<mat1.mk; k++ ) {
			if( mat1.data[i][k] != mat2.data[i][k] ) 
				return false;
		}
	}
	return true;
}
bool operator != (const Matrix &mat1, const Matrix &mat2) {
	return !(mat1==mat2);
}


double Matrix::min()  {
	double m = data[0][0];
	for( unsigned int i = 0; i<mw; i++ ) {
		for( unsigned int k = 0; k<mk; k++ ) {
			if( data[i][k] < m ) 
				m = data[i][k];
		}
	}
	return m;
}
double Matrix::max()  {
	double m = data[0][0];
	for( unsigned int i = 0; i<mw; i++ ) {
		for( unsigned int k = 0; k<mk; k++ ) {
			if( data[i][k] > m ) 
				m = data[i][k];
		}
	}
	return m;
}

bool Matrix::isSymetric() {
	//musi byæ kwadratowa
	if( mw != mk )
		return false;

	for( unsigned int i = 0; i<mw; i++ ) {
		for( unsigned int k = 0; k<mk; k++ ) {
			if( data[i][k] != data[k][i] )
				return false;
		}
	}
	return true;
}

Matrix Matrix::transposition() { //~
	Matrix res(mk,mw);
	for( unsigned int i = 0; i<mw; i++ ) {
		for( unsigned k=0; k<mk; k++ ) {
			res.data[k][i] = data[i][k];
		}
	}
	return res;

}
//alias
Matrix Matrix::operator~() {
	return transposition();
}

//Interfejs u¿ytkownika dla w³aœciwej funkcji determinant
double Matrix::determinant() {
	/* Mo¿na równie¿ u¿yæ funkcji minor 
	 return minor( -1, -1 );
	 */

	//sprawdzanie rozmiarów
	if( mw != mk ){
		cout << "Macierz powinna byæ kwadratowa!" << endl;
		return 0;
	}
	vector<unsigned int> vec; //wektor przechowuj¹cy wykreœlone kolumny
	return determinant( 0, vec );
}

//Mo¿e zostaæ sukcesywnie zast¹pione przez minor( -1, -1 );
double Matrix::determinant( unsigned int l, vector<unsigned int> vec ) {

	if( l == (mw-1) ) {
		//doszlimy do konca i zwracamy szukan¹ wartoœæ
		for( unsigned int m = 0; m < vec.size(); m++ ) {
			if( m != vec[m] ) {
				return data[l][m];
			}
		}
		return data[l][l];
	}


	double suma = 0;
	int z = 1;	
	unsigned int k = 0;
	
	for( unsigned int i = 0; i<mw; i++ ) {
		vector<unsigned int> vec2( vec );
		
		if(  k<vec.size() && vec[k] == i  ) {
			//opuszczanie zakazanego pasma
			k++;
			continue;
		}
			
		vec2.push_back( i );
		sort(vec2.begin(), vec2.end()); //sortowanie w celu uproszczenia wyszukiwania zakazanych kolumn w sekcji wy¿ej
		
		suma += z*(data[l][i])*(determinant( l+1, vec2 ));
		z=-z;
	}
	return suma;
}


double Matrix::minor( unsigned int wr, unsigned int kr ) {
	if( mw != mk ){
		cout << "Macierz powinna byæ kwadratowa!" << endl;
		return 0;
	}
	vector<unsigned int> vec;
	vec.push_back( kr );
	return minor( 0, vec, wr );
}

//tak technicznie to jest to zmodyfikowany wyznacznik, który pozwala na wykreœlenie danej kolumny i wiersza
//mo¿e równie¿ s³u¿yæ do obliczania wyznacznika!!! wystarczy skorzystaæ z funkcji minor( -1, -1 );
double Matrix::minor( unsigned int l, vector<unsigned int> vec, unsigned int vec3 ) {
	
	//doszlimy do momentu gdy musimy zwróciæ wartoœæ
	if( ( l == (mw-2) && vec3 == mw-2 )  //wykreslamy przedostatni wiersz i przedostatnia kolumne
		||  (( l == (mw-1) ) )  //najbardziej naturalny przypadek, gdy po prostu dochodzimy do konca macierzy - ostatni wiersz
		|| ( vec3 == mw-1 && l==mw-2) ) { //wykreslamy ostatni wiersz i jestesmy w przedostatni wierszu
		
		if( l == vec3 ) {
			l++; //jeœli jesteœmy w wykreœlonym wierszu to pomijamy go
		}

		
		for( unsigned int m = 0; m < vec.size(); m++ ) {
			//szukamy kolumny, która nie zosta³a wykreœlona, dlatego sortujemy vec po dodaniu wartoœci (ni¿ej)
			if( m != vec[m] ) {
				return data[l][m];
			}
		}
		//gdy wykonujemy ten blok to oznacza, ¿e zwracamy element le¿¹cy w ostatniej kolumnie
		
		unsigned int y = l;
		//przypadek gdy wykreœlamy ostatni wiersz, to przesuwamy kolumnê która zawiera zwracany element w prawo.
		if( vec3 == mw-1 )
			y++;
		
		////cout << "SUMA PODCZASTKOWA!! return[l][m]" << l << " | "<< l << " | " << data[l][l] << endl;
		return data[l][y];
	}
	
	//jeœli jesteœmy w wykreœlonym wierszu to pomijamy go
	if( vec3 == l ) l++;

	double suma = 0; //zwracana wartoœæ
	int z = 1;	//znak przy sumie, -1 lub 1
	unsigned int k = 0; //przydatne przy iteracji po zakazych kolumnach w zmiennej vec (posortowanej!)
	
	for( unsigned int i = 0; i<mw; i++ ) {
		vector<unsigned int> vec2( vec ); //tworzenie kopii vec
		
		if(  k<vec2.size() && vec2[k] == i  ) {
			//opuszczanie zakazanego pasma
			////cout << "zakazane: " << i << endl;
			k++;
			continue;
		}
			
		vec2.push_back( i ); //dodanie zakazanej kolumny
		sort(vec2.begin(), vec2.end()); //sortowanie, w celu uproszczenia niektórych operacji	
		
		suma += z*(data[l][i])*(minor( l+1, vec2, vec3 )); //dodawanie kolejnego sk³adnika do sumy
		z=-z; //zmiana znaku przy kolejnym elemencie sumy (1 lub -1)
	}

	////cout << "Suma: " << suma << endl;
	return suma;
}

Matrix Matrix::reverse( ) { //!
	double det = determinant();
	if( det == 0 ) {
		cout << "Macierz musi miec wyznacznik != 0 by moc ja odwrocic." << endl;
		return Matrix();
	}
	Matrix mat(mw, mk);
	double min;
	int z = 1;
	for( unsigned int  i= 0; i<mw; i++ ) {
		for( unsigned k=0; k<mk; k++ ) {
			min =  minor(i,k);

			if(  (i+k) % 2 == 1 ) 
				z = -1;
			else 
				z = 1;
			mat.data[i][k] = (z)* min/det;
			
		}
	}
	mat = mat.transposition(); 
	return mat;
}
//alias
Matrix Matrix::operator!() {
	return reverse();
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
	for( unsigned int i=0; i<mat.mw; i++ ) {
		for( unsigned int k=0; k<mat.mk; k++ ) {
			mat.data[i][k] = d;
		}
	}
}

