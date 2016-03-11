// Circle using mid point algorithm with float radius and center

#include<stdio.h>
#include<graphics.h>
#include<math.h>

int midPointCircle(float x,float y,float radius){
	//coordinates output file
   	FILE *coordinates=fopen("coordinates", "w");

	float pinit,pcurr;
	int curr_x,curr_y;

	// calculate the initial decision parameter
	if(floor(radius)-radius==0)
		pinit=1-radius;
	else
		pinit=5.00/4-radius;

	// initialisations
	curr_x=0;
	curr_y=floor(radius);
	pcurr=pinit;

	// operate while loop until x<y
	while(curr_x<=curr_y){
		// output points
		putpixel((int)(curr_x+x),(int)(curr_y+y),RED);
		putpixel((int)(-curr_x+x),(int)(curr_y+y),RED);
		putpixel((int)(curr_x+x),(int)(-curr_y+y),RED);
		putpixel((int)(-curr_x+x),(int)(-curr_y+y),RED);
		putpixel((int)(curr_y+y),(int)(curr_x+x),RED);
		putpixel((int)(-curr_y+y),(int)(curr_x+x),RED);
		putpixel((int)(curr_y+y),(int)(-curr_x+x),RED);
		putpixel((int)(-curr_y+y),(int)(-curr_x+x),RED);
		fprintf(coordinates,"%d %d\n",(int)(curr_x+x),(int)(curr_y+y));
		fprintf(coordinates,"%d %d\n",(int)(-curr_x+x),(int)(curr_y+y));
		fprintf(coordinates,"%d %d\n",(int)(curr_x+x),(int)(-curr_y+y));
		fprintf(coordinates,"%d %d\n",(int)(-curr_x+x),(int)(-curr_y+y));
		fprintf(coordinates,"%d %d\n",(int)(curr_y+y),(int)(curr_x+x));
		fprintf(coordinates,"%d %d\n",(int)(-curr_y+y),(int)(curr_x+x));
		fprintf(coordinates,"%d %d\n",(int)(curr_y+y),(int)(-curr_x+x));
		fprintf(coordinates,"%d %d\n",(int)(-curr_y+y),(int)(-curr_x+x));

		// algo
		if(pcurr<0){
			curr_x+=1;
			pcurr=pcurr+2*curr_x+1;
		}
		else{
			curr_x+=1;
			curr_y-=1;
			pcurr=pcurr+2*curr_x+1-2*curr_y;
		}
	}

	// close the output file
	fclose(coordinates);
	return 0;
}

int main(int argc,char *argv[]){
   
    //command-line parameters check
    if(argc<3){
       printf("Enter 3 arguments on commandine\n");
       return 0;
    }

	//get the center and radius
    float x,y,radius;
    x=atoi(argv[1]);
    y=atoi(argv[2]);
    radius=atof(argv[3]);

    // check if x and y are greater than radius else pixel out of range will be there
    if(x<radius||y<radius){
   		printf("Circle cannot be displayed\nAs x and y are less than radius so there will be pixel out of range.\n");
   		return 0;
    }

    //graphics initialisation
    int gd = DETECT,gm;
    initgraph(&gd,&gm,NULL);

    //Circle drawn from inbuilt library to check performance of ours
    putpixel(x,y,YELLOW);
    circle((int)x,(int)y,(int)radius);

    //Draw the circle using Trignometric algo
    midPointCircle(x,y,radius);

    //delay so as to view the screen
    delay(5000);
	return 0;
}