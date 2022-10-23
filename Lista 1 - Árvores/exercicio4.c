#include <stdio.h>
#include <limits.h>

typedef struct ab {
    int info;
    struct ab *esq, *dir;
} TAB;

//Retornar o maior elemento da árvore binária: int maior(TAB *a);

int maior (TAB *a) {
    //Caso o nó esteja vazio, returna o menor inteiro possível (para não influenciar);
    if (!a) {
        return INT_MIN;
    }

    //Maior nó assuimdo como o nó a, pega o maior nó da esquerda e da direita.
    int res = a->info;
    int eres = maior(a->esq);
    int dres = maior(a->dir);

    //Testa qual o maior e o armazena na variável res.
    if (eres > res) {
        res = eres;
    }

    if (dres > res) {
        res = dres;
    }

    return res;
}