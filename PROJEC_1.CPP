#include<graphics.h>
#include<time.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
#include<dos.h>
//initializing coordinates for rectangle
int left = 250, top = 150,temp;
int right = 350, bottom = 450,mid1,mid2,mid3;
char strtime[30];
int font = 8;
int direction = 0;
int font_size = 5;
//timeout function

//Delay... number of seconds respective signal color would remain turned on


//function for red signal
void red()
{
    cleardevice();
    rectangle(left, top, right, bottom);
    //signal would remained turned off for a second
    delay(1);
    settextstyle(font, direction, font_size);
    outtextxy(250,100,"STOP");
    //Dot pattern for signal
    setfillstyle(CLOSE_DOT_FILL,4);
    circle(mid1,temp+10,40);
    floodfill(mid1,temp+10,WHITE);
    delay(10000);

    /*after 10 seconds color will change to black as if signal is turned off*/
    setfillstyle(SOLID_FILL,0);
    floodfill(mid1,temp+10,WHITE);
}
//function for orange signal
void orange()
{
    cleardevice();
    rectangle(left, top, right, bottom);
    /*Following loop makes yellow signal looks like if its blinking*/
    settextstyle(font, direction, font_size);
    for(int j=0;j<5;j++)
    {
	setfillstyle(CLOSE_DOT_FILL,14);
	circle(mid1,temp+100,40);
	floodfill(mid1,temp+100,WHITE);
	outtextxy(180,100,"SLOW DOWN");
	//yellow color would stay for given number of seconds in parenthesis
	delay(500);
	outtextxy(250,100,"     ");
	setfillstyle(SOLID_FILL,0);
	floodfill(mid1,temp+100,WHITE);

	/*black color would stay for 0.05 seconds as if signal turned off*/
	delay(500);
    }
}

//function for green signal
void green()
{
    cleardevice();
    rectangle(left, top, right, bottom);
    settextstyle(font, direction, font_size);
    outtextxy(270,100,"GO");
    setfillstyle(CLOSE_DOT_FILL,2);
	circle(mid1,temp+190,40);
	floodfill(mid1,temp+190,WHITE);
	delay(10000);
	setfillstyle(SOLID_FILL,0);
    floodfill(mid1,temp+190,WHITE);
}

int main()
{
    int gd = DETECT, gm;
	initgraph (&gd,&gm,"C:\\TC\\BGI");
	mid1=(left+right)/2;
    temp=(top+bottom)/3;
    int i=1;
    while(1)
    {
	red();
	green();
	orange();
    }
    getch();
    closegraph();
	return 0;
}
