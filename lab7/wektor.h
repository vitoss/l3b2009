#ifndef WEKTOR_H
#define WEKTOR_H
#include <iostream>
#include <algorithm>
using namespace std;

//help for sorting
int nameComparator(const void * t1,const void * t2);
int priceComparator(const void * t1,const void * t2);
/**
 * Szablonowa klasa wektor.
 */
template <class T>
class wektor {
	T * items; /**< Tablica elementów przechowywanych przez wektor */
	unsigned int count; /**< aktualna ilosc elementow */
	unsigned int capacity; /**< wielkosc wektora ( w tym puste miejsca ) */
    char sortedBy; /**< wewenêtrzna zmienna decyduj¹ca czy obiekt jest posortowany czy nie i wed³ug jakiej zmiennej, 'a' - nie posortowany */

    /** Funkcja rozszerzaj¹ca wektor.
     * @param amount iloœæ elementów do dodania
     */
	void extend( unsigned int amount ); //
    
	public:
	//konstruktory
    /** 
     * Konstruktor domyœlny.
     */
    wektor();
    /** 
     * Konstruktor parametryczny.
     * @param amount pocz¹tkowa iloœæ elementów
     */
	wektor( unsigned int amount );
    /** 
     * Konstruktor parametryczny.
     * @param arr tablica zawieraj¹ca elementy docelowe
     * @param amount iloœæ elementów
     */
	wektor( T * arr, unsigned int amount );
	/** 
     * Konstruktor kopiuj¹cy
     */
	wektor( const wektor& old );
	//destruktor	
	~wektor();
	
    /** 
     * Funkcja dodaj¹ca obiekt do wektora ( a dok³adniej kopiuj¹ca go do wektora ).
     * @param obj dany obiekt
     */
	void addObject( T obj ); //na koñcu wektora
    /** 
     * Funkcja dodaj¹ca obiekt do wektora ( a dok³adniej kopiuj¹ca go do wektora ) na dan¹ pozycjê.
     * Gdy podana pozycja wykracza poza zakres wektora - obiekt nie zostaje dodany.
     * @param obj danyc obiekt
     * @param position pozycja na liœcie
     */
	void addObject( T obj, unsigned int position );
	
    /** 
     * Funkcja zwraca obiekt na danej pozycji.
     * Jeœli nie istnieje wyrzuca wyj¹tek (1).
     * @param position numer pozycji
     */
    T getObject( unsigned int position ); 
    /** 
     * Funkcja zwraca obiekt o danych identyfikatorze (z klasy DBObject).
     * Jeœli nie istnieje wyrzuca wyj¹tek (1).
     * @param id identyfikator obiektu
     */
	T& getObjectById( unsigned int id );
    /** 
     * Funkcja zwraca obiekt o danej nazwie (name z klasy DBObject).
     * Jeœli nie istnieje wyrzuca wyj¹tek (1).
     * @param name nazwa obiektu
     */
    T& getObjectByName( string name );
    /** 
     * Funkcja usuwa obiekt stoj¹cy na danej pozycji.
     * Jeœli pozycja wychodzi poza zakres wyrzuca wyj¹tek (jeœli pozycja jest wiêksza ni¿ iloœæ dostêpnych elementów)
     */
	T removeObject( unsigned int position ); 
    /** 
     * Funkcja usuwa obiekt o danych identyfikatorze (id z klasy DBObject).
     * W razie niepowodzenia wyrzuca wyj¹tek (1).
     */
	T removeObjectById( unsigned int id );
    /** 
     * Zwraca iloœæ elementów w wektorze.
     */
    unsigned int amount() { return count; }
	 
	 //pomocnicze
    /** 
     * Funkcja rezerwuj¹ca miejsce w wektorze.
     */
    void reserve( unsigned int amount ) { extend(amount); }//rezerwuje miejsce w pamiêci - dodatkowe, zeby nie kopiowac calej zawartoœci w razie potrzeby
	 
    /** 
     * Funkcja sortuj¹ca obiekty klasy DBObject (lub potomne) wed³ug nazwy. 
     */
    void sortByName() {
        if( sortedBy != 'b' ) {
            qsort( items, count, sizeof( T ), nameComparator );
            sortedBy = 'b';
        }
    }

    //TODO specjalizacja dla wektor<towar>?!!
    /** 
     * Funkcja sortuj¹ca obiekty klasy towar (lub potomne) wed³ug ceny. 
     */
    void sortByPrice() {
        if( sortedBy != 'c' ) {
            qsort( items, count, sizeof( T ), priceComparator );
            sortedBy = 'c';
        }
    }
	 
	 
	/*//operatory
	wektor & operator=(wektor &); // */
    /** 
     * Operator dodaj¹cy dwa wektory.
     */
   wektor<T> & operator+(wektor<T> &); // 
   
