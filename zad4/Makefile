CXXFLAGS= -c -g -std=c++11 -iquote inc -Wall -pedantic

szablonUkladRownan: obj obj/main.o obj/lzespolona.o
	g++ -o ./szablonUkladRownan obj/main.o obj/lzespolona.o

obj:
	mkdir -p obj

obj/main.o: src/main.cpp inc/wektor.hh inc/macierz.hh inc/lzespolona.hh inc/uklrownan.hh
	g++ -c ${CXXFLAGS} -o obj/main.o src/main.cpp

obj/lzespolona.o: src/lzespolona.cpp inc/lzespolona.hh
	g++ -c ${CXXFLAGS} -o obj/lzespolona.o src/lzespolona.cpp
