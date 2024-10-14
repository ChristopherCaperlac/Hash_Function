all: clean build run

build: main.o hashMap.o linkedList.o
	g++ main.o hashMap.o linkedList.o -o encoder

main.o: hashMap.h linkedList.h
	g++ -c main.cpp

hashMap.o: hashMap.h
	g++ -c hashMap.cpp

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