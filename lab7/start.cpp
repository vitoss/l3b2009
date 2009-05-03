//TODO : cleaning and loading once again!

/** \file start.cpp
 * Plik zawieraj�cy g��wna logik� programu.
 */


/*! \mainpage Strona g��wna: Zadanie 7
 *
 * \section intro_sec Wst�p
 *
 * Program ma za zadanie obs�u�y� prost� baz� danych o sklepach.
 *
 * \section sec1 Opis dzia�ania
 * 
 * W programie mo�na wyr�ni� kilka klas: Sklep, Filia oraz Towar.
 * \subsection Sklep
 * Sklep jest obiektem reprezentuj�cym firm�, ale nie w fizycznym sensie. W naszym przypadku ma on po prostu swoj� nazw�.
 * Nic nie stoi jednak na przeskodzie, by doda� kolejne elementy.
 * \subsection Filia
 * Filia reprezentuje fizyczny wymiar sklepu i jest �ci�le z nim zwi�zany - ka�da filia musi posiad� sw�j sklep. Jest to oddzial sklepu maj�cy sw�j adres oraz list� towar�w z cenami, kt�re zale�a od zarz�dzaj�cego fili�.
 * \subsection Towar
 *  Towar reprezentuje dobro, kt�re mo�e naby� konsument. Globalny spis towar�w mo�na por�wna� do hurtowni, a dodawanie towar�w do konkretnej filii do zam�wienia.
 * Nale�y zwr�ci� uwag�, �e nawet je�li towar zostanie usuni�ty z hurtowni to nadal mo�na spotka� go w niekt�rych filiach.
 *
 * \section sec1 Sk�adowanie danych
 * Baza danych przechowywana jest w 3 plikach: sklepy.txt, towary.txt, magazyny.txt
 * Komentarze mo�e wymaga� jedynie plik magazyny.txt, gdzie przechowywane s� relacje pomi�dzy towarami i filiami (format: id sklepu;id filii;id towaru;cena towaru)
 */


#include <iostream>
#include <fstream>
#include "towar.h"
#include "filia.h"
#include "wektor.h"
//przemyslec klase sklad, ktora przechuwuje dane: SklepID, FiliaID, cena, ilosc
//moze ma byc to klasa o skladowych statycznych, tak by prosto uzywac jej w klasie filie
//a moze kopiowac obiekty klasy towar? i zmieniac odpowiednio pola cena i ilosc?
using namespace std;
/**
 * Spis sklep�w.
 * @param p numer strony (zaczynaj�c od 0).
 */
void browseSklepy(unsigned int p);
/**
 * Spis towar�w dost�pnych w bazie danych (kt�re mo�na umie�ci� w sklepach).
 * @param p numer strony (zaczynaj�c od 0)
 * @param w referencja to zmiennej typu wektor przechowuj�cej towary
 */
void browseTowary(unsigned int p, wektor<towar>& w);
/**
 * Spis filii dla danego sklepu.
 * @param s referencja do sklepu
 */
void browseFilie( sklep & s );
/**
 * Podmenu po wybraniu opcji przegl�dania bazy danych.
 */
void browseMenu();
/**
 * Detale filii - spis towar�w.
 * @param f referenca do filii
 * @param p numer strony towar�w (zaczynaj�c od 0)
 */
void browseFilia( filia & f,  unsigned int p );
/** 
 * Funkcja wczytuj�ca dane o sklepach, filiach, towarach z plik�w.
 */
void loadData();
/**
 * Funkcja importuje dane z pliku sklepy.txt
 */
void loadSklepy();
/** 
 * Funkcja zapisuj�ca wszystkie dane w bazie do plik�w.
 */
void saveData();
/** 
 * Funkcja wy�wietlaj�ca menu g��wne programu.
 */
void mainMenu();

//Global variables
/**
 *
 */
wektor<towar> towary; /**< Zmienna globalna przechowuj�ca wszystkie dost�pne towary. */
wektor<sklep> sklepy; /**< Zmienna globalna przechowuj�ca wszystkie sklepy. */

