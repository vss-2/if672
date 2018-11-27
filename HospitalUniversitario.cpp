#include <stdio.h>
#include <iostream>
#include <cstring>

using namespace std;

// Preciso criar módulos de Heap que sejam adaptáveis

bool vazia, funcionou = false;
string opcao;
int S, I, U, A;   // Inputs necessários para questão
int esq, dir, meio, maior, menor, contador, temp, NXT;



struct dadosPaciente{
    int Idade, Urgencia, Servico;

    dadosPaciente(int I, U, A){
        Idade = I;
        Urgencia = U;
        Servico = A;
    }
};

struct Fila{
    dadosPaciente cabecaFila;
    Fila* proximo;

    Fila(dadosPaciente entrou){
        cabecaFila = entrou;
    }
};

struct Heap{
    dadosPaciente* naHeap;
    int tamanhoHeap, tamanhoInserir;

    Heap(int inputTamanho, dadosPaciente daVez){
        tamanhoHeap = inputTamanho;
        heap = new int[tamanhoHeap];
        naHeap = daVez;
        tamanhoInserir = tamanhoHeap;
    }

    // retornaPai = (node - 1)/2;
    // retornaEsq = (2 * node + 1);
    // retornaDir = (2 * node + 2);

    // Obs: Os heapify estão recebendo como
    // parâmetro os valores node, mas na verdade
    // eles recebem valores posicao, a qual devem
    // fazer o heapify

    void heapifyUpMax(int node){ // MaxHeap
        if (node > 0 && heap[(node - 1)/2] < heap[node]){
            swap(heap[node],heap[(node - 1)/2]);
            heapifyUpMax(heap[(node - 1)/2]);
        }
    }

    void heapifyDownMax(int node){ // MaxHeap
        esq = heap[(2 * node)+ 1];
        dir = heap[(2 * node)+ 2];
        maior = node;

        if(esq < tamanhoHeap && heap[(2 * node)+ 1] > heap[node]){
            maior = esq;
        }

        if(dir < tamanhoHeap && heap[(2 * node)+ 2] > heap[maior]){
            maior = dir;
        }

        if(maior != node){
            swap(node, maior);
            heapifyDownMax(maior);
        }
    }

    void dobrarEspacoHeap(){
        int* auxiliar = heap;
        tamanhoHeap = tamanho * 2;
        heap = new int [tamanhoHeap];
        for(temp = 0; temp < tamanhoHeap; temp++){
            heap[temp] = auxiliar[temp];
        }
    }

    void inserirHeap(int node){
        if(tamanhoInserir <= 0){
            dobrarEspacoHeap();
        }
        heap[tamanhoInserir] = node;
        //heapifyUpMin(tamanhoInserir);
        //heapifyUpMax(tamanhoInserir);
    }

    void heapifyUpMin(int node){
        if(node > 0 && heap[(node - 1)/2] > heap[node]){
            swap(node, (node - 1)/2);
            heapifyUpMin(heap[(node - 1)/2]);
        }
    }

    void heapifyDownMin(int node){
        esq = (2 * node) + 1;
        dir = (2 * node) + 2;
        menor = node;

        if(esq < tamanhoHeap && heap[(2 * node) + 1] < heap[node]){
            menor = esq;
        }

        if(dir < tamanhoHeap && heap[(2 * node) + 2] < heap[menor]){
            menor = dir;
        }

        if(node != menor){
            swap(node, menor);
            heapifyDownMin(menor);
        }
    }

    void removerdaHeap(){
        if(!estaVazia){
            /*
                remover = heap[0];
                trocarValores(&heap[0], &heap[tamanho_heap -1]);
                tamanho_heap--;
                heapify(0);
                return remover;
            */
            tamanhoHeap--;
        } else {
            printf("-1 -1 -1\n");
        }
    }

    bool estaVazia(){
        if(tamanhoHeap == 0){
            return true;
        } else {
            return false;
        }
    }
};

int main(){
    Heap *estudantesUrgencia = new Heap(500);
    Hera *estudantesIdade = new Heap(500);
    // Para todos os casos estudantes CIN devem pegar
    // apenas pacientes de baixa urgencia e idade

    Heap *doutoresUrgencia = new Heap(500);
    Heap *doutoresIdade = new Heap(500);
    // Para todos os casos normais NXT

    Fila ordemChegada[S] = new Fila();

    scanf("%i", &S); // Quantidade de casos teste

    while(S--){
        scanf("%s", opcao.c_str); // Estranho, mas é o necessário para pegar uma string e não um char

        if(opcao == "CIN"){ // Pegar minHeap das coisas
            scanf("%i %i %i", &I, &U, &A); // Idade, Urgencia, Servico
            dadosPaciente *cadastro = new DadosPaciente(I, U, A);
            estudantesUrgencia->inserirHeap(cadastro->Urgencia); // Tem que inserir na minHeap da Urgencia
            estudantesIdade->inserirHeap(cadastro->Idade);    // Tem que inserir na minHeap da Idade

            doutoresUrgencia->inserirHeap(cadastro->Urgencia);
            estudantesidade->inserirHeap(cadastro->Idade);

            ordemChegada[s]->inserirFila(cadastro);
            // Caso houver empate entre Urgencia e Idade:
            // Tenho que ter uma fila de ordem de chegada simples

        } else if (opcao == NXT) { // Pegar maxHeap das coisas
            scan("%s", &NXT);
            printf(ordemChegada[NXT].cabecaFila.Servico+" "+ordemChegada[NXT].cabecaFila.Idade+" "+ordemChegada[NXT].cabecaFila.Urgencia+"\n");
            // Atendimento do proximo paciente que houver na fila
            // o valor de NXT deve ser igual ao valor A do paciente
            // Preciso implementar uma funcao de remover da fila
        }
    }

    return 0;
}
