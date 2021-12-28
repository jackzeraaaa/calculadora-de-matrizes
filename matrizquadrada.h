struct MatrizQuadrada{
    //Dados
    int **matriz;
    int *tamanho;

    //Construtor
    MatrizQuadrada();
    //Destrutor
    ~MatrizQuadrada();

};

//Funções e Operações
void leMatriz(MatrizQuadrada &M1);
void criaMatrizIdentidade(MatrizQuadrada &M1, int n);
void imprimeMatriz(MatrizQuadrada &M1);
void produto(MatrizQuadrada &M1, MatrizQuadrada &M2, MatrizQuadrada &RESULTADO);
void soma(MatrizQuadrada &M1, MatrizQuadrada &M2, MatrizQuadrada &RESULTADO);
void criaTransposta(MatrizQuadrada &M1, MatrizQuadrada &TRANSPOSTA);
bool compara(MatrizQuadrada &M1, MatrizQuadrada &M2);