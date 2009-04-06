#include <iostream>
#include <fstream>

using namespace std;

/*Deklaracje*/
string nowaNazwaPliku( string );
string getExt( string );

int main( int argc, const char* argv[] ) {
	
	//Walidacja wejścia
	if( argc != 4 ) {
		cout << "Podaj prawidlowa ilosc argumentow!"<<endl;
		exit(2);
	}
	string nazwaPliku = argv[1];
	
	//Czy plik istnieje?
	ifstream plik(nazwaPliku.c_str());
	if( !plik.is_open()) {
		cout << "Plik nie istnieje!"<<endl;
		exit(8);
	}	
	
	//czy plik ma rozszerzenie .txt?
	if( getExt( nazwaPliku ) != ".txt" ) {
		cout << "Plik ma zle rozszerzenie!" << endl;
		exit(1);
	}
	
	//Na końcu nazwy zmieniamy z .txt na _nowy.txt
	string nazwaNowegoPliku = nowaNazwaPliku( nazwaPliku );
	
	//ustawianie odpowiednio wzorca i łańcucha do podmiany
	string pattern = argv[2];
	string replace = argv[3];
	
	//tekst zawiera całą zawartość pliku, line jako tymaczasowy łańcuch do wczytywania jednej linijki
	string tekst, line;
	//Kopiowanie zawartosci pliku do łańcucha znakowego
	while(!plik.eof()) {
      getline (plik,line);
      tekst.append(line);
		tekst+="\n";
	}
	
	//pos - aktualna pozycja, c - ilość podmian
 	int pos = 0, c=0;	
	int lastPos = pos; //ostatnia pozycja, by zapobiec zapętleniu
 	while( ( (pos = tekst.find( pattern )) > 0 ) && ((unsigned int)pos < tekst.length()) ) {
		tekst.replace( pos, pattern.length(), replace );
		c++;
		if( lastPos >= pos )
			break;
		lastPos = pos;
	}
	plik.close();
		
	if( lastPos == 0 ) {
		cout << "Nic nie zmieniono." <<endl;
		return 0;
	} else 
		cout << "Zmieniono " << c << " elementow." <<endl; 
	
    //Zapis podmienionej zawartości do nowego pliku
	ofstream plik2;
	plik2.open(nazwaNowegoPliku.c_str());
	plik2<<tekst;
	plik2.close();
	return 0;
}

string nowaNazwaPliku( string stara ) {
	stara.replace(stara.length()-4, 4, "_nowy.txt" );
	return stara; 	
}

string getExt( string nazwa ) {
	return nazwa.substr(nazwa.length()-4);
} 
