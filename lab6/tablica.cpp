#include <iostream>
#include <fstream>
#include "tablica.h"
#include "cell.h"

using namespace std;

Tablica::Tablica(){
	wiersz = 0;
	kolumna = 0;
	tablica = NULL;
	typ = NULL;
}

void Tablica::stworz_tablice(int nowy_wiersz, int nowa_kolumna){
	wiersz = nowy_wiersz;
	kolumna = nowa_kolumna;
	typ = new string[kolumna];
	for(int i=0; i<kolumna; i++){
		cout << " Wpisz jakiego typu ma byc kolumna int czy string ? " << endl;
		cin >> typ[i];
	}
	
	tablica = new cell **[kolumna];
	for(int i=0; i<kolumna; i++){
		tablica[i] = new cell*[wiersz];
	}

	for(int i=0; i<kolumna; i++){
		for(int j=0; j<wiersz; j++){
			if(typ[i] == "int"){
				tablica[i][j] = new cell_int;
			}
			else 
				tablica[i][j] = new cell_string;
		}
	}
	
	for(int a=0; a<kolumna; a++){
		cout << typ[a] << " " << endl;
	}
}




void Tablica::wyswietl_tablice() {
	for(int x=0; x<wiersz; x++){
		for(int y=0; y<kolumna; y++){
			cout << tablica[y][x]->zwrocenie_tekstu() << "\t";
		}
		cout << endl;
	}
}





int Tablica::zmiana_komorki(int komorka_wiersza, int komorka_kolumny, int nowe) {

	if(komorka_wiersza>wiersz || komorka_kolumny>kolumna){
		return -1;
	}

	tablica[komorka_kolumny-1][komorka_wiersza-1]->ustawienie_wartosci(nowe);
	return 0;
}



int Tablica::zmiana_komorki_tekst(int komorka_wiersza, int komorka_kolumny, string nowe_tekst) {

	if(komorka_wiersza>wiersz || komorka_kolumny>kolumna){
		return -1;
	}

	tablica[komorka_kolumny-1][komorka_wiersza-1]->ustawienie_wartosci(nowe_tekst);
	return 0;
}




void Tablica::zmiana_rozmiaru (int nowy_wiersz, int nowa_kolumna) {
	
	string* temp_typ;
	temp_typ = new string[nowa_kolumna];
		for(int x=0; x<nowa_kolumna; x++){
			if(x<kolumna){
				temp_typ[x]=typ[x];
			}
			else{
			cout << "Jaki ma być typ dodatkowych kolumn" << endl;
			cin >> temp_typ[x];
		}
	}


	cell*** tab=new cell**[nowa_kolumna];

	for(int i=0; i<nowa_kolumna; i++){
		tab[i]=new cell *[nowy_wiersz];
		}

	for(int i=0; i<nowa_kolumna; i++){
		for(int j=0; j<nowy_wiersz; j++){
			if(temp_typ[i] == "int"){
				tab[i][j]=new cell_int;
			}
			else{
				tab[i][j]=new cell_string;
			}
		}
	}



	if(wiersz>nowy_wiersz || kolumna>nowa_kolumna){
		for(int x=0; x<nowa_kolumna; x++){
			if(temp_typ[x] == "int"){		
				for(int y=0; y<nowy_wiersz; y++){	
					tab[x][y]->ustawienie_wartosci(tablica[x][y]->zwrocenie_liczby());
				}
			}
			else{
				for(int y=0; y<nowy_wiersz; y++){
					tab[x][y]->ustawienie_wartosci(tablica[x][y]->zwrocenie_tekstu());
				}
			}
		}
	}
	else{
		for(int x=0; x<kolumna; x++){
			if(temp_typ[x] == "int"){
				for(int y=0; y<wiersz; y++){
					tab[x][y]->ustawienie_wartosci(tablica[x][y]->zwrocenie_liczby());
				}
			}
			else{
				for(int y=0; y<wiersz; y++){
					tab[x][y]->ustawienie_wartosci(tablica[x][y]->zwrocenie_tekstu());
				}
			}
		}
	}
	
	for(int x=0; x<kolumna; x++){
		for(int y=0; y<wiersz; y++){
			delete tablica[x][y];
		}
		delete[] tablica[x];
	}
	
	delete[] tablica;
	delete[] typ;
	
	tablica= tab;
	wiersz= nowy_wiersz;
	kolumna= nowa_kolumna;
	typ = temp_typ;
}	




int Tablica::zapisywanie_pliku(){
	ofstream zapis_pliku;
	if(zapis_pliku.good()==true){
		zapis_pliku.open("nowa_tablica.txt");
	
		zapis_pliku<<wiersz << endl;
		zapis_pliku<<kolumna << endl;
		for(int x=0; x<kolumna; x++){
			zapis_pliku << typ[x] << " \t";
		}
		zapis_pliku << endl;
			for(int x=0; x<wiersz; x++){
				for(int y=0; y<kolumna; y++){
					zapis_pliku << tablica[y][x]->zwrocenie_tekstu() <<" \t";
				}
				zapis_pliku << endl;
			}
		zapis_pliku.close();
		return 0;
	}
	else{
		return -1;
	}
}







