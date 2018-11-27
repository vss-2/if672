#include <stdio.h>
#include <iostream>

using namespace std;

String opcao;
int S, I, U, A;   // Inputs necessários para questão
int esq2, dir2, meio2, maior, contador;

int temp, bubblerUpper, esq, dir, meio, remover;  // Valores que uso na heap, 
                                                  // criados aqui pra não comprometer tempo de processamento

struct Heap {
    int* heap;
    int tamanho;
    int tamanho_heap;

    int retornaPai(int node){
        if (node == 0){
            return 0;
        } else {
            return (node - 1) / 2;
        }
    }

    int retornaEsq(int node){
        return (2 * node + 1);
    }

    int retornaDir(int node){
        return (2 * node + 2);
    }

    // Usado na MaxHeap
    void heapifyDown(int node){
        int esq = retornaEsq(node);
        int dir = retornaDir(node);
        int maior = node;

        if (esq < tamanho_heap && heap[esq] > heap[node]){
            maior = esq;
        }
        if (dir < tamanho_heap && heap[dir] > heap[maior]){
            maior = dir;
        }
        if (maior != node){
            swap(node, maior);
            heapifyDown(maior);
        }
    }

    void heapifyUp(int node){
        if (node > 0 && retornaPai(node) < heap[node]){
            swap(heap[node], heap[(node - 1)/2]);
            heapifyUp(heap[(node - 1)/2]);
        }
    }

    Heap(int inputTamanho){         // Construtor padrão
        tamanho = inputTamanho;
        heap = new int[tamanho];
        tamanho_heap = 0;
    }

    void dobrarEspacoHeap(){        // Duplica o espaço, caso heap fique cheia
        int* auxiliar = heap;
        tamanho = tamanho * 2;
        heap = new int[tamanho];
        for (temp = 0; temp < tamanho; temp++){
            heap[temp] = auxiliar[temp];
        }
    }

    void trocarValores(int* valor1, int* valor2){   // Troca valores inseridos
        int trocatemp = *valor1;
        *valor1 = *valor2;
        *valor2 = trocatemp;
    }

    void bubble_Up(){                   // Faz valores "subirem"
        bubblerUpper = tamanho_heap - 1;
        while (bubblerUpper > 0 && heap[bubblerUpper] <= heap[(bubblerUpper-1)/2]){
            trocarValores(&heap[bubblerUpper], &heap[(bubblerUpper-1)/2]);
        }
    }

    void inserirHeap(int inserido){     // Insere valores na heap
        if (tamanho_heap){
            dobrarEspacoHeap();
        }
        heap[tamanho_heap] = inserido;
        tamanho_heap++;
        bubble_Up();
    }

    void heapify(int arrepiado){        // Arruma a heap a partir de um dado valor
        meio = arrepiado;
        esq = 2*arrepiado + 1;
        dir = 2*arrepiado + 2;

        if (esq < tamanho_heap && heap[esq] <= heap[meio]){
            meio = esq;
        }

        if (dir < tamanho_heap && heap[dir] <= heap[meio]){
            meio = dir;
        }

        if (meio != arrepiado){
            trocarValores(&heap[arrepiado], &heap[tamanho_heap - 1]);
            heapify(meio);
        }
    }

    int removerdaHeap(){ // Retorna o valor excluido
        if (!estaVazia){
            remover = heap[0];
            trocarValores(&heap[0], &heap[tamanho_heap -1]);
            tamanho_heap--;
            heapify(0);
            return remover;
        } else {
            printf("-1 -1 -1");
            return -1;
        }
    }

    bool estaVazia(){
        if(tamanho_heap == 0){
            return true;
        } else {
            return false;
        }
    }
};


int main(){
    Heap *estudantes = new Heap(1000);
    // Os estudantes tem o menor risco
    Heap *normal = new Heap(1000);
    // Aqui são atendidos os de maior prioridade
    scanf("%i", &S);
    while(S--){
        scanf("%s", &opcao);
        if(opcao == "CIN"){
            scanf("%i %i %i", &I, &U, &A);
        } else if (opcao == "NXT") {
            scanf("%i", &A);
        } else {

        }
    }
    return 0;
}
