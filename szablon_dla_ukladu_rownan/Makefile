CXXFLAGS= -c -g -std=c++11 -iquote inc -Wall -pedantic

__start__: ./test_wektora
	./test_wektora

obj:
	mkdir -p obj

./test_wektora: obj obj/main.o obj/lzesp.o
	g++ -o ./test_wektora obj/main.o obj/lzesp.o

obj/main.o: src/main.cpp inc/macierz.hh inc/lzesp.hh
	g++ -c ${CXXFLAGS} -o obj/main.o src/main.cpp


obj/lzesp.o: src/lzesp.cpp inc/lzesp.hh
	g++ -c ${CXXFLAGS} -o obj/lzesp