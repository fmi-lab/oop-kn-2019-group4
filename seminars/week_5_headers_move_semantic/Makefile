
output: container.o IntContainer.o
	g++ -std=c++14 container.o IntContainer.o -o output

container.o: container.cpp IntContainer/IntContainer.h
	g++ -c -std=c++14 container.cpp

IntContainer.o: IntContainer/IntContainer.h IntContainer/IntContainer.cpp
	g++ -c -std=c++14 IntContainer/IntContainer.cpp