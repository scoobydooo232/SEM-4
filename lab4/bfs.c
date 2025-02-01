/*
Lab 4: Program 3
Question:Write a program for breadth-first search of a graph.
*/

#include<stdio.h>
#include<stdlib.h>


void bfs(int n,int a[n][n],int u,int visited[]){
	
	int f=0;int r=-1;
	int q[n];
	q[++r] = u;
	visited[u] = 1;
	printf("Node: %d\n",u+1);
	while(f<=r){
		u = q[f++];
		for(int v = 0;v<n;v++){
			if(a[u][v] == 1 && visited[v] == 0){
				printf("Node: %d\n",v+1);
				visited[v] = 1;
				q[++r] = v;
			}
		}
	}
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
	printf("BFS Traversal\n");
	bfs(n,mat,0,visited);
}