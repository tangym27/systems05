all: stringfun.o strings.o
	gcc -o test stringfun.o strings.o

stringfun.o: stringfun.c stringfun.h
	gcc -c stringfun.c

strings.o: strings.c stringfun.h
	gcc -c strings.c

run:
	./test

clean:
	rm *.o