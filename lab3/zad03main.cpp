/** Autor Witold Wasilewski
 *  Data: 21.03.2009r.
 *  Program 3. Prezentacja.
 */
#include <iostream>
#include <fstream>
#include <vector>
#include "zad03.h"
using namespace std;

int main( void ) {
	Matrix mat1(4,4), mat2(4,4), mat3(4,4), mat4(4,3), mat5(2,2);
	//Uzupe³niamy macierzê korzystaj¹c z funkcji setColumn
	double tab1[] = {1.2,2.3, 4.5,5.6 };
	vector<double> v1( tab1, tab1+4 );
	double tab2[] = {2.2,3.3, 5.5,6.6 };
	vector<double> v2( tab2, tab2+4 );
	double tab3[] = {3.2,4.3, 7.5,8.6 };
	vector<double> v3( tab3, tab3+4 );
	double tab4[] = {12.2,42.3, 314.5,32.6};
	vector<double> v4( tab4, tab4+4 );
	double tab5[] = {1,2};
	vector<double> v5( tab5, tab5+2 );
	double tab6[] = {3,4};
	vector<double> v6( tab6, tab6+2 );
	mat1.setColumn(0, v1 );
	mat1.setColumn(1, v2 );
	mat1.setColumn(2, v3 );
	mat1.setColumn(3, v4 );
	
	mat2.setColumn(0, v4 );
	mat2.setColumn(1, v3 );
	mat2.setColumn(2, v2 );
	mat2.setColumn(3, v1 );
	mat3.setColumn(0, v2 );
	mat3.setColumn(1, v3 );
	mat3.setColumn(2, v2 );
	mat3.setColumn(3, v1 );
	mat4.setColumn(0, v2 );
	mat4.setColumn(1, v3 );
	mat4.setColumn(2, v2 );
	mat5.setColumn(0,v5);
	mat5.setColumn(1,v6);

	//Operatory arytmetyczne
	cout << "Dodawanie dwoch macierzy: " << endl << mat2+mat3;
	cout << "Odejmowanie dwoch macierzy: " << endl << mat2-mat3;
	cout << "Mnozenie dwoch macierzy: " << endl << mat2*mat3;
	cout << "Mnozenie macierzy przez skalar: " << endl << mat1*100000.0;
	mat1 = mat2; //operator przypisania
	cout << "Operator porównania: " << endl << (mat1==mat2)<<endl;
	cout << (mat1!=mat2)<<endl;
	cout << "Macierz wype³niona zerami" << endl;
	cout << Matrix::allZeros(3,5)<<endl;
	cout << "Macierz wype³niona jedynkami" << endl;
	cout << Matrix::allOne(3,5)<<endl;
	cout << "Macierz losowa" << endl;
	cout << Matrix::randomMatrix( 3, 3 );
	cout << Matrix::randomMatrix( mat1 );

	cout << "Element minimalny macierzy nr1" << endl;
	cout << mat1.min() <<endl;
	cout << "Element maksymalny macierzy nr1" << endl;
	cout << mat1.max() <<endl;
	cout << "Czy macierz jest symetryczna?" << endl;
	cout << mat1.isSymetric() <<endl;
	//Transpozycja
	cout << "Transpozycja macierzy nr4" << endl;
	cout << mat4.transposition();
	//Wyznacznik oraz macierz odwrotna
	double min[10];
	min[0] = mat1.determinant();
	min[1] = mat1.minor(1,1); //2174...
	min[2] = mat1.minor(0,1); //1144
	min[3] = mat1.minor(2,1); //197.3
	min[4] = mat1.minor( 0, 0 ); //-57.2
	min[5] = mat1.minor(3, 3); //-1.1
	min[6] = mat1.minor(2, 3); //-1.1
	min[7]=mat1.minor( 3,1 ); //-489.1..
	for( int i = 0; i<8; i++ ) {
		cout << min[i]<<endl;
	}
	
	cout << "Macierz odwrotna do macierzy nr1" <<endl<<endl;
	cout << mat1.reverse() <<endl; 

	
	cout << "Zapis do pliku" <<endl;
	//Zapis i odczyt z pliku
	ifstream iplik( "input.txt", ifstream::in );
	
	unsigned int wi,ki;
	iplik >> wi; //rozmiary wczytywane z pliku
	iplik >> ki;
	Matrix mat6(wi,ki);

	cout << "Odczyt z pliku" <<endl;
	//odczyt z pliku
	iplik >> mat6;
	iplik.close();
	//zapis do pliku
	cout << mat6;
	ofstream plik( "output.txt" );
	plik << mat6.reverse();
	plik.close();

	cout << "Wczytywanie macierz przy pomocy klawiatury." <<endl <<endl;
	//wczytywanie z ekranu
	Matrix mat7(2,2);
	cin >> mat7;
	cout << mat7;
	return 0;
}