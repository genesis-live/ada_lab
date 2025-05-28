#include <stdio.h>
#define MAX 100
#define INF 999

int p[MAX], c[MAX][MAX], t[MAX][2];

int find(int v){
    while(p[v])
        v=p[v];
    return v;
}

void union1(int i, int j){
    p[j]=i;
}

void kruskal(int n){
    int i, j, k, u, v, min, res1, res2, sum=0;
    for(k=1; k<n; k++){
        min=INF;
        for(i=1; i<=n; i++){
            for(j=1; j<=n; j++){
                if(i==j)
                    continue;
                if(c[i][j]<min){
                    u=find(i);
                    v=find(j);
                    if(u!=v){
                        res1=i;
                        res2=j;
                        min=c[i][j];

                    }
                }
            }
        }
        union1(res1, find(res2));
        t[k][1]=res1;
        t[k][2]=res2;
        sum=sum+min;
    }
    printf("\nCost of the spanning tree: %d", sum);
    printf("\nEdges of the spanning tree: \n");
    for(i=1; i<n; i++)
        printf("%d->%d\n",t[i][1], t[i][2]);
}

int main(){
    int i, j, n;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    for(i=1; i<=n; i++)
        p[i]=0;
    printf("Enter the graph data: \n");
    for(i=1; i<=n; i++)
        for(j=1; j<=n; j++)
            scanf("%d", &c[i][j]);
    kruskal(n);
    return 0;
}
/*
Enter the number of nodes: 6
Enter the graph data: 
0 6 3 5 999 999
6 0 5 999 3 999
3 5 0 999 6 4
5 999 999 0 999 2
999 3 6 999 0 6
999 999 4 2 6 0

Cost of the spanning tree: 17
Edges of the spanning tree:
4->6
1->3
2->5
3->6
2->3
*/
