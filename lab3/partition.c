#include <stdio.h>
#include <stdlib.h>


int sum(int arr[], int n) {
    int total = 0;
    for (int i = 0; i < n; i++) {
        total += arr[i];
    }
    return total;
}


int isPartitionPossible(int arr[], int n) {
    int total_sum = sum(arr, n);

    
    if (total_sum % 2 != 0) {
        return 0;
    }


    int subset_sum = total_sum / 2;

    int total_subsets = 1 << n; // 2^n subsets
    for (int i = 0; i < total_subsets; i++) {
        int subset_sum_current = 0;

       
        for (int j = 0; j < n; j++) {
            if (i & (1 << j)) {
                subset_sum_current += arr[j];
            }
        }

        if (subset_sum_current == subset_sum) {
            return 1; 
        }
    }

    return 0;
}

int main() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter the elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    if (isPartitionPossible(arr, n)) {
        printf("can be partitioned with equal sum.\n");
    } else {
        printf("cannot be partitioned with equal sum.\n");
    }

    return 0;
}
