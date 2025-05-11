#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void printSolution(int **board, int N){
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            printf("%s ", board[i][j]?"Q":"#");
        }
        printf("\n");
    }
}
bool isSafe(int **board, int N, int row, int col){
    int i, j;
    for(i=0; i<N; i++){
        if(board[row][i])
            return false;
    }
    for(i=row, j=col; i>=0 && j>=0; i--, j--){
        if(board[i][j])
            return false;
    }
    for(i=row, j=col; j>=0 && i<N; i++, j--){
        if(board[i][j])
            return false;
    }
    return true;
}

bool solveNQUtil(int **board, int N, int col){
    if(col>=N)
        return true;
    for(int i=0; i<N; i++){
        if(isSafe(board, N, i, col)){
            board[i][col]=1;
            if(solveNQUtil(board, N, col+1)){
                return true;
            }
            board[i][col]=0;
        }
    }
    return false;
}

int main(){
    int i, j, N;
    printf("Enter the number of queens: ");
    scanf("%d", &N);
    
    int **board=(int **)malloc(N*sizeof(int *));
    for(i=0; i<N; i++){
        board[i]=(int *)malloc(N*sizeof(int));
        for(j=0; j<N; j++){
            board[i][j]=0;
        }
    }

    if(!solveNQUtil(board, N, 0)){
        printf("The solution does not exist. \n");
    }
    else{
        printSolution(board, N);
    }
    for(i=0; i<N; i++){
        free(board[i]);
    }
    free(board);
    return 0;
}