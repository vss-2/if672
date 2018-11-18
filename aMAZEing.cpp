#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

struct Subconjunto {
  int pai, valor;
};

// Funcao para encontrar um elemento i (usando tecnica de compressao)
int buscar(struct Subconjunto buscado[], int i){
    if (buscado->pai != i && buscado->pai != -2){
        buscado->pai = buscar(buscado,buscado[i].pai);
    }
    return buscado->pai;
}

// Funcao que une dois conjuntos de X e Y
void unir(struct Subconjunto subconjuntos[], int x, int y){
    int raizX = buscar(subconjuntos, x);
    int raizY = buscar(subconjuntos, y);

    // Une arvores de meor rank sob a arvore de maior rank (uniao por rank)

    if (subconjuntos[raizX].rank < subconjuntos[raizY].rank){
        subconjuntos[raizX].pai = raizY;
    } else if (subconjuntos[raizX].rank > subconjuntos[raizY].rank){
        subconjuntos[raizY].pai = raizX;
    } else { 
        // Se o rank for igual, entao faca uma ser raiz e incremente +1 a outra
        subconjuntos[raizY].pai = raizX;
        subconjuntos[raizX].rank++;
    }
}

int K, N, M, Q, A, B; 
int W, valor1, valor2;
int a, b, c;
int sobrescrever, celulahorizontal, celulavertical, buscado1, buscado2, contador;

int main(){
    // Numero de casos, tamanho do lab, paredes internas rem, pares consultadas
    scanf("%i",&K);
    for (a = 0; a < K; a++) {
        scanf("%i %i %i", &N, &M, &Q);
        // N Tamanho NxN do labirinto
        // M Quantidade de paredes removidas
        // Q Quantidade de pares testados
        int Gama = (2*(N-1)) + 1;
        Subconjunto caminho[N];
        for (sobrescrever = 0; sobrescrever < N*N; sobrescrever++){
            caminho[sobrescrever].pai = sobrescrever;
            // Cada quadradinho é pai de si mesmo, e começa sendo assim
        }
        for (b = 0; b < M; b++){
            // Recebo paredes a serem removidas, tenho que unir o que elas separavam
            scanf("%i", &W); contador = 0; valor1 = 0; valor2 = 0;
            if (W % Gama > N - 2){ // Se der maior é pq é uma célula horizontal --W--
              for (celulahorizontal = W % Gama; celulahorizontal == W; celulahorizontal += N){
                contador++;
              }
              valor1 = N*contador; valor2 = valor1 + N;
            } else {
              // O valor é uma célula vertical
              for (celulavertical = W % Gama; celulavertical == W; celulavertical += Gama){
                contador++;
              }
              valor1 = (Gama * contador) - (2 * contador); valor2 = valor1 + 1;
            }
            cout << "Tenho que unir: " << valor1 << " " << valor2 << endl;
            //unir(caminho, W);
        }
        for (c = 0; c < Q; c++){
            scanf("%i %i", &A, &B);
            buscado1 = buscar(caminho, A);
            buscado2 = buscar(caminho, B);
            // Busco nos dois cantos se o valor pai é igual
            if (buscado1 != buscado2){
                printf("%i.%i 0\n", a, c);
            } else {
                printf("%i.%i 1\n", a, c);
            }
        }
    printf("\n");
    }
}
