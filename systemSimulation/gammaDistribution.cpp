#include<bits/stdc++.h>
using namespace std;

class residueRandomNumber{
public: 
	int seed, a, b, mod;

	residueRandomNumber(){
		seed = time(NULL);
		a = 1103515245;
		b = 12345;
		mod = 32768;
	}
	residueRandomNumber(int seed, int a, int b, int modValue){
		this->seed = seed;
		this->a = a;
		this->b = b;
		this->mod = modValue;
	}

	void srand(int seed){
		this->seed = seed;		
	}

	int rand(){
		seed = ((long long int)a*seed + b) % mod;
		return seed;
	}
};

int main(){
	double alpha, beta;
	printf("Enter the value of alpha and beta\n");
	scanf("%lf %lf", &alpha, &beta);

	int a1, a2, index, i;
	double r, p, q, x;
	residueRandomNumber res = residueRandomNumber();
	
	a1 = (int)alpha;
	a2 = a1 + 1;
	q = alpha - a1;
	p = 1;
	i = 0;

	// random number b/w 0 to 1
	r = 1.00 * res.rand() / (res.mod-1);
	p = p*r;

	r = 1.00 * res.rand() / (res.mod-1);
	if(r < q){
		index = a1;
	}
	else{
		index = a2;
	}

	for(; i<index;i++){
		r = 1.00 * res.rand() / (res.mod-1);
		p = p*r;
	}

	x = -1 / beta * log(p);
	printf("%lf\n", x);
}