int main( ) {    
    mainMenu();
    return 0;

}
void browseFilia( filia & f, unsigned int page = 0 ) {
    //browseTowary! jednak sie nie da
    //browseTowary( 0, f.towary );
    wektor<towar> &towars = f.towary;
    unsigned int itemsOnPage = 7;
    towar t; //tymaczasowy

    towars.sortByName();
    cout << "Lista towarow w filii (strona:" << page+1<<"):" << endl;
    //Stronicowanie
    for( int i=0; i<itemsOnPage; i++ ) {
        if( page*itemsOnPage + i >= towars.amount() )
            break;
        
        cout << towars[page*itemsOnPage + i] << endl;
    }
    unsigned int k;
    //Podmenu
    char q='a';
	while( q != 'q' ){
		cout << "Prosze wybrac opcje:\n" <<endl;
		cout <<"1. Poprzednia strona" <<endl;
		cout <<"2. Dodanie towaru" <<endl;
		cout <<"3. Usuwanie towaru" <<endl;
        cout <<"4. Edycja towaru (ustawianie nowej ceny)" <<endl;
        cout <<"5. Nastepna strona" <<endl;
        cout <<"q. Wyjscie" <<endl;
		cout <<"Prosze wybrac opcje:\n" <<endl;
		cin>>q;
		switch( q ) {
			case '1':
				if( page > 0 )
                    browseFilia(f, page-1 );
                else {
                    cout << "Jestes na pierwszej stronie" << endl;
                    browseFilia(f, page );
                }
			break;
            case '2': {
                cout << "Dodowanie nowego towaru do filii, podaj id:" <<endl;
                cin >> k;
                try {
                    towar &tt = towary.getObjectById( k );
                    towar t2( tt );
                    //validacja czy istnieje
                    cout << "Dodano nastepujacy towar:" << endl;
                    cout << t2;
                    t2.setId( towars.amount() );
                    tt.shops.addObject(&f);
                    towars.addObject( t2 );
                } catch( int e ){ 
                    cout << "Towar o podanym identyfikatorze nie istnieje!" << endl;
                    break;
                }
                cout << "Towar dodany pomyslnie.";
                browseFilia(f, page );
                      }
			break;
            case '3':
                
                cout << "Usuwanie towaru z filii. Podaj id obiektu:" << endl;
                cin >> k;
                try {
                    towars.removeObjectById( k );
                } catch( int e ) {
                    cout << "Nie istnieje towar o tym identyfikatorze!" << endl;
                    break;
                }
                //Zmniejsza indexow dla towarow ponizej usuni�tego obiektu
                for( unsigned int u=0; u<towars.amount();u++ ) {
                    if( towars[u].getId() >=k )
                        towars[u].setId(towars[u].getId()-1);
                }
                browseFilia(f,page);
			break;
            case '4':{
                cout << "Edycja towar w filii. Podaj id:" <<endl;
                cin >> k;
                double d;
                cout << "Dane edytowanego towaru"<<endl;
                try {
                    towar &t2 = towars.getObjectById( k );
                    cout << t2;
                    //Nie mozna zmieniac nazwy towaru!
                    cout << "Wprowadz nowa cene:"<<endl;
                    cin >> d;
                    t2.setPrice( d );
                    cout << t2;
                } catch( int e ){ 
                    cout << "Towar o podanym identyfikatorze nie istnieje!" << endl;
                    break;
                }
                cout << "Udana edycja towaru" <<endl;
                browseFilia(f, page );
                     }
			break;
            case '5':
				if( (page+1)*itemsOnPage < towars.amount() )
                    browseFilia(f, page+1 );
                else {
                    cout << "Jestes na ostatniej stronie" << endl;
                    browseFilia(f, page );
                }
			break;
            
			case 'q':
				break;
			break;
		}
	}
}
void browseSklepy(unsigned int page = 0) {
    unsigned int itemsOnPage = 7;
    sklep t; //tymaczasowy
    sklepy.sortByName();
    cout << "Lista sklepow (strona:" << page+1<<"):" << endl;
    //Stronicowanie
    for( int i=0; i<itemsOnPage; i++ ) {
        if( page*itemsOnPage + i >= sklepy.amount() )
            break;
        
        cout << sklepy[page*itemsOnPage + i] << endl;
    }
    unsigned int k;
    //Podmenu
    char q='a';
	while( q != 'q' ){
		cout << "Prosze wybrac opcje:\n" <<endl;
		cout <<"1. Poprzednia strona" <<endl;
		cout <<"2. Dodanie sklepy" <<endl;
		cout <<"3. Usuwanie sklepu" <<endl;
        cout <<"4. Edycja sklepu" <<endl;
        cout <<"5. Zobacz filie sklepu"<<endl;
        cout <<"6. Nastepna strona" <<endl;
        cout <<"q. Wyjscie" <<endl;
		cout <<"Prosze wybrac opcje:\n" <<endl;
		cin>>q;
		switch( q ) {
			case '1':
				if( page > 0 )
                    browseSklepy( page-1 );
                else {
                    cout << "Jestes na pierwszej stronie" << endl;
                    browseSklepy( page );
                }
			break;
			case '2':
                cin >> t;
                cout << t;
                t.setId( sklepy.amount() );
                sklepy.addObject( t );
                cout << "obiekt dodany pomyslnie.";
                browseSklepy(page);
			break;
            case '3':
                
                cout << "Usuwanie sklepu. Podaj identyfikator sklepu:" << endl;
                cin >> k;
                try {
                    sklepy.removeObjectById( k );
                } catch( int e ) {
                    cout << "Nie istnieje sklep o tym identyfikatorze!" << endl;
                    break;
                }
                //Zmniejsza indexow dla towarow ponizej usuni�tego obiektu
                for( unsigned int u=0; u<sklepy.amount();u++ ) {
                    if( sklepy[u].getId() >=k )
                        sklepy[u].setId(sklepy[u].getId()-1);
                }
                browseSklepy(page);
			break;
            case '4': {
                cout << "Edycja sklepu. Podaj id:" <<endl;
                cin >> k;
                cout << "Dane edytowanego sklepu"<<endl;
                try {
                    sklep &t2 = sklepy.getObjectById( k );
                    cout << t2;
                    cout << "Ponowne wprowadzanie danych";
                    cin >> t2;
                } catch( int e ){ 
                    cout << "Sklep o podanym identyfikatorze nie istnieje!" << endl;
                    break;
                }

                cout << "Udana edycja towaru" <<endl;
                browseSklepy( page );
                      }
			break;
            case '6':
				if( (page+1)*itemsOnPage < sklepy.amount() )
                    browseSklepy( page+1 );
                else {
                    cout << "Jestes na ostatniej stronie" << endl;
                    browseSklepy( page );
                }
			break;
            case '5': {
                cout << "Podaj id sklepu:" <<endl;
                cin >> k;
                //znajdowanie sklepu
                try {
                    sklep & t2 = sklepy.getObjectById( k );
                    browseFilie( t2 );
                } catch( int e ){ 
                    cout << "Sklep o podanym identyfikatorze nie istnieje!" << endl;
                    break;
                }
                browseSklepy(page);
                      }
            break;
			case 'q':
				return;
			break;
		}
	}
    //cout << sklepy;

}
void browseTowary( unsigned int page = 0, wektor<towar> &towars = towary) {
    unsigned int itemsOnPage = 7;
    towar t; //tymaczasowy
    towars.sortByName();
    cout << "Lista towarow (strona:" << page+1<<"):" << endl;
    //Stronicowanie
    for( int i=0; i<itemsOnPage; i++ ) {
        if( page*itemsOnPage + i >= towars.amount() )
            break;
        
        cout << towary[page*itemsOnPage + i] << endl;
    }
    unsigned int k;
    //Podmenu
    char q='a';
	while( q != 'q' ){
		cout << "Prosze wybrac opcje:\n" <<endl;
		cout <<"1. Poprzednia strona" <<endl;
		cout <<"2. Dodanie towaru" <<endl;
		cout <<"3. Usuwanie towaru" <<endl;
        cout <<"4. Edycja towaru" <<endl;
        cout <<"5. Nastepna strona" <<endl;
        cout <<"q. Wyjscie" <<endl;
		cout <<"Prosze wybrac opcje:\n" <<endl;
		cin>>q;
		switch( q ) {
			case '1':
				if( page > 0 )
                    browseTowary( page-1, towars );
                else {
                    cout << "Jestes na pierwszej stronie" << endl;
                    browseTowary( page, towars );
                }
			break;
			case '2':
                cin >> t;
                cout << t;
                t.setId( towars.amount() );
                towars.addObject( t );
                cout << "obiekt dodany pomyslnie.";
                browseTowary(page, towars);
			break;
            case '3':
                
                cout << "Usuwanie towaru. Podaj identyfikator obiektu:" << endl;
                cin >> k;
                try {
                    towars.removeObjectById( k );
                } catch( int e ) {
                    cout << "Nie istnieje towar o tym identyfikatorze!" << endl;
                    break;
                }
                //Zmniejsza indexow dla towarow ponizej usuni�tego obiektu
                for( unsigned int u=0; u<towars.amount();u++ ) {
                    if( towars[u].getId() >=k )
                        towars[u].setId(towars[u].getId()-1);
                }
                browseTowary(page, towars);
			break;
            case '4': {
                cout << "Edycja obiektu. Podaj id:" <<endl;
                cin >> k;
                cout << "Dane edytowanego obiektu"<<endl;
                try {
                    towar &t2 = towars.getObjectById( k );
                    cout << t2;
                    cout << "Ponowne wprowadzanie danych"<<endl;
                    cin >> t2;
                    cout << "Udana edycja towaru" <<endl;
                    browseTowary( page, towars );
                } catch( int e ){ 
                    cout << "Towar o podanym identyfikatorze nie istnieje!" << endl;
                    break;
                }

                      }
			break;
            case '5':
				if( (page+1)*itemsOnPage < towars.amount() )
                    browseTowary( page+1, towars );
                else {
                    cout << "Jestes na ostatniej stronie" << endl;
                    browseTowary( page, towars );
                }
			break;
            
			case 'q':
				return;
			break;
		}
	}
}

