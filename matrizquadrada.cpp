#include <iostream>
#include "matrizquadrada.h"

MatrizQuadrada::MatrizQuadrada(){
    //Recebendo o tamanho da matriz e alocando dinamicamente na memória
    tamanho = new int;
    std::cout << "Digite o tamanho da matriz: ";
    std::cin >> *tamanho;
    matriz = new int*[*tamanho];
    for(int i=0; i<*tamanho; i++){
        matriz[i] = new int[*tamanho];
    }
}

MatrizQuadrada::~MatrizQuadrada(){
    for(int i=0; i<*tamanho; i++){
        delete[] matriz[i];
    }
    delete[] matriz;
}

void leMatriz(MatrizQuadrada &M1){
    for(int i=0; i<*M1.tamanho; i++){
        for(int j=0; j<*M1.tamanho; j++){
            std::cin >> M1.matriz[i][j];
        }
    }
}

void criaMatrizIdentidade(MatrizQuadrada &M1, int n){
    //Criando um for que irá armazenar o valor de 1 em todos os índices que constituem a diagonal principal da matriz
    //ou seja, quando o índice da linha for igual o índice da coluna.
    //Caso contrário, irá armazenar 0 nos índices restantes
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(i==j){
                M1.matriz[i][j] = 1;
            }
            else{
                M1.matriz[i][j] = 0;
            }
        }
    }
}

void imprimeMatriz(MatrizQuadrada &M1){
    //Criando um for que irá imprimir todos elementos das linhas e colunas da matriz.
    for(int i=0; i<*M1.tamanho; i++){
        for(int j=0; j<*M1.tamanho; j++){
            std::cout << M1.matriz[i][j] << "\t";
        }
        std::cout << "\n";
    }
    std::cout << "\n";
}

void produto(MatrizQuadrada &M1, MatrizQuadrada &M2, MatrizQuadrada &RESULTADO){
    int soma;
    if(*M1.tamanho==*M2.tamanho && *M1.tamanho==*RESULTADO.tamanho && *M2.tamanho==*RESULTADO.tamanho){
        //Inicializando a matriz resultado
        for(int i=0; i<*M1.tamanho; i++){
            for(int j=0; j<*M1.tamanho; j++){
                RESULTADO.matriz[i][j] = 0;
            }
        }
        //Calculando o produto
        for(int i=0; i<*M1.tamanho; i++){
            for(int j=0; j<*M1.tamanho; j++){
                soma = 0;
                for(int k=0; k<*M1.tamanho; k++){
                    soma = soma + M1.matriz[i][k]*M2.matriz[k][j];
                }
                RESULTADO.matriz[i][j] = soma;
            }
        }
    }
    else{
        std::cout << "Não foi possivel calcular o produto das matrizes pois possuem tamanhos diferentes";
    }
}

bool compara(MatrizQuadrada &M1, MatrizQuadrada &M2){
    //Se as matrizes possuem tamanhos diferentes, elas não são iguais, então retornaremos falso.
    if(*M1.tamanho!=*M2.tamanho){
        return false;
    }
    //Caso as matrizes possuam tamanhos iguais, nós iremos calcular a área dessa matriz, e criaremos um loop para
    //cada vez que a matriz encontrar um valor igual, somarmos na variável 'soma' para sabermos
    //a quantidade de valores iguais
    int soma = 0;
    int areaMatriz = *M1.tamanho * *M1.tamanho;

    for(int i=0; i<*M1.tamanho; i++){
        for(int j=0; j<*M1.tamanho; j++){
            if(M1.matriz[i][j]==M2.matriz[i][j]){
                soma++;
            }
        }
    }
    //Agora iremos verificar se a quantidade de valores iguais é igual a área da Matriz
    //assim saberemos se nossas matrizes são iguais ou não.(assim espero)
    if(soma==areaMatriz){
        return true;
    }
    else{
        return false;
    }
}

void criaTransposta(MatrizQuadrada &M1, MatrizQuadrada &TRANSPOSTA){
    if(*M1.tamanho==*TRANSPOSTA.tamanho)
    {   
        //Através desse loop, iremos inverter as linhas e colunas de M1
        //e armazenar na TRANSPOSTA 
        for(int i=0; i<*M1.tamanho; i++){
            for(int j=0; j<*M1.tamanho; j++){
                TRANSPOSTA.matriz[i][j] = M1.matriz[j][i];
            }
        }
    }
}

void soma(MatrizQuadrada &M1, MatrizQuadrada &M2, MatrizQuadrada &RESULTADO){
    if(*M1.tamanho==*M2.tamanho && *M1.tamanho==*RESULTADO.tamanho && *M2.tamanho==*RESULTADO.tamanho){
        for(int i=0; i<*M1.tamanho; i++){
            for(int j=0; j<*M1.tamanho; j++){
                RESULTADO.matriz[i][j] = M1.matriz[i][j] + M2.matriz[i][j];
            }
        }
    }
}
