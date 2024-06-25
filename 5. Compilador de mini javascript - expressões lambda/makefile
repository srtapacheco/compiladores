all: saida codigo
	echo "=== Execução ==="
	./interpretador < codigo
	
codigo: saida testes/Teste1.txt
	./saida < testes/Teste1.txt > codigo
	echo "=== Codigo ==="
	cat codigo

saida: lex.yy.c y.tab.c
	g++ y.tab.c -o saida -lfl	
	
lex.yy.c: mini_js.l
	lex mini_js.l

	
y.tab.c: mini_js.y
	yacc mini_js.y
	
clean: 
	rm -f lex.yy.c y.tab.c saida