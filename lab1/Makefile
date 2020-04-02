FLAGS = -Wall -pedantic -std=c++14

./app : main.o tablica.o menu.o
	g++ -o app main.o tablica.o menu.o

main.o : main.cpp
	g++ -c ${FLAGS} -o main.o main.cpp

tablica.o : tablica.cpp tablica.h
	g++ -c ${FLAGS} -o tablica.o tablica.cpp

menu.o : menu.cpp menu.h
	g++ -c ${FLAGS} -o menu.o menu.cpp
