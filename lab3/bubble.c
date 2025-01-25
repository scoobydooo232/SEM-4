#include<stdio.h>

void bubble(int arr[100],int n){
	for(int i = 0;i<n;i++){
		for(int j = 0;j < n -i-1;j++){
			if(arr[j] > arr[j+1]) {
				int temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
			}
		}
	}
}
void main(){
	int n;
	printf("Enter your array size");
	scanf("%d",&n);
	int arr[n];
	printf("Enter your array");
	for(int i = 0;i<n;i++){
		scanf("%d",&arr[i]);
	}

	bubble(arr,n);
	for(int i = 0;i<n;i++){
		printf("%d \t",arr[i]);
	}

}