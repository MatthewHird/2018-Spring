pex4: main.o browser_sim.o stack.o
	g++ main.o browser_sim.o stack.o -o pex4

main.o: main.cpp browser_sim.h
	g++ -g -c main.cpp

browser_sim.o: browser_sim.cpp browser_sim.h stack.h
	g++ -g -c browser_sim.cpp

stack.o: stack.cpp stack.h
	g++ -g -c stack.cpp

clean:
	-rm *.o pex4