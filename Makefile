CXXFLAGS=-Wall -ansi -pedantic

all: usethis

usethis: usethis.cpp

asm: usethis.cpp
	g++ -S $(CXXFLAGS) usethis.cpp

clean:
	rm -f usethis usethis.s *~
