#include <iostream>
#include "tablica.h"
#include "menu.h"

using namespace std;

void menu_start(Tablica *arr){
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

void informacja_zwrotna(int nr_informacji, Tablica *arr) {

	int komorka_wiersza = 0;
	int komorka_kolumny = 0;
	int nowe = 0;
	int nowy_wiersz = 0;
	int nowa_kolumna = 0;
	int numer_wiersza = 0;
	int numer_kolumny = 0;
	int err = 0;

	switch(nr_informacji) {

		case 0:
			cout << "Program do tworzenia tablic" << endl;
			break;

		case 1:
			cout << "Wczytywanie tablicy z pliku ... " << endl;
			err = arr-> odczytywanie_pliku();
			
			if(err){
				cout << "Wystapil blad przy wczytywaniu tablicy" << endl;
			}

			break;

		case 2:
			cout << " Wyświetlenie tablicy " << endl;
			arr -> wyswietl_tablice();
			break;

		case 3:
			cout << "Edycja zawartosci tablicy?" << endl;
			cout << "Podaj wiersz tablicy:" << endl;
			cin >> komorka_wiersza;
			cout << "Podaj kolumne tablicy:" << endl;
			cin >> komorka_kolumny;
			cout << "Podaj nowa wartość" << endl;
			cin >> nowe;
			err = arr -> zmiana_komorki(komorka_wiersza, komorka_kolumny, nowe);	

			if(err){
				cout << "Bledna wartosc komorki" << endl;
			}
		
			break;

		case 4:
			cout << "Jaki ma byc nowy rozmiar tablicy: " << endl;
			cout << "Wiersze: " << endl;
			cin >> nowy_wiersz;
			cout << "Kolumny: " << endl;
			cin >> nowa_kolumna;
			arr -> zmiana_rozmiaru(nowy_wiersz, nowa_kolumna);			
			
			break;
		case 5:
			cout << "Sumowanie po kolumnach" << endl;
			cout << "Którą kolumne chcesz zsumowac?" << endl;
			cin >> numer_kolumny;
			err = arr -> sumowanie_kolumn(numer_kolumny);

			if(err){
				cout << "Bledne wskazanie kolumny" << endl;
			}	
			break;
		case 6:
			cout << "Sumowanie po wierszach" << endl;
			cout << "Który wiersz chcesz zsumowac?" << endl;
			cin >> numer_wiersza;
			err = arr -> sumowanie_wierszy(numer_wiersza);
	
			if(err){
				cout << "Bledne wskazanie wiersza" << endl;
			}		
			break;
		
		case 7: 
			cout << "Wartosc najmniejsza w kolumnie" << endl;
			cout << "Która kolumne chcsz poddac analizie ?"<<endl;
			cin >> numer_kolumny;
			err = arr -> minimum_kolumn(numer_kolumny);

			if(err){
				cout << "Bledne wskazanie kolumny" << endl;
			}		
			break;


		case 8: 
			cout << "Wartosc najmniejsza w wierszu" << endl;
			cout << "Który wiersz chcesz poddać analizie ?"<< endl;
			cin >> numer_wiersza;
			err = arr ->  minimum_wierszy(numer_wiersza);

			if(err){
				cout << "Bledne wskazanie wiersza" << endl;
			}		
			break;	
		case 9: 
			cout << "Wartosc najwieksza w kolumnie" << endl;
			cout << "Który wiersz chcesz poddać analizie?" << endl;
			cin >> numer_kolumny;			
			err = arr -> maximum_kolumny(numer_kolumny);

			if(err){
				cout << "Bledne wskazanie kolumny" << endl;
			}		
			break;	
		case 10: 
			cout << "Wartosc najwieksza w wierszu" << endl;
			cout << "Który wiersz chcesz poddać analizie?" << endl;
			cin >> numer_wiersza;
			err = arr -> maximum_wierszy(numer_wiersza);

			if(err){
				cout << "Bledne wskazanie wiersza" << endl;
			}	
			break;
		case 11: 
			cout << "Wartosc srednia w kolumnie" << endl;
			cout << "Z jakiej kolumny obliczyc wartosc srednia" << endl;
			cin >> numer_kolumny;
			err = arr -> srednia_kolumn(numer_kolumny);

			if(err){
				cout << "Bledne wskazanie kolumny" << endl;
			}		
			break;	
		case 12: 
			cout << "Wartosc srednia w wierszu" << endl;
			cout << "Z jakiego wiersza obliczyc wartosc srednia?" << endl;
			cin >> numer_wiersza;
			err = arr -> srednia_wierszy(numer_wiersza);

			if(err){
				cout << "Bledne wskazanie wiersza" << endl;
			}		
			break;	
		case 13: 
			cout << "Zapisanie pliku" << endl;
			arr -> zapisywanie_pliku();
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








