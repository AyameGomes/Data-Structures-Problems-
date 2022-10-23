/* Escreva uma função TLista *inverter_mn(TLista *L, int n, int
m). A função deve verificar se existe uma sequência de valores na lista L que
começa em n e termina em m. Caso a sequência exista, inverta a ordem dos
elementos que estão entre n e m nessa lista. Assuma que a lista não pode ter
números repetidos. Exemplo: para n = 10 e m = 40 para a lista de entrada -20 ->
10 -> 15 -> 90 -> 40 -> 56, temos como saída -20 -> 10 -> 90 -> 15 -> 40 -> 56. */

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

    } else {
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

TLista * insereOrdenado(TLista * a, int value) {
    TLista * novo = (TLista *) malloc(sizeof(TLista));
    novo->info = value;
    novo->prox = NULL;

    if (a == NULL) {
        return novo;
    }

    TLista * ant = NULL;
    TLista * aux = a;

    while(aux != NULL && aux->info < value) {
        ant = aux;
        aux = aux->prox;
    }

    novo->prox = aux;
    if (ant != NULL) {
        ant->prox = novo;
        return a;
    }
    

    return novo;
}

TLista * merge(TLista * a, TLista * b) {
    //criar uma terceira lista, inserir ordenado na nova a lista a, e depois a b

    TLista * novaLista = inicializaNull();

    TLista * aux = a;
    while (aux != NULL) {
        novaLista = insereOrdenado(novaLista, aux->info);
        aux = aux->prox;
    }

    TLista * auxB = b;

    while(auxB != NULL) {
        novaLista = insereOrdenado(novaLista, auxB->info);
        auxB = auxB->prox;
    }

    return novaLista;
}

TLista *inverter_mn(TLista *a, int n, int m) {
    //Caso os valores não estejam na lista.
    if (busca(a, n) == NULL || busca(a, m) == NULL) {
        printf("Valores inválidos!");
        return NULL;
    }

    //Verificar se tem nós na lista entre os inteiros n e m, e invertê-los (não incluso).
    TLista * aux = a;
    TLista * antAux = NULL;

    //Enquanto a lista não acabou e é diferente de n.
    while (aux != NULL && aux->info != n) {
        antAux = aux;
        aux = aux->prox;
    }

    TLista * aux2 = aux;
    TLista * aux2Ant = NULL;
    if(aux->info == n) {
        while(aux2 != NULL && aux2->info != m) {
            aux2Ant = aux2;
            aux2 = aux2->prox;
        }
    }

    //Resultado positivo, os dois valores existem na lista.
    if (aux2->info == m) {
        TLista * ant = aux2Ant;
        TLista * prox = NULL;

        while (aux->info != m) {
            prox = aux->prox;
            //Inverte o ponteiro do nó.
            aux->prox = ant;

            ant = aux;
            aux = prox;
        }
    }

    return a;
}

int main(void) {
    TLista * head = (TLista *) malloc(sizeof(TLista));
    head = NULL;
    head = insereOrdenado(head, 10);
    head = insereOrdenado(head, 187);
    head = insereOrdenado(head, 1);
    head = insereOrdenado(head, 9);
    head = insereOrdenado(head, 92);

    imprimeLista(head);

    head = remover(head, 10);
    head = remover(head, 1);

    //imprimeLista(head);

    //inverter_mn(head, 9, 187);

    imprimeLista(head);

}