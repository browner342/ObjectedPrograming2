#
#  To sa opcje dla kompilacji
#
CXXFLAGS=-g -Iinc -Wall -pedantic -std=c++11

TRGDIR=/tmp/rysowanie_3D

__start__: ./rysowanie_3D
	./rysowanie_3D

./rysowanie_3D: obj obj/main.o obj/lacze_do_gnuplota.o obj/wektor3D.o
	g++ -Wall -pedantic -std=c++11 -o ./rysowanie_3D obj/main.o\
                        obj/lacze_do_gnuplota.o obj/wektor3D.o


obj:
	mkdir -p obj

obj/lacze_do_gnuplota.o: inc/lacze_do_gnuplota.hh src/lacze_do_gnuplota.cpp
	g++ -c ${CXXFLAGS} -o obj/lacze_do_gnuplota.o src/lacze_do_gnuplota.cpp

obj/main.o: src/main.cpp inc/lacze_do_gnuplota.hh inc/wektor.hh inc/wektor3D.hh inc/macierz.hh
	g++ -c ${CXXFLAGS} -o obj/main.o src/main.cpp

obj/wektor3D.o: src/wektor3D.cpp inc/wektor3D.hh inc/wektor.hh
	g++ -c ${CXXFLAGS} -o obj/wektor3D.o src/wektor3D.cpp

clean:
	rm -f obj/*.o ./rysowanie_3D
