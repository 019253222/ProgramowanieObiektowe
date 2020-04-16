#include <iostream>
#include "menu.h"

using namespace std;

void wyswietl_menu (){

	cout << "Wybierz opcje" << endl;
	cout << "1. - Utworzenie tablicy" << endl;
	cout << "2. - Wyświetlenie tablicy " << endl; 
	cout << "3. - Zmiana zawartosci komorki tablicy" << endl;
	cout << "4. - Zmiana rozmiaru tablicy " << endl;
	cout << "5. - Wyłączenie programu " << endl;  
}

void informacja_zwrotna(int nr_informacji) {
	
	switch(nr_informacji) {
		case 11:
			cout << "BLAD, Tablica nie istnieje !" << endl;
			break;
		
		case 12:
			cout << "BLAD, Wartosc musi byc wieksza lub rowna 0" << endl;
			break;
		
		case 13:
			cout << "BLAD, Wartosc nie moze przekraczac rozmiaru tablicy" << endl;
			break;	
			
		case 0:
			cout << "Program do tworzenia tablic" << endl;
			break;

		default:
			cout << "Domyslna wiadomosc" << endl;
		}
}

void start_Menu(int* tablica, int* rozmiar_tablicy) {

}


