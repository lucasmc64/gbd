#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#include "bPlusTree.h"

/*
** Trabalho R06 GBD
** Integrantes:
** Lucas Marçal (11911BCC012)
** Lucas Mattos (11911BCC015)
**
** Instruções de Compilação: simplesmente compilar e linkar os 3 arquivos .c
*/

void criaArvore1(FILE *file) {

    fseek(file, sizeof(arvore_1), SEEK_SET);    // anda o arquivo até a posição do primeiro nó

    long int posicao_raiz = ftell(file);        // guarda a posição do nó raiz

    arvore_1 arvore;
    arvore.raiz = posicao_raiz;                 // salva a posição da raiz na estrutura árvore
    no_1 raiz = criaFolha1();
    fwrite(&raiz, sizeof(no_1), file);          // salva a raiz no arquivo

    fseek(file, 0, SEEK_SET);
    fwrite(&arvore, sizeof(arvore_1), file);    // salva a estrutura da árvore no arquivo
}

no_1 criaFolha1() {
    no_1 folha;
    folha.eh_folha = true;
    folha.anterior = NULL;
    folha.proximo = NULL;
    folha.total_chaves = 0;

    return folha;
}

no_1 criaInterno1() {
    no_1 interno;
    folha.eh_folha = false;
    folha.total_chaves = 0;

    return folha;
}
