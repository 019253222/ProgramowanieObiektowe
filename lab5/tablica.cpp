#include <iostream>
#include <fstream>
#include "tablica.h"
#include "cell.h"

using namespace std;

Tablica::Tablica(){
	wiersz = 0;
	kolumna = 0;
	tablica = NULL;

}
void Tablica::wyswietl_tablice() {
	for(int x=0; x<wiersz; x++){
		for(int y=0; y<kolumna; y++){
			cout << tablica[x][y].zwrocenie_liczby() << "\t";
		}
		cout << endl;
	}
}



void Tablica::wyswietl_tablice_tekst() {
	for(int x=0; x<wiersz; x++){
		for(int y=0; y<kolumna; y++){
			cout << tablica[x][y].zwrocenie_tekstu()<< "\t";
		}
		cout << endl;
	}
}


int Tablica::zmiana_komorki(int komorka_wiersza, int komorka_kolumny, int nowe) {

	if(komorka_wiersza>wiersz || komorka_kolumny>kolumna){
		return -1;
	}

	tablica[komorka_wiersza-1][komorka_kolumny-1].zwrocenie_liczby()=nowe;
	return 0;
}



int Tablica::zmiana_komorki_tekst(int komorka_wiersza, int komorka_kolumny, string nowe_tekst) {

	if(komorka_wiersza>wiersz || komorka_kolumny>kolumna){
		return -1;
	}

	tablica[komorka_wiersza-1][komorka_kolumny-1].zwrocenie_tekstu()=nowe_tekst;
	return 0;
}




void Tablica::zmiana_rozmiaru (int nowy_wiersz, int nowa_kolumna) {
	cell** tab=new cell*[nowy_wiersz];

	for(int i=0; i<nowy_wiersz; i++){
		tab[i]=new cell [nowa_kolumna];
		}

	for(int x=0; x<nowy_wiersz; x++){
		for(int y=0; y<nowa_kolumna; y++){
			tab[x][y].zwrocenie_liczby()=0;
		}
	}
	if(wiersz>nowy_wiersz || kolumna>nowa_kolumna){
		for(int x=0; x<nowy_wiersz; x++){
			for(int y=0; y<nowa_kolumna; y++){
				tab[x][y].zwrocenie_liczby()=tablica[x][y].zwrocenie_liczby();
				}
			}
		}
		else{
			for(int x=0; x<wiersz; x++){
				for(int y=0; y<kolumna; y++){
					tab[x][y].zwrocenie_liczby()=tablica[x][y].zwrocenie_liczby();
				}
			}
		}
		for(int x=0; x<kolumna; x++){
			delete[] tablica[x];
		}

	delete[] tablica;
	
	tablica= tab;
	wiersz= nowy_wiersz;
	kolumna= nowa_kolumna;
}	







void Tablica::zmiana_rozmiaru_tekstu (int nowy_wiersz, int nowa_kolumna) {
	cell** tab=new cell*[nowy_wiersz];

	for(int i=0; i<nowy_wiersz; i++){
		tab[i]=new cell [nowa_kolumna];
		}

	for(int x=0; x<nowy_wiersz; x++){
		for(int y=0; y<nowa_kolumna; y++){
			tab[x][y].zwrocenie_tekstu()="0";
		}
	}
	if(wiersz>nowy_wiersz || kolumna>nowa_kolumna){
		for(int x=0; x<nowy_wiersz; x++){
			for(int y=0; y<nowa_kolumna; y++){
				tab[x][y].zwrocenie_tekstu()=tablica[x][y].zwrocenie_tekstu();
				}
			}
		}
		else{
			for(int x=0; x<wiersz; x++){
				for(int y=0; y<kolumna; y++){
					tab[x][y].zwrocenie_tekstu()=tablica[x][y].zwrocenie_tekstu();
				}
			}
		}
		for(int x=0; x<kolumna; x++){
			delete[] tablica[x];
		}

	delete[] tablica;
	
	tablica= tab;
	wiersz= nowy_wiersz;
	kolumna= nowa_kolumna;
}





int Tablica::zapisywanie_pliku(){
	ofstream zapis_pliku;
	if(zapis_pliku.good()==true){
		zapis_pliku.open("nowa_tablica.txt");
	
		zapis_pliku<<wiersz << endl;
		zapis_pliku<<kolumna << endl;
	
		for(int x=0; x<wiersz; x++){
			for(int y=0; y<kolumna; y++){
				zapis_pliku<<tablica[x][y].zwrocenie_liczby()<<"\t";
			}
			zapis_pliku<< endl;
		}
		zapis_pliku.close();
		return 0;
	}
	else{
		return -1;
	}
}





