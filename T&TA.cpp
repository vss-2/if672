#include <stdio.h>

using namespace std;

double prioridade = 0;
int N, M, mcount, X, Y, B, C, S, T;
int Bs[101];
int Cs[101];
int percorrer;

double W;

int resposta = 0;

struct no{
    int prioridade, valor;
    no *proximo;
};

struct filaPrioridade {
    no *inicio, *fim;
    int tamanho;
};

struct trupla {
    int indo, chegando, peso;
};

filaPrioridade *inserir(filaPrioridade *pq, trupla valores){
    no *auxiliar = new no();
    auxiliar->valor = valores->peso;
    auxiliar->proximo = NULL;
    if(pq->inicio == NULL){
        q->inicio = q->fim = aux;
        pq->tamanho = pq->tamanho + 1;
        return pq;
    } else {
        percorrer = 0;
        while (percorrer < pq->tamanho - 1){
            if (valores->peso > pq->no->proximo->prioridade){
                no temporario = new no();                       // Crio novo nó
                temporario->proximo = pq->no->proximo;          // temporario aponta para o resto da fila
                pq->no->proximo = temporario;                   // próximo aponta para o temporario
                return pq;
            }
            percorrer++;
        }
    }
}

/*
    Qual é a ideia?
    Inserir, temos dois casos, está vazio a fila ou não.
    No primeiro caso, somente preencher.
    No segundo caso, temos que percorrer a fila, até 
    encontrar o caso que a prioridade é maior.
*/

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

    scanf("%d",&prioridade);
    scanf("%i",&N);
    scanf("%i",&M);
    
    // Pega prioridades, e entrada N e M

    int Xs[M];
    int Ys[M];
    double Ws[M];
    int ladj[M];

    // Cria array para X e Y, de tamanho N
    // após isso recebe entradas dos arrays

    for (mcount = 0; mcount < N; mcount++){
        scanf("%i", &X[mmount]); // Origem
        scanf("%i", &Y[mmount]); // Destino
        // Tenho que fazer par ordenado (X,Y) e (Y,X)
        scanf("%i", &B); // Velocidade
        scanf("%i", &C); // Custo
        Ws[M] = (P*B + (1-P)*C)) / (B+C); // Peso
    }



    // Recebe origem e destino

    while(cin){
        scanf("%i", &S);
        scanf("%i", &T);
    }

    return 0;
}
