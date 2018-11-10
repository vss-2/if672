#include <stdio.h>

using namespace std;

int tempswap, auxswap, esq, dir, paizao, SUtroca, SUtemp, removeHP; int um = 1; 

struct Node {
    int dado; 
    Node *esq; Node *dir;
};

void Node *swap(int valor){
    tempswap = no->dado;
    no->dado = valor;
    valor = tempswap;
}

int Node tamanho(){
    um = 1;
    if (this->left != NULL) r += this->left->tamanho();
    if (this->right != NULL) r += this->right->tamanho();
    return r;
}

void Node inserir(Node* no){
    if (this->esq == NULL) this->esq = no;
    else if (this->dir == NULL) this->dir = no;
    else if (this->left->tamanho() > this->right->tamanho()) this->right->inserir(no);
    else this->esq->inserir(no);
}

struct Heap {
    int array[50000]; int n;
};

void HeapSwap (Heap *H, int a, int b){
    auxswap = H->array[a];
    H->array[a] = H->array[b];
    H->array[b] = auxswap;
}

int esqNo (Heap *H, int paizao){
    esq = (paizao*2) + 1;
    if (esq <= H->n){
        return esq;
    } else {
        return -1;
    }
}

int dirNo (Heap *H, int paizao){
    dir = (paizao*2) + 2;
    if (dir <= H->n){
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
}

void HeapInserir (Heap *H, int valor){
    H->array[H->n] = valor;
    H->n++;
    SiftUp(H, H->n-1);
}

int HeapRemover (Heap *H){
    if (H->n > -1){
        removeHP = H->array[0];
        H->array[0] = H->array[H->n-1];
        H->n--;
        
    }
}


int main(){
    return 0;
}
