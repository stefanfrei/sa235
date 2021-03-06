
output: main.o banker.o
	g++ main.o banker.o -o output

main.o: main.cpp
	g++ -c main.cpp

banker.o: banker.cpp banker.h
	g++ -c banker.cpp

clean:
	rm *.o output

target: dependencies
	action