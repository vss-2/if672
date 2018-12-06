#include <iostream>
#include <stdio.h>
#include <algorithm>

using namespace std;

int K, Ncount, P, W, zerador, i, j, quantidadeUsada = 0;

struct Item {
    int Preco, Peso;
};

int main(){
    int N = 0;
    scanf("%i %i", &N, &K);

    // [Numero de itens][peso]
    int tabelaKnapsack[N][K] = { 0 };
    Item itens[N]; int printresposta[N] = { 0 };

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
        for (j = 1; j < K; j++){
                /*tabelaKnapsack[W][i] = tabelaKnapsack[W][i-1];
                if(itens[i].Peso >= j){
                   tabelaKnapsack[i][j] = max(tabelaKnapsack[i][j], tabelaKnapsack[i-1][j - itens[i].Peso] + itens[i].Preco);
                */
                //cout << "peso de itens: " << itens[i-1].Peso << " peso j: " << j << endl;
                if (itens[i-1].Peso <= j){
                    tabelaKnapsack[i][j] = max(tabelaKnapsack[i-1][j], tabelaKnapsack[i-1][j - itens[i-1].Peso] + itens[i-1].Preco);
                    //cout << "inseri " << tabelaKnapsack[i][j] << " " << endl;
                }
            }
        }

    printf("%i", tabelaKnapsack[N-2][K-2]);

    int resposta = tabelaKnapsack[N-2][K-2];

    quantidadeUsada = 0;

    for(zerador = N; zerador > 0 && resposta > 0; zerador--){
        if(resposta == tabelaKnapsack[zerador - 1][K]){
            continue;
        } else {
            printresposta[zerador - 1]; // Array de pesos
            quantidadeUsada++;
        }
    }
    // sort(printresposta[0], printresposta[N-1]);

    zerador = 0;
    while(zerador < quantidadeUsada){
        if (zerador+1 < quantidadeUsada){
            printf("%i ", tabelaKnapsack[zerador]);
        } else {
            printf("%i\n", tabelaKnapsack[zerador]);
        }
        zerador++;
    }
    return 0;
}
