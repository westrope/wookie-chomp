CC= clang
CFLAGS= -c -g

120++: main.o lex.yy.o
	$(CC) -o 120++ main.o lex.yy.o -ll

main.o: main.c y.tab.h
	$(CC) $(CFLAGS) main.c 

lex.yy.o: lex.yy.c token.h
	$(CC) $(CFLAGS) lex.yy.c

lex.yy.c: 120++.l
	flex 120++.l

clean:
	rm lex.yy.o main.o 120++ lex.yy.c
