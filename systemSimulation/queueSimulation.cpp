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

class normalDistributionRandomNumber{
public: 
	double sigma, mu;
	residueRandomNumber r;

	normalDistributionRandomNumber(){
		sigma = 0.5;
		mu = 0;
		r = residueRandomNumber();
	}
	normalDistributionRandomNumber(double mu, double sigma){
		this->mu = mu;
		this->sigma = sigma;
		r = residueRandomNumber();
	}

	double rand(){
		double z=0;
		for(int i=0;i<12;i++){
			z += (1.00 * r.rand() / (r.mod - 1));
		}
		z -= 6;	
		return mu + z*sigma;
	}
};

int main(){
	double intervalArrival, cummArrival=0, servBegin=0, servTime=0, servEnd=0, waitTime=0, servIdle=0, totalWaitTime=0, totalServIdle=0;
	normalDistributionRandomNumber arrRand = normalDistributionRandomNumber(10, 2.5);
	normalDistributionRandomNumber servRand = normalDistributionRandomNumber(9, 1.5);
	
	printf("i, intervalArrival, cummArrival, servBegin, servTime, servEnd, waitTime, servIdle\n");
	for(int i=0;i<20;i++){
		intervalArrival = arrRand.rand();
		cummArrival += intervalArrival;
		
		// it has to be done before calculating new serverEnd time
		// waitTime = oldServerEnd Time - newCummulativeArrivalTime
		// thus it is placed after after cummukative arrival time have been calculated
		// and before serverEnd time have been calculated
		if(cummArrival < servEnd){
			waitTime = servEnd - cummArrival;
			servIdle = 0;
		}
		else{
			waitTime = 0;
			servIdle = cummArrival - servEnd;
		}
		
		if(cummArrival>servEnd)
			servBegin = cummArrival;
		else
			servBegin = servEnd;

		servTime = servRand.rand();
		servEnd = servBegin + servTime;

		totalWaitTime += waitTime;
		totalServIdle += servIdle;
		printf("%d %lf %lf %lf %lf %lf %lf %lf\n", i, intervalArrival, cummArrival, servBegin, servTime, servEnd, waitTime, servIdle);
	}

	printf("Avg. Wait Time: %lf\nAvg. Server Idle Time: %lf\n", totalWaitTime/20, totalServIdle/20);
	return 0;
}