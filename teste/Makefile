all: analisador.out
	../Testes_Trabalhos/test.py -d testes -p ./analisador.out

lex.yy.c: scan.l
	lex scan.l

analisador.out: main.cc lex.yy.c 
	g++ -std=c++17 main.cc -o analisador.out -lfl
	
clean: analisador.out lex.yy.c
	rm analisador.out lex.yy.c