#ifndef CELL_H
#define CELL_H
#include <iostream>
#include <string>

using namespace std;

class cell{

private:

	int liczba;	
	string tekst;

public:

	int & zwrocenie_liczby(){return liczba;}
	string & zwrocenie_tekstu(){return tekst;}
	cell(){
		liczba=0;
		tekst="";
	}
};

#endif
