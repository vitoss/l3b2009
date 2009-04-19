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
     * Konstruktor domy�lny
     */
    vect(): size(0) {}
    /**
     * Konstruktor tworz�cy nowy wektor o zadanej d�ugo�ci i zawarto�ci.
     * @param size d�ugo�� wektra
     * @param arr tablica warto�ci. Nie mo�e by� mniejsza od size
     */
    vect( unsigned int size, double * arr );
    /**
     * Konstruktor tworz�cy nowy wektor o zadanej d�ugo�ci.
     * @param size d�ugo�� wektora
     */
    vect( unsigned int size );
    /**
     * Konstruktor kopiuj�cy.
     */
    vect( const vect& v );
    /**
     * Destruktor. Czy�ci pami��.
     */
    ~vect();
    
    /**
     * Operator przypisania
     */
    vect &operator = ( vect & v );
    
    double & operator[]( unsigned int index );
    
    /**
     * Funkcja zwracaj��a d�ugo�� wektora
     * @return d�ugo�� wektora.
     */
    unsigned int get_size() { return size; }
    
    /**
     * Funkcja ustawia d�ugo�� wektora. Gdy jest to liczba mniejsza nast�puje obci�cie, gdy wi�ksza uzupe�nienie zerami.
     * @param size docelowa d�ugo�� wektora
     */
    void set_size( unsigned int size );
    
    /**
     * Funkcja dodaj�ca element na ko�cu wektora (ostatnia wsp�rz�dna).
     * @param elem dany element
     * @return prawda/fa�sz (udana, nieudana operacja)
     */
    bool dodaj( double elem );
    
    /**
    * Operator por�wnania dw�ch wektor�w. 
    * R�wno�� zachodzi, gdy wektory maj� te same wymiary i odpowiadaj�ce sobie wsp�rz�dne s� r�wne.
    * @param v1,v2 dane wektory.
    * @return prawda/fa�sz
    */
    friend bool operator== (const vect &v1, const vect &v2);
    /**
     * Operator nier�wno�ci dw�ch wektor�w. Przeciwie�stwo ==.
     * @param v1,v2 dane wektory.
     * @return prawda/fa�sz
     */
    friend bool operator!= (const vect &v1, const vect &v2) { return !(v1==v2); }
    
    //Overloaded in/out operators
	/** Operator wypisywania na ekran
	 * @param os	strumie� wyj�cia
	 * @param v	referencja do wektora
	 */
    friend ostream& operator<< (ostream& os, const vect &v);
    
    /** Operator wczytywania ze standardowego wej�cia
	 * @param os	strumie� wej�cia
	 * @param v	referencja do wektora
	 */
    friend istream& operator>> (istream&, vect &v);
};
#endif