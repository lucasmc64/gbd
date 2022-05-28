#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct aluno {
    int seq_aluno;
    char codigo_curso[3];
    char nome_aluno[43];
} __attribute__((packed)) Aluno;

void generate_string(char *string , int length) {
    if(string == NULL || length < 0)
        return;

    for(int i = 0; i < length - 1; i++)
        string[i] = (rand() % (127 - 33)) + 33;

    string[length - 1] = '\0';
}

void create_heap_file(FILE *file, int nro_de_registros) {
    for(int i = 0; i < nro_de_registros; i++) {
        Aluno a;

        a.seq_aluno = i;
        generate_string(&(a.codigo_curso), sizeof(a.codigo_curso));
        generate_string(&(a.nome_aluno), sizeof(a.nome_aluno));
    }
}

int main() {
    struct aluno teste;

    printf("Tamanho seq_aluno: %d\n", sizeof(teste.seq_aluno));
    printf("Tamanho codigo_curso: %d\n", sizeof(teste.codigo_curso));
    printf("Tamanho nome_aluno: %d\n", sizeof(teste.nome_aluno));

    printf("Tamanho da struct aluno: %d\n", sizeof(teste));

    printf("\n\n\n");

    for(int i = 0; i < 10; i++) {
        char s[5];

        generate_string(s, 5);

        printf("%s\n", s);
    }

    //FILE *file;
    //create_heap_file(&(file), qtd_registros);

    return 0;
}
