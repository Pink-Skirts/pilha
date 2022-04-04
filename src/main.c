#include "Pilha.h"

int main() {
    PilhaCh P1 = criarPilha();
    PilhaCh P2 = criarPilha();

    P1 = pushPilha(P1, 'g');
    P1 = pushPilha(P1, 'u');
    P1 = pushPilha(P1, 'g');
    P1 = pushPilha(P1, 'a');
    P1 = pushPilha(P1, 'a');
    P1 = popPilha(P1);

    printf("\n");

    printf("Tamanho: %d elementos\n", obterProfundidade(P1));
    mostrarPilha(P1);
    printf("\nTopo: %c", acessarPilha(P1));

    P2 = copiarPilha(P1, P2);
    printf("\n\n");

    printf("Tamanho: %d elementos\n", obterProfundidade(P1));
    mostrarPilha(P2);
    printf("\nTopo: %c", acessarPilha(P2));

    printf("\n\n");
    P1 = inverter(P1);
    mostrarPilha(P1);

    return 0;
}