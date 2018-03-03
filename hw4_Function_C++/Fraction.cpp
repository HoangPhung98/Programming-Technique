#include<iostream>
using namespace std;
struct Fraction{
	int numerator;
	int denominator;
}temp,frt1,frt2,sum1,sum2,sum3,sum4,sum5,sum6,sub1,sub2,sub3,sub4,sub5;
void printFraction(){
printf("frt1 = %d / %d \n",frt1.numerator, frt1.denominator);
printf("frt2 = %d / %d \n \n",frt2.numerator,frt2.denominator);
}
void scanFraction(Fraction &frt){
	printf("Numerator :");
	scanf("%d",&frt.numerator);
	printf("Denominator :");
	scanf("%d",&frt.denominator);
}
//**Add fraction
//fraction+fraction
Fraction operator + (Fraction frt1, Fraction frt2){
	Fraction frtTemp;
	frtTemp.numerator = frt1.numerator*frt2.denominator + frt2.numerator*frt1.denominator;
	frtTemp.denominator = frt1.denominator*frt2.denominator;
	return frtTemp; 
}
//fraction+integer number
Fraction operator + (Fraction frt1,int a){
	Fraction frtTemp;
	frtTemp.numerator = frt1.numerator + a*frt1.denominator;
	frtTemp.denominator = frt1.denominator;
	return frtTemp; 
}
//integer number + fraction
Fraction operator + (int a,Fraction frt1){
	Fraction frtTemp;
	frtTemp.numerator = frt1.numerator + a*frt1.denominator;
	frtTemp.denominator = frt1.denominator;
	return frtTemp; 
}
Fraction operator +=(Fraction &frt1, Fraction frt2){
	frt1.numerator = frt1.numerator*frt2.denominator + frt2.numerator*frt1.denominator;
	frt1.denominator = frt1.denominator*frt2.denominator;
	return frt1;
}
Fraction operator +=(Fraction &frt1, int a){
	frt1.numerator = frt1.numerator + a*frt1.denominator;
	return frt1;
}
Fraction operator ++(Fraction &frt1, int ){
	frt1.numerator = frt1.numerator+frt1.denominator;
	temp.numerator = frt1.numerator;
	temp.denominator = frt1.denominator;
	return temp;
}
Fraction& operator ++(Fraction &frt1){
	frt1.numerator = frt1.numerator+frt1.denominator;
	return frt1;
}
//**Add fraction End/>


//**Sub fraction
//fraction-fraction
Fraction operator - (Fraction frt1, Fraction frt2){
	Fraction frtTemp;
	frtTemp.numerator = frt1.numerator*frt2.denominator - frt2.numerator*frt1.denominator;
	frtTemp.denominator = frt1.denominator*frt2.denominator;
	return frtTemp; 
}
//fraction-integer number
Fraction operator - (Fraction frt1,int a){
	Fraction frtTemp;
	frtTemp.numerator = frt1.numerator - a*frt1.denominator;
	frtTemp.denominator = frt1.denominator;
	return frtTemp; 
}
//integer number - fraction
Fraction operator - (int a,Fraction frt1){
	Fraction frtTemp;
	frtTemp.numerator = a*frt1.denominator - frt1.numerator;
	frtTemp.denominator = frt1.denominator;
	return frtTemp; 
}

Fraction operator -=(Fraction &frt1, Fraction frt2){
	frt1.numerator = frt1.numerator*frt2.denominator - frt2.numerator*frt1.denominator;
	frt1.denominator = frt1.denominator*frt2.denominator;
	return frt1;
}
Fraction operator -=(Fraction &frt1, int a){
	frt1.numerator = frt1.numerator - a*frt1.denominator;
	return frt1;
}
Fraction operator --(Fraction &frt1, int ){
	frt1.numerator = frt1.numerator-frt1.denominator;
	temp.numerator = frt1.numerator;
	temp.denominator = frt1.denominator;
	return temp;
}
Fraction& operator --(Fraction &frt1){
	frt1.numerator = frt1.numerator-frt1.denominator;
	return frt1;
}
//**Sub fraction End/>

//**RUT GON
void Compact(Fraction &frt){
	//tim UCLN
	int r;
	int x = frt.numerator;
	int y = frt.denominator;
	while(y!=0){
		r = x%y;
		x = y;
		y = r;
	}
	frt.numerator /= x;
	frt.denominator /= x;
}
//**RUT GON End />
int main(){
	frt1.numerator = 1;
	frt1.denominator = 2;
	
	frt2.numerator = 1;
	frt2.denominator = 3;
	
	printFraction();
	printf("******************\n");
	
	printf("===== TEST ADD =====\n");
	sum1 = frt1 + frt2;
		printf("Sum1: frt1 + frt2 = %d / %d \n",sum1.numerator, sum1.denominator);
		printFraction();
	sum2 = frt1 + 2;
		printf("Sum2: frt1 + 2 = %d / %d \n",sum2.numerator, sum2.denominator);
		printFraction();
	sum3 = 2 + frt1;
		printf("Sum3: 2 + frt1 = %d / %d \n",sum3.numerator, sum3.denominator);
		printFraction();
	frt1 += frt2;
		printf("frt1+=frt2 = %d / %d \n",frt1.numerator, frt1.denominator);
		printFraction();
	frt1 += 2;
		printf("frt1+=2 = %d / %d \n",frt1.numerator, frt1.denominator);
		printFraction();
	frt1++;
		printf("frt1++ = %d / %d \n",frt1.numerator, frt1.denominator);
		printFraction();
	++frt1;
		printf("++frt1 = %d / %d \n",frt1.numerator, frt1.denominator);
		printFraction();
	//check if ++frt1 return a variable or not
	++frt1.denominator = 2;
	frt1.numerator = 1;
		printf("++frt1 = %d / %d \n",frt1.numerator, frt1.denominator);
		printFraction();
		
	
	printf("===== TEST SUBTRACT =====\n");
	sub1 = frt1 - frt2;
		printf("Sub1: frt1 - frt2 = %d / %d \n",sub1.numerator, sub1.denominator);
		printFraction();
	sub2 = frt1 - 2;
		printf("Sub2: frt1 - 2 = %d / %d \n",sub2.numerator, sub2.denominator);
		printFraction();
	sub3 = 2 - frt1;
		printf("Sub3: 2 - frt1 = %d / %d \n",sub3.numerator, sub3.denominator);
		printFraction();
	frt1 -= frt2;
		printf("frt1-=frt2 = %d / %d \n",frt1.numerator, frt1.denominator);
		printFraction();
	frt1 -= 2;
		printf("frt1-=2 = %d / %d \n",frt1.numerator, frt1.denominator);
		printFraction();
	frt1--;
		printf("frt1-- = %d / %d \n",frt1.numerator, frt1.denominator);
		printFraction();
	--frt1;
		printf("--frt1 = %d / %d \n",frt1.numerator, frt1.denominator);
		printFraction();
	//check if ++frt1 return a variable or not
	--frt1.denominator = 1;
	frt1.numerator = 2;
		printf("--frt1 = %d / %d \n",frt1.numerator, frt1.denominator);
		printFraction();
	
	printf("===== TEST COMPACT =====\n");
	frt1.numerator = 5;
	frt1.denominator = 10;
	Compact(frt1);
	printFraction();
//	scanFraction(frt1);
//	scanFraction(frt2);
	
}

