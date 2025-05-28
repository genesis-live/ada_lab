#include <stdio.h>
#define INF 999

int prim(int c[10][10], int n, int s){
    int v[10], ver[10], d[10], sum=0, i, j, min, u;
    for(i=1; i<=n; i++){
        ver[i]=s;
        d[i]=c[s][i];
        v[i]=0;
    }
    v[s]=1;
    for(i=1; i<=n-1; i++){
        min=INF;
        for(j=1; j<=n; j++)
        if(v[j]==0 && d[j]<min){
            min=d[j];
            u=j;
        }
        v[u]=1;
        sum=sum+d[u];
        printf("\n%d to %d sum= %d", ver[u], u, sum);
        for(j=1; j<=n; j++)
            if(v[j]==0 && c[u][j]<d[j]){
                d[j]=c[u][j]; 
                ver[j]=u;
            }
    }
    return sum;
}

int main(){
    int c[10][10], n, s, i, j, res;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    printf("Enter the graph data: \n");
    for(i=1; i<=n; i++)
        for(j=1; j<=n; j++)
            scanf("%d", &c[i][j]);
    printf("Enter the source node: ");
    scanf("%d", &s);
    res=prim(c,n,s);
    printf("\nCost: %d", res);
    return 0;
}
/*
Enter the number of nodes: 6
Enter the graph data: 
0 60 10 999 999 999
60 0 999 20 40 70
10 999 0 999 999 50
0 20 999 0 999 999
999 40 999 999 0 30
999 70 50 80 30 0
Enter the source node: 1

1 to 3 sum= 10
3 to 6 sum= 60
6 to 5 sum= 90
5 to 2 sum= 130
2 to 4 sum= 150
Cost: 150
*/
