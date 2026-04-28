#include <stdio.h>
#include <stdlib.h>
#define TAMANHO 31

typedef struct Node{
    
    int key;
    int value;
    struct Node* next;

}Node;

Node* table[TAMANHO];

void inserir(int key, int value){

    int index= abs(key)%TAMANHO;

    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->key=key;
    newNode->value=value;

    newNode->next=table[index];
    table[index] = newNode;

}

Node* search(int key){

    int index = abs(key)%TAMANHO;
    Node* node = table[index];

    while(node!=NULL){
        
        if(node->key==key){
            return node;
        }
        node=node->next;

    }
    return NULL;
    
}

int main(){

}