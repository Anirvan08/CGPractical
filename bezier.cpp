#include<stdio.h>
#include<graphics.h>
#include<iostream>
#include<conio.h>
#include<stdlib.h>
#include<math.h>
void bezier(int x[4], int y[4])
{
double t;
for(t=0.0;t < 1.0;t+=0.0005)
{
double xt=pow(1-t,3)*x[0]+3*t*pow(1-t,2)*x[1]+3*pow(t,2)*(1-t)*x[2]+pow(t,3)*x[3];
double yt=pow(1-t,3)*y[0]+3*t*pow(1-t,2)*y[1]+3*pow(t,2)*(1-t)*y[2]+pow(t,3)*y[3];
putpixel(xt,yt,BLUE);
}
for(int i=0;i < 4;i++)
putpixel(x[i],y[i],YELLOW);
getch();
closegraph();
return;
}
int main()
{
int gdriver = DETECT, gmode, errorcode;
initgraph(&gdriver, &gmode, "..\\bgi");
errorcode = graphresult();
if (errorcode != grOk)
{
printf("Graphics error: %s\n", grapherrormsg(errorcode));
printf("Press any key to halt:");
getch();
exit(1);
}
int x[4],y[4];
int i;
std::cout<<"Enter x and y coordinates"<<std::endl;
for(i=0;i < 4;i++)
{
std::cin>>x[i];
std::cout<<std::endl;
std::cin>>y[i];
}
bezier(x,y);
}
