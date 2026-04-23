#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int value;
    struct Node* left;
    struct Node* right;
}Node;

Node* createNode(int value){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->value=value;
    newNode->left=newNode->right=NULL;
    return newNode;
}

Node* insertNode(Node* root, int x){

    if(root==NULL){
        return createNode(x);
    }

    if(x>=root->value){
        root->right=insertNode(root->right,x);
    }
    else{
        root->left=insertNode(root->left,x);
    }

    return root;
}

void preOrdem(Node* root){
    if(root==NULL) return;
    printf("%d ", root->value);
    preOrdem(root->left);
    preOrdem(root->right);
}

void Ordem(Node* root){
    if(root==NULL) return;
    Ordem(root->left);
    printf("%d ", root->value);
    Ordem(root->right);
}

void posOrdem(Node* root){
    if(root==NULL) return;
    posOrdem(root->left);
    posOrdem(root->right);
    printf("%d ", root->value);
}

int main(){
    Node* root = NULL;
    int n;
    while(scanf("%d", &n)!=EOF){
        root=insertNode(root,n);
    }

    preOrdem(root);
    printf(".\n");
    Ordem(root);
    printf(".\n");
    posOrdem(root);
    printf(".\n");
}