#include <stdio.h>

void merge(int* v, int left, int mid, int right){

    int n1 = mid-left+1;
    int n2=right-mid;

    int v1[n1],v2[n2];

    for(int i=0;i<n1;i++){
        v1[i]=v[left+i];
    }
    for(int i=0;i<n2;i++){
        v2[i]=v[mid+1+i];
    }

    int i=0,j=0,k=left;
    while(i<n1&&j<n2){
        if(v1[i]<=v2[j]){
            v[k]=v1[i];
            i++;
        }
        else{
            v[k]=v2[j];
            j++;
        }
        k++;
    }

    while(i<n1){
        v[k]=v1[i];
        i++;
        k++;
    }

    while(j<n2){
        v[k]=v2[j];
        j++;
        k++;
    }

}   

void mergeSort(int* v, int left, int right){

    if(left>=right) return;

    int mid = left + (right-left)/2;
    mergeSort(v, left, mid);
    mergeSort(v,mid+1,right);
    merge(v,left,mid,right);
}

/*
int main() {
    int data[] = {67, 12, 5, 90, 34, 1};
    int n = sizeof(data) / sizeof(data[0]);

    printf("Original: ");
    for(int i = 0; i < n; i++) printf("%d ", data[i]);

    mergeSort(data, 0, n - 1);

    printf("\nSorted:   ");
    for(int i = 0; i < n; i++) printf("%d ", data[i]);
    printf("\n");

    return 0;
}
*/