CC = g++

all: Mother.o Daughter.o main.o result

Mother.o: Mother.cpp
	g++ -c $^

Daughter.o: Daughter.cpp
	g++ -c $^

main.o: main.cpp
	g++ -c $^

result: Mother.o Daughter.o main.o
	g++ -g $^ -o $@

clean:
	rm *.o result