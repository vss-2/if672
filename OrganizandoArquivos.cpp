#include <iostream>
#include <stdio.h>

using namespace std;

int A, a, M, X, b, c, mainProcura, mainHash, buscar, Y, posicaoFinal, f, meio, fimHash, hashSoma, hashContador;
string buscaFinal;

struct Lista{
    string valor;
    struct Lista *proximo;
    int tamanho;

    Lista(){
        tamanho = 0;
    }

    void inserir(Lista *aSerInserida, string valor){
        Lista *nova = new Lista();
        aSerInserida->valor = valor;
        aSerInserida->proximo = nova;
        aSerInserida->tamanho++;
    }

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
};

int hashing(string texto, int modulo){
    hashSoma = 0;
    for (hashContador = 0; hashContador < texto.length(); hashContador++){
        hashSoma = hashSoma + ((hashContador+1)*texto.at(hashContador));
    }
    fimHash = hashSoma % modulo;
    return fimHash;
}

int buscabinaria (int ids[], int esquerda, int direita, int procurado){
    if(direita >= esquerda){
        meio = esquerda + (direita - esquerda)/2;

        if(ids[meio] == procurado){
            return meio;
        }

        if(ids[meio] > procurado){
            return buscabinaria(ids, esquerda, meio-1, procurado);
        }

        return buscabinaria(ids, meio+1, direita, procurado);
    }
    return -1;
}

int main(){
    scanf("%i", &A);
    // Tamanho da entrada

    string nomes[A];
    int ids[A];

    a = 0;
    while(a < A){
        cin >> nomes[a];
        cin >> ids[a];
        a++;
    }

    scanf("%i", &M);
    scanf("%i", &X);
    // M = tamanho da gaveta nova
    // X = qntd de arquivos movidos

    int preencherGaveta[M] = { 0 };

    Lista gavetaNova[M];

    while(b < X){
        cin >> mainProcura;
        mainProcura = buscabinaria(ids, 0, A, mainProcura);
        // Busca arquivo e retorna posição do mesmo

        mainHash = hashing(nomes[mainProcura], M);
        // Faz o hashing, retornando o valor novo

        gavetaNova->inserir(&gavetaNova[mainHash], nomes[mainProcura]);
        // Insiro na gaveta o processo
    }

    b = 0;

    while(b < M){
        printf("%i: %i\n", b, gavetaNova[b].tamanho);
        b++;
        // Printa tamanhos
    }

    scanf("%i", &Y);
    // Recebe valores consultados

    b = 0; f = 0;

    while(b < Y){
        cin >> buscaFinal;
        posicaoFinal = hashing(buscaFinal, M);
        printf("%i: ", b);
        f = 0;
        int resultado = gavetaNova[posicaoFinal].busca(&gavetaNova[posicaoFinal], buscaFinal);
        printf("%i\n", resultado);
        b++;
    }
    return 0;
}