   /** 
     * Operator zwracaj¹cy obiekt na danej pozycji.
     */
   T & operator[](unsigned int position) {
       if( position >= count )
           return items[0];
       return items[position];
   }
   
   /** 
     * Operator wypisania na ekran ca³ego wektora.
     */
   friend ostream & operator<< <> (ostream &os, wektor<T> &w);
   
   

   
};

template<typename T> wektor<T>::wektor() {
    count = 0;
    capacity = 0;
    sortedBy='a';
}

template<typename T> wektor<T>::wektor( T * arr, unsigned int amount ): capacity(amount) {
    items = new T[amount];
    for( unsigned int i=0; i<amount; i++ ) {
        items[i] = arr[i];
    }
    count = amount;
    sortedBy='a';
}
template<typename T> wektor<T>::wektor( unsigned int amount ): capacity(amount), count(0) {
    items = new T[amount];
    sortedBy='a';
}

template<typename T> wektor<T>::wektor( const wektor& old ) {
    count = old.count;
    capacity = old.capacity;
    if( capacity > 0 ) {
        items = new T[capacity];
        if( count >0 ) {
            
            for( unsigned int i=0; i<count; i++ ) {
                items[i] = old.items[i];
            }
        }
    }
    sortedBy=old.sortedBy;
}

template<typename T> wektor<T>::~wektor() {
    //cout<<"desktruktor wektora"<<endl;
    //cout << count << "|" << capacity <<endl;
    //if( count > 0 ) {
    //    cout << "Ma elementy";
    //}
    //cout << endl;
    //if( capacity > 0 )
    //    delete[] items;
    ////TODO remove
    //capacity = 0;
    //count = 0;
}

template<typename T> void wektor<T>::addObject( T obj ) {
    //sprawdzanie czy wektor jest zape³niony
    if( count == capacity )
        extend(5);
    items[count++] = obj;
    sortedBy = 'a';
}

template<typename T> void wektor<T>::addObject( T obj, unsigned int position ) {
    if( count == capacity )
        extend(5);
    //nieekonomiczne
    T * tempArray = new T[capacity]; 
    count++;
    int increment = 0;
    for(unsigned int i=0; i<count; i++ ) {
        if( i==position ) {
            tempArray[i] = obj;
            increment = 1;
        }
        else
            tempArray[i] = items[i-increment];
    }

    delete[] items;
    items = tempArray;
    sortedBy = 'a';
}

template<typename T> void wektor<T>::extend( unsigned int amount ) {
    capacity += amount;
    T * tempArray = new T[capacity]; 
    for(unsigned int i=0; i<count; i++ )
        tempArray[i] = items[i];
    if( count > 0 )
        delete[] items; 
    items = tempArray;
}

template<typename T> T wektor<T>::getObject( unsigned int position ) {
    if( position >= count ) 
        throw 1;
    else
        return items[position];
}

template<typename T> T wektor<T>::removeObject( unsigned int position ) {
    if( position >= count )
        throw 1;
    
    T temp = items[position];
    for( unsigned int i = position; i<count-1; i++ )
    {
        items[i] = items[i+1];
    }

    //Usuwanie ostatniego, podwojnego elementu
    //items[count-1] = new T();
    //delete *(items[count-1]);
    count--;
    return temp;
}

template<typename T> 
wektor<T> & wektor<T>::operator+(wektor<T> & w ){
    int y = w.count -( capacity - count );
    if( y > 0 ) {
        extend( (unsigned int)y );
    }
    for( int i=0; i<w.count; i++ ) {
        items[count++] = w.items[i];
    }
    return *this;
}// 

template<typename T> 
ostream & operator<< (ostream &os, wektor<T> &w) {
    for( unsigned int i=0; i<w.count; i++ ) {
        cout << w.items[i];
    }
    if( w.count == 0 )
        cout << "Brak elementow na liscie." << endl;
    return os;
}


template<typename T>
T& wektor<T>::getObjectById( unsigned int id ) {
    for( unsigned int i=0; i<count; i++ ) {
        if( items[i].getId() == id )
            return items[i];
    }
    //throws exception? return null? TODO
    throw 1;
}

template<typename T>
T& wektor<T>::getObjectByName( string name ) {
    for( unsigned int i=0; i<count; i ++ ) {
        if( items[i].getName() == name )
            return items[i];
    }
    //throws exception? return null? TODO
    return items[0];
}
template<typename T>
T wektor<T>::removeObjectById( unsigned int id ) {
    T t;
    for( unsigned int i=0; i<count; i ++ ) {
        if( items[i].getId() == id )
        {
            t = removeObject( i );
            return t;
        }
    }
    throw 1;
}
#endif