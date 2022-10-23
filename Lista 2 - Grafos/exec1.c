#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct vizinho {
int id_vizinho;
struct vizinho *prox;
}TVizinho;

typedef struct grafo{
    int id_vertice;
    TVizinho *prim_vizinho;
    struct grafo *prox;
}TGrafo;

TGrafo *inicializa(){
    return NULL;
}

void imprime(TGrafo *g){
    TGrafo * aux = g;

    while(aux != NULL){
        printf("Vértice %d\n", aux->id_vertice);
        printf("Vizinhos: ");
        TVizinho *v = aux->prim_vizinho;
        while(v != NULL){
            printf("%d ", v->id_vizinho);
            v = v->prox;
        }
        printf("\n\n");
        aux = aux->prox;
    }
}

TGrafo* busca_vertice(TGrafo* g, int x){
    while((g != NULL) && (g->id_vertice != x)) {
        g = g->prox;
    }
    return g;
}

TVizinho* busca_aresta(TGrafo *g, int v1, int v2){
    TGrafo *pv1 = busca_vertice(g,v1);
    TGrafo *pv2 = busca_vertice(g,v2);
    TVizinho *resp = NULL;
    //checa se ambos os vértices existem
    if((pv1 != NULL) && (pv2 != NULL)) {
        //percorre a lista de vizinhos de v1 procurando por v2
        resp = pv1->prim_vizinho;
        while ((resp != NULL) && (resp->id_vizinho != v2)) {
            resp = resp->prox;
        }
    }
    return resp;
}

TGrafo *insere_vertice(TGrafo *g, int x){
    TGrafo *p = busca_vertice(g, x);
    if(p == NULL){
        p = (TGrafo*) malloc(sizeof(TGrafo));
        p->id_vertice = x;
        p->prox = g;
        p->prim_vizinho = NULL;
        g = p;
    }
    return g;
}

void insere_um_sentido(TGrafo *g, int v1, int v2){
    TGrafo *p = busca_vertice(g, v1);
    TVizinho *nova = (TVizinho *) malloc(sizeof(TVizinho));
    nova->id_vizinho = v2;
    nova->prox = p->prim_vizinho;
    p->prim_vizinho = nova;
}

void insere_aresta(TGrafo *g, int v1, int v2){
    TVizinho *v = busca_aresta(g, v1, v2);
    if(v == NULL)
        insere_um_sentido(g, v1, v2);
        insere_um_sentido(g, v2, v1);
}

void retira_um_sentido(TGrafo *g, int v1, int v2){
    TGrafo *p = busca_vertice(g, v1);
    if(p != NULL) {
        TVizinho *ant = NULL;
        TVizinho *atual = p->prim_vizinho;
        while ((atual) && (atual->id_vizinho != v2)) {
            ant = atual;
            atual = atual->prox;
        }
        if (ant == NULL) //v2 era o primeiro nó da lista
            p->prim_vizinho = atual->prox;
        else
            ant->prox = atual->prox;
        free(atual);
    }
}

void retira_aresta(TGrafo *g ,int v1, int v2){
    TVizinho* v = busca_aresta(g,v1,v2);
    if(v != NULL) {
        retira_um_sentido(g, v1, v2);
        retira_um_sentido(g, v2, v1);
    }
}

TGrafo *retira_vertice(TGrafo *g, int v){
    TGrafo *p = g;
    TGrafo *ant = NULL;
    while((p != NULL) && (p->id_vertice != v)){
        ant = p;
        p = p->prox;
    }
    if(p != NULL) {
        while (p->prim_vizinho != NULL)
            retira_aresta(g, v, p->prim_vizinho->id_vizinho);
        if (ant == NULL)
            g = g->prox;
        else
            ant->prox = p->prox;
        free(p);
    }
    return g;
}


int nos(TGrafo * a) {
    int nos = 0;
    TGrafo * aux = a;

    while(aux != NULL) {
        nos += 1;
        aux = aux->prox;
    }

    return nos;
}

int nv(TGrafo * a) {
    int vertices = 0;

    TGrafo * aux = a;
    while (aux != NULL) {
        TVizinho * vizAux = aux->prim_vizinho;
        while(vizAux != NULL) {
            vertices += 1;
            vizAux = vizAux->prox;
        }
        
        aux = aux->prox;
    }

    return vertices;
}

int main(void) {
    TGrafo * head = inicializa();
    head = insere_vertice(head, 10);
    head = insere_vertice(head, 12);
    head = insere_vertice(head, 17);
    head = insere_vertice(head, 1);

    int teste = nos(head);

    imprime(head);
    printf("%d \n", teste);
}