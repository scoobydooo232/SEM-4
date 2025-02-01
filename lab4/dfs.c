/*
Lab 4: Program 2
Question:Write a program for depth-first search of a graph. Identify the push and pop order
of vertices.
*/

#include<stdio.h>
#include<stdlib.h>
#define max 100


void dfs(int n,int mat[n][n],int visited[],int u){

    visited[u] = 1;
    printf("Pushing:%d\n",u+1);
    for(int v = 0;v<n;v++){
        //printf("(u,v) = (%d,%d)\tmat[u][v] = %d\n",u,v,mat[u][v]);
        if(mat[u][v] == 1 && visited[v] == 0){
            //printf("Node %d is adjancent to Node %d\n",u+1,v+1);
            dfs(n,mat,visited,v);
        }
    }
    printf("Popping:%d\n",u+1);
}

void main(){


    int n;
    printf("Enter number of nodes\n");
    scanf("%d",&n);
    int visited[n];
    int mat[n][n];
    for(int i = 0;i<n;i++){
        visited[i] = 0;
        for(int j = 0;j<n;j++){
            mat[i][j] = 0;
        }
    }
    int in;
    for(int i = 0;i<n;i++){
        in = 0;
        while(in != -1){
            printf("\nNode %d is adjancent to Node:(-1 for next node) ",i+1);
            scanf("%d",&in);
            if(in-1 != i && in != -1){
                printf("%d %d\n",i,in-1);
                mat[i][in-1] = 1;
            }

            
        }
    }
    printf("Adjacency matrix\n");
    printf("  ");
    for(int i =0;i<n;i++){
        printf("%d ",i+1);
    }
    printf("\n");
    for(int i =0;i<n;i++){
        printf("%d " ,i+1);
        for(int j =0;j<n;j++){
            printf("%d ",mat[i][j]);
        }
        printf("\n");

    }
    dfs(n,mat,visited,0);

}