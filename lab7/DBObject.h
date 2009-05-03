#ifndef DBOBJECT_H
#define DBOBJECT_H

using namespace std;
/**
 * Klasa rodzic dla wszystkich obiektów przechowywanych w bazie danych.
 */
class DBObject {
protected:
    unsigned int id; /**< Unikalny w danym zasiêgu (np. towary w filii nie interferuj¹ z globalnymi towarami) identyfikator obiektu */	
	string name; /**< Nazwa obiektu */
    /**
     * Konstruktor domyœlny
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
     * Funkcja wirtualna ustawij¹ca nazwê obiektu.
     * Ka¿da klasa powinna przeprowadziæ (implementowaæ) odpowiedni¹ walidacjê wejœcia.
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