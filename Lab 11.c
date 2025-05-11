#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void merge(int arr[], int left, int mid, int right){
    int i, j, k;
    int n1=mid-left+1;
    int n2=right-mid;
    int *L=(int *)malloc(n1*sizeof(int));
    int *R=(int *)malloc(n2*sizeof(int));
    for(i=0; i<n1; i++)
        L[i]=arr[left+i];
    for(j=0; j<n2; j++)
        R[j]=arr[mid+1+j];
    i=0; j=0;
    k=left;
    while(i<n1 && j<n2){
        if(L[i]<=R[j]){
            arr[k]=L[i];
            i++;
        }
        else{
            arr[k]=R[j];
            j++;
        }
        k++;
    }
    while(i<n1){
        arr[k]=L[i];
        k++; i++;
    }
    while(j<n2){
        arr[k]=R[j];
        k++;j++;
    }
    free(L);
    free(R);
}

void MergeSort(int arr[], int left, int right){
    if(left<right){
        int mid=left+(right-left)/2;
        MergeSort(arr, left, mid);
        MergeSort(arr, mid+1, right);
        merge(arr, left, mid, right);
    }
}

void generateRandomNumbers(int arr[], int n){
    for(int i=0; i<n; i++){
        arr[i]=rand()%100000;
    }
}

int main(){
    int i, n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    if(n<=5000){
        printf("Enter a number greater than 5000.\n");
        return 1;
    }
    int *arr=(int *) malloc(n*sizeof(int));
    if(arr==NULL){
        printf("Memory allocation failed.\n");
        return -1;
    }
    generateRandomNumbers(arr, n);
    clock_t start=clock();
    for(i=0; i<1000; i++){
        MergeSort(arr, 0, n-1);
    }
    clock_t end=clock();
    double time_taken=((double) (end-start))/CLOCKS_PER_SEC/1000.0;
    printf("Time taken: %f", time_taken);
    free(arr);
    return 0;
}