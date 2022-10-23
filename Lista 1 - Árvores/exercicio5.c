#include <stdio.h>
#include <limits.h>

typedef struct ab {
    int info;
    struct ab *esq, *dir;
} TAB;

//Testar se uma árvore é zigue-zague, isto é, todos os nós internos possuem exatamente uma sub-árvore vazia: int zz(TAB *a);

int zz(TAB *a) {
    //Caso o nó seja 
    if (!a) {
        return 1;
    }

    return (((a->esq && !a->dir) || (!a->esq && a->dir) || (!a->esq && !a->dir)) && zz(a->dir) && zz(a->esq));
}