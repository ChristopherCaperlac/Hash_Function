upstreamRepo = https://github.com/ChristopherCaperlac/Hash_Function

all: clean build
	make run

build:
	g++ -o encoder main.cpp hash.cpp

clean:
	rm encoder -f

run:
	./encoder < ./inputs/sample_input.txt

# Make a fork repository first and "git clone forkedRepo_URL" then use setup
setup:
	git remote add upstream $(upstreamRepo)

# Update can cause conflicts with your directory
update:
	git pull origin main
	git pull upstream main

# This is a non descriptive commit 
save:
	git add .
	git commit
	git push origin main

# For more complex merges, manually make a Pull Request in Github from the upstream repository 
mergeUp:
	git merge upstream/main