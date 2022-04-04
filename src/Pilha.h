/**
* Created by Gustavo Scaglione on 01/04/22.
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#ifndef PILHA_PILHA_H
#define PILHA_PILHA_H

#define MAX 10
#define sinal 0
#define fantasma 36

typedef struct {
    int topo; //Indica a posicao do ultimo elemento
    unsigned char vetor[MAX];
}PilhaCh;

/**
 * Interface
 */
PilhaCh criarPilha();
int obterProfundidade(PilhaCh);
void mostrarPilha(PilhaCh);
unsigned char acessarPilha(PilhaCh);
PilhaCh pushPilha(PilhaCh, char);
PilhaCh popPilha(PilhaCh);
PilhaCh esvaziarPilha(PilhaCh);
PilhaCh copiarPilha(PilhaCh, PilhaCh);
PilhaCh inverter(PilhaCh);

/**
 * Implementacao das funcoes
 */
PilhaCh criarPilha(){
    PilhaCh P1;
    P1.topo = sinal; //Sinaliza a posicao do ultimo elemento como 0
    P1.vetor[0] = MAX; //A primeira posicao (0) sempre
    return P1;         //armazena o tamanho alocado do vetor.
}

/**
 * Retorna o valor do topo da pilha, ou seja, a posicao do ultimo item
 */
int obterProfundidade(PilhaCh P1){
    return P1.topo;
}

/**
 * Verifica se a lista esta vazia, de acordo com a posicao
 * do ultimo elemento.
 */
bool verificaVazia(PilhaCh P1){
    bool vazia = false;
    if (P1.topo == sinal)
        vazia = true;
    return vazia;
}

/**Apresenta os elementos armazenados na pilha,
 * a partir do topo, ate a primeira posicao.
*/
void mostrarPilha(PilhaCh P1) {
    int i;
    if (!verificaVazia(P1)) {
        printf("Pilha: ");
        for (i = P1.topo; i > 0; i--)
            printf("%c ", P1.vetor[i]);
    }
    else printf("%c", fantasma);
}

/**
 *Retorna o valor do topo da pilha
 */
unsigned char acessarPilha(PilhaCh P1){
    unsigned char c = fantasma;
    if (!verificaVazia(P1))
        c = P1.vetor[P1.topo];
    return c;
}

/**
 * Insere um elemento na posicao do topo da pilha
 */
PilhaCh pushPilha(PilhaCh P1, char c) {
    if (P1.topo != P1.vetor[0]){
        P1.topo++;
        P1.vetor[P1.topo] = c;
    }
    return P1;
}

/**
 * Remove o elemento armazenado no topo da pilha
 */
PilhaCh popPilha(PilhaCh P1){
    if (P1.topo != sinal)
        P1.topo--;
    return P1;
}

/**
 *  Esvazia a pilha ao resetar o valor do ultimo elemento (topo)
 */
PilhaCh esvaziarPilha(PilhaCh P1){
    P1.topo = 0;
    return P1;
}

/**
 * Copia uma pilha, e a armazena em outra
 */
PilhaCh copiarPilha(PilhaCh P1, PilhaCh P2){
    int i;
    if (!verificaVazia(P1)) {
        P2.topo = P1.topo;
        for (i = P2.topo; i > 0; i--) {
            P2.vetor[i] = P1.vetor[i];
        }
    }
    return P2;
}

/**
 * Inverte todos os elementos da pilha
 */
PilhaCh inverter(PilhaCh P1){
    int i = 1, meio = P1.topo/2, topo;
    unsigned char aux;
    if (!verificaVazia(P1)){
        while (i <= meio + 1) {
            topo = P1.topo;
            aux = P1.vetor[i];
            P1.vetor[i] = P1.vetor[topo];
            P1.vetor[topo] = aux;
            i++;
        }
        return P1;
    }
}


#endif //PILHA_PILHA_H