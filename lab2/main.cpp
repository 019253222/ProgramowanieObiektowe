#include <iostream>
#include "tablica.h"
#include "menu.h"

using namespace std;

int main() {
	int* tablica = NULL;
	int rozmiar_tablicy = 0;

	start_Menu(tablica, &rozmiar_tablicy);
	if (tablica != NULL) delete[] tablica; // Zabezpieczenie przed pozostawieniem zalokowanej pamięci
	
	return 0;
}
