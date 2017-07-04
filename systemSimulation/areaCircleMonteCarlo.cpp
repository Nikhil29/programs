#include<bits/stdc++.h>
using namespace std;

double areaOfCircle(int r, int iter){
	srand(time(NULL));

	int total=iter, inside=0;
	double x, y;
	while(iter--){
		x = 1.00 * rand() / RAND_MAX * (2*r) - r;
		y = 1.00 * rand() / RAND_MAX * (2*r) - r;
		if(x*x + y*y <= r*r)
			inside++;
	}
	return 1.00 * inside / total * 2 * r * 2 * r;
}

int main(){
	int r, iter;

	printf("Enter the radius of circle whose area to be found: ");
	scanf("%d",&r);

	printf("Enter the number of iterations: ");
	scanf("%d",&iter);

	printf("Area of Circle: %lf\n", areaOfCircle(r, iter));
	return 0;
}