pex5: main.o wiki_country.o country_data.o my_list.o
	g++ main.o wiki_country.o country_data.o my_list.o -o pex5

main.o: main.cpp wiki_country.h
	g++ -g -c main.cpp

wiki_country.o: wiki_country.cpp wiki_country.h dictionary.h dictionary.inl.h my_list.h country_data.h my_exceptions.h
	g++ -g -c wiki_country.cpp

country_data.o: country_data.cpp country_data.h
	g++ -g -c country_data.cpp

my_list.o: my_list.cpp my_list.h
	g++ -g -c my_list.cpp

clean:
	-rm *.o pex5