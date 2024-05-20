all: miniJS.out
	../Testes_Trabalhos/test.py -d testes/testes3 -p ./miniJS.out

lex.yy.c: miniJS.l
	lex miniJS.l

y.tab.c: miniJS.y
	yacc miniJS.y

miniJS.out: lex.yy.c y.tab.c
	g++ -o miniJS.out y.tab.c -lfl