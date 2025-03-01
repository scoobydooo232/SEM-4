#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(int arr[], int n) {

    for(int i=n-1/2 ; i>=0; i--){
        int k=i;
        int v=arr[k];
        int heap=0;

        while(!heap && 2*k<=n-1){
            int j=2*k;

            if(j<n-1){
                if(arr[j]<arr[j+1]){
                    j++;
                }
            }
            if(v>=arr[j]){
                heap=1;
            }
            else{
                arr[k]=arr[j];
                k=j;
            }

        }
        arr[k]=v;
    }
}

void heapSort(int arr[], int n) {

    int k=n;

    for (int i = k - 1; i > 0; i--) {
        swap(&arr[0], &arr[i]);

        k--;

        heapify(arr, k);
    }
}


void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int n;

    printf("Enter the number of nodes:\n");
    scanf("%d", &n);

    int arr[n];

    printf("Enter the elements of the array:\n");
    for(int i=0; i<n; i++){
        scanf("%d", &arr[i]);
    }

    printf("Original array: ");
    printArray(arr, n);

    heapify(arr, n);

    printf("Heap: ");
    printArray(arr, n);

    heapSort(arr,n);

    printf("Sorted array:");
    printArray(arr,n);
    printf("\n");

    return 0;
}