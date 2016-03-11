// rsa encryption algorithm

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

// check if prime number
int checkPrime(int x){
	int i;
	for(i=2;i<=sqrt(x);i++){
		if(x%i==0)
			return 0;
	}
	return 1;
}

int main(){
	int temp,prime;

	// get the prime number p
	while(1){
		// find the random number
		temp=random();

		// check if the random number is prime number
		prime=checkPrime(temp);
		if(temp==1)
			break;
	}

	// get the prime number q
	while(1){
		// find the random number
		temp=random();

		// check if the random number is prime number
		prime=checkPrime(temp);
		if(temp==1)
			break;
	}

	phi=(p-1)*(q-1);
	n=p*q;

	// e=
	d=multiplicativeInverse(e);

	return 0;
}