void browseMenu() {
    char q='a';
	while( q != 'q' ){
		cout << "Prosze wybrac opcje:\n" <<endl;
		cout <<"1. Przegladanie sklepow(filii)" <<endl;
		cout <<"2. Przegladanie towarow" <<endl;
		cout <<"q. Wyjscie z menu" <<endl;
		cout <<"Prosze wybrac opcje:\n" <<endl;
		cin>>q;
		switch( q ) {
			case '1':
				browseSklepy();
			break;
			case '2':
				browseTowary();
			break;
			case 'q':
				return;
			break;
		}
	}
}

void browseFilie( sklep &skl ) {
    filia t; //tymaczasowy
    wektor<filia> & sfilie = skl.filie;
    sfilie.sortByName();
    cout << "Lista filii:" << endl;
    //Stronicowanie
    cout << sfilie;
    unsigned int k;
    //Podmenu
    char q='a';
	while( q != 'q' ){
		cout << "Prosze wybrac opcje:\n" <<endl;
		cout <<"1. Dodanie filii" <<endl;
		cout <<"2. Usuwanie filii" <<endl;
        cout <<"3. Edycja filii" <<endl;
        cout <<"4. Zobacz detale (dodawanie towar�w)" <<endl;
        cout <<"q. Wyjscie" <<endl;
		cout <<"Prosze wybrac opcje:\n" <<endl;
        
        
		cin>>q;
		switch( q ) {
			case '1':
                cin >> t;
                cout << t;
                t.setId( sfilie.amount() );
                sfilie.addObject( t );
                cout << "filia dodana pomyslnie.";
                browseFilie(skl);
			break;
            case '2':
                cout << "Usuwanie filii. Podaj id obiektu:" << endl;
                cin >> k;
                
                try {
                    sfilie.removeObjectById( k );
                } catch( int e ) {
                    cout << "Nie istnieje filia o tym identyfikatorze!" << endl;
                    break;
                }
                //Zmniejsza indexow dla towarow ponizej usuni�tego obiektu
                for( unsigned int u=0; u<sfilie.amount();u++ ) {
                    if( sfilie[u].getId() >=k )
                        sfilie[u].setId(sfilie[u].getId()-1);
                }
                browseFilie(skl);
			break;
            case '3': {
                cout << "Edycja filii. Podaj id:" <<endl;
                cin >> k;
                cout << "Dane edytowanego obiektu";
                try {
                    filia &t2 = sfilie.getObjectById( k );
                    cout << t2;
                    cout << "Ponowne wprowadzanie danych";
                    cin >> t2;
                } catch( int e ){ 
                    cout << "Towar o podanym identyfikatorze nie istnieje!" << endl;
                    break;
                }
                cout << "Udana edycja towaru" <<endl;
                browseFilie( skl );
                      }
			break;
            case '4': {
                cout << "By zobaczyc detale filii podaj id:" <<endl;
                cin >> k;
                try{
                    filia &t2 = sfilie.getObjectById( k );
				    browseFilia( t2 );
                } catch( int e ){ 
                    cout << "Filia o podanym identyfikatorze nie istnieje!" << endl;
                    break;
                }
                browseFilie( skl ); 
                      }
			break;
            
			case 'q':
				return;
			break;
		}
	}


}

