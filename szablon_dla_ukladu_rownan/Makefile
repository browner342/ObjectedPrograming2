CXXFLAGS= -c -g -std=c++11 -iquote inc -Wall -pedantic

__start__: ./test_wektora
	./test_wektora

obj:
	mkdir -p obj

./test_wektora: obj obj/main.o obj/lzespolona.o
	g++ -o ./test_wektora obj/main.o obj/lzespolona.o

obj/main.o: src/main.cpp inc/macierz.hh inc/lzespolona.hh
	g++ -c ${CXXFLAGS} -o obj/main.o src/main.cpp


obj/lzespolona.o: src/lzespolona.cpp inc/lzespolona.hh
	g++ -c ${CXXFLAGS} -o obj/lzespolona.o src/lzespolona.cpp