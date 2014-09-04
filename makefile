CC= gcc
CFLAGS= -c -g

120++: main.o lex.yy.o
	$(CC) -o 120++ main.o lex.yy.o -ll

main.o: main.c ytab.h
	$(CC) $(CFLAGS) main.c 

lex.yy.o: lex.yy.c
	$(CC) $(CFLAGS) lex.yy.c

lex.yy.c: 120++.l
	flex muth.l
