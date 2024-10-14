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

# Do "git clone repositoryURL" to get your own local copy 

# Update can cause conflicts with your directory
update:
	git pull origin main

# This is the structure of a commit 
# git add .
# git commit -m 'your message here'
# git push origin main
