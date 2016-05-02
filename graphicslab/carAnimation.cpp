// car animation

#include <bits/stdc++.h>
using namespace std;
#include <graphics.h>

void drawCar(int xLeftLower,int yLeftLower){
   circle(xLeftLower+50, yLeftLower-25, 25);
   circle(xLeftLower+150, yLeftLower-25, 25);
   rectangle(xLeftLower, yLeftLower-100, xLeftLower+200, yLeftLower-50);
   line(xLeftLower, yLeftLower-100, xLeftLower, yLeftLower-150);
   line(xLeftLower, yLeftLower-150, xLeftLower+150, yLeftLower-150);
   line(xLeftLower+150, yLeftLower-150, xLeftLower+200, yLeftLower-100);
}

int main(int argc,char *argv[]){
   //graphics initialisation
   int gd = DETECT,gm;
   initgraph(&gd,&gm,NULL);
   setbkcolor(WHITE);
   setcolor(BLACK);
   setfontcolor(BLACK);

   //Draw the ellipse using Trignometric algo
   for(int x=50;x<=400;x++){
      cleardevice();
      outtextxy(x, 100, "Animation of a car\n");
      drawCar(x, 300);
      delay(25);
   }

   //delay so as to view the screen
   delay(5000);
	return 0;
}