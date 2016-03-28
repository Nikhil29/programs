// 2d transformations for a point

#include <bits/stdc++.h>
#include <graphics.h>
using namespace std;

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

int plotPoint(point p){
	putpixel(p.x, p.y, RED);
	return 0;
}

int plotTriangle(point a, point b, point c){
	line(a.x, a.y, b.x, b.y);
	line(b.x, b.y, c.x, c.y);
	line(c.x, c.y, a.x, a.y);
	return 0;
}

int main(int argc,char *argv[]){
	FILE *input=fopen("input", "r");

	// initialisations
	point a,b,c,aFinal,bFinal,cFinal;
	translation t;
	rotation r;
	scale s;
	fscanf(input,"%d%d",&a.x,&a.y);
	fscanf(input,"%d%d",&b.x,&b.y);
	fscanf(input,"%d%d",&c.x,&c.y);
	fscanf(input,"%d%d",&t.x,&t.y);
	fscanf(input,"%f",&r.angle);
	fscanf(input,"%d%d",&s.x,&s.y);

	//graphics initialisation
   	int gd = DETECT,gm;
   	initgraph(&gd,&gm,NULL);
	
	// translation
	plotTriangle(a,b,c);
	aFinal=translatePoint(a,t);
	bFinal=translatePoint(b,t);
	cFinal=translatePoint(c,t);
	sleep(3);
	plotTriangle(aFinal,bFinal,cFinal);

	// rotation
	sleep(3);
	plotTriangle(a,b,c);
	aFinal=rotatePoint(a,r);
	bFinal=rotatePoint(b,r);
	cFinal=rotatePoint(c,r);
	sleep(3);
	plotTriangle(aFinal,bFinal,cFinal);

	// scaling
	sleep(3);
	plotTriangle(a,b,c);
	aFinal=scalePoint(a,s);
	bFinal=scalePoint(b,s);
	cFinal=scalePoint(c,s);
	sleep(3);
	plotTriangle(aFinal,bFinal,cFinal);
	
	//delay so as to view the screen and close the graph
   	delay(50000);
   	closegraph();
   	fclose(input);
	return 0;
}