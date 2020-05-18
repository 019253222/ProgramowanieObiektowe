FLAGS = -Wall -pedantic -std=c++14

./app : main.o tablica.o menu.o tablica_wysw.o
	g++ -o app main.o tablica.o menu.o tablica_wysw.o

main.o : main.cpp
	g++ -c ${FLAGS} -o main.o main.cpp

tablica.o : tablica.cpp tablica.h
	g++ -c ${FLAGS} -o tablica.o tablica.cpp

menu.o : menu.cpp menu.h
	g++ -c ${FLAGS} -o menu.o menu.cpp

tablica_wysw.o : tablica_wysw.cpp tablica_wysw.h
	g++ -c ${FLAGS} -o tablica_wysw.o tablica_wysw.cpp
