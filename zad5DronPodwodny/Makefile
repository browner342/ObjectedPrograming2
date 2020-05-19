#
#  To sa opcje dla kompilacji
#
CXXFLAGS=-g -Iinc -Wall -pedantic -std=c++11

TRGDIR=/tmp/rysowanie_3D

__start__: ./rysowanie_3D
	./rysowanie_3D

./rysowanie_3D: obj obj/main.o obj/lacze_do_gnuplota.o obj/wektor3D.o obj/scena.o obj/woda.o obj/dno.o
	g++ -Wall -pedantic -std=c++11 -o ./rysowanie_3D obj/main.o\
                        obj/lacze_do_gnuplota.o obj/wektor3D.o obj/scena.o obj/woda.o obj/dno.o


obj:
	mkdir -p obj

obj/lacze_do_gnuplota.o: inc/lacze_do_gnuplota.hh src/lacze_do_gnuplota.cpp
	g++ -c ${CXXFLAGS} -o obj/lacze_do_gnuplota.o src/lacze_do_gnuplota.cpp

obj/main.o: src/main.cpp inc/lacze_do_gnuplota.hh inc/wektor.hh inc/wektor3D.hh inc/macierz.hh inc/scena.hh 
	g++ -c ${CXXFLAGS} -o obj/main.o src/main.cpp

obj/scena.o: src/scena.cpp inc/scena.hh inc/wektor3D.hh inc/woda.hh inc/woda.hh inc/consts.h
	g++ -c ${CXXFLAGS} -o obj/scena.o src/scena.cpp

obj/woda.o: src/woda.cpp inc/woda.hh inc/wektor3D.hh inc/consts.h
	g++ -c ${CXXFLAGS} -o obj/woda.o src/woda.cpp
	
obj/dno.o: src/dno.cpp inc/dno.hh inc/wektor3D.hh inc/consts.h
	g++ -c ${CXXFLAGS} -o obj/dno.o src/dno.cpp

obj/wektor3D.o: src/wektor3D.cpp inc/wektor3D.hh inc/wektor.hh
	g++ -c ${CXXFLAGS} -o obj/wektor3D.o src/wektor3D.cpp

clean:
	rm -f obj/*.o ./rysowanie_3D
