lab10: main.o tree_manager.o family_tree.o person.o stack.o
	g++ main.o tree_manager.o family_tree.o person.o stack.o -o lab10

main.o: main.cpp tree_manager.h
	g++ -g -c main.cpp

tree_manager.o: tree_manager.cpp tree_manager.h family_tree.h person.h stack.h
	g++ -g -c tree_manager.cpp

family_tree.o: family_tree.cpp family_tree.h person.h
	g++ -g -c family_tree.cpp

person.o: person.cpp person.h
	g++ -g -c person.cpp

stack.o: stack.cpp stack.h person.h
	g++ -g -c stack.cpp

clean:
	-rm *.o lab10