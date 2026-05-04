#include <stdio.h>

void swap(int* a, int* b){
    int temp = *a;
    *a=*b;
    *b=temp;
}

int middle(int* v, int low, int high){
    int mid = low+(high-low)/2;

    if ((v[low] <= v[mid] && v[mid] <= v[high]) || (v[high] <= v[mid] && v[mid] <= v[low])) return mid;
    else if ((v[mid] <= v[low] && v[low] <= v[high]) || (v[high] <= v[low] && v[low] <= v[mid])) return low;
    else return high;
}

int partition(int* v, int low, int high){

    int pivotIndex = middle(v, low, high);
    swap(&v[pivotIndex], &v[high]);    
    int pivot=v[high];
    int j=low-1;

    for(int i=low;i<high;i++){
        if(v[i]<pivot){
            j++;
            swap(&v[i],&v[j]);
        }
    }
    swap(&v[j+1],&v[high]);
    return j+1;

}

void quickSort(int* v, int low, int high){

    if(low>=high) return;

    int p = partition(v,low,high);
    quickSort(v,low,p-1);
    quickSort(v,p+1,high);

}

/*
int main(){

    int data[] = {67, 12, 5, 90, 34, 1};
    int n = sizeof(data) / sizeof(data[0]);

    printf("Original array: ");
    for(int i = 0; i < n; i++) printf("%d ", data[i]);

    quickSort(data, 0, n - 1);

    printf("\nSorted array:   ");
    for(int i = 0; i < n; i++) printf("%d ", data[i]);
    printf("\n");

    return 0;

}
*/