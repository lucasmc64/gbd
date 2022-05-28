#ifndef GBD_H_
#define GBD_H_

#include <stdio.h>

typedef struct aluno {
    int seq_aluno;
    char codigo_curso[3];
    char nome_aluno[43];
} __attribute__((packed)) Aluno;

// R02
void create_heap_file(FILE *file, int nro_de_registros);
void read_random(FILE *file, int seq_aluno);
void isrt_at_end(FILE *file); // insere registro aleatório
void update_random(FILE *file, int seq_aluno, char *novo_nome, char *novo_codigo);
void delete_random(FILE *file, int seq_aluno);

// R03
void varredura_sequencial(FILE *file, int tam_bloco);

// R04
void varredura_aleatoria(FILE *file);

#endif // GBD_H_
