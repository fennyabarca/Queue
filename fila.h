#ifndef fila_h
#define fila_h

#include <stdio.h>
#include <stdlib.h>

#endif /* fila_h */

typedef struct fila{
    int primeiro, ultimo, contador, capacidade;
    int *vetor;
}Fila;

typedef struct fila Fila;

//Fila Vazia
int fila_vazia (Fila *);

//Fila Cheia
int fila_cheia (Fila *);

//Insere Fila
void insere_fila (int, Fila *);

//Remove Fila
int remove_fila (Fila *);

//Mostra Fila
void mostra_fila (Fila *);
void mostra_vetor (Fila *);

//Inicia Fila
void inicia_fila (Fila *, int);


