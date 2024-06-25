#!/bin/bash

normalize_output() {
    echo "$1" | tr -d '[:space:]'
}


declare -a inputs=(
    "print - 2 + 3*4.1;"
    "print \"\"\"hello, \" + \"world\" + \"!\\\"\";"
    "a = \"hello, \"; b = a + \"world\" + \"!\"; print b;"
    "a = 3.1 * 4 - 0.1; b = (a - 1)*(a + 1); print -b;"
    "aba = \"aba\"; cate = \"cate\"; x1 = 10; y1 = 3.14; cc = aba + cate + \"\\\\\" + aba + cate; d = cc + cc; d = 1.0 / x1 + y1 - 0 * x1 * 2;"
    "__ = 2; ___ = 1.1; ___ = __ + __ * ___; print __;"
    "x = 1.3; a1 = 2/((x+1)*(x-1)); b1 = max( a1 * a1, x ); print a1; print x; print b1;"
    "a = -8!; b = (2 * 2 + 1)!/3!; print b! / -a ^ 2;"
    "a = 2 ^ 9 ^ 0.5; b = 3.1 * a ^ a ^ (1/3!) + 1; print -b ^ 2!;"
    "a = --( - 4 - 2 + 10 ); print +-+---a!;"
    "x = \"maior: \"; a = - 2.1; b = 3.1; print x + dtos( max( a, b ) );"
    "x = 1; y = \"1\"; z = x + y;"
    "x = 1; y = 2; a = mdc( x, y );"
    "b = (-8)!;"
    "a = 0; print a^(-0!);"
)

declare -a expected_outputs=(
    "0 2 - 3 4.1 * + print #"
    "\"\"\"hello, \" \"world\" + \"!\\\"\" + print #"
    "a \"hello, \" = ^ b a @ \"world\" + \"!\" + = ^ b @ print #"
    "a 3.1 4 * 0.1 - = ^ b a @ 1 - a @ 1 + * = ^ 0 b @ - print #"
    "aba \"aba\" = ^ cate \"cate\" = ^ x1 10 = ^ y1 3.14 = ^ cc aba @ cate @ + \"\\\\\" + aba @ + cate @ + = ^ d cc @ cc @ + = ^ d 1.0 x1 @ / y1 @ + 0 x1 @ * 2 * - = ^"
    "__ 2 = ^ ___ 1.1 = ^ ___ __ @ __ @ ___ @ * + = ^ __ @ print #"
    "x 1.3 = ^ a1 2 x @ 1 + x @ 1 - * / = ^ b1 a1 @ a1 @ * x @ max # = ^ a1 @ print # x @ print # b1 @ print #"
    "a 0 8 fat # - = ^ b 2 2 * 1 + fat # 3 fat # / = ^ b @ fat # 0 a @ 2 power # - / print #"
    "a 2 9 0.5 power # power # = ^ b 3.1 a @ a @ 1 3 fat # / power # power # * 1 + = ^ 0 b @ 2 fat # power # - print #"
    "a 0 0 0 4 - 2 - 10 + - - = ^ 0 0 0 0 a @ fat # - - - - print #"
    "x \"maior: \" = ^ a 0 2.1 - = ^ b 3.1 = ^ x @ a @ b @ max # dtos # + print #"
    "x 1 = ^ y \"1\" = ^ z x @ y @ + = ^"
    "x 1 = ^ y 2 = ^ a x @ y @ mdc # = ^"
    "b 0 8 - fat # = ^"
    "a 0 = ^ a @ 0 0 fat # - power # print #"
)


if [ ${#inputs[@]} -ne ${#expected_outputs[@]} ]; then
    echo "Número de entradas não é igual ao número de saídas esperadas."
    exit 1
fi


passed_tests=0


for ((i=0; i<${#inputs[@]}; i++)); do
    input="${inputs[i]}"
    expected_output="${expected_outputs[i]}"

   
    output=$(echo "$input" | ./saida)
    normalized_output=$(normalize_output "$output")
    normalized_expected_output=$(normalize_output "$expected_output")

    
    if [ "$normalized_output" == "$normalized_expected_output" ]; then
        echo "Teste $((i+1)) passou."
        passed_tests=$((passed_tests + 1))
    else
        echo "Teste $((i+1)) falhou:"
        echo "  Entrada: $input"
        echo "  Saída esperada: $expected_output"
        echo "  Saída do programa: $output"
        echo "  Normalizada esperada: $normalized_expected_output"
        echo "  Normalizada obtida: $normalized_output"
    fi
done


total_tests=${#inputs[@]}
echo "+------------------------------+"
echo "| $total_tests tests run/ $passed_tests test passed |"
echo "+------------------------------+"
