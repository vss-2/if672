#include <iostream> 
#include <stdio.h>

using namespace std;

int N, K, Ncount, P, W, zerador, i, j, quantidadeUsada;

struct Item {
    int Preco, Peso;
};

int main(){
    scanf("%i %i", &N, &K);

    // [Numero de itens][peso]
    int tabelaKnapsack[N][K] = { 0 };
    int itens[N]; int printresposta[N] = { 0 };

    while (Ncount < N){
        scanf("%i %i", &itens[Ncount].Preco, &itens[Ncount].Peso);
        Ncount++;
    }

    zerador = 0;
    /*
    while(zerador < N){
        tabelaKnapsack[zerador][K] = 0;
        zerador++;
    }

    zerador = 0;
    while(zerador < K){
        tabelaKnapsack[N][zerador] = 0;
        zerador++;
    }

    // Zeradas as primeiras linhas e colunas da tabela
    */
    for (i = 1; i < N; i++){
        for (j = 1; j < W; j++){
            tabelaKnapsack[W][i] = tabelaKnapsack[W][i-1];
            if(itens[i].Peso <= j){
                tabelaKnapsack[i][j] = max(tabelaKnapsack[i][j], tabelaKnapsack[i-1][j - itens[i].Peso] + itens[i].Preco);
            }
        }
    }
    printf("%i", tabelaKnapsack[N-1][K-1]);

    int resposta = tabelaKnapsack[N-1][K-1];

    quantidadeUsada = 0;

    for(zerador = N; zerador < 0 && resposta > 0; zerador++){
        if(resposta == tabelaKnapsack[zerador - 1][K]){
            continue;
        } else {
            printresposta[zerador - 1]; // Array de pesos 
            quantidadeUsada++;
        }
    }

    printresposta.sort();

    zerador = 0;
    while(zerador < quantidadeUsada){
        if (zerador+1 < quantidadeUsada)
            printf("%i ", tabelaKnapsack[zerador]);
            zerador++;
        else 
            printf("%i\n", tabelaKnapsack[zerador]);
    }

    return 0;
}
