#ifndef MENU_H
#define MENU_H
#include "tablica.h"

void petlaMenu(int *tablica){

	int odpowiedz = 0;
	while (1){
	
	drukujMenu();

	pobierzOdpowiedz(&odpowiedz);

	if(przetworzOdpowiedz(odpowiedz) == -1){
		break;
		}
	
	}
}


void drukujMenu(){
	// wyswietl menu
}

void pobierzOdpowiedzi(int *odpowiedz){
	// wczytaj odpowiedz uzytkownika
}


void przetworzOdpowiedz(int odpowiedz){

	//przetworz odpowiedz
	switch(odpowiedz){
		...
	}
}

#endif
