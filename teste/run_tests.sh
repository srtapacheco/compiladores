#!/bin/bash

# Compila o lexer
lex tradutor.l
g++ lex.yy.c -o lexer -ll

# Inicializa contadores
PASSED=0
TEST_NUM=0

# Lê o arquivo de testes
while IFS= read -r line1 && IFS= read -r line2; do
    let TEST_NUM+=1
    # Armazena entrada e saída esperada
    INPUT="$line1"
    EXPECTED_OUTPUT="$line2"

    # Executa o lexer e compara a saída
    echo "$INPUT" | ./lexer > "test_output.txt"
    echo "$EXPECTED_OUTPUT" > "expected_output.txt"
    if diff -q "test_output.txt" "expected_output.txt" > /dev/null; then
        echo "Test $TEST_NUM passed."
        let PASSED+=1
    else
        echo "Test $TEST_NUM failed."
        echo "Expected Output:"
        cat "expected_output.txt"
        echo "Actual Output:"
        cat "test_output.txt"
    fi
done < "all_tests.txt"

# Mostra sumário dos resultados
echo "$PASSED out of $TEST_NUM tests passed."

# Limpa arquivos gerados
rm lexer lex.yy.c test_output.txt expected_output.txt
