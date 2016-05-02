#include<bits/stdc++.h>
using namespace std;
#include<graphics.h>

int main(){
	int gd=DETECT,gm;
	int x[4],y[4],px,py,i;
	double t;

	// take input
	cout<<"Enter four control points for Bezier curve: ";
	for(i=0;i<4;i++) 
		cin>>x[i]>>y[i];
	
	// graphics initialisation
	initgraph(&gd,&gm,NULL);
	setbkcolor(WHITE);
	setcolor(BLACK);
	setfontcolor(BLACK);

	// bezier curve
	printf("\n\tBezier Curve for points: (%d, %d) (%d, %d) (%d, %d) (%d, %d)\n", x[0], y[0], x[1], y[1], x[2], y[2], x[3], y[3]);
	for(t=0.0;t<=1.0;t+=0.001){
		px=(1-t)*(1-t)*(1-t)*x[0]+3*t*(1-t)*(1-t)*x[1]+3*t*t*(1-t)*x[2]+t*t*t*x[3];
		py=(1-t)*(1-t)*(1-t)*y[0]+3*t*(1-t)*(1-t)*y[1]+3*t*t*(1-t)*y[2]+t*t*t*y[3];
		putpixel(px,py,getcolor());
		delay(2);
	}
	delay(5000);
	closegraph();
}