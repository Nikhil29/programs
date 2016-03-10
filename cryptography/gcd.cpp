#include<bits/stdc++.h>
using namespace std;

int gcd(int a,int b)
{
	if(b==0)
		return a;
	return gcd(b,a%b);
}

int main()
{
	int a,b,x;
	scanf("%d%d",&a,&b);
	x=gcd(a,b);
	printf("GCD: %d\n",x);
}