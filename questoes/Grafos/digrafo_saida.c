#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct grafo{
    int n;
    int** matriz;
}grafo;

grafo* cria_grafo(int n){
    grafo* g = malloc(sizeof(grafo));
    g->n=n;

    g->matriz = malloc(sizeof(int*)*n);
    for(int i=0;i<n;i++){
        g->matriz[i]=malloc(sizeof(int)*n);
        for(int j=0;j<n;j++){
            g->matriz[i][j]=0;
        }
    }
    return g;
}

void cria_aresta(grafo* g, int u, int v){
    g->matriz[u][v]=1;
}

bool isNoExit(grafo* g, int u, int n){
    for(int i=0;i<n;i++){
        if(g->matriz[u][i]==1) return false;
    }
    return true;
}

int main() {
    int V, A;
    scanf("%d %d", &V, &A);

    grafo *g = cria_grafo(V);

    int u,v;
    for(int i=0;i<A;i++){
        scanf("%d %d", &u, &v);
        cria_aresta(g,u,v);
    }
    
    int cont=0;
    for(int i=0;i<V;i++){
        if(isNoExit(g,i,V)) cont++;
    }
    printf("%d\n", cont);
    
    return 0;
}