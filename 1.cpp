#include <iostream>
using namespace std;

class K {
	int Z1;
	float Z2;
	char Z3;
	const float PI;

public:
	//Konstruktory/Destruktory
	K( int k1 = 1, float k2 = 2.4f, char k3 = 'a' ) : PI(3.14f)  {
		cout<< "Konstruktor parametryczny/domniemany"<<endl;
		Z1 = k1;
		Z2 = k2;
		Z3 = k3;
	}

	K( const K  &k ) : PI(3.14f)  {
		cout<< "Konstruktor kopiujacy"<<endl;
		Z1 = k.Z1;
		Z2 = k.Z2;
		Z3 = k.Z3;
	}

	~K() {
		cout<< "Destruktor"<<endl;
	}

	//Accessors
	void set_Z1( int z ) {
		Z1 = z;
	}
	void set_Z2( float f ) {
		Z2 = f;
	}
	void set_Z3( char c ) {
		Z3 = c;
	}

	int get_Z1() {
		return Z1;
	}
	float get_Z2() {
		return Z2;
	}
	char get_Z3( ) {
		return Z3;
	}
	float get_PI() {
		return PI;
	}

	void wypisz() {
		cout << "Z1 = " << Z1 <<endl;
		cout << "Z2 = " << Z2 <<endl;
		cout << "Z3 = " << Z3 <<endl;
		cout << "PI = " << PI <<endl;
	}

};

void fun1(K obj);
K fun2();

int main( void ) {
	K k1;
	K k2(1,1.5,'b');
	K k3(k2);
	K *wk = new K;
	wk->set_Z1(2);
	wk->set_Z2(1.5);
	wk->set_Z3('c');
	cout<<"Wywolanie funkcji fun1(fun2())" << endl;
	fun1(fun2());

	cout<<"Obiekt k1:"<<endl;
	k1.wypisz();
	cout<<"Obiekt k2:"<<endl;
	k2.wypisz();
	cout<<"Obiekt k3:"<<endl;
	k3.wypisz();

	cout << "Obiekt dynamiczny wk dostep wskaznikiem" << endl;
	wk->wypisz();
	cout << "Obiekt dynamiczny wk dostep jak do obiektu" << endl;
	(*wk).wypisz();

	delete wk;
	return 0;
}

void fun1(K obj) {
	cout<< "Poczatek funkcji fun1"<<endl;
	obj.wypisz();
	cout<< "Koniec funkcji fun1"<<endl<<endl;
}

K fun2() {
	cout<< "Poczatek funkcji fun2"<<endl;
	int i;
	float f;
	char c;
	cout<< "Podaj wartosci dla nowego obiektu klasy K. Podaj Z1 (int):"<<endl;
	cin>>i;
	cout<< "Podaj Z2 (float):"<<endl;
	cin>>f;
	cout<< "Podaj Z3 (char):"<<endl;
	cin>>c;
	K obj;
	obj.set_Z1(i);
	obj.set_Z2(f);
	obj.set_Z3(c);
	cout<< "Koniec funkcji fun2"<<endl;
	return obj;
}