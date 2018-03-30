
#include<stdio.h>
//long find_Hn(int n){
//	if(n>5) return find_Hn(n-1)+find_Hn(n-2)+find_Hn(n-3);
//	else if(n<4) return n;
//	else if(n==4) return 7;
//	else if(n==5)return 13;
//}

long cal_sum(int n){
	int i=0;
	if(n>5){
		int h1 = 3, h2 = 7, h3 = 13;
		int hi;
		long sum = 26;
		for(int i = 6; i<= n ; i++){
			hi = h1 + h2 + h3;
			sum += hi;
			h1 = h2; h2 = h3; h3 = hi;
		}
		return sum;
	}else if(n == 5) return 26;
		else if(n == 4) return 13;
		else if(n == 3) return 6;
		else if(n == 2) return 3;
		else if(n == 1) return 1;
}

int main(){
	int n=10;
	for(int i=1; i<=n; i++){
//		printf("%d ",find_Hn(i));
		printf("%d\n",cal_sum(i));
	}
}