///############
/**
 * Funkcja importuj�ca dane z pliku towary.txt.
 */
void loadTowary();
/**
 * Funkcja importuj�ca dane z pliku magazyny.txt.
 */
void loadMagazyn();
void loadData() {
    loadTowary();
    loadSklepy();
    loadMagazyn();
}
void loadTowary() {
    ifstream plik("towary.txt");
    string linia;
    unsigned int i;
    string temp;
    double d;
    while(!plik.eof()) {
        plik >> i;
        plik >> temp;
        plik >> d;
        //cout << temp;
        towar t(i, temp, d );
        towary.addObject(t);
    }
}

//###############
/**
 * Funkcja exportuj�ca dane do pliku towary.txt.
 */
void saveTowary();
/**
 * Funkcja exportuj�ca dane do pliku sklepy.txt.
 */
void saveSklepy();
/**
 * Funkcja exportuj�ca dane do pliku magazyny.txt.
 */
void saveMagazyn();
void saveData() {
    cout << "Zapisywanie danych do plikow." << endl;
    //ustawianie relacji sklep matka - filia  - przy extend si� psuje!
    for( int i = 0; i <sklepy.amount(); i++ ) {
        sklep * ts = &sklepy[i];
        for( int t=0; t< ts->filie.amount(); t++ ) {
                ts->filie[t].matka = ts;
        }
    }
    
    //zapisywanie towar�w
    saveTowary();
    saveSklepy();
    saveMagazyn();
}
void saveTowary() {
    ofstream plik("towary.txt", ios::out);
    for( int i=0; i<towary.amount(); i++ ) {
        towar t = towary[i];
        plik << t.getId() << endl << t.getName() << endl<< t.getPrice()<<endl;
    }
    plik.close();
}

