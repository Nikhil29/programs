// 2d transformations for a point

#include <bits/stdc++.h>
#include <graphics.h>
using namespace std;

// x and y coordinates of a point
class point{
public:
	int x,y;
	point(){
		x=0;
		y=0;
	}
	point(int x,int y){
		this->x=x;
		this->y=y;
	}
};

// x and y are translations in x and y directions
class translation{
public:
	int x,y;
	translation(){
		x=0;
		y=0;
	}
	translation(int x,int y){
		this->x=x;
		this->y=y;
	}
};

// angle is the angle of rotation
class rotation{
public:
	float angle;
	rotation(){
		angle=0;
	}
	rotation(int angle){
		this->angle=angle;
	}
};

// x and y are scaling in x and y directions
class scale{
public:
	int x,y;
	scale(){
		x=0;
		y=0;
	}
	scale(int x, int y){
		this->x=x;
		this->y=y;
	}
};

// xabout signifies if shear is in x direction
// x is the amount of shear about given yAxis
class shear{
public:
	int x,y,xAxis,yAxis;
	bool xAbout,yAbout;
	shear(){
		x=0;
		y=0;
	}
	shear(int x, int y, int xAxis, int yAxis, bool xAbout, bool yAbout){
		this->x=x;
		this->y=y;
		this->xAxis=xAxis;
		this->yAxis=yAxis;
		this->xAbout=xAbout;
		this->yAbout=yAbout;
	}
};

// xAbout and yAbout tells to reflect about x or y axis
class reflection{
public:
	bool xAbout, yAbout;
	reflection(){
		xAbout=0;
		yAbout=0;
	}
	reflection(bool xAbout, bool yAbout){
		this->xAbout=xAbout;
		this->yAbout=yAbout;
	}
};

point translatePoint(point p, translation t){
	p.x+=t.x;
	p.y+=t.y;
	return p;
}

point rotatePoint(point p, rotation r){
	point result;
	result.x=abs((p.x)*cos(r.angle)-(p.y)*sin(r.angle));
	result.y=abs((p.x)*sin(r.angle)+(p.y)*cos(r.angle));
	return result;
}

point scalePoint(point p, scale s){
	p.x=(s.x)*(p.x);
	p.y=(s.y)*(p.y);
	return p;
}

point shearPoint(point p, shear sh){
	if(sh.xAbout){
		p.x = (p.x) + (sh.x) * ((p.y)-(sh.yAxis));
	}
	else if(sh.yAbout){
		p.y = (p.y) + (sh.y) * ((p.x)-(sh.xAxis));
	}
	return p;
}

point reflectPoint(point p, reflection rf){
	if(rf.xAbout){
		p.y = -1*p.y;
	}
	if(rf.yAbout){
		p.x = -1*p.x;
	}
	return p;
}

int plotPoint(point p){
	putpixel(p.x, p.y, getcolor());
	return 0;
}

int plotTriangle(point a, point b, point c){
	line(a.x, a.y, b.x, b.y);
	line(b.x, b.y, c.x, c.y);
	line(c.x, c.y, a.x, a.y);
	return 0;
}

int printPoint(point p){
	printf("(%d, %d)\n",p.x,p.y);
	return 0;
}

int printTriangle(point a, point b, point c){
	printPoint(a);
	printPoint(b);
	printPoint(c);
	return 0;
}

int main(int argc,char *argv[]){
	FILE *input=fopen("input", "r");

	// initialisations
	int temp,temp1;
	point a,b,c,aFinal,bFinal,cFinal;
	translation t;
	rotation r;
	scale s;
	shear sh;
	reflection rf;

	// input coordinates of triangle 
	fscanf(input,"%d%d",&a.x,&a.y);
	fscanf(input,"%d%d",&b.x,&b.y);
	fscanf(input,"%d%d",&c.x,&c.y);

	// translation, rotation and scaling
	fscanf(input,"%d%d",&t.x,&t.y);
	fscanf(input,"%f",&r.angle);
	fscanf(input,"%d%d",&s.x,&s.y);

	// shear , temp=0 implies shear in x else shear in y
	fscanf(input,"%d",&temp);
	if(temp==0){
		sh.xAbout=1;
		fscanf(input,"%d%d", &sh.x, &sh.yAxis);
	}
	else{
		sh.yAbout=1;
		fscanf(input,"%d%d", &sh.y, &sh.xAxis);
	}

	// reflection temp and temp1 signify if reflection about x or y
	fscanf(input, "%d%d", &temp,&temp1);
	if(temp)
		rf.xAbout=1;
	if(temp1)
		rf.yAbout=1;

	// graphics initialisation
   	int gd = DETECT,gm;
   	initgraph(&gd,&gm,NULL);
   	setbkcolor(WHITE);
   	setcolor(BLACK);
	
	// translation
	plotTriangle(a,b,c);
	aFinal=translatePoint(a,t);
	bFinal=translatePoint(b,t);
	cFinal=translatePoint(c,t);
	sleep(3);
	plotTriangle(aFinal,bFinal,cFinal);

	// rotation
	sleep(3);
	cleardevice();
	plotTriangle(a,b,c);
	aFinal=rotatePoint(a,r);
	bFinal=rotatePoint(b,r);
	cFinal=rotatePoint(c,r);
	sleep(3);
	plotTriangle(aFinal,bFinal,cFinal);

	// scaling
	sleep(3);
	cleardevice();
	plotTriangle(a,b,c);
	aFinal=scalePoint(a,s);
	bFinal=scalePoint(b,s);
	cFinal=scalePoint(c,s);
	sleep(3);
	plotTriangle(aFinal,bFinal,cFinal);

	// shear
	sleep(3);
	cleardevice();
	plotTriangle(a,b,c);
	aFinal=shearPoint(a,sh);
	bFinal=shearPoint(b,sh);
	cFinal=shearPoint(c,sh);
	sleep(3);
	plotTriangle(aFinal, bFinal, cFinal);

	// reflection
	// sleep(3);
	// cleardevice();
	aFinal=reflectPoint(a,rf);
	bFinal=reflectPoint(b,rf);
	cFinal=reflectPoint(c,rf);
	// sleep(3);
	// plotTriangle(aFinal, bFinal, cFinal);
	
	//delay so as to view the screen and close the graph
   	delay(5000);
   	closegraph();
   	fclose(input);

   	printTriangle(aFinal, bFinal, cFinal);
	return 0;
}