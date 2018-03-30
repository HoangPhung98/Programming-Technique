#include<stdio.h>
int find_Hn(int n){
	if(n<4) return n;
	else{
		return find_Hn(n-1)+find_Hn(n-2)+find_Hn(n-3)
	}
}
int main(){
	int result = find_Hn(10);
	printf("%d",result);
}
