#include <iostream>
#include <stdio.h>

using namespace std;

double prioridade = 0;
int N, M, mcount, X, Y, B, C, S, T;

struct no{  
  int origem, destino;
  double peso;
};

struct heap{
  no ligacoes[5000];
};

no *montarNo(no *nov, int ori, int dest, double pes){
  nov->origem = ori;
  nov->destino = dest;
  nov->peso = pes;
  return nov;
}

heap *montarHeap(heap *atual, no botar, int posicao){
  atual->ligacoes[posicao] = botar;
  return atual;
}

heap *printarNo(heap *atual, int posicao){
  cout << atual->ligacoes[posicao].origem << " " << atual->ligacoes[posicao].destino << " " << atual->ligacoes[posicao].peso << " \n";
  return atual;
}

int main() {
    /*
        ------------------- Proposito do Main --------------------
        1. Ele recebe prioridade do cliente, quantidade de
           vértices e arestas, as quais irá receber em seguida
        2. Logo após recebe ligações entre vértices,
           com velocidade, custo e faz o cálculo do peso
        3. Marca o caminho do par ordenado numa lista
        ---------------------------------------------------------
    */

    scanf("%lf",&prioridade);
    scanf("%d",&N);
    scanf("%d",&M);

    // Pega prioridades, e entrada N e M

    int Xs[M];
    int Ys[M];
    double Ws[M];
    int ladj[2][M];

    heap *menorcaminho = new heap();
    no *novo = new no();

    for (mcount = 0; mcount < M; mcount++){
        scanf("%i", &Xs[mcount]); // Origem
        scanf("%i", &Ys[mcount]); // Destino

        ladj[0][M] = 1;  // Marco na lista de adjacencia
        ladj[1][M] = 1;  // Tenho que marcar (X,Y) e (Y,X)

        scanf("%i", &B); // Velocidade
        scanf("%i", &C); // Custo
        Ws[mcount] = (((prioridade*B + (1-prioridade)*C))/(B+C)); // Peso
        
        //printf("Peso calculado: %.2f \n",Ws[mcount]);

        novo = montarNo(novo, Xs[mcount], Ys[mcount], Ws[mcount]);

        menorcaminho = montarHeap(menorcaminho, *novo, mcount); 

        printarNo(menorcaminho, mcount);

        //cout << menorcaminho->ligacoes[mcount] << " \n" << " \n" << menorcaminho[mcount]->destino << " \n" << menorcaminho[mcount]->peso << " \n";

        //cout << novo->origem << " \n" << novo->destino << " \n" << novo->peso << " \n";
    }

    // Recebe origem e destino

    while(cin){
        scanf("%i", &S);
        scanf("%i", &T);
    }
}
