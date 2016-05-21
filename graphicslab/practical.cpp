#include<bits/stdc++.h>
using namespace std;
#include<graphics.h>

int main(){
	int gd=DETECT, gm;
	initgraph(&gd, &gm, NULL);

	circle(250, 250, 50);
	
	line(200, 225, 300, 225);
	line(200, 225, 200, 125);
	line(300, 225, 300, 125);
	line(200, 125, 300, 125);

	line(240, 250, 240, 350);
	line(240, 250, 140, 250);
	line(140, 250, 140, 350);
	line(140, 350, 240, 350);

	line(140, 250, 90, 300);
	line(140, 350, 90, 300);

	line(140, 350, 190, 390);
	line(240, 350, 190, 390);

	line(260, 250, 260, 350);
	line(260, 250, 360, 250);
	line(360, 250, 360, 350);
	line(260, 350, 360, 350);

	line(360, 250, 410, 300);
	line(360, 350, 410, 300);

	line(360, 350, 310, 400);
	line(260, 350, 310, 400);

	setcolor(RED);
	floodfill(250, 250, 15);
	floodfill(250, 220, 15);
	floodfill(239, 251, 15);
	floodfill(261, 251, 15);

	setcolor(YELLOW);
	floodfill(250, 130, 15);
	floodfill(190, 300, 15);
	floodfill(310, 300, 15);

	setcolor(GREEN);
	floodfill(120, 300, 15);
	floodfill(200, 375, 15);
	floodfill(380, 300, 15);
	floodfill(300, 375, 15);

	delay(10000);
	closegraph();
	return 0;
}