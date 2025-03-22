#include<stdio.h>

int min(int a, int b){
	return a>b?b:a;
}

void floyds(int D[][10], int n){

	for(int k=0; k<n;k++){
		for(int i=0; i<n; i++){
			for(int j=0; j<n; j++){
				D[i][j]=min(D[i][j],(D[i][k]+D[k][j]));
			}
		}
		
	}
	printf("Distant Matrix of Shortest Paths:\n");
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			printf("%d\t", D[i][j]);
		}
		printf("\n");
	}

}

void main(){
	int n;

	printf("Enter the number of nodes:");
	scanf("%d", &n);

	int adjMat[10][10];

	printf("Enter the number of elements:\n");
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			scanf("%d", &adjMat[i][j]);

		}
	}

	printf("Original Adjacency Matrix:\n");
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			printf("%d\t", adjMat[i][j]);
		}
		printf("\n");
	}

	floyds(adjMat, n);
}
