CC= gcc
CFLAGS= -c -g

120++: main.o lex.yy.o token.o list.o
	$(CC) -o 120++ main.o lex.yy.o token.o list.o -ll

main.o: main.c y.tab.h
	$(CC) $(CFLAGS) main.c

token.o: token.c
	$(CC) $(CFLAGS) token.c

list.o: list.c
	$(CC) $(CFLAGS) list.c

lex.yy.o: lex.yy.c token.h list.h
	$(CC) $(CFLAGS) lex.yy.c

lex.yy.c: 120++.l
	flex 120++.l

clean:
	rm lex.yy.o main.o 120++ lex.yy.c
