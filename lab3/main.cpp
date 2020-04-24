#include <iostream>
#include <fstream>
#include "tablica.h"
#include "menu.h"

using namespace std;

int main() {
	Tablica arr;
	arr.wiersz = 0;
	arr.kolumna = 0;
	menu_start(arr);
	
	return 0;
}
