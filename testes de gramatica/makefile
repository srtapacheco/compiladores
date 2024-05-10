all: saida entrada1.txt
	./saida < entrada1.txt

saida: lex.yy.c npr.tab.c
	g++ npr.tab.c -o saida -lfl	
	
lex.yy.c: npr.l
	lex npr.l
	
npr.tab.c: npr.y
	bison npr.y
	
clean: 
	rm -f lex.yy.c npr.tab.c saida