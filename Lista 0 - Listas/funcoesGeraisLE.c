#include <stdio.h>
#include <stdlib.h>

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

TLista * insereInicio(TLista * a, int value) {
    //Criando novo nó
    TLista * novo = (TLista *) malloc(sizeof(TLista));
    novo->info = value;
    novo->prox = a;

    //Caso a lista esteja vazia, o novo nó se torna o primeiro nó
    if (!a) {
        return novo;
    }


    return novo;
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

int main(void) {
    TLista * head = inicializa(0);
    head = insereInicio(head, 10);
    head = insereInicio(head, 9);
    head = insereInicio(head, 187);
    head = insereInicio(head, 1);

    imprimeLista(head);

    remover(head, 10);

    imprimeLista(head);

}