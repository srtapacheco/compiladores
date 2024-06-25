# Trabalho 2 - Geração de forma intermediária

# Analisador Léxico para Tokens Específicos
Este projeto inclui um analisador léxico desenvolvido com a ferramenta LEX. O analisador é capaz de identificar diversos tipos de tokens em um texto-fonte, como identificadores, números inteiros e de ponto flutuante, palavras-chave (insensíveis a maiúsculas e minúsculas), operadores, comentários e strings.

## Compilação e Execução
Para compilar o analisador léxico, execute o seguinte comando no diretório do projeto:

lex tradutor.l

g++ -std=c++17 lex.yy.c -o saida -ll

## E para rodar os testes

./run_tests.sh

## Gramática utilizada

A -> id { Print( lexema ); } = E { Print( "= ^"); } ';'

E -> E + T { Print( "+"); }
   | E - T { Print( "-"); }
   | T
   
T -> T * F { Print( "*"); }
   | T / F { Print( "/"); }
   | H

H -> H ^ F { Print( "power #"); }
   | H { Print( "fat #"); }
   | F
   
F -> id { Print(lexema + "@"); }
| num { Print( lexema ); }
| ( E )


REMOÇÃO DA RECURSIVIDADE ===================

A -> id { Print( lexema ); } = E { Print( "= ^"); } ';'
   
E -> T E'

E' -> + T { Print( "+"); } E'
	| - T { Print( "-"); } E'
	| ε   
   
T -> H T'


T' -> * H { Print( "*"); } T'
   | / H { Print( "/"); } T'
   | ε
   
H -> F H'   

H' -> ^ F { Print( "power #"); } H'
   | F { Print( "fat #"); } H'
   | ε
   
F -> id { Print(lexema + "@"); }
| num { Print( lexema ); }
| ( E )

