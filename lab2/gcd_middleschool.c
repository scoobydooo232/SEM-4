#include<stdio.h>


int PF(int m,int pf_m[],int index_m){
	for(int i = 2;i<= m;i++){
		if(m%i == 0){
			while(m%i == 0){
				m = m/i;
				pf_m[index_m] = i;
				index_m++;
			}
			
		}
	}

	return index_m;
}



int GCD(int m,int n){

	if(m == 0 || n == 0){
		return 0;
	}
	if(m == 1 || n == 1){
		return 1;
	}

	int pf_m[m];
	int pf_n[n];
	int index_m = 0;
	int index_n = 0;


	index_m = PF(m,pf_m,index_m);
	index_n = PF(n,pf_n,index_n);

	int i = 0;
	int j = 0;
	int result = 1;

	while(i <= index_m && j <= index_n){
		if(pf_m[i] == pf_n[j]){
			result = result*pf_m[i];
			i++;
			j++;
		}
		else if(pf_m[i] < pf_n[j]){
			i++;
		}else{
			j++;
		}
	}

	return result;

}


void main(){
	int m,n;
	printf("enter the numbers m and n\n");
	scanf("%d %d",&m,&n);
	int gcd = GCD(m,n);
	printf("GCD OF M AND N USING MIDDLE SCHOOL METHOD %d \n",gcd);
}
