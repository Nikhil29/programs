//Bresnham's Line algorithm

#include<graphics.h>
#include<stdio.h>

// absolute i.e mod of x
int abs(int x){
   if(x<0)
      return -x;
   else
      return x;
}

int main(int argc,char *argv[]){
   // command line arguments check
   if(argc<5){
      printf("Enter coordinates of end points of line on commandine\n");
      return -1;
   }

   // coordinates output file
   FILE *coordinates=fopen("coordinates", "w");

   // commandline input
   int x1,x2,y1,y2;
   int p_curr,currx,curry;
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

   // Initialise graphics
   int gd = DETECT,gm;
   initgraph(&gd,&gm,NULL);
   
   //slope
   float m=((float)y2-y1)/(x2-x1);
   int dx=abs(x2-x1);
	int dy=abs(y2-y1);
   putpixel(x1, y1, RED);

   // algorithm
	if(m<=1 && m>=-1){
		currx=x1;
		curry=y1;
		p_curr=2*dy-dx;
   	putpixel(x1,y1,RED);
      if(m>=0){
      	for(currx=x1+1;currx<=x2;currx++){
      		if(p_curr>=0){
      			curry++;
      			p_curr=p_curr+2*dy-2*dx;
      		}
      		else{
      			p_curr=p_curr+2*dy;
      		}
            fprintf(coordinates,"%d %d\n",currx,curry);
      		putpixel(currx,curry,RED);
      	}
      }
      else{
         for(currx=x1+1;currx<=x2;currx++){
            if(p_curr>=0){
               curry--;
               p_curr=p_curr+2*dy-2*dx;
            }
            else{
               p_curr=p_curr+2*dy;
            }
            fprintf(coordinates,"%d %d\n",currx,curry);
            putpixel(currx,curry,RED);
         }
      }
	}

   // delay to able to view graphics
	delay(5000);
	return 0;
}