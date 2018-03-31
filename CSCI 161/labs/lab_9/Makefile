lab9: main.o tech_dict.o dictionary.o
	g++ main.o tech_dict.o dictionary.o -o lab9

main.o: main.cpp tech_dict.h
	g++ -g -c main.cpp

tech_dict.o: tech_dict.cpp tech_dict.h dictionary.h
	g++ -g -c tech_dict.cpp

dictionary.o: dictionary.cpp dictionary.h
	g++ -g -c dictionary.cpp

clean:
	-rm *.o lab9