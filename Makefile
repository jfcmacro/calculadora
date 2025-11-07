all: calculadora.o test

calculadora.o: calculadora.c
	${CC} -c $<

test: test.o calculadora.o
	${CC} -o $@ $^ -lcunit

test.o: test.c calculadora.h
	${CC} -c $<

clean:
	rm -f *.o
	rm -f test
	rm -f *~


