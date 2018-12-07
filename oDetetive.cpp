#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

int Ncount, input1, input2, i, j, quantidadeUsada, zerador, contador, printer;

int main(){
  int N, K;
  scanf("%i %i", &N, &K);
  // Numero de itens e peso da sacola

  int tabelaKnapsack[N + 1][K + 1]; // Tabela N x K, tamanho expandido em 1 pra resposta
  int printResposta;                // No maximo, vai caber tudo

  // Vetor contendo os proximos pesos e precos
  vector<pair<int, pair<int,int> > > itens; 
  // Tive que criar essa aberração após ler errado a entrada, o segundo pair guarda a Preço e ordem de entrada

  while(Ncount < N){  // Recebendo as entradas
    scanf("%i %i", &input1, &input2);  
    // Essa desgraça de push e make me confundiu todo, vai assim mesmo
    // Peso e preco, eu confundi a entrada, inverti aqui

    itens.push_back(make_pair(input2, make_pair(input1,Ncount)));
    Ncount++;
  }

  // Organizando array, usando como base o peso, 
  // o objetivo é colocar na tabela corretamente
  //sort(itens.begin(), itens.end());

      for (i = 1; i <= N; i++){     // Nao começa pelo zero pois primeira linha e coluna é zerada
        for (j = 1; j <= K; j++){   // Tô ganhando N+K tempo, talkei?
            
            //cout << "peso de itens: " << itens[i-1].first << " peso j: " << j << endl;

            // Pegando os pesos e itens olhando se na linha anterior estão os mais valiosos
            if (itens[i-1].first <= j){
                tabelaKnapsack[i][j] = max(itens[i-1].second.first + tabelaKnapsack[i-1][j - itens[i-1].first], tabelaKnapsack[i-1][j]);
                //cout << "inseri " << tabelaKnapsack[i][j] << " " << endl;
            } else {
                tabelaKnapsack[i][j] = tabelaKnapsack[i-1][j];
            }
        }
    }

  printf("%i\n", tabelaKnapsack[N][K]); // Resposta do problema

  printResposta = tabelaKnapsack[N][K];

  contador = 0;

  string respostaOrdenada = "";

  for (zerador = N; zerador > 0 && printResposta > 0; zerador--){
    if (printResposta != tabelaKnapsack[zerador-1][K]){
      //printf("%i ", itens[zerador-1].second.second);
      respostaOrdenada = to_string(itens[zerador-1].second.second) + " " + respostaOrdenada;
      printResposta = printResposta - itens[zerador - 1].second.first;
      K = K - itens[zerador - 1].first;
      contador++;
    }
  }

    cout << respostaOrdenada << endl;

  return 0;
}
