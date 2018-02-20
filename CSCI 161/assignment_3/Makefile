pex3: main.o reservation_system.o linked_list.o res_data.o
		g++ main.o reservation_system.o linked_list.o res_data.o -o pex3

main.o: main.cpp reservation_system.h
		g++ -g -c main.cpp

reservation_system.o: reservation_system.cpp reservation_system.h linked_list.h res_data.h
		g++ -g -c reservation_system.cpp

linked_list.o: linked_list.cpp linked_list.h res_data.h
		g++ -g -c linked_list.cpp

res_data.o: res_data.cpp res_data.h
		g++ -g -c res_data.cpp

clean: 
		-rm *.o pex3