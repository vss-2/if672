#include <iostream>
#include <stdio.h>
#include <vector>
#include <climits>

#define INF INT_MAX;

using namespace std;

double prioridade = 0;
int N, M, mcount, X, Y, B, C, S, T;
double pai[20000];

struct listAdjacencia{
    pair<int, int> ES;
    struct listAdjacencia *proximo;
};

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


    scanf("%lf", &prioridade);
    scanf("%d", &N);
    scanf("%d", &M);

    // Pega prioridades, e entrada N e M
    // N = quantidade de nos na rede
    // M = quantidade de ligações entre nos
    
    listAdjacencia ladj[N] = new listAdjacencia();

    /*for(int j=0;j<N;j++) {
        adj[j].clear();
    }*/

    int Xs[M];
    int Ys[M];
    double Ws[M];
    int ladj[2][M];

    heap *menorcaminho = new heap();
    no *novo = new no();

    for (mcount = 0; mcount < M; mcount++){
        scanf("%i", &Xs[mcount]); // Origem
        scanf("%i", &Ys[mcount]); // Destino

        ladj[Xs[mcount]] = make_pair(Xs[mcount], Ys[mcount]);  // Marco na lista de adjacencia
        ladj[Ys[mcount]] = make_pair(Ys[mcount], Xs[mcount]);  // Tenho que marcar (X,Y) e (Y,X)

        scanf("%i", &B); // Velocidade
        scanf("%i", &C); // Custo
        Ws[mcount] = (((prioridade*B + (1-prioridade)*C))/(B+C)); // Peso

        //Ze
        adj[a].push_back(make_pair(Ws[mcount],Xs[mcount]));
        adj[b].push_back(make_pair(Ws[mcount],Ys[mcount]));

        novo = montarNo(novo, Xs[mcount], Ys[mcount], Ws[mcount]);

        menorcaminho = montarHeap(menorcaminho, *novo, mcount);

        printarNo(menorcaminho, mcount);

    }

    while(!tovisit.empty()){
        tovisit.pop();
    }

    for(int k=0;k<v;k++){//equivalent to memset??
        minD[k]=infi+1;
        //printf(" dto%d = %d",k,minD[k]);
    }

    minD[S]=0;

    // Recebe origem e destino

    while(cin){
        scanf("%i", &S);
        scanf("%i", &T);
        dijkstra(S, T);
    }
}
