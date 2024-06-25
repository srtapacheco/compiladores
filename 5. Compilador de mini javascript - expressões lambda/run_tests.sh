#!/bin/bash

# Função para normalizar a saída
normalize_output() {
    echo "$1" | tr -d '[:space:]'
}

# Função para extrair a parte relevante do output
extract_relevant_output() {
    echo "$1" | sed -n '/=== Console ===/,$p'
}

# Função para rodar um único teste
run_test() {
    local input="$1"
    local expected_output="$2"
    local index="$3"
    local n

    s=$(echo "$input" | ./saida 2>/dev/null)
    if [ -z "$s" ]; then
        echo "Teste $((index+1)) falhou (saída vazia de ./saida)."
        echo # Linha em branco
        return 1
    fi

    

    echo "$s" > codigo

    # Step 3: Feed intermediate output to interpretador
    output=$(echo "$s" | ./mdp/interpretador 2>/dev/null)
    if [ -z "$output" ]; then
        echo "Teste $((index+1)) falhou.."
        return 1
    fi
    
    # Extrair a parte relevante da saída do programa
    relevant_output=$(extract_relevant_output "$output")
    normalized_output=$(normalize_output "$output")
    normalized_expected_output=$(normalize_output "$expected_output")
    
    if [ "$normalized_output" == "$normalized_expected_output" ]; then
        #echo "Teste $((index+1)) passou."
        return 0
    else
        echo "Teste $((index+1)) falhou (saída diferente do esperado)."
        echo # Linha em branco
        echo "Entrada: 
$input"
        echo
        echo "     Saída esperada: $expected_output"
        echo "  Saída do programa: $output"
        return 1
    fi
}

# Entradas e saídas esperadas
declare -a inputs=(
"let i;
for( i = 0; i < 10; i++ ) {}"

"let o = {
  campo: 'aba',
  pi: 31415.0 / 10000.0,
  obj: { g: 56 }
};
{
  let b = { s:o };
  0 asm{.};
}"

"function log( msg, i ) {
  msg asm{println # undefined};
}

let console = { log: log, teste : [ 'aba', 'cate' ] };

console.log( [1, 2, 3] );
console.log( console.teste );"

"function log( msg ) {
  msg asm{println # undefined};
}

function criaObj() {
  return { a : [ {}, { teste: 1 }, c=24*8+1 ], b: 'nome', log: x => print(x) };
}

let obj = [];
let c;
{ obj = criaObj();
let c = [];

log( obj );
log( obj.a );
log( obj.a[obj.a[1].teste+1] );
}"

"let par = function( n ) {
  if( n % 2 == 0 )
    return true;
  else
    return false;
};

let a = par( 4 );"

"function log( msg ) {
  msg asm{println # undefined};
}

function map( a, f ) {
  let res = [];

  forEach( a, (x,j) => (res[j] = f(x)) );

  return res;
}

function forEach( array, funcao ) {
  for( let i = 0; i < array.size; i = i + 1 )
    funcao( array[i], i );
}

let a = [ 1, 2, 3, 4 ];
log( map( a, x => x*x + 1 ) );"



"function log( msg ) {
  msg asm{println # undefined};
}

function invert( a ) {
  let res = [];

  for( let i = 0; i < a.size; i = i + 1 )
    res[a.size-i-1] = a[i];

  return res;
}

function reduce( a, f, x ) {
  for( let i = 0; i < a.size; i = i + 1 ) 
    x = f( a[i], x, i );

  return x;
}

let a = [1, 2, 3, 4, 5];

log( reduce( a, (x,y) => x + y, 0 ) );

let b = [ x => 2*x, x => x + 1 ];

let pipe = (af, x) => reduce( af, (f,x) => f(x), x );

log( pipe( b, 9 ) );
log( pipe( invert( b ), 9 ) );"

"function criaPessoa( nome, sobrenome ) {
  return { nome: nome, sobrenome: sobrenome, nomeCompleto : pessoa => pessoa.nome + ' ' + pessoa.sobrenome };
}

function log( msg ) {
  msg asm{println # undefined};
}

let p = criaPessoa( 'Maria', 'da Silva' );

log( p.nomeCompleto( p ) );"

"function log( msg ) {
  msg asm{println # undefined};
}

function mdc( a = 36, b = 48 ) {
  if( b == 0 )
    return a;
  else
    return mdc( b, a%b );
}

log( mdc() );
log( mdc( 18 ) );
log( mdc( 15, 25 ) );"

"function log( msg ) {
  msg asm{println # undefined};
}

function imprimeMdc( a = 36, b = 48, print = m => log( 'Saida: ' + m )  ) {
  if( b == 0 )
    print( a );
  else
    imprimeMdc( b, a%b, print );
}

imprimeMdc( 24, 18 );
imprimeMdc( 8, 4, log );"

"let a = x => y;
{
  a( 9 );
  return 0;
}"

"let a, f = x => { a = x; return y => a*(y + 1.01); };
let b = f(9);
let c = b(7);
let d = f( 8.1 )( 7.1 );"

"let f = x => y => x*y;
let b = f(9);
let c = b(7);
let d = f( 8.1 )( 7.1 );"

"let f = (x,a=y=>9) => (y,b) => y;
let b = f(9);
let c = b(7);
let d = f( 8.1 )( 7.1 );"


"let a, c;
let b, d;
a = [ 2, 3, (b={}).j = 0 ];
c = [ 2, 3, (d={ k : a[1] }).j = 0 ];"

)

