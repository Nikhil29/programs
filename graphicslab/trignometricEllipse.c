// Trignometric Algo for drawing the ellipse

#include<graphics.h>
#include<math.h>
#include<stdio.h>

// draw the circle with given integer center and axes
int trignometricEllipse(int x,int y,int a,int b){
   float curr_x,curr_y;
   int angle;
   FILE *coordinates=fopen("coordinates", "w");
   
   // algo 
   for(angle=0;angle<360;angle++){
      curr_x=x+a*cos((float)angle/180*3.14);
      curr_y=y+b*sin((float)angle/180*3.14);
      putpixel((int)curr_x,(int)curr_y,getcolor());
      fprintf(coordinates, "%d %d\n", (int)curr_x, (int)curr_y);
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
   setfontcolor(BLACK);

   //Draw the ellipse using Trignometric algo
   printf("\n\tEllipse using Trignometric Algo\n\tCenter: (%d, %d)\n\ta: %d\tb: %d\n", x, y, a, b);
   trignometricEllipse(x,y,a,b);

   //delay so as to view the screen
   delay(5000);
   closegraph();
	return 0;
}