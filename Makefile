all: usethis

usethis: usethis.cpp

assembly: usethis.cpp
	g++ -S $(CFLAGS) usethis.cpp

clean:
	rm -f usethis usethis.s *~