declare -a expected_outputs=(

"=== Console ===
=== Vars ===
|{ i: 10; undefined: undefined; }|
=== Pilha ==="

"=== Console ===
=== Vars ===
|{ o: { campo: aba; obj: { g: 56; }; pi: 3.1415; }; undefined: undefined; }|
|{ b: { s: { campo: aba; obj: { g: 56; }; pi: 3.1415; }; }; }|
=== Pilha ===
|0|"


"=== Console ===
[ 0: 1; 1: 2; 2: 3; ]
[ 0: aba; 1: cate; ]
=== Vars ===
|{ console: { log: { &funcao: ##; }; teste: [ 0: aba; 1: cate; ]; }; log: { &funcao: ##; }; undefined: undefined; }|
=== Pilha ==="

"=== Console ===
{ a: [ 0: { }; 1: { teste: 1; }; 2: 193; ]; b: nome; log: { &funcao: ##; }; }
[ 0: { }; 1: { teste: 1; }; 2: 193; ]
193
=== Vars ===
|{ c: 193; criaObj: { &funcao: ##; }; log: { &funcao: ##; }; obj: { a: [ 0: { }; 1: { teste: 1; }; 2: 193; ]; b: nome; log: { &funcao: ##; }; }; undefined: undefined; }|
=== Pilha ===
"

"=== Console ===
=== Vars ===
|{ a: true; par: { &funcao: ##; }; undefined: undefined; }|
=== Pilha ==="

"=== Console ===
[ 0: 2; 1: 5; 2: 10; 3: 17; ]
=== Vars ===
|{ a: [ 0: 1; 1: 2; 2: 3; 3: 4; ]; forEach: { &funcao: ##; }; log: { &funcao: ##; }; map: { &funcao: ##; }; undefined: undefined; }|
=== Pilha ==="


"=== Console ===
15
19
20
=== Vars ===
|{ a: [ 0: 1; 1: 2; 2: 3; 3: 4; 4: 5; ]; b: [ 0: { &funcao: ##; }; 1: { &funcao: ##; }; ]; invert: { &funcao: ##; }; log: { &funcao: ##; }; pipe: { &funcao: ##; }; reduce: { &funcao: ##; }; undefined: undefined; }|
=== Pilha ===
"


"=== Console ===
Maria da Silva
=== Vars ===
|{ criaPessoa: { &funcao: ##; }; log: { &funcao: ##; }; p: { nome: Maria; nomeCompleto: { &funcao: ##; }; sobrenome: da Silva; }; undefined: undefined; }|
=== Pilha ==="

"=== Console ===
12
6
5
=== Vars ===
|{ log: { &funcao: ##; }; mdc: { &funcao: ##; }; undefined: undefined; }|
=== Pilha ==="


"=== Console ===
Saida: 6
4
=== Vars ===
|{ imprimeMdc: { &funcao: ##; }; log: { &funcao: ##; }; undefined: undefined; }|
=== Pilha ==="


"Erro: Não é permitido 'return' fora de funções.
=== Console ===
=== Vars ===
|{ undefined: undefined; }|
=== Pilha ==="


"=== Console ===
=== Vars ===
|{ a: 8.1; b: { &funcao: ##; }; c: 72.09; d: 65.691; f: { &funcao: ##; }; undefined: undefined; }|
=== Pilha ==="



"== Console ===
=== Erro: Variável não declarada: x ===
=== Instrução: 53 ===
=== Vars ===
|{ b: { &funcao: ##; }; c: undefined; f: { &funcao: ##; }; undefined: undefined; }|
|{ &retorno: ##; arguments: [ 0: 7; ]; y: 7; }|
=== Pilha ===
|c|
"

"=== Console ===
=== Vars ===
|{ b: { &funcao: ##; }; c: 7; d: 7.1; f: { &funcao: ##; }; undefined: undefined; }|
=== Pilha ==="

"=== Console ===
=== Vars ===
|{ a: [ 0: 2; 1: 3; 2: 0; ]; b: { j: 0; }; c: [ 0: 2; 1: 3; 2: 0; ]; d: { j: 0; k: 3; }; undefined: undefined; }|
=== Pilha ==="

)

if [ ${#inputs[@]} -ne ${#expected_outputs[@]} ]; then
    echo "Número de entradas não é igual ao número de saídas esperadas."
    exit 1
fi

# Contador de testes que passaram
passed_tests=0

# Loop para rodar todos os testes
for ((i=0; i<${#inputs[@]}; i++)); do
    if run_test "${inputs[i]}" "${expected_outputs[i]}" "$i"; then
        passed_tests=$((passed_tests + 1))
    fi
done

# Resultado final
total_tests=${#inputs[@]}
echo "+------------------------------+"
echo "| $passed_tests tests run / $total_tests test passed |"

percentage=$(( passed_tests * 100 / $total_tests ))
echo "| $percentage% |"
echo "+------------------------------+"