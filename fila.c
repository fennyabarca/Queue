#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "fila.h"

/*struct fila{
    int primeiro, ultimo, contador, capacidade;
    int *vetor;
};*/

void inicia_fila (Fila *ponteiroFila, int capacidade){
    ponteiroFila -> primeiro = 0;
    ponteiroFila -> ultimo = 0;
    ponteiroFila -> vetor = (int *) malloc (capacidade * sizeof(int));
    ponteiroFila -> contador = 0;
    ponteiroFila -> capacidade = capacidade;
}

//Fila Vazia
int fila_vazia (Fila *ponteiroFila){
    return (ponteiroFila -> contador == 0);
}

//Fila Cheia
int fila_cheia (Fila *ponteiroFila){
    if (ponteiroFila -> contador == ponteiroFila -> capacidade)
        return 1;
    return 0;
}

//Função de implementação do próximo elemento da fila considerando estrutura circular
int proxima (Fila *ponteiroFila, int posicao){
    return (posicao + 1) % ponteiroFila -> capacidade;
}

//Insere Fila
void insere_fila (int i, Fila *ponteiroFila){
    ponteiroFila -> vetor [ponteiroFila -> ultimo] = i;
    //do modo que está implementado ultimo representa a ultima posicao antes do retorno da fila
    ponteiroFila -> ultimo = proxima (ponteiroFila, ponteiroFila -> ultimo);
    ponteiroFila -> contador++;
}

//Remove Fila
int remove_fila (Fila *ponteiroFila){
    int auxiliar = ponteiroFila -> vetor [ponteiroFila -> primeiro];
    ponteiroFila -> primeiro = proxima(ponteiroFila, ponteiroFila -> primeiro);
    ponteiroFila -> contador --;
    return auxiliar;
}

//Mostra Fila
void mostra_fila (Fila *ponteiroFila){
    int i = ponteiroFila -> primeiro;
    printf("\n");
    if (fila_vazia(ponteiroFila))
        printf("fila vazia");
    else{
        do{
            printf("%d", ponteiroFila -> vetor[i]);
            i = proxima(ponteiroFila,i);
        }while (i != ponteiroFila -> ultimo);
        //printf("\n");
    }
}
void mostra_vetor (Fila *ponteiroFila){
    int i;
    if (fila_vazia(ponteiroFila)){
        for(i=0; i<ponteiroFila -> capacidade; i++)
            printf("_");
    }
    else if (fila_cheia(ponteiroFila)){
        for(i=0; i<ponteiroFila -> capacidade; i++)
            printf("%d", ponteiroFila -> vetor[i]);
    }
    else if (ponteiroFila -> primeiro < ponteiroFila -> ultimo){
        for (i=0; i<ponteiroFila -> primeiro; i++) //aceita i++ pq está varrendo o vetor
            printf("_");
        for (i=ponteiroFila -> primeiro; i<ponteiroFila -> ultimo; i++)
            printf("%d", ponteiroFila -> vetor[i]);
        for (i=ponteiroFila -> ultimo; i <ponteiroFila ->capacidade; i++)
            printf("_");
    }
    else{
        for (i=0; i<ponteiroFila -> ultimo; i++)
             printf("%d", ponteiroFila -> vetor[i]);
        for (i=ponteiroFila -> ultimo; i<ponteiroFila -> primeiro; i++ )
            printf("_");
        for (i=ponteiroFila -> primeiro; i<ponteiroFila -> capacidade; i++)
            printf("%d", ponteiroFila -> vetor[i]);
    }
}
