#include "gbd.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void generate_string(char *string , int length) {
    if(string == NULL || length < 0)
        return;

    for(int i = 0; i < length - 1; i++)
        /* string[i] = (rand() % (127 - 33)) + 33; */
        string[i] = 65 + rand() % 26;

    string[length - 1] = '\0';
}

void create_heap_file(FILE *file, int nro_de_registros) {
    for(int i = 0; i < nro_de_registros; i++) {
        Aluno a;

        a.seq_aluno = i;
        generate_string(a.codigo_curso, 4);
        generate_string(a.nome_aluno, 42);

        /* printf("Aluno %d:\nCurso: %s\nNome: %s\n", a.seq_aluno, a.codigo_curso, a.nome_aluno); */
        /* printf("\n"); */

        fwrite(&a, sizeof(Aluno), 1, file);
    }
}

void isrt_at_end(FILE *file) {
    Aluno a;

    Aluno teste;
    fseek(file, -sizeof(Aluno), SEEK_END);
    fread(&teste, sizeof(Aluno), 1, file);

    a.seq_aluno = teste.seq_aluno + 1;
    generate_string(a.codigo_curso, 3);
    generate_string(a.nome_aluno, 43);

    printf("Novo aluno a ser adicionado: \nAluno %d:\nCurso: %s\nNome: %s\n", a.seq_aluno, a.codigo_curso, a.nome_aluno);
    printf("\n");


    fwrite(&a, sizeof(Aluno), 1, file);
}


void read_random(FILE *file, int seq_aluno, Aluno *aluno) {
    fseek(file, seq_aluno * sizeof(Aluno), SEEK_SET);
    fread(aluno, sizeof(Aluno), 1, file);
}

void update_random(FILE *file, int seq_aluno, char *novo_nome, char *novo_codigo) {
    Aluno newAluno;
    newAluno.seq_aluno = seq_aluno;
    strcpy(newAluno.nome_aluno, novo_nome);
    strcpy(newAluno.codigo_curso, novo_codigo);

    fseek(file, sizeof(Aluno) * seq_aluno, SEEK_SET);
    fwrite(&newAluno, sizeof(Aluno), 1, file);
}

void varredura_sequencial(FILE *file, int tam_bloco) {

    Aluno a;
    fseek(file, -sizeof(Aluno), SEEK_END);
    fread(&a, sizeof(Aluno), 1, file);

    int total_registros = a.seq_aluno + 1, i = 0;
    int registros_validos = 0, nro_lidos = 0;

    fseek(file, 0, SEEK_SET);

    clock_t start = clock();

    Aluno* bloco = malloc(tam_bloco * sizeof(Aluno));

    while (i < total_registros) {
        int registros_a_ler = tam_bloco, j = 0;

        if (total_registros - i < tam_bloco)
            registros_a_ler = total_registros - i;

        printf("Lendo %d registros...\n", registros_a_ler);

        fread(bloco, sizeof(Aluno), registros_a_ler, file);

        for(; j < registros_a_ler; j++)
        {
            nro_lidos++;
            if (bloco[j].seq_aluno >= 0)
        }
    }
}
