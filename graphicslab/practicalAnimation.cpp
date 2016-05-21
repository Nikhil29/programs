#include<bits/stdc++.h>
using namespace std;
#include<graphics.h>

int drawStar(int x, int y){
	line(x, y-110, x-50, y-50);
	line(x, y-110, x+50, y-50);

	line(x-50, y-50, x-100, y-50);
	line(x-100, y-50, x-50, y);

	line(x+50, y-50, x+100, y-50);
	line(x+100, y-50, x+50, y);

	line(x-50, y, x-100, y+70);
	line(x-100, y+70, x, y+20);

	line(x+50, y, x+100, y+70);
	line(x+100, y+70, x, y+20);
	return 0;
}

int main(){
	int gd=DETECT, gm;
	initgraph(&gd, &gm, NULL);

	for(int i=0;i<=200;i++){
		cleardevice();
		drawStar(100, 110+i);
		drawStar(400, 310-i);
		delay(10);
	}

	delay(3000);
	closegraph();
	return 0;
}