#include<graphics.h>
#include<stdio.h>
int main(int argc,char *argv[]){
	int x1,x2,y1,y2,p_curr,dx,dy,curr_x,curr_y;
	float m;
   	x1=atoi(argv[1]);
   	y1=atoi(argv[2]);
   	x2=atoi(argv[3]);
   	y2=atoi(argv[4]);
   	m=((float)y2-y1)/(x2-x1);
   	// printf("%f\n",m);
   	dx=x2-x1;
   	dy=y2-y1;
   	int gd = DETECT,gm;
   	initgraph(&gd,&gm,NULL);
   	if(m<=1){
   		curr_x=x1;
   		curr_y=y1;
   		p_curr=2*dy-dx;
	   	putpixel(x1,y1,RED);
	   	for(curr_x=x1;curr_x!=x2;curr_x++){
	   		if(p_curr>=0){
	   			curr_y++;
	   			p_curr=p_curr+2*dy-2*dx;
	   		}
	   		else{
	   			p_curr=p_curr+2*dy;
	   		}
	   		putpixel(curr_x,curr_y,RED);
	   	}
   	}
   	delay(5000);
	return 0;
}