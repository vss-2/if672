#include <iostream>
#include <stdio.h>
#include <vector>
#include <queue>

int INF = 999999;

using namespace std;

double prioridade = 0;
int N, M, mcount, X, Y, B, C, S, T;
double pai[20000];

typedef pair<double,double> ii;
typedef vector<ii> vii;
priority_queue <ii,vii,greater<ii>> tovisit;
typedef vector<double> vi;
double desgraca[20000];
int minD[20000];
vii adj[20000];
int t, v, e, a, b, w, infi;

//-------------- Ze Dijkstra ----------------//


bool dijkstra(int S, int T){
    bool way =false;
    double edgeweight,weightTillNow;
    int current, child;
    ii aux;
    tovisit.push(make_pair(minD[S],S));

    while(!tovisit.empty()){
        aux=tovisit.top(); tovisit.pop();
        current=aux.second;

            for(auto aux : adj[current]){
                edgeweight=aux.first;
                child=aux.second;
                if(child==T)
                    way=true;
                if(minD[current]+edgeweight<minD[child]){
                    desgraca[child] = current;
                    cout << "Opa achei o resultado hein colega: " << current << endl;
                    minD[child]=minD[current]+edgeweight;
                    tovisit.push(make_pair(minD[child],child));
                }
            }
    }
    cout << minD[T] << endl;
    return way;
}
//-------------- Ze Dijkstra ----------------//

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
  cout << atual->ligacoes[posicao].origem << " " << atual->ligacoes[posicao].destino << "       " << atual->ligacoes[posicao].peso << " \n";
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

    for(int j=0;j<N;j++) {
        adj[j].clear();
    }


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
