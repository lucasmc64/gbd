#include <stdio.h>
#include <stdlib.h>

#include "bPlusTree.h"

/*
** Trabalho R06 GBD
** Integrantes:
** Lucas Marçal (11911BCC012)
** Lucas Mattos (11911BCC015)
**
** Instruções de Compilação: simplesmente compilar e linkar os 3 arquivos .c
*/

FILE* create_file(const char* path, int tipo)
{
    FILE* new_file = fopen(path, "wb+");

    if (new_file == NULL)
    {
        printf("Erro ao criar arquivo!\n");
        return NULL;
    }

    if (tipo == 1) {
        criaArvore1(new_file);
    } else if (tipo == 2) {

    } else if (tipo == 3) {

    }

    return new_file;
}

int main()
{
    printf("Hello world!\n");
    return 0;
}
