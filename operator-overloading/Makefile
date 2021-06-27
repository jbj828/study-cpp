CC = g++

all: Hannah.o main.o result

Hannah.o: Hannah.cpp
	g++ -c $^

main.o: main.cpp
	g++ -c $^

result: Hannah.o main.o
	g++ -g $^ -o $@

clean:
	rm *.o result