all: clean build
	make run

build:
	g++ -o encoder main.cpp hash.cpp hashMap.cpp linkedList.cpp

clean:
	rm encoder -f

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
