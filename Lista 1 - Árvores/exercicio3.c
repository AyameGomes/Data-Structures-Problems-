#include <stdio.h>

typedef struct ab {
    int info;
    struct ab *esq, *dir;
} TAB;

/* Escreva uma função em C que, dadas duas árvores deste tipo, testa se estas
árvores são iguais. A função retorna um se elas são iguais e zero, caso
contrário. A função deve obedecer ao seguinte protótipo: int igual(TAB
*a1, TAB* a2); */

int igual(TAB *a, TAB *b) {
    //Caso ambos os nós são vazios, returna verdadeiro.
    if (!a && !b) {
        return 1;
    }

    //Caso uma das árvores é não varia, testa se os valores de a e b são iguais, e faz o mesmo teste para suas subárvores e retorna o resultado.
    return (igual(a->esq, b->esq) && igual(a->dir, b->dir) && (a->info == b->info));
}