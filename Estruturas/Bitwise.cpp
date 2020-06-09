#include <iostream>

using namespace std;

// Fazer (1 << indice) estamos definindo 1 no binario[indice]

void settarEnesimoBit(int &valor, int indice){
    // Usando operador ou "|"
    valor |= (1 << indice);
}

void unsettarEnesimoBit(int &valor, int indice){
    // Usando operador e "&"
    valor &= (~(1 << indice));
}

void inverterEnesimoBit(int &valor, int indice){
    // Usando operador xor "^"
    valor ^= (1 << indice);
}

bool verificarEnesimoBit(int &valor, int indice){
    bool n_bit = valor & (1 << indice);
}

void inverterBits(int &valor, int indice){
    valor = ~(valor);
}

void complementoDe2(int &valor){
    valor = inverterBits(*valor) + 1;
}

bool verificarMenorBit(int &valor){
    bool menorbit = valor & (valor - 1);
}

void limparAteMenosSignif(int &valor, int indice){
    // LSB =  Least Significant Bit
    int enesimo = ~((1 << indice + 1) - 1);
    valor &= enesimo;
}

void limparAteMaisSignif(int &valor, int indice){
    // MSB = Most Significant Bit
    int enesimo = (1 << indice) - 1;
    valor &= enesimo;
}

char MAIUSCULO(char[] &minusculo){
    return minusculo |= ' ';
}

char minusculo(char[] &MAIUSCULO){
    return MAIUSCULO &= '_';
}

int contadorBits1(int valor){
    int cont = 0;
    while(valor){
        // Soma caso 1o bit seja 1, avança dividindo por 2
        cont += valor & 1;
        valor &= (valor - 1);
        // Serve usando shift right: valor >>= 1;
    }
    return cont;
}

int acharNaBase2(int valor){
    int base = 0;
    while(valor >>= 1){
        // Divide por 2 enquanto não for 0
        base++;
    }
    return base;
}

bool ehPotenciaDe2(int valor){
    return (valor && !(valor & valor-1));
