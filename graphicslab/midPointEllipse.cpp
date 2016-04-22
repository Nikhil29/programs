// make circle using mid point ellipse

#include <bits/stdc++.h>
using namespace std;
#include <graphics.h>

// draw the circle with given integer center and axes
int midPointEllipse(int x,int y,int a,int b){
	int curr_x,curr_y,pcurr;
   FILE *coordinates=fopen("coordinates", "w");

   // initialisations
   curr_x=0;
   curr_y=b;
   pcurr=b*b-a*a*b+a*a/4;
   putpixel(x+curr_x, y+curr_y, getcolor());

   // region 1
   while(2*b*b*curr_x<2*a*a*curr_y){
      if(pcurr<0){
         curr_x++;
         pcurr=pcurr+2*b*b*curr_x+b*b;
      }
      else{
         curr_x++;
         curr_y--;
         pcurr=pcurr+2*b*b*curr_x-2*a*a*curr_y+b*b;
      }
      putpixel(x+curr_x, y+curr_y, getcolor());
      putpixel(x-curr_x, y-curr_y, getcolor());
      putpixel(x+curr_x, y-curr_y, getcolor());
      putpixel(x-curr_x, y+curr_y, getcolor());
      fprintf(coordinates, "%d %d\n", curr_x, curr_y);
   }

   // region 2
   pcurr=b*b*(curr_x+0.5)*(curr_x+0.5)+a*a*(curr_y-1)*(curr_y-1)-a*a*b*b;
   while(curr_y!=0){
      if(pcurr>0){
         curr_y--;
         pcurr=pcurr-2*a*a*curr_y+a*a;
      }
      else{
         curr_x++;
         curr_y--;
         pcurr=pcurr+2*b*b*curr_x-2*a*a*curr_y+a*a;
      }
      putpixel(x+curr_x, y+curr_y, getcolor());
      putpixel(x-curr_x, y-curr_y, getcolor());
      putpixel(x-curr_x, y+curr_y, getcolor());
      putpixel(x+curr_x, y-curr_y, getcolor());
      fprintf(coordinates, "%d %d\n", curr_x, curr_y);
   }

   fclose(coordinates);
	return 0;
}

int main(int argc,char *argv[]){
   
   //command-line parameters check
   if(argc<4){
      printf("Enter 4 arguments on commandine\n");
      return 0;
   }

   //get the center and radius
   int x,y,a,b;
   x=atoi(argv[1]);
   y=atoi(argv[2]);
   a=atoi(argv[3]);
   b=atoi(argv[4]);

   // check for pixel out of range
   if(x<a||y<b){
      printf("Enter center of ellipse such that center points are less than a and b.\nElse therer will be pixel out of range.\n");
      return 0;
   }

   //graphics initialisation
   int gd = DETECT,gm;
   initgraph(&gd,&gm,NULL);
   setbkcolor(WHITE);
   setcolor(BLACK);

   //Draw the ellipse using Trignometric algo
   midPointEllipse(x,y,a,b);

   //delay so as to view the screen
   delay(5000);
	return 0;
}