#include <stdio.h>
#include <stdlib.h>

typedef struct no {
   int dado;
   struct no *esq, *dir;
}no;

typedef struct Pilha{

    no** dados;
    int topo;
    int capacidade;

}Pilha;

Pilha* criar_pilha(int capacidade) {
    Pilha *p = (Pilha*)malloc(sizeof(Pilha));
    p->capacidade = capacidade;
    p->topo = -1;
    p->dados = (no**)malloc(capacidade * sizeof(no*));
    return p;
}

void empilha(Pilha* p, no* n){

    if(n==NULL) return;
    p->topo++;
    int indice_atual = p->topo;
    p->dados[indice_atual]=n;

}

no* desempilha(Pilha* p){
    if(p->topo==-1) return NULL;
    int indiceDoTopo = p->topo;
    no* node = p->dados[indiceDoTopo];
    p->topo--;
    return node;
    
}

void em_ordem(no* raiz){

    if(raiz==NULL) return;

    Pilha* p = criar_pilha(100);
    no* atual = raiz;

    while(atual!=NULL || p->topo!=-1){

        while(atual!=NULL){
            empilha(p,atual);
            atual=atual->esq;
        }

        atual = desempilha(p);
        printf("%d ", atual->dado);
        atual=atual->dir;

    }

    free(p->dados);
    free(p);

}