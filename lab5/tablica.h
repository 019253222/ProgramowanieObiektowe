#ifndef TABLICA_H
#define TABLICA_H
#include <iostream>
#include <fstream>
#include "cell.h"

using namespace std;

// Klasa przechowująca tablicę, ilość wierszy, kolumn oraz funkcje, które operują na

class Tablica{


private:

	cell **tablica;
	int kolumna;
	int wiersz;


public:

Tablica();

/**
* Funkcja odpowiadajaca za wyswietlanie tablicy liczbowej
*/

void wyswietl_tablice();

/**
* Funkcja odpowiadajaca za wyswietlenie tablicy tekstowej
*/

void wyswietl_tablice_tekst();

/**
* Funkcja odpowiadajaca za zmiane zawartosci w komorce wybranej przez uzytkownika
* @param[in] komorka_wiersza, komorka wiersza ktora jest uzywana
* @param[in] komorka_kolumny, komorka kolumny ktora jest uzywana
* @param[in] nowe, nowa wartosc komorki wpisana przez uzytkownika
* @return 0 przy poprawnym przebiegu, -1 jako blad - odwolanie do nieistniejacych wartosci
*/

int zmiana_komorki(int komorka_wiersza, int komorka_kolumny, int nowe);

/**
*
*/

int zmiana_komorki_tekst(int komorka_wiersza, int komorka_kolumny, string nowe_tekst);


/**
* Funkcja odpowiadajaca za zmiane rozmiaru tablicy 
* @param[in] nowy_wiersz, nowa liczba wierszy
* @param[in] nowa_kolumna, nowa liczba kolumn
*/

void zmiana_rozmiaru (int nowy_wiersz, int nowa_kolumna);

/**
*
*/


void zmiana_rozmiaru_tekstu (int nowy_wiersz, int nowa_kolumna);

/**
* Funkcja odpowiadajaca za zapisywanie tablicy do pliku
* @return 0 przy poprawnym przebiegu, -1 jako blad  
*/

int zapisywanie_pliku();

int zapisywanie_pliku_tekst();

/**
* Funkcja odpowiadajaca za odczyt tablicy z pliku
* @return 0 przy poprwanym przebiegu, -1 jako blad otworzenia pliku
*/

int odczytywanie_pliku();

int odczytywanie_pliku_tekst();

/**
* Funkcja odpowiadajaca za sumowanie wedlug wierszy
* @return 0 przy poprawnym przebiegu, -1 jako blad 
*/

int sumowanie_wierszy(int numer_wiersza);

/**
* Funkcja odpowiadajaca za sumowanie wedlug kolumn
* @return 0 przy poprawnym przebiegu, -1 jako blad 
*/

int sumowanie_kolumn(int numer_kolumny);

/**
* Funkcja odpowiadajaca za znalezienie wartosci minimalnej w wybranej kolumnie
* @return 0 przy poprawnym przebiegu, -1 jako blad 
*/

int minimum_kolumn(int numer_kolumny);

/**
* Funkcja odpowiadajaca za znalezienie wartosci minimalnej w wybranym wierszu
* @return 0 przy poprawnym przebiegu, -1 jako blad 
*/

int minimum_wierszy(int numer_wiersza);

/**
* Funkcja odpowiadajaca za znalezienie wartosci maksymalnej w wybranej kolumnie
* @return 0 przy poprawnym przebiegu, -1 jako blad 
*/

int maximum_kolumny(int numer_kolumny);

/**
* Funkcja odpowiadajaca za znalezienie wartosci maksymalnej w wybranym wierszu
* @param Tablica arr, tablica ktora jest uzywana w funkcji
* @return 0 przy poprawnym przebiegu, -1 jako blad 
*/

int maximum_wierszy(int numer_wiersza);

/**
* Funkcja odpowiadajaca za obliczenie wartosci sredniej dwoch wybranych kolumn
* @return 0 przy poprawnym przebiegu, -1 jako blad 
*/

int srednia_kolumn(int numer_kolumny);

/**
* Funkcja odpowiadajaca za obliczenie wartoci sredniej dwoch wybranych wierszy
* @return 0 przy poprawnym przebiegu, -1 jako blad 
*/

int srednia_wierszy(int numer_wiersza);

~Tablica();

};
#endif
