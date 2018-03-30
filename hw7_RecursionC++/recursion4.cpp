
#include<stdio.h>
int find_hn(int n){
	if(n>4)return 2*(find_hn(n-1)-find_hn(n-3)+find_hn(n-4))-find_hn(n-5);
	else return n;
}
//long cal_sum(int n){
//	long sum = 0;
//	for(int i=1; i<=n; i++) sum += find_hn(i);
//	return sum;
//}

long cal_sum(int n){
	if(n>4){
		long sum = 10;
		int h1 = 0, h2 = 1, h3 = 2, h4 = 3, h5 = 4;
		int hi;
		for(int i=5; i<=n; i++){
			hi = 2*(h5 - h3 + h2) - h1;
			sum += hi;
			h1 = h2; h2 = h3; h3 = h4; h4 = h5; h5 = hi;
		}
		return sum;
	}else if(n==4) return 10;
		else if(n==3) return 6;
		else if(n==2) return 3;
		else return 1;
}


int main(){
	int n = 20;
	for(int i=1; i<=n; i++){
		printf("%d %d\n",find_hn(i),cal_sum(i));
	}
}
