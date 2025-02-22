#include<stdio.h>
#include<stdlib.h>

void QuickSort(int arr[], int start, int end);  

int findPartition(int arr[], int start, int end) {
    int l = start + 1;
    int r = end;
    int pivot = arr[start];  
    
    while (l <= r) {
        while (arr[l] <= pivot && l <= end) l++;  
        while (arr[r] > pivot && r >= start) r--;  
        if (l < r) {
            int temp = arr[l];
            arr[l] = arr[r];
            arr[r] = temp;
        }
    }

    
    int temp = arr[start];
    arr[start] = arr[r];
    arr[r] = temp;

    return r;  
 }

void QuickSort(int arr[], int start, int end) {
    if (start >= end) return;  
    int partition = findPartition(arr, start, end);  
    QuickSort(arr, start, partition - 1);  
    QuickSort(arr, partition + 1, end);   
}

int main() {
    int size;
    
    printf("Enter the number of elements in the array: ");
    scanf("%d", &size);

    int arr[size];  
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    QuickSort(arr, 0, size - 1);  

    printf("Sorted array: \n");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}
