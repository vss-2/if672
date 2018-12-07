#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

int Ncount, input1, input2, i, j, quantidadeUsada, zerador, contador;

struct precoEordem{
  int Preco, Ordem;
};

int main(){
  int N, K;
  scanf("%i %i", &N, &K);
  // Numero de itens e peso da sacola

  int tabelaKnapsack[N + 1][K + 1]; // Tabela N x K, tamanho expandido em 1 pra resposta
  int printResposta;                // No maximo, vai caber tudo

  // Vetor contendo os proximos pesos e precos
  vector<pair<int,int>> itens;

  while(Ncount < N){  // Recebendo as entradas
    scanf("%i %i", &input1, &input2);  
    // Essa desgraça de push e make me confundiu todo, vai assim mesmo
    itens.push_back(make_pair(input2, input1));
    Ncount++;
  }

  // Organizando array, usando como base o peso, 
  // o objetivo é colocar na tabela corretamente
  //sort(itens.begin(), itens.end()); Não é necessário, ignore

      for (i = 0; i <= N; i++){     // Nao começa pelo zero pois primeira linha e coluna é zerada
        for (j = 0; j <= K; j++){   // Tô ganhando N+K tempo, talkei?
            
            //cout << "peso de itens: " << itens[i-1].first << " peso j: " << j << endl;

            // Pegando os pesos e itens olhando se na linha anterior estão os mais valiosos
            if (i == 0 || j == 0){
              tabelaKnapsack[i][j] = 0;
            } else if (itens[i-1].first <= j){
                tabelaKnapsack[i][j] = max(itens[i-1].second + tabelaKnapsack[i-1][j - itens[i-1].first], tabelaKnapsack[i-1][j]);
                //cout << "inseri " << tabelaKnapsack[i][j] << " " << endl;
            } else {
                tabelaKnapsack[i][j] = tabelaKnapsack[i-1][j];
            }
        }
    }

  printf("%i\n", tabelaKnapsack[N][K]); // Resposta do problema

  printResposta = tabelaKnapsack[N][K];

  contador = 0;

  for (zerador = N; zerador > 0 && printResposta > 0; zerador--){
    if (printResposta == tabelaKnapsack[zerador-1][K]){
      continue;
    } else {
      printf("%i ", itens[zerador-1].first);
      printResposta = printResposta - itens[zerador - 1].second;
      K = K - itens[zerador - 1].first;
    }
  }

  return 0;
}
