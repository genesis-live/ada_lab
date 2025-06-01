#include <stdio.h>
#define MAX 100
int p[MAX], w[MAX], x[MAX];
double max_profit;
int n, m, i;

void greedyknapsack(int n, int w[], int p[], int m){
    double ratio[MAX];
    for(i=0; i<n; i++)
        ratio[i]=(double)p[i]/w[i];
    for(i=0; i<n-1; i++){
        for(int j=i+1; j<n; j++){
                if(ratio[i]<ratio[j]){
                    double temp1=ratio[i];
                    ratio[i]=ratio[j];
                    ratio[j]=temp1;

                    int temp2=w[i];
                    w[i]=w[j];
                    w[j]=temp2;

                    temp2=p[i];
                    p[i]=p[j];
                    p[j]=temp2;
                }
        }
    }
    int current_weight=0;
    max_profit=0.0;
    for(i=0; i<n; i++){
        if(current_weight+w[i]<=m){
            x[i]=1;
            current_weight+=w[i];
            max_profit+=p[i];
        }
        else{
            x[i]=(m-current_weight)/(double)w[i];
            max_profit+=x[i]*p[i];
            break;
        }
    }
    printf("Optimal solution for the greedy knapsack problem is: %.1f \n", max_profit);
    printf("Solution vector: ");
    for(i=0; i<n; i++)
        printf("%d ", x[i]);
}

int main(){
    printf("Enter the number of objects: ");
    scanf("%d", &n);
    printf("Enter the profits followed by weights: \n");
    for(i=0; i<n; i++)
        scanf("%d%d", &p[i], &w[i]);
    printf("Enter the max capacity: ");
    scanf("%d", &m);
    greedyknapsack(n,w,p,m);
    return 0;
}
/*
Enter the number of objects: 4
Enter the profits followed by weights: 
23 56
45 78
76 98
78 78
Enter the max capacity: 100
Optimal solution for the greedy knapsack problem is: 78.0 
Solution vector: 1 0 0 0
*/
