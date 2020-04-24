#include <iostream>
#include "tablica.h"
#include "menu.h"

using namespace std;

void menu_start(Tablica &arr){
	int nr_informacji = 0;
	while(nr_informacji!=14){
		wyswietl_menu();
		wybieranie_menu(&nr_informacji);
		informacja_zwrotna(nr_informacji, arr);
		
	}
}

void wyswietl_menu (){

	cout << "Wybierz opcje" << endl;
	cout << "1. - Wczytywanie tablicy" << endl;
	cout << "2. - Wyświetlenie tablicy " << endl; 
	cout << "3. - Zmiana zawartosci komorki tablicy" << endl;
	cout << "4. - Zmiana rozmiaru tablicy " << endl;
	cout << "5. - Sumowanie po kolumnach" << endl;
	cout << "6. - Sumowanie po wierszach" << endl; 
	cout << "7. - Wartość najmniejsza w kolumnie" << endl;
	cout << "8. - Wartosc najmniejsza w wierszu" << endl;
	cout << "9. - Wartosc najwieksza w kolumnie " << endl;
	cout << "10. - Wartosc najwieksza w wierszu" << endl;
	cout << "11. - Wartosc srednia w kolumnie " << endl;
	cout << "12. - Wartosc średnia w wierszu  " << endl;
	cout << "13. - Zapisz do pliku " << endl;
	cout << "14. - Wyłacz program" << endl; 
}

void informacja_zwrotna(int nr_informacji, Tablica &arr) {

	int komorka_wiersza = 0;
	int komorka_kolumny = 0;
	int nowe = 0;
	int new_wiersz = 0;
	int new_kolumna = 0;

	switch(nr_informacji) {

		case 0:
			cout << "Program do tworzenia tablic" << endl;
			break;

		case 1:
			cout << "Wczytywanie tablicy z pliku ... " << endl;
			odczytywanie_pliku(&arr);
			break;

		case 2:
			cout << " Wyświetlenie tablicy " << endl;
			wyswietl_tablice(arr);
			break;

		case 3:
			cout << "Edycja zawartosci tablicy?" << endl;
			cout << "Podaj wiersz tablicy:" << endl;
			cin >> komorka_wiersza;
			cout << "Podaj kolumne tablicy:" << endl;
			cin >> komorka_kolumny;
			cout << "Podaj nowa wartość" << endl;
			cin >> nowe;
			zmiana_komorki(arr, komorka_wiersza, komorka_kolumny, nowe);			
			break;

		case 4:
			cout << "Jaki ma byc nowy rozmiar tablicy: " << endl;
			cin >> new_wiersz;
			cin >> new_kolumna;
			zmiana_rozmiaru(&arr, new_wiersz, new_kolumna);			
			
			break;
		case 5:
			cout << "Sumowanie po kolumnach" << endl;
			sumowanie_kolumn(arr);
			break;
		case 6:
			cout << "Sumowanie po wierszach" << endl;
			sumowanie_wierszy(arr);			
			break;
		
		case 7: 
			cout << "Wartosc najmniejsza w kolumnie" << endl;
			minimum_kolumn(arr);
			break;
		case 8: 
			cout << "Wartosc najmniejsza w wierszu" << endl;
			minimum_wierszy(arr);
			break;	
		case 9: 
			cout << "Wartosc najwieksza w kolumnie" << endl;
			maximum_kolumny(arr);
			break;	
		case 10: 
			cout << "Wartosc najwieksza w wierszu" << endl;
			maximum_wierszy(arr);
			break;
		case 11: 
			cout << "Wartosc srednia w kolumnie" << endl;
			srednia_kolumn(arr);
			break;	
		case 12: 
			cout << "Wartosc srednia w wierszu" << endl;
			srednia_wierszy(arr);
			break;	
		case 13: 
			cout << "Zapisanie pliku" << endl;
			zapisywanie_pliku(arr);
			break;	
		case 14: 
			cout << "Wyłączenie programu" << endl;
		
		default:
			cout << "Domyslna wiadomosc" << endl;
		}
}


			
void wybieranie_menu(int *nr_informacji){
	cout << "Wybierz opcje:" << endl;
	cin >> *nr_informacji;
}








