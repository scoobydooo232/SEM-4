#include<stdio.h>

void warshall(int R[][10], int n){

	for(int k=0; k<n;k++){
		for(int i=0; i<n; i++){
			for(int j=0; j<n; j++){
				R[i][j]=(R[i][j] ||(R[i][k] && R[k][j]));
			}
		}
		for(int i=0; i<n; i++){
			for(int j=0; j<n; j++){
				printf("%d\t", R[i][j]);
			}
			printf("\n");
		}
		printf("\n");
	}

	printf("Transitive Closure Graph:\n");
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			printf("%d\t", R[i][j]);
		}
		printf("\n");
	}
}

int main(){
	int n;

	printf("Enter the size of the matrix:");
	scanf("%d", &n);

	int adjMat[10][10];

	printf("Enter elements:\n");
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

	warshall(adjMat,n);


}