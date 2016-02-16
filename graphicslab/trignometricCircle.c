// Trignometric Algo for drawing the circle

#include<graphics.h>
#include<math.h>
#include<stdio.h>

// draw the circle with given cenetr and radius
int mycircle(int x,int y,int radius){
   float curr_x,curr_y;
   int angle;
   
   for(angle=0;angle<360;angle++){
      curr_x=x+cos((float)angle/180*3.14)*radius;
      curr_y=y+sin((float)angle/180*3.14)*radius;
      putpixel((int)curr_x,(int)curr_y,RED);
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

   //get the center and radius
   int x,y,radius;
   x=atoi(argv[1]);
   y=atoi(argv[2]);
   radius=atoi(argv[3]);

   //Circle drawn from inbuilt library to check performance of ours
   putpixel(x,y,YELLOW);
   circle(x,y,radius);

   //Draw the circle using Trignometric algo
   mycircle(x,y,radius);

   //delay so as to view the screen
   delay(5000);
	return 0;
}