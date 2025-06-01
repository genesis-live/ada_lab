#include <stdio.h>
int w[10], p[10], n;

int max(int a, int b){
    return a>b?a:b;
}

int knapsack(int i, int m){
    if(i==n)
        return w[i]>m?0:p[i];
    if(w[i]>m)
        return knapsack(i+1, m);
    return max(knapsack(i+1, m), knapsack(i+1, m-w[i])+p[i]);
}

int main(){
    int m, i, max_profit;
    printf("Enter the number of objects: ");
    scanf("%d", &n);
    printf("Enter the max capacity: ");
    scanf("%d", &m);
    printf("Enter the profit followed by weight of the objects: \n");
    for(i=1; i<=n; i++)
        scanf("%d%d", &p[i], &w[i]);
    max_profit=knapsack(1, m);
    printf("Max profit: %d", max_profit);
    return 0;
}

/*
Enter the number of objects: 4
Enter the max capacity: 5
Enter the profit followed by weight of the objects: 
12 3
43 5
45 2
55 3
Max profit: 100
*/
