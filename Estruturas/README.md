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
