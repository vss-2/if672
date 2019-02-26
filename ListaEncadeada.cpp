#include <iostream>

using namespace std;

// A seguinte lista funciona de forma encadeada, sendo
// assim, ela não é estática, não é necessário verificar
// se ela está cheia

struct Lista {
    string valorString;
    int valorInt;
    int tamanhoLista;
    struct Lista *proximo;

    // As vezes os métodos retornam Int
    // mas poderiam facilmente retornar Strings.
    // Cabe ao usuário adaptá-lo.

    Lista(){
        tamanhoLista = 0;
    }

    // Recebe com input a lista,
    // na qual string será inserida
    void inserir(Lista *aSerInserida, string valor){
        Lista *nova = new Lista();
        aSerInserida->valor = valor;
        aSerInserida->proximo = nova;
        aSerInserida->tamanho++;
    }

    // Recebe uma lista, na qual
    // será buscada a string texto
    // retornando a posição que este se encontra
    int busca(struct Lista* buscada, string texto){
        int contador = 0;
        struct Lista* atual = buscada;
        while(true){
            if (atual->valor != texto){
                atual = atual->proximo;
                contador++;
            } else {
                return contador;
            }
        }
    }

    void remover(struct Lista* buscada, string texto){
        struct Lista* atual = buscada;
        while(true){
            if (buscada.tamanhoLista == 0){
                printf("Lista está vazia!\n");
            } else if (atual->valorString != texto){
                // Busca, igual no método de busca
                atual = atual->proximo;
            } else {
                // Achei o igual
                if(buscada.proximo == NULL){
                    // Não há próximo, estamos no fim, devo anular o atual
                    cout << "Removi " << texto << endl;
                    atual.valorString = NULL;
                    atual.valorInt = NULL;
                } else {
                    // Faço a troca dos ponteiros de próximo
                    cout << "Removi " << texto << endl;
                    atual.proximo = buscada.proximo;
                    buscada.valorString = NULL;
                    buscada.valorInt = NULL;
                }
                // O tamanho da lista foi reduzido
                buscada.tamanhoLista--;
            }
        }
    }

    // O famoso length, tamanho da Lista
    int tamanho(Lista *aSerMedida){
        return aSerMedida.tamanhoLista;
    }

    // Retorna booleano se está vazio ou não
    bool estaVazia(Lista *L){
        return L->tamanhoLista == 0 ? true : false;
    }

    // Retorna primeiro valor armazenado
    int valorCabeca(Lista *L){
        return L->valorInt;
    }

    // Retorna último valor armazenado
    int valorCauda(Lista *L){
        Lista* temp = L;
        while(L->proximo != NULL){
            temp = temp->proximo;
        }
        return temp->valorInt;
    }
};
