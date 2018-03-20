main.o: main.cpp Set.cpp SET.h
	g++ main.cpp Set.cpp
clean:
	rm a.out
open:
	./a.out
