#include <iostream>
#include <vector>
#include "zad03.h"
using namespace std;

int main( void ) {
	Matrix mat1(4,4), mat2(4,4), mat3(4,4);
	double tab1[] = {1.2,2.3, 4.5,5.6 };
	vector<double> v1( tab1, tab1+4 );
	double tab2[] = {2.2,3.3, 5.5,6.6 };
	vector<double> v2( tab2, tab2+4 );
	double tab3[] = {3.2,4.3, 7.5,8.6 };
	vector<double> v3( tab3, tab3+4 );
	double tab4[] = {12.2,42.3, 314.5,32.6 };
	vector<double> v4( tab4, tab4+4 );
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
	cout << mat2+mat3;
	cout << mat2-mat3;
	cout << mat2*mat3;
	cout << mat1*100000.0;
	mat1 = mat2;
	cout << (mat1==mat2)<<endl;
	cout << (mat1!=mat2)<<endl;
	cout << Matrix::allZeros(3,5)<<endl;
	cout << Matrix::allOne(3,5)<<endl;
	cout << Matrix::randomMatrix( 3, 3 );
	cout << Matrix::randomMatrix( mat1 );
	return 0;
}