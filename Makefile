CXXFLAGS=-Wall -pedantic -std=c++11 -g

all: usethis

usethis: usethis.cpp

asm: usethis.cpp
	g++ -S $(CXXFLAGS) usethis.cpp

clean:
	rm -rf usethis usethis.s usethis.dSYM
