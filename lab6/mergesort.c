#include <stdio.h>

void merge(int arr[], int temp[], int left, int mid, int right, int *invCount) {
    int i = left;    
    int j = mid + 1; 
    int k = left;    
    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
            *invCount += (mid - i + 1); 
        }
    }

    while (i <= mid) {
        temp[k++] = arr[i++];
    }

    while (j <= right) {
        temp[k++] = arr[j++];
    }

    for (i = left; i <= right; i++) {
        arr[i] = temp[i];
    }
}

void mergeSort(int arr[], int temp[], int left, int right, int *invCount) {
    if (left < right) {
        int mid = (left + right) / 2;

        mergeSort(arr, temp, left, mid, invCount);       
        mergeSort(arr, temp, mid + 1, right, invCount);  

        merge(arr, temp, left, mid, right, invCount);   
    }
}

int main() {
    int n;
    
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];
    int temp[n];
    int invCount = 0;

    printf("Enter the elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    mergeSort(arr, temp, 0, n - 1, &invCount);

    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    printf("Number of inversions: %d\n", invCount);

    return 0;
}
