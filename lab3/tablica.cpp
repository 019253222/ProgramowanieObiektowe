#include <iostream>
#include <fstream>
#include "tablica.h"
#include "menu.h"

using namespace std;




void wyswietl_tablice(Tablica arr) {
	for(int x=0; x<arr.wiersz; x++){
		for(int y=0; y<arr.kolumna; y++){
			cout << arr.tablica[x][y] << "\t";
		}
		cout << endl;
	}
}

void zmiana_komorki(Tablica arr, int komorka_wiersza, int komorka_kolumny, int nowe) {

	arr.tablica[komorka_wiersza-1][komorka_kolumny-1]=nowe;

}


int** zmiana_rozmiaru (Tablica* arr, int new_wiersz, int new_kolumna) {

	return 0;	
}




void zapisywanie_pliku(Tablica arr){
	ofstream zapis_pliku;
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
}

void odczytywanie_pliku(Tablica* arr){
	ifstream odczyt_pliku;
	odczyt_pliku.open("tablica.txt");
	
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
}


void sumowanie_wierszy(Tablica arr){
	cout << "Który wiersz chcesz zsumowac?" << endl;
	int numer_wiersza;
	cin >> numer_wiersza;
	int suma_wierszy = 0;
	for(int i=0; i<arr.kolumna; i++){
		suma_wierszy+=arr.tablica[numer_wiersza-1][i];
	}
	cout << "Wynik sumowania wiersza rowna sie" << suma_wierszy << endl;
}

void sumowanie_kolumn(Tablica arr){
	cout << "Którą kolumne chcesz zsumowac?" << endl;
	int numer_kolumny = 0;
	cin >> numer_kolumny;
	int suma_kolumn = 0;
	for(int i=0; i<arr.wiersz; i++){
		suma_kolumn+= arr.tablica[i][numer_kolumny-1];
	}
	cout << "Wynik sumowania kolumny rowna sie" << suma_kolumn << endl;
}

void minimum_kolumn(Tablica arr){
	cout << "Która kolumne chcsz poddac analizie ?"<<endl;
	int numer_kolumny = 0;
	cin >> numer_kolumny;
	int kolumna_minimum = arr.tablica[0][numer_kolumny-1];
	for(int i=0; i<arr.wiersz; i++){
		if(kolumna_minimum>arr.tablica[i][numer_kolumny-1]){
			kolumna_minimum = arr.tablica[i][numer_kolumny-1];
		}
	}
	cout << "Najmniejsza wartosc w kolumnie to :" << kolumna_minimum << endl;
}


void minimum_wierszy(Tablica arr){
	cout << "Który wiersz chcesz poddać analizie ?"<< endl;
	int numer_wiersza = 0;
	cin >> numer_wiersza;
	int wiersz_minimum = arr.tablica[numer_wiersza-1][0];
	for(int i=0; i<arr.kolumna; i++){
		if(wiersz_minimum>arr.tablica[numer_wiersza-1][i]){
			wiersz_minimum = arr.tablica[numer_wiersza-1][i];
		}
	}
	cout << "Najmniejsza wartosc w wierszu to :" << wiersz_minimum << endl;
}

void maximum_kolumny(Tablica arr){
	cout << "Który wiersz chcesz poddać analizie?" << endl;
	int numer_kolumny = 0;
	cin >> numer_kolumny;
	int kolumna_maximum = arr.tablica[0][numer_kolumny-1];
	for(int i=0; i<arr.wiersz; i++){
		if(kolumna_maximum<arr.tablica[i][numer_kolumny-1]){
			kolumna_maximum = arr.tablica[i][numer_kolumny-1];
		}
	}
	cout << "Najwieksza wartosc w kolumnie to:" << kolumna_maximum << endl;
}


void maximum_wierszy(Tablica arr){
	cout << "Który wiersz chcesz poddać analizie?" << endl;
	int numer_wiersza=0;
	cin >> numer_wiersza;
	int wiersz_maximum = arr.tablica[numer_wiersza-1][0];
	for(int i=0; i<arr.kolumna; i++){
		if(wiersz_maximum<arr.tablica[numer_wiersza-1][i]){
			wiersz_maximum = arr.tablica[numer_wiersza-1][i];
		}
	}
	cout<< "Najwieksza wartosc w wierszu to:" << wiersz_maximum << endl;
}

void srednia_kolumn(Tablica arr){
	cout << "Z jakiej kolumny obliczyc wartosc srednia" << endl;
	int numer_kolumny = 0;
	cin >> numer_kolumny;
	int suma_kolumn = 0;
	for(int i=0; i<arr.wiersz; i++){
		suma_kolumn+= arr.tablica[i][numer_kolumny-1];
	}
	int kolumna_srednia = suma_kolumn/arr.wiersz;
	
	cout << "Srednia kolumny wynosi" << kolumna_srednia << endl;
}

void srednia_wierszy(Tablica arr){
	cout << "Z jakiego wiersza obliczyc wartosc srednia?" << endl;
	int numer_wiersza = 0;
	cin >> numer_wiersza;
	int suma_wierszy = 0;
	for(int i=0; i<arr.kolumna; i++){
		suma_wierszy+= arr.tablica[numer_wiersza-1][i];
	}
	int wiersz_srednia = suma_wierszy/arr.kolumna;
	
	cout << "Srednia wiersza wynosi" << wiersz_srednia << endl;
}
		

