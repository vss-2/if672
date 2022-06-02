# Anotações

### Busca binária
Consiste numa técnica utilizada em estruturas como array para verificar rapidamente, em O(log n), se um elemento está presente. Pode ser adaptada para situações como: encontrar a primeira ocorrência de um elemento particular, encontrar onde se posicionaria um elemento na lista, entre outros. Pode ser implementada recursivamente ou iterativamente.

### Two pointers (dois ponteiros)
É uma técnica de reduzir uso de memória através da criação de 2 variáveis que estão iniciam em posições opostas no array e vão se movimentando em direção ao centro. Essa ferramenta pode ser usada, por exemplo, para descobrir se a soma de dois números quaisquer de um array gera um número objetivo, ou quais todas as somas geram o número objetivo; em grafos, pode-se verificar se um grafo é cíclico (dar mais velocidade/incremento a um dos ponteiros e ver se ele atinge o outro). Numa questão, é possível ordenar um vetor ao mesmo tempo que aplica uma operação matemática de quadrado nele.

# Ávore Trie
Árvores trie são uma estrutura de dados que serve, em sua maioria dos casos, para armazenar caracteres que são comuns a várias palavras distintas com um "radical" em comum. Por exemplo, ovulo e ovos tem em comum "ov" e podem ser armazenados em uma árvore trie para otimizar a busca. Ex:
<br>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;#
<br>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;/
<br>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;o
<br>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;/
<br>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;v
<br>&nbsp;&nbsp;&nbsp;&nbsp;/ \\
<br>&nbsp;&nbsp;&nbsp;u&nbsp;&nbsp;&nbsp;o
<br>&nbsp;&nbsp;/&nbsp;&nbsp;&nbsp;/
<br>&nbsp;&nbsp;l&nbsp;&nbsp;&nbsp;s
<br>&nbsp;/&nbsp;&nbsp;&nbsp;*
<br>o
<br>*
<br>
Obs: # é a raiz da árvore e * é o fim de uma palavra

# Janela deslizante
É uma técnica utilizada quando estamos interessados em identificar cadeias de caracteres ou outros tipos de subconjuntos e suas particularidades: se os elementos estão na mesma ordem, se os elementos são permutações (anagramas), encontrar todos os anagramas, etc. Uma evolução deste método é o Rabin-Karp, onde, além da janela deslizante, é aplicada uma função de hash na janela para evitar a checagem elemento-por-elemento, algo que consome muito tempo.

# Rabin-Karp
Podemos usar Rabin Karp para descobrir a maior sequência de elementos em ordem. Normalmente, o custo computacional é de O(m-n+1), mas num caso de uma função de hash ruim que potencialize o número de colisões (espúrias), temos O(m*n). Uma forma de melhorar a função de hash é multiplicar cada número da cadeia por 10^n, onde n é a posição na cadeia.

# Soma de 2
Muitas vezes, as questões pedem para você trabalhar com 2 elementos para verificar se há um terceiro no conjunto, ou realizar operações matemáticas entre eles. Por exemplo: dado um vetor contendo N elementos e um valor K, se você quiser remover os pares que juntos somam K, pode fazer isso salvando todas os ocorrências no vetor e perguntando se a subtração dele - K está no vetor, se sim remover o elemento.

# Backtracking
Backtracking é uma técnica que consiste em explorar uma solução até onde for possível e, quando perceber que não dá mais, voltar atrás para tentar outra solução diferente. Backtracking está inerentemente associado a uma árvore de estado de espaço, por exemplo, no problema das 8 rainhas usa-se o backtracking para avaliar se há conflito entre rainhas, se houve, aplica-se o backtracking até o estágio que não havia conflito. Comumente, o backtracking é implementado de forma recursiva, mas pode ser adaptado, por exemplo para uma método DFS (sendo que o propósito da DFS é percorrer todo, sem paradas até o fim). Para gerar todas as combinações de cadeias abrindo e fechando parênteses, pode-se usar o backtracking (combinacoes_parenteses.py).

# Operadores Bitwise
Algumas operações podem ser feitas a nível binário (normalmente quando realizar as mesmas utilizando inteiros seria custosa, ou quando o número em si não é completamente importante, mas sim algum dado extraído dele, ver aplicando_bitwise.py), por exemplo: divisão, multiplicação. São operadores bitwise em Python:
* & = AND
* ~ = NOT
* | = OR
* ^ = XOR
* y << x = Multiplicação: (y*(2**x))
* x >> y = Divisão com arredondamento para baixo (floor): (x // (2**y))