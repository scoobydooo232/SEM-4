#include<stdio.h>
#include<limits.h>

void swap(int arr[], int i, int j) {
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

void reverse(int arr[], int start, int end) {
    while (start < end) {
        swap(arr, start, end);
        start++;
        end--;
    }
}

int next_permutation(int arr[], int n) {
    int k = -1;
    for (int i = n - 2; i >= 0; i--) {
        if (arr[i] < arr[i + 1]) {
            k = i;
            break;
        }
    }

    if (k == -1) {
        reverse(arr, 0, n - 1);
        return 0;

    }

    int l = -1;
    for (int i = n - 1; i > k; i--) {
        if (arr[k] < arr[i]) {
            l = i;
            break;
        }
    }

    swap(arr, k, l);
    reverse(arr, k + 1, n - 1);
    return 1;  
}


void assignmentProblem(int n, int cost[n][n]){
    int min_cost=INT_MAX;
    int bestAssignment[10];

    int arr[n];
    for(int i=0;i<n;i++){
        arr[i]=i;
    }


    while(1){

        int total_cost=0;

        for(int i=0; i<n;i++){
            total_cost+=cost[i][arr[i]];
        }

        if(total_cost<min_cost){
            min_cost=total_cost;
            for (int i = 0; i < n; i++) {
                bestAssignment[i] = arr[i];  
            }
        }

        if(!next_permutation(arr,n)){
            break;
        }

    }

    printf("Best cost:%d\n",min_cost);
    printf("Arrangement of agents:");
    for(int i=0;i<n;i++){
        printf("%d\n",bestAssignment[i]+1);
    }

}

int main() {
    int n;
    printf("The number of agents:");
    scanf("%d",&n);

    int cost[n][n];
    printf("Enter the costs:\n");
    for(int i=0; i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&cost[i][j]);
            printf("\n");
        }
    }
    assignmentProblem(n, cost);

    return 0;
}