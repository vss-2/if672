#include <stdio.h>
#include <iostream>

using namespace std;

String opcao;
int S, I, U, A;   // Inputs necessários para questão

int temp, bubblerUpper, esq, dir, meio, remover;  // Valores que uso na heap, 
                                                  // criados aqui pra não comprometer tempo de processamento

struct Heap {
    int* heap;
    int tamanho;
    int tamanho_heap;

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
        remover = heap[0];
        trocarValores(&heap[0], &heap[tamanho_heap -1]);
        tamanho_heap--;
        heapify(0);
        return remover;
    }
};

int esq2, dir2, meio2, maior, contador;


// -------------------- Fila de Prioridades --------------------------//

int temp, bubblerUpper, esq, dir, meio, remover;

struct FilaPrioridades {
    int* FP;
    int tamanho;
    int tamanho_FP;

    FilaPrioridades(int inputTamanho){         // Construtor padrão
        tamanho = inputTamanho;
        FP = new int[tamanho];
        tamanho_FP = 0;
    }

    void dobrarEspacoHeap(){        // Duplica o espaço, caso heap fique cheia
        int* auxiliar = FP;
        tamanho = tamanho * 2;
        FP = new int[tamanho];
        for (temp = 0; temp < tamanho; temp++){
            FP[temp] = auxiliar[temp];
        }
    }

    void trocarValores(int* valor1, int* valor2){   // Troca valores inseridos
        int trocatemp = *valor1;
        *valor1 = *valor2;
        *valor2 = trocatemp;
    }

    void bubble_Up(){                   // Faz valores "subirem"
        bubblerUpper = tamanho_FP - 1;
        while (bubblerUpper > 0 && FP[bubblerUpper] <= FP[(bubblerUpper-1)/2]){
            trocarValores(&FP[bubblerUpper], &FP[(bubblerUpper-1)/2]);
        }
    }

    void inserirHeap(int inserido){     // Insere valores na heap
        if (tamanho_FP){
            dobrarEspacoHeap();
        }
        FP[tamanho_FP] = inserido;
        tamanho_FP++;
        bubble_Up();
    }

    void heapify(int arrepiado){        // Arruma a heap a partir de um dado valor
        meio = arrepiado;
        esq = 2*arrepiado + 1;
        dir = 2*arrepiado + 2;

        if (esq < tamanho_FP && FP[esq] <= FP[meio]){
            meio = esq;
        }

        if (dir < tamanho_FP && FP[dir] <= FP[meio]){
            meio = dir;
        }

        if (meio != arrepiado){
            trocarValores(&FP[arrepiado], &FP[tamanho_FP - 1]);
            heapify(meio);
        }
    }

    int removerdaHeap(){ // Retorna o valor excluido
        remover = FP[0];
        trocarValores(&FP[0], &FP[tamanho_FP - 1]);
        tamanho_FP--;
        heapify(0);
        return remover;
    }
};

// -------------------- Fila de Prioridades --------------------------//


String opcao;
int S, I, U, A;

int main(){
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
