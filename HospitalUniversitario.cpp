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

struct FilaPrioridades {  // É a famosa MAX HEAP
    // Vetor para armazenar elementos
    int* fp;
    int tamanho_fp;
    int tamanho;

    FilaPrioridades(int N){
        tamanho = N;
        fp = new int[tamanho];
        tamanho_fp = 0;
    }

    void dobrarTamanho(){
        int* copiaAuxiliar = fp;
        tamanho = tamanho * 2;
        fp = new int[tamanho];
        for (contador = 0; contador < tamanho; contador++){
            fp[contador] = copiaAuxiliar[contador];
        }
    }
 
    // retorna o pai de A[i]
    // Não se chama isso se i for a raiz, talquei?
    int retornaPai(int i) { 
        return (i - 1) / 2; 
    }
 
    // retorna o filho a esquerda de A[i]    
    int retornaEsq(int i) { 
        return (2 * i + 1); 
    }
 
    int retornaDir(int i) { 
        return (2 * i + 2); 
    }
 
    void troca(int a, int b){
        int c = a;
        a = b;
        b = c;
    }

    // Algoritmo Heapify-down recursivo
    // usamos o nó i e pegamos os seus filhos imediatos
    // violamos a propriedade da heap, devemos arrumá-la
    void heapify_down(int i){
        // get left and right child of node at index i
        int esq2 = retornaEsq(i);
        int dir2 = retornaDir(i);
 
        maior = i;
 
        // compare A[i] with its left and right child
        // and find largest value
        if (esq2 < tamanho() && fp[esq2] > fp[i])
            maior = esq2;
 
        if (dir2 < fp.tamanho() && fp[dir2] > fp[maior])
            maior = dir2;
 
        // swap with child having greater value and 
        // call heapify-down on the child
        if (maior != i) {
            troca(fp[i], fp[maior]);
            heapify_down(maior);
        }
    }
 
    // Recursive Heapify-up algorithm
    void heapify_up(int i){
        // check if node at index i and its parent violates 
        // the heap property
        if (i && fp[retornaPai(i)] < fp[i]) 
        {
            // swap the two if heap property is violated
            troca(fp[i], fp[retornaPai(i)]);
            
            // call Heapify-up on the parent
            heapify_up(retornaPai(i));
        }
    }

    // return size of the heap
    int tamanho(){
        return fp.tamanho_fp;
    }
 
    // function to check if heap is empty or not
    bool estaVazio(){
        return tamanho() == 0;
    }
    
    // insert key into the heap
    void inserir(int key){
        // Insira o novo elemento ao fim do array
        if (tamanho == tamanho_fp){
            dobrarTamanho();
        }
        
        // Pegue o índice do elemento e chame heapify bubble up
        int index = tamanho() - 1;
        heapify_up(index);
    }
 
    // function to remove element with highest priority (present at root)
    void pop(){
        if (tamanho() != 0){
            fp[0] = fp.back();
            fp.pop_back();
            heapify_down(0);
        }
    }
 
    // function to return element with highest priority (present at root)
    int top(){
        if (tamanho() != 0){
            return fp[0];    // or return A[0];
        }
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
