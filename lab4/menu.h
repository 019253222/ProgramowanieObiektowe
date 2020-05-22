#ifndef MENU_H
#define MENU_H
#include "tablica.h"

/**
* Funkcja odpowiadajaca za wyswietlenie menu
*/

void wyswietl_menu ();

/**
* Funkcja odpowiadajaca za petle menu
* @param[in,out] Tablica arr , tablica ktorej uzywa funkcja
*/

void menu_start(Tablica *arr);

/**
* Funkcja odpowiadajaca za przetwarzanie wyboru uzytkownika(zapytanie)
* @param[in,out] nr_informacji jest to numer ktory wpisal uzytkownik
*/

void wybieranie_menu(int *nr_informacji);

/**
* Funkcja odpowiadajaca za wczytanie wyboru uzytkownika
* @param[in] nr_informacji jest to numer ktory wpisal uzytkownik
* @param[in,out] Tablica arr, tablica na ktorej pracuja inne programy
*/

void informacja_zwrotna(int nr_informacji, Tablica *arr);

#endif
