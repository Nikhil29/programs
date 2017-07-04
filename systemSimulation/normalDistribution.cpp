#include<bits/stdc++.h>
#include<unistd.h>
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

class normalDistributionRandomNumber{
public: 
	double sigma, mu;

	normalDistributionRandomNumber(){
		sigma = 0.5;
		mu = 0;
	}
	normalDistributionRandomNumber(double mu, double sigma){
		this->mu = mu;
		this->sigma = sigma;
	}

	double rand(){
		residueRandomNumber r = residueRandomNumber();
		double z=0;
		for(int i=0;i<12;i++){
			z += (1.00 * r.rand() / (r.mod - 1));
		}
		z -= 6;	
		return mu + z*sigma;
	}
};

int main(){
	double sigma, mu, z;
	printf("Enter the mean and standard deviation\n");
	scanf("%lf %lf", &mu, &sigma);

	normalDistributionRandomNumber r = normalDistributionRandomNumber(mu, sigma);
	while(1){
		printf("%lf\n", r.rand());
		sleep(1);
	}
	return 0;
}