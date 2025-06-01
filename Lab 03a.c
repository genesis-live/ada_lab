#include <stdio.h>

int min(int a, int b){
    return a<b?a:b;
}

void floyd(int p[][10], int n){
    int i, j, k;
    for(k=1; k<=n; k++)
        for(i=1; i<=n; i++)
            for(j=1; j<=n; j++)
                p[i][j]=min(p[i][j], p[i][k]+p[k][j]);
}

int main(){
    int a[10][10], n;
    printf("Enter the n value: ");
    scanf("%d", &n);
    printf("Enter the graph data: \n");
    for(int i=1; i<=n; i++)
        for(int j=1; j<=n; j++)
            scanf("%d", &a[i][j]);
    floyd(a, n);
    printf("The shortest path matrix is: \n");
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
    return 0;
}
/*
Enter the n value: 4
Enter the graph data: 
0 999 3 999
2 0 999 999
999 7 0 1
6 999 999 0
The shortest path matrix is: 
0 10 3 4
2 0 5 6
7 7 0 1
6 16 9 0
*/