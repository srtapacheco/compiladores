# Analisador Léxico para Tokens Específicos
Este projeto inclui um analisador léxico desenvolvido com a ferramenta LEX. O analisador é capaz de identificar diversos tipos de tokens em um texto-fonte, como identificadores, números inteiros e de ponto flutuante, palavras-chave (insensíveis a maiúsculas e minúsculas), operadores, comentários e strings.

## Compilação e Execução
Para compilar o analisador léxico, execute o seguinte comando no diretório do projeto:

lex scan.lex

g++ -Wall -std=c++17 main.cc -lfl