int Tablica::zapisywanie_pliku_tekst(){
	ofstream zapis_pliku;
	if(zapis_pliku.good()==true){
		zapis_pliku.open("nowa_tablica_tekstowa.txt");
	
		zapis_pliku<<wiersz << endl;
		zapis_pliku<<kolumna << endl;
	
		for(int x=0; x<wiersz; x++){
			for(int y=0; y<kolumna; y++){
				zapis_pliku<<tablica[x][y].zwrocenie_tekstu()<<"\t";
			}
			zapis_pliku<< endl;
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
		tablica = new cell* [wiersz];
		for(int i=0; i<wiersz; i++){
			tablica[i] = new cell [kolumna];
		}
		for(int x=0; x<wiersz; x++) {
			for(int y=0; y<kolumna; y++){
				odczyt_pliku >> tablica[x][y].zwrocenie_liczby();
			}
		}
		odczyt_pliku.close();
		return 0;
	}
	else{
		return -1;
	}
}



int Tablica::odczytywanie_pliku_tekst(){
	ifstream odczyt_pliku;
	odczyt_pliku.open("tablica_tekstowa.txt");
	if(odczyt_pliku.good()==true){
	
		odczyt_pliku >> wiersz;
		odczyt_pliku >> kolumna;
		tablica = new cell* [wiersz];
		for(int i=0; i<wiersz; i++){
			tablica[i] = new cell [kolumna];
		}
		for(int x=0; x<wiersz; x++) {
			for(int y=0; y<kolumna; y++){
				odczyt_pliku >> tablica[x][y].zwrocenie_tekstu();
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
		suma_wierszy+=tablica[numer_wiersza-1][i].zwrocenie_liczby();
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
		suma_kolumn+= tablica[i][numer_kolumny-1].zwrocenie_liczby();
	}
	cout << "Wynik sumowania kolumny rowna sie: " << suma_kolumn << endl;
	return 0;
}

int Tablica::minimum_kolumn(int numer_kolumny){
	
	if(numer_kolumny>kolumna){
		return -1;
	}

	int kolumna_minimum = tablica[0][numer_kolumny-1].zwrocenie_liczby();
	for(int i=0; i<wiersz; i++){
		if(kolumna_minimum>tablica[i][numer_kolumny-1].zwrocenie_liczby()){
			kolumna_minimum = tablica[i][numer_kolumny-1].zwrocenie_liczby();
		}
	}
	cout << "Najmniejsza wartosc w kolumnie to : " << kolumna_minimum << endl;
	return 0;
}


int Tablica::minimum_wierszy(int numer_wiersza){
	
	if(numer_wiersza>wiersz){
		return -1;
	}

	int wiersz_minimum = tablica[numer_wiersza-1][0].zwrocenie_liczby();
	for(int i=0; i<kolumna; i++){
		if(wiersz_minimum>tablica[numer_wiersza-1][i].zwrocenie_liczby()){
			wiersz_minimum = tablica[numer_wiersza-1][i].zwrocenie_liczby();
		}
	}
	cout << "Najmniejsza wartosc w wierszu to : " << wiersz_minimum << endl;
	return 0;
}

int Tablica::maximum_kolumny(int numer_kolumny){

	if(numer_kolumny>kolumna){
		return -1;
	}

	int kolumna_maximum = tablica[0][numer_kolumny-1].zwrocenie_liczby();
	for(int i=0; i<wiersz; i++){
		if(kolumna_maximum<tablica[i][numer_kolumny-1].zwrocenie_liczby()){
			kolumna_maximum = tablica[i][numer_kolumny-1].zwrocenie_liczby();
		}
	}
	cout << "Najwieksza wartosc w kolumnie to: " << kolumna_maximum << endl;
	return 0;
}


int Tablica::maximum_wierszy(int numer_wiersza){

	if(numer_wiersza>wiersz){
		return -1;
	}

	int wiersz_maximum = tablica[numer_wiersza-1][0].zwrocenie_liczby();
	for(int i=0; i<kolumna; i++){
		if(wiersz_maximum<tablica[numer_wiersza-1][i].zwrocenie_liczby()){
			wiersz_maximum = tablica[numer_wiersza-1][i].zwrocenie_liczby();
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
		suma_kolumn+= tablica[i][numer_kolumny-1].zwrocenie_liczby();
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
		suma_wierszy+= tablica[numer_wiersza-1][i].zwrocenie_liczby();
	}
	float wiersz_srednia = suma_wierszy/kolumna;
	
	cout << "Srednia wiersza wynosi: " << wiersz_srednia << endl;
	return 0;
}
		


Tablica::~Tablica(){
	
	for(int x=0; x<kolumna; x++){
		delete[] tablica[x];
	}

	delete[] tablica;
}