void saveSklepy() {
    ofstream plik("sklepy.txt", ios::out);
    for( int i=0; i<sklepy.amount(); i++ ) {
        sklep &s = sklepy[i];
        plik << s.getId() << endl << s.getName() << endl;
        //zapisywanie filii
        for( int k=0; k<s.filie.amount(); k++ ) {
            filia &f = s.filie[k];
            plik <<"+" <<endl;
            plik << f.getId() << endl << f.getName() << endl << f.getAdress() <<endl;

        }
        
        plik << "#" << endl;
    }
    plik.close();
}

void saveMagazyn() {
    ofstream plik("magazyny.txt", ios::out);
    for( int i=0; i<towary.amount(); i++ ) {
       towar& t = towary[i];
       for( int k=0; k<t.shops.amount(); k++ ) {
           filia *f = t.shops[k];
           sklep *s = f->matka;
           towar &t2 = f->towary.getObjectByName( t.getName() );
           plik << s->getId() << ";" << f->getId() << ";"<<t.getId()<<";"<<t2.getPrice()<<";";
       }
    }
    plik.close();
                
}

void mainMenu() {
//MENU
    char q='a';
	while( q != 'q' ){
		cout << "Prosze wybrac opcje:\n" <<endl;
		cout <<"1. Przegladanie bazy danych" <<endl;
		cout <<"2. Ladowanie bazy danych" <<endl;
		cout <<"3. Zapisywanie bazy danych" <<endl;
        cout <<"4. Szukanie towaru po nazwie" <<endl;
        cout <<"5. Szukanie sklepu po nazwie" <<endl;
        cout <<"6. Szukanie towaru po cenie" <<endl;
        cout <<"7. Stworz raport."<<endl;
		cout <<"q. Wyjscie" <<endl;
		cout <<"Prosze wybrac opcje:\n" <<endl;
		cin>>q;
		switch( q ) {
			case '1':
				browseMenu();
			break;
			case '2':
				loadData();
			break;
            case '3':
				saveData();
			break;
            case '4':
            {
                string pattern;
                bool flag = false;
                cout << "Wprowadz szukana fraze." <<endl;
                cin >> pattern;
                cout << "Wyniki wyszukiwania";
                for( int i=0; i<towary.amount(); i++ ) {
                    if( towary[i].getName().find(pattern) != -1 ) {
                        cout << towary[i];
                        flag = true;
                    }
                }
                if( !flag )
                    cout << "Nic nie znaleziono." << endl;
            }
            break;
            case '5':
            {
                string pattern;
                bool flag = false;
                cout << "Wprowadz szukana fraze." <<endl;
                cin >> pattern;
                cout << "Wyniki wyszukiwania";
                for( int i=0; i<sklepy.amount(); i++ ) {
                    if( sklepy[i].getName().find(pattern) != -1 ) {
                        cout << sklepy[i];
                        flag = true;
                    }
                }
                if( !flag )
                    cout << "Nic nie znaleziono." << endl;
            }
            break;
            case '6':
            {
                double d1, d2;
                bool flag = false;
                cout << "Wprowadz dolna granice ceny" <<endl;
                cin >> d1;
                cout << "Wprowadz gorna granice ceny" <<endl;
                cin >> d2;
                if( d1 > d2 ) {
                    cout << "Zle wprowadzono zakres ceny!"<<endl;
                    break;
                }
                cout << "Wyniki wyszukiwania";
                for( int i=0; i<towary.amount(); i++ ) {
                    if( towary[i].getPrice()<d2 && towary[i].getPrice()>d1) {
                        cout << towary[i];
                        flag = true;
                    }
                }
                if( !flag )
                    cout << "Nic nie znaleziono." << endl;
            }
            break;
            case '7':
            {
            
            //sortowanie towarow
            towary.sortByName();
            for( unsigned int i=0; i<towary.amount(); i++ ) {
                cout << "Towar o nazwie: " << towary[i].getName() << " mozna nabyc w:"<<endl;
                //sortowanie sklepow
                towary[i].shops.sortByPrice();
                for( unsigned int k=0; k<towary[i].shops.amount(); k++ ){
                    //searching for price
                    double p = towary[i].shops[k]->towary.getObjectByName( towary[i].getName() ).getPrice();
                    cout << towary[i].shops[k]->getName() << " ( " << towary[i].shops[k]->getAdress() << " ) "
                            << " po cenie " << p <<endl;;
                }
            }
            }
            break;
			case 'q':
				return;
			break;
		}
	}
	cout <<"Dziekujemy za korzystanie z programu.\n"  << endl;
}

