// Trignometric Algo for drawing the circle

#include<graphics.h>
#include<math.h>
#include<stdio.h>

// draw the circle with given integer center and radius
int trignometricCircle(int x,int y,int radius){
   float curr_x,curr_y;
   int angle;
   FILE *coordinates=fopen("coordinates", "w");
   
   // algo
   for(angle=0;angle<360;angle++){
      curr_x=x+cos((float)angle/180*3.14)*radius;
      curr_y=y+sin((float)angle/180*3.14)*radius;
      putpixel((int)curr_x,(int)curr_y,getcolor());
      fprintf(coordinates, "%d %d\n", (int)curr_x, (int)curr_y);
   }
   return 0;
}

int main(int argc,char *argv[]){
   
   //command-line parameters check
   if(argc<3){
      printf("Enter 3 arguments on commandine\n");
      return 0;
   }

   //graphics initialisation
   int gd = DETECT,gm;
   initgraph(&gd,&gm,NULL);
   setbkcolor(WHITE);
   setcolor(BLACK);

   //get the center and radius
   int x,y,radius;
   x=atoi(argv[1]);
   y=atoi(argv[2]);
   radius=atoi(argv[3]);

   //Draw the circle using Trignometric algo
   trignometricCircle(x,y,radius);

   //delay so as to view the screen
   delay(5000);
	return 0;
}