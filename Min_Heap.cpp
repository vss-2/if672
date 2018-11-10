#include <stdio.h>

using namespace std;

int tempswap, auxswap, esq, dir, paizao, SUtroca, SUtemp, removeHP; int um = 1; 

struct Node {
    int dado; 
    Node *esq; Node *dir;
};

struct Heap {
    int array[50000]; Node n;
};

void Node *swap(int valor){
    tempswap = no->dado;
    no->dado = valor;
    valor = tempswap;
    // A ideia é simples:
    // faça a troca usando pivô
}

int Node tamanho(){
    um = 1;
    if (this->left != NULL) r += this->left->tamanho();
    if (this->right != NULL) r += this->right->tamanho();
    return r;
    // Para saber o tamanho:
    // percorre recursivamente
    // da esquerda para direita
    // e retorne o tamanho da soma
}

void Node inserir(Node* no){
    if (this->esq == NULL) this->esq = no;
    else if (this->dir == NULL) this->dir = no;
    else if (this->left->tamanho() > this->right->tamanho()) this->right->inserir(no);
    else this->esq->inserir(no);
    // O da esquerda está vazio?
    // O da direta está vazio?
    // Se o ramo esquerdo for maior, bota na direita
    // Senão, bota na esquerda
}


void HeapSwap (Heap *H, int a, int b){
    auxswap = H->array[a];
    H->array[a] = H->array[b];
    H->array[b] = auxswap;
    // Entra a heap e os valores a serem trocados
    // Use pivô e efetue a troca
}

int esqNo (Heap *H, int paizao){
    esq = (paizao*2) + 1;
    if (esq <= H->n->dado){
        return esq;
    } else {
        return -1;
    }
}

int dirNo (Heap *H, int paizao){
    dir = (paizao*2) + 2;
    if (dir <= H->n->dado){
        return dir;
    } else {
        return -1;
    }
}

void SiftUp (Heap *H, int a){
    SUtroca = 1;
    SUtemp = 0;
    while (a > 0 && troca){
        troca = 0;
        paizao = (a - 1)/2;
        if (H->array[a] > h->array[paizao]){
            HeapSwap (H, a, paizao);
            a = paizao;
            troca = 1;
        }
    }
    // Tenho que organizar enquanto o
    // Heap na posição de a for maior que o pai
    // Quando acabar, encerra o SiftUp
}

void HeapInserir (Heap *H, int valor){
    H->array[H->n->dado] = valor;
    H->n->dado++;
    SiftUp(H, H->n->dado-1);
}

int HeapRemover (Heap *H){
    if (H->n->dado > -1){
        removeHP = H->array[0];
        H->array[0] = H->array[H->n->dado-1];
        H->n->dado--;
    }
}


int main(){
    return 0;
}
