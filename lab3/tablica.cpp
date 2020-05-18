#include <iostream>
#include <fstream>
#include "tablica.h"
#include "menu.h"

using namespace std;





int zmiana_komorki(Tablica arr, int komorka_wiersza, int komorka_kolumny, int nowe) {

	if(komorka_wiersza>arr.wiersz || komorka_kolumny>arr.kolumna){
		return -1;
	}

	arr.tablica[komorka_wiersza-1][komorka_kolumny-1]=nowe;
	return 0;
}



void zmiana_rozmiaru (Tablica & arr, int nowy_wiersz, int nowa_kolumna) {
	int ** tab=new int*[nowy_wiersz];

	for(int i=0; i<nowy_wiersz; i++){
		tab[i]=new int[nowa_kolumna];
		}

	for(int x=0; x<nowy_wiersz; x++){
		for(int y=0; y<nowa_kolumna; y++){
			tab[x][y]=0;
		}
	}
	if(arr.wiersz>nowy_wiersz || arr.kolumna>nowa_kolumna){
		for(int x=0; x<nowy_wiersz; x++){
			for(int y=0; y<nowa_kolumna; y++){
				tab[x][y]=arr.tablica[x][y];
				}
			}
		}
		else{
			for(int x=0; x<arr.wiersz; x++){
				for(int y=0; y<arr.kolumna; y++){
					tab[x][y]=arr.tablica[x][y];
				}
			}
		}
		for(int x=0; x<arr.kolumna; x++){
			delete[] arr.tablica[x];
		}

	delete[] arr.tablica;
	
	arr.tablica= tab;
	arr.wiersz= nowy_wiersz;
	arr.kolumna= nowa_kolumna;
}	






int zapisywanie_pliku(Tablica arr){
	ofstream zapis_pliku;
	if(zapis_pliku.good()==true){
		zapis_pliku.open("nowa_tablica.txt");
	
		zapis_pliku<<arr.wiersz << endl;
		zapis_pliku<<arr.kolumna << endl;
	
		for(int x=0; x<arr.wiersz; x++){
			for(int y=0; y<arr.kolumna; y++){
				zapis_pliku<<arr.tablica[x][y]<<"\t";
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

int odczytywanie_pliku(Tablica* arr){
	ifstream odczyt_pliku;
	odczyt_pliku.open("tablica.txt");
	if(odczyt_pliku.good()==true){
	
		odczyt_pliku >> arr->wiersz;
		odczyt_pliku >> arr->kolumna;
		arr->tablica = new int* [arr->wiersz];
		for(int i=0; i<arr->wiersz; i++){
			arr->tablica[i] = new int [arr->kolumna];
		}
		for(int x=0; x<arr->wiersz; x++) {
			for(int y=0; y<arr->kolumna; y++){
				odczyt_pliku >> arr->tablica[x][y];
			}
		}
		odczyt_pliku.close();
		return 0;
	}
	else{
		return -1;
	}
}

int sumowanie_wierszy(Tablica arr, int numer_wiersza){

	if(numer_wiersza>arr.wiersz){
		return -1;
	}

	int suma_wierszy = 0;
	for(int i=0; i<arr.kolumna; i++){
		suma_wierszy+=arr.tablica[numer_wiersza-1][i];
	}
	cout << "Wynik sumowania wiersza rowna sie: " << suma_wierszy << endl;
	return 0;
}

int sumowanie_kolumn(Tablica arr, int numer_kolumny){

	if(numer_kolumny>arr.kolumna){
		return -1;
	}	

	int suma_kolumn = 0;
	for(int i=0; i<arr.wiersz; i++){
		suma_kolumn+= arr.tablica[i][numer_kolumny-1];
	}
	cout << "Wynik sumowania kolumny rowna sie: " << suma_kolumn << endl;
	return 0;
}

int minimum_kolumn(Tablica arr, int numer_kolumny){
	
	if(numer_kolumny>arr.kolumna){
		return -1;
	}

	int kolumna_minimum = arr.tablica[0][numer_kolumny-1];
	for(int i=0; i<arr.wiersz; i++){
		if(kolumna_minimum>arr.tablica[i][numer_kolumny-1]){
			kolumna_minimum = arr.tablica[i][numer_kolumny-1];
		}
	}
	cout << "Najmniejsza wartosc w kolumnie to : " << kolumna_minimum << endl;
	return 0;
}


int minimum_wierszy(Tablica arr, int numer_wiersza){
	
	if(numer_wiersza>arr.wiersz){
		return -1;
	}

	int wiersz_minimum = arr.tablica[numer_wiersza-1][0];
	for(int i=0; i<arr.kolumna; i++){
		if(wiersz_minimum>arr.tablica[numer_wiersza-1][i]){
			wiersz_minimum = arr.tablica[numer_wiersza-1][i];
		}
	}
	cout << "Najmniejsza wartosc w wierszu to : " << wiersz_minimum << endl;
	return 0;
}

int maximum_kolumny(Tablica arr, int numer_kolumny){

	if(numer_kolumny>arr.kolumna){
		return -1;
	}

	int kolumna_maximum = arr.tablica[0][numer_kolumny-1];
	for(int i=0; i<arr.wiersz; i++){
		if(kolumna_maximum<arr.tablica[i][numer_kolumny-1]){
			kolumna_maximum = arr.tablica[i][numer_kolumny-1];
		}
	}
	cout << "Najwieksza wartosc w kolumnie to: " << kolumna_maximum << endl;
	return 0;
}


int maximum_wierszy(Tablica arr, int numer_wiersza){

	if(numer_wiersza>arr.wiersz){
		return -1;
	}

	int wiersz_maximum = arr.tablica[numer_wiersza-1][0];
	for(int i=0; i<arr.kolumna; i++){
		if(wiersz_maximum<arr.tablica[numer_wiersza-1][i]){
			wiersz_maximum = arr.tablica[numer_wiersza-1][i];
		}
	}
	cout<< "Najwieksza wartosc w wierszu to: " << wiersz_maximum << endl;
	return 0;
}

int srednia_kolumn(Tablica arr, int numer_kolumny){

	if(numer_kolumny>arr.kolumna){
		return -1;
	}

	float suma_kolumn = 0;
	for(int i=0; i<arr.wiersz; i++){
		suma_kolumn+= arr.tablica[i][numer_kolumny-1];
	}
	float kolumna_srednia = suma_kolumn/arr.wiersz;
	
	cout << "Srednia kolumny wynosi: " << kolumna_srednia << endl;
	return 0;
}

int srednia_wierszy(Tablica arr, int numer_wiersza){

	if(numer_wiersza>arr.wiersz){
		return -1;
	}

	float suma_wierszy = 0;
	for(int i=0; i<arr.kolumna; i++){
		suma_wierszy+= arr.tablica[numer_wiersza-1][i];
	}
	float wiersz_srednia = suma_wierszy/arr.kolumna;
	
	cout << "Srednia wiersza wynosi: " << wiersz_srednia << endl;
	return 0;
}
		

