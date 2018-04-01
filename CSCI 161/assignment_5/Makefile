pex5: main.o wiki_country.o country_data.o sorted_list.o
	g++ main.o wiki_country.o country_data.o sorted_list.o -o pex5

main.o: main.cpp wiki_country.h
	g++ -g -c main.cpp

wiki_country.o: wiki_country.cpp wiki_country.h dictionary.h dictionary.inl.h sorted_list.h country_data.h my_exceptions.h
	g++ -g -c wiki_country.cpp

country_data.o: country_data.cpp country_data.h
	g++ -g -c country_data.cpp

sorted_list.o: sorted_list.cpp sorted_list.h
	g++ -g -c sorted_list.cpp

clean:
	-rm *.o pex5