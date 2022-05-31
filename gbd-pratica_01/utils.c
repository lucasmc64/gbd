#include "utils.h"
#include <stdio.h>
#include <stdlib.h>
#define LINE_MAX_LENGTH 128

char* read_line()
{
    int position = 0; // Indice da entrada
    char* buffer = malloc(sizeof(char) * LINE_MAX_LENGTH); // Aloca-se tamanho máximo para comando
    char c;

    if(!buffer)
    {
        printf("Erro de alocação!\n");
        return NULL;
    }

    while(1)
    {
        c = getchar();
        if (c == EOF) // stdin foi fechado
        {
            free(buffer);
            return NULL;
        }

        // Adiciona caractere de stdin no buffer. Se c for \n, finalizamos a string com \0 e retornamos o ponteiro.
        if(c == '\n')
        {
            buffer[position] = '\0';
            return buffer;
        }
        else
        {
            buffer[position++] = c;
        }

        // Corta entradas que excedam CMD_MAX_SIZE
        if(position + 1 >= LINE_MAX_LENGTH)
        {
            int ch;
            while((ch = getchar()) != '\n' && ch != EOF); // Remove todos os caracteres depois de LINE_MAX_SIZE do buffer stdin
            buffer[position] = '\0';
            return buffer;
        }
    }
}

int file_exists(const char* path) {
    FILE* file_test;
    if ((file_test = fopen(path, "r")))
    {
        fclose(file_test);
        return 1;
    }
    return 0;
}
