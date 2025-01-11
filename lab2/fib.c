#include<stdio.h>


int fib(int n){
	if(n <= 1){ return n;}
	return fib(n-1) + fib(n-2);

}


void main()
{
	int m;
	printf("enter the number   \n");
	scanf("%d",&m);
	int ans = fib(m);
	printf("fib nth number %d" , ans);	

}

