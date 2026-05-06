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

void pos_ordem(no* raiz){

    if (raiz == NULL) return;

    // Precisamos de duas pilhas
    Pilha* s1 = criar_pilha(1000);
    Pilha* s2 = criar_pilha(1000);

    empilha(s1, raiz);

    while (s1->topo != -1) {
        no* atual = desempilha(s1);
        
        // Em vez de imprimir, guardamos na s2
        empilha(s2, atual);

        // No Pós-ordem reverso, empilhamos ESQUERDA primeiro
        // para que a DIREITA seja processada antes na s1
        if (atual->esq != NULL) {
            empilha(s1, atual->esq);
        }
        if (atual->dir != NULL) {
            empilha(s1, atual->dir);
        }
    }

    // Agora a s2 contém os nós na ordem: Raiz, Dir, Esq (de cima para baixo)
    // Ao desempilhar, teremos: Esq, Dir, Raiz!
    int primeiro = 1;
    while (s2->topo != -1) {
        no* atual = desempilha(s2);
        if (!primeiro) printf(" ");
        printf("%d", atual->dado);
        primeiro = 0;
    }

    // Limpeza
    free(s1->dados); free(s1);
    free(s2->dados); free(s2);

}