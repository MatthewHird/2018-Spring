lab_4: main.o growing_array.o
	g++ main.o growing_array.o -o lab_4

main.o: main.cpp growing_array.h
	g++ -std=c++11 -c main.cpp

growing_array.o: growing_array.cpp growing_array.h
	g++ -std=c++11 -c growing_array.cpp

clean: 
	rm *.o lab_4