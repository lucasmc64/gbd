#define ORDER 3

typedef struct REG_ALUNO {
    int seq_aluno;
    char matricula_aluno[12];
    char nome_aluno[36];
} registro;

typedef struct B_PLUS_TREE_TIPO_1 {
    long int raiz;
} arvore_1;

typedef struct NO_TIPO_1 {
    bool eh_folha;
    long int ponteiros[ORDER+1];
    long int anterior;
    long int proximo;
    struct REG_ALUNO registros[ORDER];
    int chaves[ORDER];
    int total_chaves;
} no_1;

// arvores alternativa 2 e 3