int Tablica::odczytywanie_pliku(){
	ifstream odczyt_pliku;
	odczyt_pliku.open("tablica.txt");
	if(odczyt_pliku.good()==true){
	
		odczyt_pliku >> wiersz;
		odczyt_pliku >> kolumna;
		typ = new string [kolumna];
		for(int i=0; i<kolumna; i++){
			odczyt_pliku >> typ[i];
		}
		tablica = new cell **[kolumna];
		for(int i=0; i<kolumna; i++){
			tablica[i] = new cell*[wiersz];
		}
		for(int i=0; i<kolumna; i++){
			for(int j=0; j<wiersz; j++){
				if(typ[i] == "int"){
					tablica[i][j] = new cell_int;
				}
				else{
					tablica[i][j] = new cell_string;
				}
			}
		}





		for(int x=0; x<wiersz; x++) {
			for(int y=0; y<kolumna; y++){
				if(typ[y] == "int"){
					int type;
					odczyt_pliku >> type;
					tablica[y][x]->ustawienie_wartosci(type);
				}
				else{
					string type;
					odczyt_pliku >> type;
					tablica[y][x]->ustawienie_wartosci(type);
				}
			}
		}
		
		odczyt_pliku.close();
		return 0;
	}
	else{
		return -1;
	}
}




int Tablica::sumowanie_wierszy(int numer_wiersza){

	if(numer_wiersza>wiersz){
		return -1;
	}

	int suma_wierszy = 0;
	for(int i=0; i<kolumna; i++){
		suma_wierszy+=tablica[i][numer_wiersza-1]->zwrocenie_liczby();
	}
	cout << "Wynik sumowania wiersza rowna sie: " << suma_wierszy << endl;
	return 0;
}

int Tablica::sumowanie_kolumn(int numer_kolumny){

	if(numer_kolumny>kolumna){
		return -1;
	}	

	int suma_kolumn = 0;
	for(int i=0; i<wiersz; i++){
		suma_kolumn+= tablica[numer_kolumny-1][i]->zwrocenie_liczby();
	}
	cout << "Wynik sumowania kolumny rowna sie: " << suma_kolumn << endl;
	return 0;
}

int Tablica::minimum_kolumn(int numer_kolumny){
	
	if(numer_kolumny>kolumna){
		return -1;
	}

	int kolumna_minimum = tablica[numer_kolumny-1][0]->zwrocenie_liczby();
	for(int i=0; i<wiersz; i++){
		if(kolumna_minimum>tablica[numer_kolumny-1][i]->zwrocenie_liczby()){
			kolumna_minimum = tablica[numer_kolumny-1][i]->zwrocenie_liczby();
		}
	}
	cout << "Najmniejsza wartosc w kolumnie to : " << kolumna_minimum << endl;
	return 0;
}


int Tablica::minimum_wierszy(int numer_wiersza){
	
	if(numer_wiersza>wiersz){
		return -1;
	}

	int wiersz_minimum = tablica[numer_wiersza-1][0]->zwrocenie_liczby();
	for(int i=0; i<kolumna; i++){
		if(wiersz_minimum>tablica[i][numer_wiersza-1]->zwrocenie_liczby()){
			wiersz_minimum = tablica[i][numer_wiersza-1]->zwrocenie_liczby();
		}
	}
	cout << "Najmniejsza wartosc w wierszu to : " << wiersz_minimum << endl;
	return 0;
}

int Tablica::maximum_kolumny(int numer_kolumny){

	if(numer_kolumny>kolumna){
		return -1;
	}

	int kolumna_maximum = tablica[0][numer_kolumny-1]->zwrocenie_liczby();
	for(int i=0; i<wiersz; i++){
		if(kolumna_maximum<tablica[i][numer_kolumny-1]->zwrocenie_liczby()){
			kolumna_maximum = tablica[i][numer_kolumny-1]->zwrocenie_liczby();
		}
	}
	cout << "Najwieksza wartosc w kolumnie to: " << kolumna_maximum << endl;
	return 0;
}


int Tablica::maximum_wierszy(int numer_wiersza){

	if(numer_wiersza>wiersz){
		return -1;
	}

	int wiersz_maximum = tablica[numer_wiersza-1][0]->zwrocenie_liczby();
	for(int i=0; i<kolumna; i++){
		if(wiersz_maximum<tablica[i][numer_wiersza-1]->zwrocenie_liczby()){
			wiersz_maximum = tablica[i][numer_wiersza-1]->zwrocenie_liczby();
		}
	}
	cout<< "Najwieksza wartosc w wierszu to: " << wiersz_maximum << endl;
	return 0;
}

int Tablica::srednia_kolumn(int numer_kolumny){

	if(numer_kolumny>kolumna){
		return -1;
	}

	float suma_kolumn = 0;
	for(int i=0; i<wiersz; i++){
		suma_kolumn+= tablica[numer_kolumny-1][i]->zwrocenie_liczby();
	}
	float kolumna_srednia = suma_kolumn/wiersz;
	
	cout << "Srednia kolumny wynosi: " << kolumna_srednia << endl;
	return 0;
}

int Tablica::srednia_wierszy(int numer_wiersza){

	if(numer_wiersza>wiersz){
		return -1;
	}

	float suma_wierszy = 0;
	for(int i=0; i<kolumna; i++){
		suma_wierszy+= tablica[i][numer_wiersza-1]->zwrocenie_liczby();
	}
	float wiersz_srednia = suma_wierszy/kolumna;
	
	cout << "Srednia wiersza wynosi: " << wiersz_srednia << endl;
	return 0;
}
		


Tablica::~Tablica(){
	
	for(int x=0; x<kolumna; x++){
		for(int y=0; y<wiersz; y++){

			delete tablica[x][y];
		}
	
		delete[] tablica[x];
	}
	delete[] tablica;
	delete[] typ;
}



