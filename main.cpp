#include <iostream>
#include "matrizquadrada.h"

int main(void){
    MatrizQuadrada M1, M2, M3, I, R, T;
    leMatriz(M1);
    criaMatrizIdentidade(I, 3);
    produto(M1,I,R);
    if (compara(M1,R)){
        std::cout << "Matrizes iguais!\n";
    }
    else{
        std::cout << "Matrizes diferentes!\n";
    }
    imprimeMatriz(M1);
    imprimeMatriz(R);
    criaTransposta(R,T);
    leMatriz(M2);
    soma(R,M2,M3);
    imprimeMatriz(M2);
    imprimeMatriz(M3);
}