all: sieve.o
	gcc -g driver.c sieve.c -lm

run: all
	./a.out $(args)

sieve.o: sieve.c sieve.h
	gcc -c -g sieve.c -lm
clean:
	rm *~ *.gch* a.out *.o *#* ; rm -r *.dSYM
