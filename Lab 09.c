#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void SelectionSort(int arr[], int n){
    int i, j, min_idx;
    for(i=0; i<n-1; i++){
        min_idx=i;
        for(j=i+1; j<n; j++){
            if(arr[j]<arr[min_idx])
                min_idx=j;
        }
        int temp=arr[i];
        arr[i]=arr[min_idx];
        arr[min_idx]=temp;
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
    SelectionSort(arr, n);
    clock_t end=clock();
    double time_taken=((double)(end-start))/CLOCKS_PER_SEC;
    printf("Time taken to sort: %f", time_taken);
    return 0;
}