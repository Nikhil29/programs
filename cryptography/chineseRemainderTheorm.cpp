// chinese remainder theorm

#include<bits/stdc++.h>
using namespace std;

// gcd function
int gcd(int a,int b)
{
	if(b==0)
		return a;
	return gcd(b,a%b);
}

// extended eulcidean
pair<int,int> extendedeuclidean(int r1,int r2,int s1,int s2,int t1,int t2){
	if(r2==0){
		pair<int,int> x;
		x.first = s1;
		x.second = t1;
		return x;
	}
	return extendedeuclidean(r2, r1%r2, s2, s1-r1/r2*s2, t2, t1-r1/r2*t2);
}

// multiplicative inverse returns -1 if it doesnot exist
int multiplicativeInverse(int a,int n){
	int inverse;
	if(gcd(n,a)==1){
		inverse=(extendedeuclidean(a,n,1,0,0,1).first)%n;
		if(inverse<0){
			inverse=inverse+n;
		}
		return inverse;
	}
	else{
		return -1;
	}
}

// chinese remainder theorm returns -1 if no solution
int chineseRemainder(int no_eq,int r[],int divisor[]){
	int i,j,temp,M,m[no_eq],m_inverse[no_eq],result;

	// check if the solution exists by checking if all divisors are coprime to each other
	for(i=0;i<no_eq;i++){
		for(j=0;j<no_eq;j++){
			if(i==j)
				continue;
			temp=gcd(divisor[i],divisor[j]);
			if(temp!=1)
				return -1;
		}
	}

	// find the M
	M=1;
	for(i=0;i<no_eq;i++){
		M=M*divisor[i];
	}

	// find array m
	for(i=0;i<no_eq;i++){
		m[i]=M/divisor[i];
	}

	// find array m_inverse
	for(i=0;i<no_eq;i++){
		m_inverse[i]=multiplicativeInverse(m[i],divisor[i]);
	}

	// get the answer
	result=0;
	for(i=0;i<no_eq;i++){
		result=(result+r[i]*m[i]*m_inverse[i])%M;
	}
	return result;
}

int main(){
	int no_eq,i,r[100],divisor[100],result;

	// input
	printf("Enter the number of equations: ");
	scanf("%d",&no_eq);
	printf("Enter the remainder and the divisor of every equation\n");
	for(i=0;i<no_eq;i++){
		scanf("%d%d",&r[i],&divisor[i]);
	}

	result=chineseRemainder(no_eq,r,divisor);

	// output
	if(result==-1){
		printf("No solution Exists\n");
	}
	else{
		printf("Solution for above equations: %d\n",result);
	}
	return 0;
}