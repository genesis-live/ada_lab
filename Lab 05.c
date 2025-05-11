#include <stdio.h>
int temp[10], k=0;

void sort(int a[][10], int id[], int n){
    int i, j;
    for(i=1; i<=n; i++){
        if(id[i]==0){
            id[i]=-1;
            temp[++k]=i;
            for(j=1; j<=n; j++){
                if(a[i][j]==1 && id[j]!=-1){
                    id[j]--;
                }
            }
            i=0;
        }
    }
}

int main(){
    int a[10][10], id[10], i, j, n;
    for(i=1; i<=10; i++){
        id[i]=0;
    }
    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    printf("Enter the graph data: \n");
    for(i=1; i<=n; i++)
        for(j=1; j<=n; j++){
            scanf("%d", &a[i][j]);
            if(a[i][j]==1)
                id[j]++;
        }
    sort(a, id, n);
    if(k!=n){
        printf("Topological sorting not possible. \n");
    }
    else{
        printf("\nTopological order: ");
        for(i=1; i<=k; i++){
            printf("%d ", temp[i]);
        }
    }
}