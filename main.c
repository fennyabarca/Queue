#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "fila.h"

/*int main (int argc, char *argv[]){
    Fila f;
    int i = 1;
    inicia_fila (&f, 12);
    while (!fila_cheia(&f)){
        insere_fila (i++, &f);
        mostra_fila (&f);
    }
    while (!fila_vazia(&f)){
        printf("\n%d foi atendido", remove_fila(&f));
        mostra_fila(&f);
    }
    return 0;
}*/

int main (){
    Fila f;
    inicia_fila (&f, 10);
    srand (time(NULL));
    do{
        if (rand() % 2){
            if (!fila_cheia(&f)){
                insere_fila(rand() % 10, &f);
            }
        }
        else{
            if (!fila_vazia(&f)){
                remove_fila(&f);
            }
        }
        mostra_fila(&f);
        mostra_vetor(&f);
    }
    while (!fila_vazia(&f));
    return 0;
}
