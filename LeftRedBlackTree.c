#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
enum Color {RED,BLACK};

typedef struct Node{
    int value;
    enum Color color;
    struct Node* left;
    struct Node* right;
}Node;

Node* createNode(int x){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->value = x;
    newNode->color = RED;
    newNode->left=newNode->right=NULL;
    return newNode;
}

bool isBlack(Node* x){
    if(x==NULL) return true;
    return x->color == BLACK;
}   

bool isRed(Node* x){
    if(x==NULL) return false;
    return x->color == RED;
}

Node* riseColor(Node* root){
    root->color = RED;
    root->left->color = BLACK;
    root->right->color = BLACK;
    return root;
}


Node* leftRotate(Node* root){
    Node* a = root->right;
    a->color = BLACK;    
    root->color=RED;
    Node* beta = a->left;
    a->left = root;
    root->right = beta;

    return a;
}

Node* rightRotate(Node* root){
    Node* a = root->left;
    a->color = BLACK;
    root->color = RED;
    Node* beta = a->right;
    a->right = root;
    root->left = beta;

    return a;
}

Node* insertNode(Node* root, int x){
    if(root!=NULL){

        if(x>root->value) root->right = insertNode(root->right,x);
        else root->left = insertNode(root->left,x);

        if(isBlack(root->left) && isRed(root->right)) root = leftRotate(root);
        if(isBlack(root) && isRed(root->left) && isRed(root->left->left)) root = rightRotate(root);
        if(isRed(root->left) && isRed(root->right)) riseColor(root);

        return root;
               
    }
    else return createNode(x);
}

Node* insert(Node* root, int x){

    root = insertNode(root,x);
    root->color=BLACK;
    return root;

}

void Ordem(Node* root){
    if(root==NULL) return;
    Ordem(root->left);
    printf("%d ", root->value);
    Ordem(root->right);
}


int main(){

    Node* root = NULL;
    int n;
    while(scanf("%d", &n)!=EOF){
        root = insertNode(root,n);
    }

    Ordem(root);

}