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


void criaArvore(FILE *file, int alternativa) {

    fseek(file, sizeof(Arvore), SEEK_SET);    // anda o arquivo até a posição do primeiro nó

    long int posicao_raiz = ftell(file);        // guarda a posição do nó raiz

    Arvore arvore;
    arvore.raiz = posicao_raiz;                 // salva a posição da raiz na estrutura árvore

    if (alternativa == 1) {

        No_1 raiz = criaNo1(true);
        fwrite(&raiz, sizeof(No_1), 1, file);          // salva a raiz no arquivo

    } else if (alternativa == 2) {

        No_2 raiz = criaNo2(true);
        fwrite(&raiz, sizeof(No_2), 1, file);          // salva a raiz no arquivo

    } else {

        No_3 raiz = criaNo3(true);
        fwrite(&raiz, sizeof(No_3), 1, file);          // salva a raiz no arquivo

    }

    fseek(file, 0, SEEK_SET);
    fwrite(&arvore, sizeof(Arvore), 1, file);    // salva a estrutura da árvore no arquivo
}

No_1 criaNo1(bool folha) {

    No_1 no;

    if (folha) {
        no.eh_folha = true;
        no.anterior = NULL;
        no.proximo = NULL;
    } else {
        no.eh_folha = false;
    }
    
    no.total_chaves = 0;

    return no;
}

No_2 criaNo2(bool folha) {

    No_2 no;

    if (folha) {
        no.eh_folha = true;
        no.anterior = NULL;
        no.proximo = NULL;
    } else {
        no.eh_folha = false;
    }
    
    no.total_chaves = 0;

    return no;
}

No_3 criaNo3(bool folha) {

    No_3 no;

    if (folha) {
        no.eh_folha = true;
        no.anterior = NULL;
        no.proximo = NULL;
    } else {
        no.eh_folha = false;
    }
    
    no.total_chaves = 0;

    return no;
}

void insereArvore(FILE *file, Registro novo_reg, int alternativa) {

    Arvore arvore;        
    fread(&arvore, sizeof(Arvore), 1, file);  // lê a estrutura da árvore

    long int pos_raiz = arvore.raiz;

    if (alternativa == 1) {

        No_1 raiz;
        fseek(file, pos_raiz, SEEK_SET);         // procura a raiz
        fread(&raiz, sizeof(No_1), 1, file);

        if (raiz.eh_folha) {

            

        } else {
            // ...
        }

    } else if (alternativa == 2) {

        No_2 raiz;
        fseek(file, pos_raiz, SEEK_SET);         // procura a raiz
        fread(&raiz, sizeof(No_2), 1, file);

        if (raiz.eh_folha) {

            // ...

        } else {

            // ...

        }

    } else {

        No_3 raiz;
        fseek(file, pos_raiz, SEEK_SET);         // procura a raiz
        fread(&raiz, sizeof(No_3), 1, file);

        if (raiz.eh_folha) {
            // ...
        } else {
            // ...
        }

    }

}

// implementar busca por intervalo
