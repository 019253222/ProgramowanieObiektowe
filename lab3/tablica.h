#ifndef TABLICA_H
#define TABLICA_H

struct Tablica{
	int **tablica;
	int wiersz;
	int kolumna;
};

void wyswietl_tablice(Tablica arr);

void zmiana_komorki(Tablica arr, int komorka_wiersza, int komorka_kolumny, int nowe);

int** zmiana_rozmiaru (Tablica* arr, int new_wiersz, int new_kolumna);

void zapisywanie_pliku(Tablica arr);

void odczytywanie_pliku(Tablica* arr);

void sumowanie_wierszy(Tablica arr);

void sumowanie_kolumn(Tablica arr);

void minimum_kolumn(Tablica arr);

void minimum_wierszy(Tablica arr);

void maximum_kolumny(Tablica arr);

void maximum_wierszy(Tablica arr);

void srednia_kolumn(Tablica arr);

void srednia_wierszy(Tablica arr);


#endif
