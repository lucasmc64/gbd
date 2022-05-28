#include "gbd.h"
#include <stdio.h>
#include <stdlib.h>

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
        generate_string(a.codigo_curso, 3);
        generate_string(a.nome_aluno, 43);

        printf("Aluno %d:\nCurso: %s\nNome: %s\n", a.seq_aluno, a.codigo_curso, a.nome_aluno);
        printf("\n");

        fwrite(&a, sizeof(Aluno), 1, file);
    }
}

void read_random(FILE *file, int seq_aluno, Aluno *aluno) {
    fseek(file, seq_aluno * sizeof(Aluno), SEEK_SET);
    fread(aluno, sizeof(Aluno), 1, file);
}
