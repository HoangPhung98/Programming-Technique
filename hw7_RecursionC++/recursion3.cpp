
#include<stdio.h>
int find_hn(int n){
	if(n>=5)return find_hn(n-1) - find_hn(n-2) + find_hn(n-3) + find_hn(n-4);
	else return n;
}
//long cal_sum(int n){
//	long sum=0;
//	for(int i=1; i<=n; i++) sum += find_hn(i);
//	return sum;
//}

long cal_sum(int n){
	if(n>4){
		int h1 = 4, h2 = 3, h3 = 2, h4 = 1; 
		int hi;
		long sum = 10;
		for(int i=5; i<=n; i++){
			hi = h1 - h2 + h3 + h4;
			sum += hi;
			h4 = h3, h3 = h2; h2 = h1; h1 = hi;
		}
		return sum;
	}else if(n == 4) return 10;
		else if(n==3) return 6;
		else if(n==2) return 3;
		else return 1;
}


int main(){
	int n=20;
	for(int i=1; i<=n; i++){
		printf("%d\n",cal_sum(i));
	}
}
