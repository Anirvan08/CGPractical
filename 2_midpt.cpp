#include<graphics.h>
#include<stdlib.h>
#include<stdio.h>
#include<iostream>
#include<math.h>
#include<conio.h>
    void plot8(int x, int y, int cx, int cy)
    {
        putpixel(x+cx,y+cy,GREEN);
        putpixel(y+cx,x+cy,GREEN);
        putpixel(y+cx,-x+cy,GREEN);
        putpixel(x+cx,-y+cy,GREEN);
        putpixel(-x+cx,-y+cy,GREEN);
        putpixel(-y+cx,-x+cy,GREEN);
        putpixel(-y+cx,x+cy,GREEN);
        putpixel(-x+cx,y+cy,GREEN);
    } 
    int main()
    {
        int gdriver = DETECT, gmode, errorcode;
        int x,y,r,cx,cy,E,SE,D;
        initgraph(&gdriver, &gmode, "..\\bgi");
        errorcode = graphresult();
        if (errorcode != grOk)
        {
            printf("Graphics error: %s\n", grapherrormsg(errorcode));
            printf("Press any key to halt:");
            getch();
            exit(1);
        }
        std::cout<<"\nEnter centre(x): ";
        std::cin>>cx;
        std::cout<<"\nEnter centre(y): ";
        std::cin>>cy;
        std::cout<<"\nEnter radius: ";
        std::cin>>r;
        x=0;
        y=r;
        plot8(x,y,cx,cy);
        D=1-r;
        while(y>x)
        {
            if(D<=0)
            {
                E=(2*x)+3;
                D+=E;
                x++;
            }
            else
            {
                SE=(2*x)-(2*y)+5;
                D+=SE;
                x++;
                y--;
            }
            plot8(x,y,cx,cy);
        }
        getch();
        closegraph();
    }
