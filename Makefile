CXXFLAGS=-Wall -pedantic -std=c++11 -O3

all: usethis

usethis: usethis.cpp

asm: usethis.cpp
	g++ -S $(CXXFLAGS) usethis.cpp

clean:
	rm -f usethis usethis.s *~
