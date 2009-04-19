#ifndef VECT
#define VECT
#include <iostream>

using namespace std;

/** vect class.
 * Klasa wektor.
 * @author	Witold Wasilewski
 * @version 1
 */
class vect {
    protected:
    unsigned int size;
    double * arr;
    
    public:
    
    //Konstruktory
    /**
     * Konstruktor domyœlny
     */
    vect(): size(0) {}
    /**
     * Konstruktor tworz¹cy nowy wektor o zadanej d³ugoœci i zawartoœci.
     * @param size d³ugoœæ wektra
     * @param arr tablica wartoœci. Nie mo¿e byæ mniejsza od size
     */
    vect( unsigned int size, double * arr );
    /**
     * Konstruktor tworz¹cy nowy wektor o zadanej d³ugoœci.
     * @param size d³ugoœæ wektora
     */
    vect( unsigned int size );
    /**
     * Konstruktor kopiuj¹cy.
     */
    vect( const vect& v );
    /**
     * Destruktor. Czyœci pamiêæ.
     */
    ~vect();
    
    /**
     * Operator przypisania
     */
    vect &operator = ( vect & v );
    
    double & operator[]( unsigned int index );
    
    /**
     * Funkcja zwracaj¹æa d³ugoœæ wektora
     * @return d³ugoœæ wektora.
     */
    unsigned int get_size() { return size; }
    
    /**
     * Funkcja ustawia d³ugoœæ wektora. Gdy jest to liczba mniejsza nastêpuje obciêcie, gdy wiêksza uzupe³nienie zerami.
     * @param size docelowa d³ugoœæ wektora
     */
    void set_size( unsigned int size );
    
    /**
     * Funkcja dodaj¹ca element na koñcu wektora (ostatnia wspó³rzêdna).
     * @param elem dany element
     * @return prawda/fa³sz (udana, nieudana operacja)
     */
    bool dodaj( double elem );
    
    /**
    * Operator porównania dwóch wektorów. 
    * Równoœæ zachodzi, gdy wektory maj¹ te same wymiary i odpowiadaj¹ce sobie wspó³rzêdne s¹ równe.
    * @param v1,v2 dane wektory.
    * @return prawda/fa³sz
    */
    friend bool operator== (const vect &v1, const vect &v2);
    /**
     * Operator nierównoœci dwóch wektorów. Przeciwieñstwo ==.
     * @param v1,v2 dane wektory.
     * @return prawda/fa³sz
     */
    friend bool operator!= (const vect &v1, const vect &v2) { return !(v1==v2); }
    
    //Overloaded in/out operators
	/** Operator wypisywania na ekran
	 * @param os	strumieñ wyjœcia
	 * @param v	referencja do wektora
	 */
    friend ostream& operator<< (ostream& os, const vect &v);
    
    /** Operator wczytywania ze standardowego wejœcia
	 * @param os	strumieñ wejœcia
	 * @param v	referencja do wektora
	 */
    friend istream& operator>> (istream&, vect &v);
};
#endif