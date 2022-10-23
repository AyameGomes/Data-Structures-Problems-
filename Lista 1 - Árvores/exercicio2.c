#include <stdio.h>

typedef struct ab {
    int info;
    struct ab *esq, *dir;
} TAB;

/*Escreva uma função em C que faz o espelho de uma árvore binária (o que está
à esquerda na árvore original, estará a direita no espelho, e vice-versa): TAB*
espelho(TAB *a);*/

TAB* criaNo(int valor) {
    //Aloca memória e cria um novo nó com o valor fornecido como parâmetro e os filhos vazios.
    TAB *novo = (TAB*)malloc(sizeof(TAB));

    novo->info = valor;
    novo->dir = NULL;
    novo->esq = NULL;
}

TAB* espelho(TAB *a) {
    //Caso base: o nó não existe.
    if (!a) {
        return NULL;
    }

    //Cria um novo nó com o valor do nó a.
    TAB * novo = criaNo(a->info);

    //Chama recursivamente a função para a esquerda e a direita da árvore.
    novo->esq = espelho(a->dir);
    novo->dir = espelho(a->esq);

    return novo;
}