#include <stdio.h>
#include <stdlib.h>

typedef struct Heap{
    int* data;
    int size;
    int capacity;
}Heap;

void swap(int* a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

Heap* createHeap(int capacity){
    Heap* heap = (Heap*)malloc(sizeof(Heap));
    heap->size = 0;
    heap->capacity = capacity;
    heap->data = (int*)malloc(capacity*sizeof(int));
    return heap;
}

void resizeHeap(Heap* heap){
    heap->capacity*=2;
    int* temp = (int*)realloc(heap->data,heap->capacity*sizeof(int));
    if(temp==NULL) return;
    heap->data = temp;
}

void siftUp(Heap* heap, int i){
    while(i>0){
        int parent = (i-1)/2;
        if(heap->data[i]<heap->data[parent]){
            swap(&heap->data[i],&heap->data[parent]);
            i = parent;
        }
        else break; 
    }
}

void siftDown(Heap* heap, int i){
    while(2*i + 1 < heap->size){
        int left = 2*i+1;
        int right = 2*i+2;
        int largest = left;
        if(right<heap->size && heap->data[right]<heap->data[left]){
            largest = right;
        }

        if(heap->data[i]>heap->data[largest]){
            swap(&heap->data[i],&heap->data[largest]);
            i = largest;    
        }
        else break;
    }
}

void push(Heap* heap, int x){
    if(heap->size==heap->capacity) resizeHeap(heap);

    heap->data[heap->size] = x;
    siftUp(heap,heap->size);
    heap->size++;
}

int pop(Heap* heap){
    if(heap->size<=0) return -1;

    int root = heap->data[0];
    heap->data[0] = heap->data[heap->size-1];
    heap->size--;

    siftDown(heap,0);
    return root;
}

int main() {
    Heap* h = createHeap(10);
    
    int n;
    scanf("%d", &n);
    getchar();

    for(int i=0;i<n;i++){
        char operacao;
        scanf(" %c", &operacao);
        if(operacao=='+'){
            int ano;
            scanf("%d", &ano);
            push(h,ano);
        }
        else if(operacao=='?') printf("%d\n", pop(h));
    }
    
    return 0;
}