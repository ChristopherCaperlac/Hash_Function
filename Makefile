all: clean build

build: main.o hash.o linkedList.o
	g++ main.o hash.o linkedList.o -o encoder

main.o: hash.h linkedList.h
	g++ -c main.cpp

hash.o: hash.h
	g++ -c hash.cpp

linkedList.o: linkedList.h
	g++ -c linkedList.cpp

clean:
	rm encoder *.o -f

run:
	./encoder < ./inputs/sample_input.txt

demo:
	./demoEncoder < ./inputs/sample_input.txt

update:
	git pull origin main