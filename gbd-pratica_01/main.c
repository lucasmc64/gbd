#include "gbd.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
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

    //  printf("%s\n", s);
    //}

    FILE *file = fopen("/run/media/carmo/Storage/heap_file.heap", "ab+");
    srand(time(NULL));

    /* int qtd_registros = 802424000; */

    /* create_heap_file(file, qtd_registros); */

    fclose(file);

#if defined (__WIN32) || defined (WIN32) || defined (__WIN32__) || defined (__NT__)
    printf("Hello I'm on windows!\n");
#elif defined (__unix__)
    printf("Hello I'm on unix!\n");
#endif

    printf("%d\n", sizeof(Aluno));
    return 0;
}
