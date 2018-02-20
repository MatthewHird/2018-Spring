pex2: main.o image.o
	g++ -g main.o image.o -o pex2

main.o: main.cpp image.h
	g++ -g -c main.cpp

image.o: image.cpp image.h
	g++ -g -c image.cpp

clean:
	rm *.o pex2
