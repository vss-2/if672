#include <stdio.h>
#include <stdlib.h>

struct Subconjunto {
    int pai, rank, valor;
};

// Funcao para encontrar um elemento i (usando tecnica de compressao)
int buscar(int buscado){
    if (buscado.pai != buscado){
        buscado.pai = buscar(buscado.pai);
    }
    return buscado.pai;
}

// Funcao que une dois conjuntos de X e Y
int unir(struct Subconjunto subconjuntos[], int x, int y){
    int raizX = buscar(subconjuntos, x);
    int raizY = buscar(subconjuntos, y);

    // Une arvores de meor rank sob a arvore de maior rank (uniao por rank)

    if (subsconjuntos[raizX].rank < subconjuntos[raizY].rank){
        subconjuntos[raizX].pai = raizY;
    } else if (subconjuntos[raizX].rank > subconjuntos[raizY].rank){
        subconjuntos[raizY].pai = raizX;
    } else { 
        // Se o rank for igual, entao faca uma ser raiz e incremente +1 a outra
        subconjuntos[raizY].pai = raizX;
        subconjuntos[raizX].rank++;
    }
}

int main(){
    int K, N, M, Q, A, B; // Numero de casos, tamanho do lab, paredes internas rem, pares consultadas
    int W[M];
    int buscado1, buscado2;
    scanf("%i",&K);
    int a, b, c;
    for (a = 0; a < K; a++) {
        scanf("%i %i %i", &N, &M, &Q);
        for (b = 0; b < M; b++){
            scanf("%i", &W[M]);
        }
        for (c = 0; c < Q; c++){
            scanf("%i %i", &A, &B);
            buscado1 = buscar(A);
            buscado2 = buscar(A);
            if (buscado1 != buscado2){
                printf("%i.%i 0\n", a, c);
            } else {
                printf("%i.%i 1\n", a, c);
            }
        }
    }
}
