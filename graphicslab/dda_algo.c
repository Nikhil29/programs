// dda algorithm for line drawing.
// Provide the line coordinates at commandline.

#include<graphics.h> 
#include<stdio.h>

int main(int argc,char *argv[])
{
   if(argc<3)
      printf("Enter 4 arguments on commandine\n");
   int i,j,x1,x2,y1,y2;
   float currx,curry;
   x1=atoi(argv[1]);
   y1=atoi(argv[2]);
   x2=atoi(argv[3]);
   y2=atoi(argv[4]);
   int gd = DETECT,gm;
   initgraph(&gd,&gm,NULL);
   line(x1,y1,x2,y2);
   float m=((float)y2-y1)/(x2-x1);
   putpixel(x1,y1,RED);
   currx=x1;
   curry=y1;
   if(m<=1&&m>=-1){
      currx=x1;
      curry=y1;
      while(currx!=x2){
         currx+=1;
         if(m>=0){
            curry=curry+m;
         }
         else{
            //m is negative so take it as it is
            curry=curry+m;
         }
         // printf("%d %d\n",currx,curry);
         putpixel((int)currx,(int)curry,RED);
      }
   }
   if(m>1||m<-1){
      if(m>1){
         currx=x1;
         curry=y1;
         while(curry!=y2){
            curry+=1;
            if(m>=0){
               currx=currx+1/m;
            }
            else{
               //m is negative so take it asit is
               currx=currx+1/m;
            }
            // printf("%d %d\n",currx,curry);
            putpixel((int)currx,(int)curry,RED);
         }
      }
      else{
         currx=x2;
         curry=y2;
         while(curry!=y1){
            curry+=1;
            if(m>=0){
               currx=currx+1/m;
            }
            else{
               //m is negative so take it asit is
               currx=currx+1/m;
            }
            // printf("%d %d\n",currx,curry);
            putpixel((int)currx,(int)curry,RED);
         }
      }
   }
   delay(5000);
   closegraph();
   return 0;
}