#include "tablica.h"
using namespace std;


int* new_tablica(int rozmiar_tablicy) {
	int* tabela = new int[rozmiar_tablicy];
	return tabela;
}

int wyswietl_tablice(int* tablica, int rozmiar_tablicy) {
	if(tablica==NULL) {
		return 11;

	}
	
	cout << "Tablica o rozmiarze " << rozmiar_tablicy << endl;
	for(int i=0, i<rozmiar_Tablicy; i++) {
		cout << tablica[i] << endl;
		
	}
	return 0;
}

int zmiana_komorki(int* tablica, int rozmiar_tablicy, int komorka, int new_wartosc) {
	if(tablica==NULL) {
		return 11;
	}

	if(komorka<0) {
		return 12;
	}

	if(komorka>=rozmiar_tablicy) {
		return 13;
	}

	tablica[komorka]=new_wartosc;

	return 0;
}

int* zmiana_romiaru (int* tablica, int& rozmiar_tablicy, int new_rozmiar_tablicy) {

	return 0;
}

