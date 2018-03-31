lab8: main.o person.o
	g++ main.o person.o -o lab8

main.o: main.cpp queue.h queue.inl.h person.h my_exceptions.h
	g++ -g -c main.cpp

person.o: person.cpp person.h
	g++ -g -c person.cpp

clean:
	-rm *.o lab8