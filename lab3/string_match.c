#include<stdio.h>
#include<string.h>

int match(char string1[100],char string2[100],int n,int m){
	for(int i = 0;i < n-m + 1;i++){
		int flag = 1;
		for(int j = 0;j < m ;j++){
			if(string2[j] != string1[j+i]){
				flag = 0;
				break;
			}
		}

		if(flag) return i;
	}

	return -1;
}



void main(){
	char string1[100];
	char string2[100];
	printf("enter string1 ");
	gets(string1);
	printf("enter string2 ");
	gets(string2);
	int n = strlen(string1);
	int m = strlen(string2);
	int result = match(string1,string2,n,m);

	printf("result %d" ,result);

}