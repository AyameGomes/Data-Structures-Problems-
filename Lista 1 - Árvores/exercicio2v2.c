#include <stdio.h>

typedef struct ab {
    int info;
    struct ab *esq, *dir;
} TAB;

/*Escreva uma função em C que faz o espelho de uma árvore binária (o que está
à esquerda na árvore original, estará a direita no espelho, e vice-versa): TAB*
espelho(TAB *a);*/

//Versão sem criar uma nova árvore, espelhando a original.

TAB* espelho(TAB *a) {
    //Caso base: o nó não existe.
    if (!a) {
        return NULL;
    }

    //Variável auxiliar.
    TAB * temp;

    //Chamando a função recursivamente para as subárvores.
    espelho(a->esq);
    espelho(a->dir);

    //Invertendo.
    temp = a->esq;
    a->esq = a->dir;
    a->dir = temp;

    return a;
}