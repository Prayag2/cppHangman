SHELL=/bin/bash
srcDir := src
buildDir := bin
buildTarget := $(buildDir)/hangman
flags := -std=c++17 -Wall -Wextra -Werror -Weffc++ -Wconversion -Wsign-conversion -pedantic-errors

srcFiles := $(wildcard $(srcDir)/*.cpp)
headerFiles := $(wildcard $(srcDir)/*.h)

all: $(buildTarget)
	$(buildTarget)

$(buildTarget): $(srcFiles) $(buildDir) $(headerFiles)
	g++ $(flags) -O2 -DNDEBUG $(srcFiles) -o $(buildTarget)

debug: $(srcFiles) $(buildDir) $(headerFiles)
	g++ $(flags) -ggdb $(srcFiles) -o $(buildTarget)

clean:
	rm -rf $(buildDir)

$(buildDir):
	mkdir -p $(buildDir)
