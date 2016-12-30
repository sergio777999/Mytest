
mainex: main.o func.o
		g++ -g main.o func.o -o mainex

main.o: main.cpp
		g++ -c main.cpp

func.o: func.cpp func.h
		g++ -c func.cpp

clean:
		rm *.o mainex