void loadSklepy() {
    ifstream plik("sklepy.txt");
    string linia;
    unsigned int i;
    string temp;
    while(!plik.eof()) {
        plik >> i; //id
        plik >> temp; //name
        if( temp == "#" )
            break;
        //cout << "Dodawanie sklepu o nazwie " << temp << endl;
        sklep s( i, temp );
        plik >> temp;
        while( temp == "+" ) {
            
            unsigned int id;
            string fname;
            string fadress;
            //dodawanie filii
            plik >> id;
            plik >> fname;
            //plik >> fadress;
            getline( plik, fadress );
            getline( plik, fadress );
            filia f( id, fname, fadress );
            s.filie.addObject( f );
            
            plik >> temp;
        }
        sklepy.addObject( s );


    }
}

void loadMagazyn() {
    ifstream plik("magazyny.txt");
    string linia;
    unsigned int i1, i2, i3;
    double d;
     
    char temp[2];

    while( !plik.eof() ) {
        plik >> i1;
        plik.read( temp, 1 );
        plik >> i2;
        plik.read( temp, 1 );
        plik >> i3;
        plik.read( temp, 1 );
        plik >> d;

        if( i1 == -1 )
            break;

        sklep &s = sklepy.getObjectById( i1 );
        filia &f = s.filie.getObjectById( i2 );
        towar &t = towary.getObjectById( i3 );
        towar t2( t );
        t2.setPrice( d );
        f.towary.addObject( t2 );
        t.shops.addObject( &f );
        plik.read( temp, 1 );
        i1=-1;
    }
}