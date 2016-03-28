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

class randomGenerator{
	int seed;
	public:
		randomGenerator(){
			seed=10005;
		}
		randomGenerator(int x){
			seed=x;
		}
		unsigned int getRandom(){
			seed=seed*1103515245+12345;
			return ((unsigned)(seed/65536) % 32768);
		}
};

// check if prime number
int checkPrime(int x){
	int i;
	for(i=2;i<=sqrt(x);i++){
		if(x%i==0)
			return 0;
	}
	return 1;
}

// fast exponentiation with mod
int power(int p,int q,int mod){
	if(q==0)
		return 1;
	long long int temp=(int)power(p,q/2,mod);
	if(q%2==0)
		temp=(temp*temp)%mod;
	else{
		temp=(temp*temp)%mod;
		temp=(temp*p)%mod;
	}
	return (int)temp;
}

// encrypt the number with rsa
int encryptRsa(int input,int e,int n){
	return power(input,e,n);
}

// decrypt the number with dsa
int decryptRsa(int input,int d,int n){
	return power(input,d,n);
}
int main(){
	int temp,prime,phi,p,q,n,d,e;
	randomGenerator myrand = randomGenerator(time(NULL));

	// get the prime number p
	while(1){
		// find the random number
		temp=myrand.getRandom();

		// check if the random number is prime number
		prime=checkPrime(temp);
		if(prime==1)
			break;
	}
	p=temp;

	// get the prime number q
	while(1){
		// find the random number
		temp=myrand.getRandom();

		// check if the random number is prime number
		prime=checkPrime(temp);
		if(prime==1)
			break;
	}
	q=temp;

	phi=(p-1)*(q-1);
	n=p*q;
	printf("p=%d\nq=%d\nn=%d\n",p,q,n);

	// get e
	while(1){
		// e belongs > 1 and < phi
		e=myrand.getRandom()%(phi-2)+2;
		if(gcd(e,phi)==1)
			break;
	}

	d=multiplicativeInverse(e, phi);
	printf("d=%d\ne=%d\n",d,e);

	int input,encrypt,decrypt;

	// take input
	printf("Enter the number to be encrypted: ");
	scanf("%d", &input);

	// encrypt using rsa
	encrypt=encryptRsa(input, e, n);
	printf("Encrypted: %d\n",encrypt);

	// decrypt using rsa
	decrypt=decryptRsa(encrypt, d, n);
	printf("Decrypted: %d\n",decrypt);

	return 0;
}