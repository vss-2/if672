#include <stdio.h>

using namespace std;

double prioridade = 0;
int N, M, mcount, X, Y, B, C, S, T;
int Bs[101];
int Cs[101];

int resposta = 0;

struct no{
    int prioridade, valor;
    no *proximo;
};

struct filaPrioridade {
    no *frente;
};


filaPrioridade *colocar(filaPrioridade *pq, int valor, int prioridade){
    
    return pq;
}


filaPrioridade *estavazia(filaPrioridade *pq){
    return
}

filaPrioridade *dotopo(filaPrioridade *pq){
    return
}

filaPrioridade *popar(*filaPrioridade *pq){
    return
}

bool dijkstra(int S, int T){
    filaPrioridade avisitar = new filaPrioridade();
    
    bool caminho = false;
    int pesoV, atual, filho, pesoAtual;

    avisitar.colocar(make_pair(minDist[S], S));

    pair <int, int> auxiliar;

    while (!avisitar.estavazia()){
        auxiliar = avisitar.dotopo(); avisitar.popar();
        atual = auxiliar.second();

        for (auto auxiliar : ){
            pesoV = auxiliar.first;
            filho = auxiliar.second;
            if (filho == ){
                caminho = true;
            }

            if(minDist[atual] + pesoV < minDist[filho]){
                minDist[filho] = minD[atual] + pesoV;
                avisitar.colocar(make_pair(minDist[filho], filho));
            }
        }
    
    return caminho;
}

int main(){

    std::ios

    scanf("%d",&prioridade);
    scanf("%i",&N);
    scanf("%i",&M);
    
    //Pega prioridades, e entrada N e M

    int Xs[M];
    int Ys[M];
    int ladj[M];

    //Cria array para X e Y, de tamanho N
    //após isso recebe entradas dos arrays

    for (mcount = 0; mcount < N; mcount++){
        scanf("%i", &X[mmount]);
        scanf("%i", &Y[mmount]);
        scanf("%i", &B[mmount]);
        scanf("%i", &C[mmount]);
    }

    double W = (P*B + (1-P)*C)) / (B+C);

    //Recebe origem e destino

    while(cin){
        scanf("%i", &S);
        scanf("%i", &T);
    }

    return 0;
}
