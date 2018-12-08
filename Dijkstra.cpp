#include <iostream>
#include <stdio.h>
#include <climits>
#define infinito INT_MAX

using namespace std;

int dobrador, extrator, organizar, prioridade, N, M, infinitador, percorredor, pegaMenor, W, mContador, X, Y, B, C, S, T;
int *resposta;

struct Vertice {
    int origem, destino;
    double ponderado;
    Vertice *proximo;

    Vertice(int dest, double peso){
        destino = dest;
        ponderado = peso;
    }
};

struct minHeap{
    int *heap;
    int valor;
    int tamanhoHeap;

    minHeap(int var){
        valor = var;
        heap = new int [valor];
        tamanhoHeap = 0;
    }

    void aumentarHeap(){
        // Se veio para cá,
        // signifca que faltou
        // espaço na heap

        dobrador = 0;
        int *temp = heap;
        valor = valor * 2;
        heap = new int [valor];
        while(dobrador < valor){
            heap[dobrador] = temp[dobrador];
        }
    }

    void inserirHeap(int inserido){
        if(valor == tamanhoHeap){
            aumentarHeap();
        }
    }

    void heapify(int arrumar){
        int meio = arrumar;
        int esq = 2 * arrumar + 1;
        int dir = 2 * arrumar + 2;

        if(esq < tamanhoHeap && heap[esq] <= heap[meio]){
            meio = esq;
        }

        if(dir < tamanhoHeap && heap[dir] <= heap[meio]){
            meio = dir;
        }

        if(meio != arrumar){
            swap(heap[meio], heap[arrumar]);
            heapify(meio);
        }

    }

    int extrairHeap(){
        extrator = heap[0];
        swap(heap[0], heap[tamanhoHeap - 1]);
        tamanhoHeap--;
        heapify(0);
        return extrator;
    }

    void organizarCima(){
        // Quando inserido um valor
        // organizo conforme ele deveria estar
        // isso é baseado no principio de que
        // a heap já está organizada antes dele entrar
        organizar = tamanhoHeap - 1;
        while(organizar > 0 && heap[organizar] <= heap[(organizar - 1)/2]){
            swap(heap[organizar], heap[(organizar - 1)/2]);
            organizar = (organizar - 1)/2;
        }
    }
};

struct listAdj{
    Vertice *primeiro;
    Vertice *fim;
    int tamanhoLista;

    listAdj(){
        primeiro = new Vertice(0, 0);
        fim = primeiro;
        tamanhoLista = 0;
    }

    void inserir(int destino, double peso){
        Vertice *criado = new Vertice(destino, peso);
        criado->proximo = fim->proximo;
        fim->proximo = criado;
        fim = criado;
        tamanhoLista++;
    }
};

struct Grafo{
    listAdj *ligacoes;
    int tamanhoGrafo;
    minHeap *caminhos;
    double *pesos;
    int *origem;

    Grafo(int tam){
        tamanhoGrafo = tam;
        ligacoes = new listAdj[tamanhoGrafo];
        pesos = new double[tamanhoGrafo];
        origem = new int[tamanhoGrafo];
    }

    void inserirCaminho(int origem, int destino, double peso){
        ligacoes[origem].inserir(destino, peso);
    }

    int *dijkstra(){
        while(infinitador < tamanhoGrafo){
            pesos[infinitador] = infinito;
            origem[infinitador] = -1;
            infinitador++;

            // Preencho todo mundo com infinito
            // e a sua origem como nada (-1)
        }

        // Começando pelo 0, dist = 0
        // e o pai dele é ele mesmo
        pesos[0] = 0;
        origem[0] = 0;

        caminhos = new minHeap(tamanhoGrafo);

        percorredor = 0;
        while(percorredor < tamanhoGrafo){
            caminhos->inserirHeap(percorredor);
            pegaMenor = caminhos->extrairHeap();
            Vertice *e = ligacoes[pegaMenor].primeiro->proximo;

            while(e != nullptr){
                // e não pode ser vazio
                if(pesos[e->destino] > pesos[pegaMenor] + e->ponderado){
                    pesos[e->destino] = pesos[pegaMenor] + e->ponderado;
                    origem[e->destino] = pegaMenor;
                }
                e = e->proximo;
            }
            percorredor++;
        }
        return origem;
    }
};

void printarCaminho(int pai[], int origem){
    if(pai[origem] == -1){
        return;
    }
    printarCaminho(pai, pai[origem]);
    printf("%i ", origem);
}

int main(){
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

    Grafo *mapa = new Grafo(N);
    // Grafo com os N elementos (vértices)

    mContador = 0;
    while(mContador < M) {
        scanf("%i %i %i %i", &X, &Y, &B, &C);
        // Origem e destino, e dados para cálculo do peso

        W = (((prioridade * B + (1 - prioridade) * C)) / (B + C));
        // Peso

        mapa->inserirCaminho(X, Y, W);
        mapa->inserirCaminho(Y, X, W);

        mContador++;
    }

        resposta = mapa->dijkstra();

        while(cin){
            scanf("%i %i", &S, &T);
            while(S != T){
                printf("%i ", S);
                S = resposta[S];
            }
            printarCaminho(resposta, S);
        }
    return 0;
}
