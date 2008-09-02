all: usethis

usethis: usethis.cpp

asm: usethis.cpp
	g++ -S $(CFLAGS) usethis.cpp

clean:
	rm -f usethis usethis.s *~
