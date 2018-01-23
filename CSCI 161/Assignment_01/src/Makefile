taxi_reservation_system: main.o reservation_system.o linked_list.o res_data.o
		g++ main.o reservation_system.o linked_list.o res_data.o -o taxi_reservation_system

main.o: main.cpp ../include/main.h ../include/reservation_system.h
		g++ -c main.cpp

reservation_system.o: reservation_system.cpp ../include/reservation_system.h ../include/linked_list.h ../include/res_data.h
		g++ -c reservation_system.cpp

linked_list.o: linked_list.cpp ../include/linked_list.h ../include/res_data.h
		g++ -c linked_list.cpp

res_data.o: res_data.cpp ../include/res_data.h
		g++ -c res_data.cpp

clean: 
		rm *.o taxi_reservation_system
