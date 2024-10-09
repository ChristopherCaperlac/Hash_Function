all: clean build
	make run

build:
	g++ -o encoder main.cpp hash.cpp

clean:
	rm encoder -f

run:
	./encoder < ./inputs/sample_input.txt

# Do "git clone repositoryURL" to get your own local copy 

# Update can cause conflicts with your directory
update:
	git pull origin main

# This is a non descriptive commit 
save:
	git add .
	git commit -m 'default message'
	git push origin main
