#include <iostream>
#include "tablica_wysw.h"
#include "tablica.h"

using namespace std;


void wyswietl_tablice(Tablica arr) {
	for(int x=0; x<arr.wiersz; x++){
		for(int y=0; y<arr.kolumna; y++){
			cout << arr.tablica[x][y] << "\t";
		}
		cout << endl;
	}
}
