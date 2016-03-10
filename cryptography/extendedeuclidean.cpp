#include<bits/stdc++.h>
using namespace std;

pair<int,int> extendedeuclidean(int r1,int r2,int s1,int s2,int t1,int t2){
	if(r2==0){
		pair<int,int> x;
		x.first = s1;
		x.second = t1;
		return x;
	}
	return extendedeuclidean(r2, r1%r2, s2, s1-r1/r2*s2, t2, t1-r1/r2*t2);
}

int gcd(int a,int b){
	if(b==0)
		return a;
	return gcd(b,a%b);
}

int main(){
	int a,b,result_gcd,multiplicative_inverse;
	pair<int,int> result;

	// input
	scanf("%d%d",&a,&b);
	
	result = extendedeuclidean(a,b,1,0,0,1);
	result_gcd = gcd(a,b);
	
	printf("%d * %d + %d * %d = %d\n",a,result.first,b,result.second,result_gcd);
	
	// multiplicative inverse
	if(result_gcd==1){
		multiplicative_inverse = result.first%b;
		while(multiplicative_inverse<0)
		{
			multiplicative_inverse = multiplicative_inverse+b;
		}
		multiplicative_inverse = multiplicative_inverse%b;
		printf("Multiplicative Inverse: %d\n",multiplicative_inverse);
	}
	else{
		printf("Multiplicative Inverse doesnot exists.\n");
	}
	return 0;
}