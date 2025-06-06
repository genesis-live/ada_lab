#include <stdio.h>
#define INF 999

void dijkstra(int c[10][10], int n, int s, int d[10]){
    int v[10], min, u, i, j;
    for(i=1; i<=n; i++){
        d[i]=c[s][i];
        v[i]=0;
    }
    v[s]=1;
    for(i=1; i<=n; i++){
        min=INF;
        for(j=1; j<=n; j++)
            if(v[j]==0 && d[j]<min){
                min=d[j];
                u=j;
            }
        v[u]=1;
        for(j=1; j<=n; j++)
            if(v[j]==0 && (d[u]+c[u][j])<d[j])
                d[j]=d[u]+c[u][j];
   }
}

int main(){
    int n, s, i, j;
    int c[10][10], d[10];
    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    printf("Enter the graph data: \n");
    for(i=1; i<=n; i++)
        for(j=1; j<=n; j++)
            scanf("%d", &c[i][j]);
    printf("Enter the source node: ");
    scanf("%d", &s);
    dijkstra(c,n,s,d);
    for(i=1; i<=n; i++)
        printf("Shorstest distance from %d to %d is %d.\n", s, i, d[i]);
    return 0;
}
/*
Enter the number of nodes: 5
Enter the graph data: 
0 10 3 999 999
999 0 1 2 999
999 4 0 8 2
999 999 999 0 7
999 999 999 9 0
Enter the source node: 5 
Shorstest distance from 5 to 1 is 999.
Shorstest distance from 5 to 2 is 999.
Shorstest distance from 5 to 3 is 999.
Shorstest distance from 5 to 4 is 9.
Shorstest distance from 5 to 5 is 0.
*/