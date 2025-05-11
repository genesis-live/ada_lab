#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int *a, int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}

int partition(int arr[], int low, int high){
    int pivot=arr[high];
    int i=low-1;
    for(int j=low; j<=high-1; j++){
        if(arr[j]<pivot){
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i+1], &arr[high]);
    return (i+1);
}

void quickSort(int arr[], int low, int high){
    if(low<high){
        int pi=partition(arr, low, high);
        quickSort(arr, low, pi-1);
        quickSort(arr, pi+1, high);
    }
}

void generateRandomNumber(int arr[], int n){
    for(int i=0; i<n; i++){
        arr[i]=rand()%10000;
    }
}

int main(){
    int i, j, n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    if(n<=5000){
        printf("Enter number greater than 5000, \n");
        return 1;
    }
    int *arr= (int *)malloc(n*sizeof(int));
    if(arr==NULL){
        printf("Failed to allocate memory\n");
        return -1;
    }
    generateRandomNumber(arr,n);
    clock_t start=clock();
    quickSort(arr, 0, n-1);
    clock_t end=clock();
    double time_taken=((double)(end-start))/CLOCKS_PER_SEC;
    printf("Time taken to sort: %f", time_taken);
    return 0;
}