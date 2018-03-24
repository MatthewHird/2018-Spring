pex4: main.o browser_sim.o
	g++ main.o browser_sim.o -o pex4

main.o: main.cpp browser_sim.h
	g++ -g -c main.cpp

browser_sim.o: browser_sim.cpp browser_sim.h stack.h stack.inl.h my_exceptions.h
	g++ -g -c browser_sim.cpp

clean:
	-rm *.o pex4