#ifndef TABLICA_H
#define TABLICA_H

// Struktura przechowujaca dane

struct Tablica{
	int **tablica;
	int wiersz;
	int kolumna;
};

/**
* Funkcja odpowiadajaca za zmiane zawartosci w komorce wybranej przez uzytkownika
* @param[in,out] Tablica arr, uzywana tablica
* @param[in] komorka_wiersza, komorka wiersza ktora jest uzywana
* @param[in] komorka_kolumny, komorka kolumny ktora jest uzywana
* @param[in] nowe, nowa wartosc komorki wpisana przez uzytkownika
* @return 0 przy poprawnym przebiegu, -1 jako blad - odwolanie do nieistniejacych wartosci
*/
int zmiana_komorki(Tablica arr, int komorka_wiersza, int komorka_kolumny, int nowe);

/**
* Funkcja odpowiadajaca za zmiane rozmiaru tablicy 
* @param[in,out] Tablica & arr, uzywana tablica 
* @param[in] nowy_wiersz, nowa liczba wierszy
* @param[in] nowa_kolumna, nowa liczba kolumn
*/

void zmiana_rozmiaru (Tablica & arr, int nowy_wiersz, int nowa_kolumna);

/**
* Funkcja odpowiadajaca za zapisywanie tablicy do pliku
* @param[in] Tablica arr, tablica ktorej zawartosc jest zapisywana do pliku
* @return 0 przy poprawnym przebiegu, -1 jako blad  
*/

int zapisywanie_pliku(Tablica arr);

/**
* Funkcja odpowiadajaca za odczyt tablicy z pliku
* @param[in,out] Tablica* arr, tablica z ktorej wczytywane sa dane (z pliku)
* @return 0 przy poprwanym przebiegu, -1 jako blad otworzenia pliku
*/

int odczytywanie_pliku(Tablica* arr);

/**
* Funkcja odpowiadajaca za sumowanie wedlug wierszy
* @param Tablica arr, tablica ktora jest uzywana w funkcji
* @return 0 przy poprawnym przebiegu, -1 jako blad 
*/

int sumowanie_wierszy(Tablica arr, int numer_wiersza);

/**
* Funkcja odpowiadajaca za sumowanie wedlug kolumn
* @param Tablica arr, tablica ktora jest uzywana w funkcji
* @return 0 przy poprawnym przebiegu, -1 jako blad 
*/

int sumowanie_kolumn(Tablica arr, int numer_kolumny);

/**
* Funkcja odpowiadajaca za znalezienie wartosci minimalnej w wybranej kolumnie
* @param Tablica arr, tablica ktora jest uzywana w funkcji
* @return 0 przy poprawnym przebiegu, -1 jako blad 
*/

int minimum_kolumn(Tablica arr, int numer_kolumny);

/**
* Funkcja odpowiadajaca za znalezienie wartosci minimalnej w wybranym wierszu
* @param Tablica arr, tablica ktora jest uzywana w funkcji
* @return 0 przy poprawnym przebiegu, -1 jako blad 
*/

int minimum_wierszy(Tablica arr, int numer_wiersza);

/**
* Funkcja odpowiadajaca za znalezienie wartosci maksymalnej w wybranej kolumnie
* @param Tablica arr, tablica ktora jest uzywana w funkcji
* @return 0 przy poprawnym przebiegu, -1 jako blad 
*/

int maximum_kolumny(Tablica arr, int numer_kolumny);

/**
* Funkcja odpowiadajaca za znalezienie wartosci maksymalnej w wybranym wierszu
* @param Tablica arr, tablica ktora jest uzywana w funkcji
* @return 0 przy poprawnym przebiegu, -1 jako blad 
*/

int maximum_wierszy(Tablica arr, int numer_wiersza);

/**
* Funkcja odpowiadajaca za obliczenie wartosci sredniej dwoch wybranych kolumn
* @param Tablica arr, tablica ktora jest uzywana w funkcji
* @return 0 przy poprawnym przebiegu, -1 jako blad 
*/

int srednia_kolumn(Tablica arr, int numer_kolumny);

/**
* Funkcja odpowiadajaca za obliczenie wartoci sredniej dwoch wybranych wierszy
* @param Tablica arr, tablica ktora jest uzywana w funkcji
* @return 0 przy poprawnym przebiegu, -1 jako blad 
*/

int srednia_wierszy(Tablica arr, int numer_wiersza);




#endif
