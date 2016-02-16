// dda algorithm for line drawing.
// Provide the line coordinates at commandline.

#include<graphics.h> 
#include<stdio.h>

int main(int argc,char *argv[])
{
   if(argc<5){
      printf("Enter coordinates of end points of line on commandine\n");
      return -1;
   }

   //coordinates output file
   FILE *coordinates=fopen("coordinates", "w");

   //commandline input
   int i,j,x1,x2,y1,y2;
   float currx,curry;
   x1=atoi(argv[1]);
   y1=atoi(argv[2]);
   x2=atoi(argv[3]);
   y2=atoi(argv[4]);

   //if coordinates are not in increasing order of x then make them
   if(x1>x2){
      int temp=x1;
      x1=x2;
      x2=temp;
      temp=y1;
      y1=y2;
      y2=temp;
   }
   
   //graphics initialise
   int gd = DETECT,gm;
   initgraph(&gd,&gm,NULL);

   //draw line using line function to check the correctness of the algo
   line(x1,y1,x2,y2);

   //find the slope
   float m=((float)y2-y1)/(x2-x1);

   if(m<=1&&m>=-1){
      putpixel(x1,y1,RED);
      currx=x1;
      curry=y1;
      while(currx!=x2){
         currx+=1;
         curry=curry+m;
         fprintf(coordinates, "%d %d\n",(int)currx,(int)curry);
         putpixel((int)currx,(int)curry,RED);
      }
   }

   if(m>1||m<-1){
      if(m>1){
         putpixel(x1,y1,RED);
         currx=x1;
         curry=y1;
         while(curry!=y2){
            curry+=1;
            currx=currx+1/m;
            fprintf(coordinates,"%d %d\n",(int)currx,(int)curry);
            putpixel((int)currx,(int)curry,RED);
         }
      }
      else{
         putpixel(x2,y2,RED);
         currx=x2;
         curry=y2;
         while(curry!=y1){
            curry+=1;
            currx=currx+1/m;
            fprintf(coordinates, "%d %d\n",(int)currx,(int)curry);
            putpixel((int)currx,(int)curry,RED);
         }
      }
   }

   delay(5000);
   closegraph();
   return 0;
}