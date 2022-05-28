#include "gbd.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    /* struct aluno teste; */

    /* printf("Tamanho seq_aluno: %d\n", sizeof(teste.seq_aluno)); */
    /* printf("Tamanho codigo_curso: %d\n", sizeof(teste.codigo_curso)); */
    /* printf("Tamanho nome_aluno: %d\n", sizeof(teste.nome_aluno)); */

    /* printf("Tamanho da struct aluno: %d\n", sizeof(teste)); */

    /* printf("\n\n\n"); */

    /* for(int i = 0; i < 10; i++) { */
    /*     char s[5]; */

    /*     generate_string(s, 5); */

        printf("%s\n", s);
    }

    FILE *file = fopen("heap_file.heap", "wb+");
    int qtd_registros = 10;
    create_heap_file(file, qtd_registros);

    fclose(file);
    return 0;
}
