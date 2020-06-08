#ifndef CELL_H
#define CELL_H
#include <iostream>
#include <string>

using namespace std;

class cell{


public:

	virtual int zwrocenie_liczby() = 0;
	virtual string zwrocenie_tekstu() = 0;
	virtual int ustawienie_wartosci(int new_wartosc)=0;
	virtual int ustawienie_wartosci(string new_wartosc)=0;
};

/*
* Klasa która zawiera dane tekstowe
*/


class cell_string: public cell{

public:
/*
* Zwrocenie zawartosci liczbowej komorki
* @return 0
*/
	virtual int zwrocenie_liczby(){
		return 0;
	}
/*
* Zwrocenie zawartosci tekstowej komorki
* @return tekst = zawartosc komorki
*/	
	virtual string zwrocenie_tekstu(){
		return tekst;
	}
/*
* Zmiana zawartosci liczbowej komorki
* @param new_wartosc = wartosc ktora bedzie wstawiona
* @return 0
*/
	virtual int ustawienie_wartosci(int new_wartosc){
		return 0;
	}
/*
* Zmiana zawartosci tekstowej komorki
* @param new_wartosc = wartosc ktora bedzie wstawiona
* @return 0 - brak bledu
*/
	virtual int ustawienie_wartosci(string new_wartosc){
		tekst = new_wartosc;
		return 0;
	}
	cell_string(){
		tekst = "nic";
	}

private:
/*
* Zawartosc ktora znajduje sie w komorce
*/
	string tekst;


};

/*
* Klasa która zawiera dane liczbowe
*/

class cell_int: public cell{

public:
/*
* Zwrocenie zawartosci liczbowej komorki
*/
	virtual int zwrocenie_liczby(){
		return liczba;
	}
/*
* Zwrocenie zawartosci tekstowej komorki
*/
	virtual string zwrocenie_tekstu(){
		return to_string(liczba);
	}
/*
* Zmiana zawartosci liczbowej komorki
* @param[in] new_wartosc = wartosc ktora bedzie wstawiona 
* @return 0 - bez bledu
*/
	virtual int ustawienie_wartosci(int new_wartosc){
		liczba = new_wartosc;
		return 0;
	}
/*
* Zmiana zawartosci tekstowej komorki
* @param[in] new_wartosc = wartosc ktora bedzie wstawiona 
* @return -1 - brak mozliwosci wstawienia string do int
*/
	virtual int ustawienie_wartosci(string new_wartosc){
		return -1;
	}
/*
* Konstruktor klasy, ktory ma wartosc domyslna pola rowna 0
*/	
	cell_int(){
		liczba = 0;
	}


private:
/*
* Zawartosc ktora znajduje sie w komorce
*/
	int liczba; 

};

#endif
