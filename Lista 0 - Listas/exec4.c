#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct lista {
    int info;
    struct lista *prox;
} TLista;

TLista * busca(TLista * a, int value) {
    TLista * aux = a;

    while (aux != NULL && aux->info != value) {
        aux = aux->prox;
    }

    if (aux != NULL) {
        return aux;
    }

    return NULL;
}

TLista * remover(TLista * a, int value) {
    if (busca(a, value) != NULL) {
        TLista * aux = a;
        TLista * ant = NULL;

        while (aux->info != value) {
            ant = aux;
            aux = aux->prox;
        }

        //Caso seja o único da lista.
        if (aux->prox == NULL && ant == NULL) {
            free(aux);

            return NULL;
        }

        //Caso seja último da lista.
        if (aux->prox == NULL) {
            ant->prox = NULL;
            free(aux);

            return a;
        }

        //Caso seja o primeiro da lista
        if (ant == NULL) {
            TLista * head = aux->prox;
            free(aux);

            return head;
        }

        //Caso esteja no meio.
        if (aux->prox != NULL && ant != NULL) {
            ant->prox = aux->prox;
            free(aux);

            return a;
        }

    }
    else {
        printf("Valor não está na lista.");
        return NULL;
    }
}

TLista * inicializa(int value) {
    TLista * a = (TLista *) malloc(sizeof(TLista));
    a->info = value;
    a->prox = NULL;

    return a; 
}

TLista * inicializaNull() {
    TLista * a = (TLista *) malloc(sizeof(TLista));
    a = NULL;

    return a; 
}

TLista * insereInicio(TLista * a, int value) {
    //Criando novo nó
    TLista * novo = (TLista *) malloc(sizeof(TLista));
    novo->info = value;
    novo->prox = a;

    //Caso a lista esteja vazia, o novo nó se torna o primeiro nó

    return novo;
}

TLista * insereFim(TLista * a, int value) {
    TLista * novo = (TLista *) malloc(sizeof(TLista));
    novo->info = value;
    novo->prox = NULL;

    if (a == NULL) {
        return novo;
    }

    //Criando novo nó

    TLista * aux = a;

    while(aux->prox != NULL) {
        aux = aux->prox;
    }

    aux->prox = novo;

    return a;
}

void imprimeLista(TLista * a) {
    TLista * aux = a;
    
    while (aux) {
        printf("%d ", aux->info);
        printf("\n");

        aux = aux->prox;
    }
    printf("\n Fim da lista. \n");

}

TLista * inverte_vizinhos(TLista *a, int value) {
    if (!a) {
        return NULL;
        printf("Lista vazia!");
    }

    TLista * ant = NULL;
    TLista * aux = a;

    while (aux != NULL) {
        if (aux->info == value && ant != NULL && aux->prox != NULL) {
            int anterior = ant->info;
            ant->info = aux->prox->info;
            aux->prox->info = anterior;
        }

        ant = aux;
        aux = aux->prox;
    }

    return a;
}

TLista * ordenar(TLista *a) {
    if (!a) {
        printf("Lista vazia!");
        return NULL;
    }

    TLista * ordenado = inicializaNull();

    while (a != NULL) {
        int menorValor = INT_MAX;

        TLista * aux = a;

        while (aux != NULL) {
            if (aux->info < menorValor) {
                menorValor = aux->info;
            }

            aux = aux->prox;
        }

        ordenado = insereFim(ordenado, menorValor);
        a = remover(a, menorValor);
    }

    return ordenado;
}

int main(void) {
    TLista * head = (TLista *) malloc(sizeof(TLista));
    head = NULL;
    head = insereFim(head, 10);
    head = insereFim(head, 9);
    head = insereFim(head, 187);
    head = insereFim(head, 1);
    head = insereFim(head, 9);

    imprimeLista(head);

    head = ordenar(head);

    imprimeLista(head);
}