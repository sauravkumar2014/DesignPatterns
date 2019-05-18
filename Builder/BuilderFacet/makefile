CXX = g++
CXXFLAGS = -Wall -g
main: main.o Person.o PersonBuilder.o
	$(CXX) $(CXXFLAGS) -o main main.o Person.o PersonBuilder.o

main.o: main.cpp Person.hpp PersonBuilder.hpp PersonAddrBuilder.hpp PersonJobBuilder.hpp
	$(CXX) $(CXXFLAGS) -c main.cpp

Person.o: Person.hpp PersonBuilder.hpp
PersonBuilder.o: Person.hpp PersonBuilder.hpp PersonAddrBuilder.hpp PersonJobBuilder.hpp