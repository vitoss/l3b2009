#ifndef DBOBJECT_H
#define DBOBJECT_H

using namespace std;
/**
 * Klasa rodzic dla wszystkich obiekt�w przechowywanych w bazie danych.
 */
class DBObject {
protected:
    unsigned int id; /**< Unikalny w danym zasi�gu (np. towary w filii nie interferuj� z globalnymi towarami) identyfikator obiektu */	
	string name; /**< Nazwa obiektu */
    /**
     * Konstruktor domy�lny
     */
    DBObject() {} 
    /**
     * Konstruktor parametryczny.
     * @param i identyfikator obiektu
     * @param n nazwa obiektu
     */
    DBObject( unsigned int i, string n ): id(i), name(n) {}
public:
    /**
     * Operator rzutowania na typ char *.
     * @return Nazwa obiektu zrzutowana na char *.
     */
    operator const char *() { return name.c_str(); }
    /**
     * Funkcja wirtualna ustawij�ca nazw� obiektu.
     * Ka�da klasa powinna przeprowadzi� (implementowa�) odpowiedni� walidacj� wej�cia.
     */
    virtual void setName( string ) = 0; // + walidacja
    //setters
	/**
     * Ustawia identyfikator.
     */
    void setId( unsigned int nid ) { id = nid; }
    //getters
    /**
     * @return nazwa obiektu
     */
    string getName() { return name; }
    /**
     * @ return identyfikator obiektu
     */
    int getId() {return id; }
};
#endif