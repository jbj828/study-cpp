CC = g++

Sally.o: Sally.cpp
	g++ -c $^

main.o: main.cpp
	g++ -c $^

result: Sally.o main.o
	g++ -g $^ -o $@

clean:
	rm *.o result