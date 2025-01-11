#include<stdio.h>


int GCD(int m,int n){
	int smol;
	
	if(m == 0 && n == 0) return 0;

	if(m < n){
		smol = m;
	}else{
		smol = n;
	}

	while(smol != 0){
		if(m%smol == 0 && n%smol == 0) return smol;
		else smol--;
	}

	return smol;
}

void main(){
	int m,n;
	printf("enter the numbers m and n\n");
	scanf("%d %d",&m,&n);
	int gcd = GCD(m,n);
	printf("GCD OF M AND N USING CONSECUTIVE METHOD %d \n",gcd);
}

