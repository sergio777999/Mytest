all: debug_test

debug_test: main.o functions.o
			g++ -g --std=c++11 main.o functions.o -o debug_test

main.o: main.cpp
			g++ -c main.cpp

functions.o: functions.cpp functions.h
			g++ -c functions.cpp

clean:
			rm *o debug_test
