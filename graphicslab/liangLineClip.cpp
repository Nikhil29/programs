#include<bits/stdc++.h>
using namespace std;
#include<graphics.h>

int main()
{
	int gd, gm ;
	int x1 , y1 , x2 , y2 ;
	int wxmin,wymin,wxmax, wymax ;
	float u1 = 0.0,u2 = 1.0 ;
	int p1 , q1 , p2 , q2 , p3 , q3 , p4 ,q4 ;
	float r1 , r2 , r3 , r4 ;
	int x11 , y11 , x22 , y22 ;
	printf("Enter the windows left xmin , top boundry ymin\n");
	scanf("%d%d",&wxmin,&wymin);
	printf("Enter the windows right xmax ,bottom boundry ymax\n");
	scanf("%d%d",&wxmax,&wymax);
	printf("Enter line x1 , y1 co-ordinate\n");
	scanf("%d%d",&x1,&y1);
	printf("Enter line x2 , y2 co-ordinate\n");
	scanf("%d%d",&x2,&y2);
	p1 = -(x2 - x1 ); q1 = x1 - wxmin ;
	p2 = ( x2 - x1 ) ; q2 = wxmax - x1 ;
	p3 = - ( y2 - y1 ) ; q3 = y1 - wymin ;
	p4 = ( y2 - y1 ) ; q4 = wymax - y1 ;

	if( ( ( p1 == 0.0 ) && ( q1 < 0.0 ) ) ||
	( ( p2 == 0.0 ) && ( q2 < 0.0 ) ) ||
	( ( p3 == 0.0 ) && ( q3 < 0.0 ) ) ||
	( ( p4 == 0.0 ) && ( q4 < 0.0 ) ) )
	{
		detectgraph(&gd,&gm);
		initgraph(&gd,&gm,NULL);
		rectangle(wxmin,wymax,wxmax,wymin);
		line(x1,y1,x2,y2);
		line(x1,y1,x2,y2);
		delay(2000);
	}
	else{
		if( p1 != 0.0 )
		{
			r1 =(float) q1 /p1 ;
			if( p1 < 0 )
				u1 = max(r1 , u1 );
			else
				u2 = min(r1 , u2 );
		}
		if( p2 != 0.0 )
		{
			r2 = (float ) q2 /p2 ;
			if( p2 < 0 )
				u1 = max(r2 , u1 );
			else
				u2 = min(r2 , u2 );
		}
		if( p3 != 0.0 )
		{
			r3 = (float )q3 /p3 ;
			if( p3 < 0 )
				u1 = max(r3 , u1 );
			else
				u2 = min(r3 , u2 );
		}
		if( p4 != 0.0 )
		{
			r4 = (float )q4 /p4 ;
			if( p4 < 0 )
				u1 = max(r4 , u1 );
			else
				u2 = min(r4 , u2 );
		}

		if( u1 > u2 )
			printf("line rejected\n");
		else
		{
			x11 = x1 + u1 * ( x2 - x1 ) ;
			y11 = y1 + u1 * ( y2 - y1 ) ;

			x22 = x1 + u2 * ( x2 - x1 );
			y22 = y1 + u2 * ( y2 - y1 );

			detectgraph(&gd,&gm);
			initgraph(&gd,&gm, NULL);
			setbkcolor(WHITE);
			setcolor(BLACK);
			rectangle(wxmin,wymax,wxmax,wymin);
			line(x1,y1,x2,y2);
			line(x1,y1,x2,y2);
			line(x11,y11,x22,y22);
			delay(2000);
		}
	}
	return 0;
}