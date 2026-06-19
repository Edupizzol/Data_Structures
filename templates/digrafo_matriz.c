#include <stdio.h>
#include <stdlib.h>

typedef struct grafo{
    int n;
    int** matriz;
}grafo;

grafo* cria_digrafo(int n){
    
    grafo *g = malloc(sizeof(grafo));
    g->n = n;
    g->matriz = malloc(sizeof(int*)*n);
    
    for(int i=0;i<n;i++){
        g->matriz[i] = malloc(sizeof(int)*n);
        for(int j=0;j<n;j++){
            g->matriz[i][j]=0;
        }
    }
    return g;
    
}

void insere_aresta(grafo* g, int u, int v){
    
    g->matriz[u][v]=1;
    
}

int encontra_grau_entrada(grafo* g, int v, int n){
    
    int cont=0;
    for(int i=0;i<n;i++){
        if(g->matriz[i][v]==1) cont++;
    }
    
    return cont;
    
}

int encontra_grau_saida(grafo* g, int v, int n){
    
    int cont=0;
    for(int i=0;i<n;i++){
        if(g->matriz[v][i]==1) cont++;
    }
    
    return cont;
    
}

int main() {
    int V, A;
    scanf("%d %d", &V, &A);

    grafo* g = cria_digrafo(V);

    int u,v;
    for(int i=0;i<A;i++){
        scanf("%d %d", &u, &v);
        insere_aresta(g,u,v);
    }

    for(int i=0;i<V;i++){
        printf("%d %d\n", encontra_grau_entrada(g,i,V), encontra_grau_saida(g,i,V));
    }
    
    return 0;
}