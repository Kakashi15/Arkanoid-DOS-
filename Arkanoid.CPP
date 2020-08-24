
#include<iostream.h>
#include<conio.h>
#include<graphics.h>
#include<dos.h>
#include<stdlib.h>
void main()
{
int g=DETECT,m;
int cx=320 , cy=100 , r=5 , rx=320 ,del=7, i=0,j,k,rec,dif=0,inc=-1,dinc=0,memory=0;
char hit ,z,time[10],result[10];
int A=0,B=0,C=0,D=0,E=0,F=0,G=0,H=0,I=0,J=0,score=0;
initgraph(&g,&m,"c:\\turboc3\\bgi");
clrscr();
setcolor(YELLOW);
setfillstyle(SOLID_FILL,YELLOW);
floodfill(1,1,YELLOW);
for(rec=0;rec<10;rec++)
{
 setcolor(rec);
 setfillstyle(HATCH_FILL,rec);
 rectangle(rec*64,0,rec*64+64,10);
 floodfill(rec*64+1,1,rec);
 setcolor(YELLOW);
 rectangle(rec*64,0,rec*64+64,10);
}
while(hit!=27)
{ hit=13;

  setcolor(RED);
  setfillstyle(SOLID_FILL,RED);
  circle(cx,cy,r);
  floodfill(cx,cy,RED);
  rectangle(rx-40,450,rx+40,460);
  floodfill(rx-39,451,RED);
  floodfill(rx+39,459,RED);
  delay(del);
  setcolor(YELLOW);
  circle(cx,cy,r+1);

  line(rx-41,450,rx-41,460);
  line(rx-42,450,rx-42,460);
  line(rx-43,450,rx-43,460);
  line(rx-44,450,rx-44,460);
  line(rx+41,450,rx+41,460);
  line(rx+42,450,rx+42,460);
  line(rx+43,450,rx+43,460);
  line(rx+44,450,rx+44,460);

  if(kbhit())
  {
  hit=getch();
  }
  switch(hit)
  {
  case 'a':
  case 'j': rx=rx-4;break;
  case 'd':
  case 'l': rx=rx+4;break;
	 //
  }

  if(cy==440)
  {
   i++;
   dif=rx-cx;
   dinc=inc;
   inc=1;
  }
  if(cy==15)
  {
   i++;
   dif=rx-cx;
   dinc=inc;
   inc=1;

  setcolor(YELLOW);
  setfillstyle(SOLID_FILL,YELLOW);
  if(cx<=64&&cx>=0)
   {
   floodfill(1,1,YELLOW);
   A=1;
   }
  if(cx<=128&&cx>=64)
   {
   floodfill(65,1,YELLOW);
   B=1;
   }
  if(cx<=192&&cx>=128)
   {
   floodfill(129,1,YELLOW);
   C=1;
   }
  if(cx<=256&&cx>=192)
   {
   floodfill(193,1,YELLOW);
   D=1;
   }
  if(cx<=320&&cx>=256)
   {
   floodfill(257,1,YELLOW);
   E=1;
   }
  if(cx<=384&&cx>=320)
   {
   floodfill(327,1,YELLOW);
   F=1;
   }
  if(cx<=448&&cx>=384)
   {
   floodfill(391,1,YELLOW);
   G=1;
   }
  if(cx<=512&&cx>=448)
   {
   floodfill(455,1,YELLOW);
   H=1;
   }
  if(cx<=576&&cx>=512)
   {
   floodfill(519,1,YELLOW);
   I=1;
   }
  if(cx<=640&&cx>=576)
   {
   floodfill(583,1,YELLOW);
   J=1;
   }
   score=A+B+C+D+E+F+G+H+I+J;
   if(score==10)
   {  clrscr();
   setcolor(YELLOW);
   setfillstyle(SOLID_FILL,YELLOW);
    floodfill(1,1,YELLOW);
    setcolor(RED);
    outtextxy(280,200,"VICTORY");
    itoa(i,time,10);
    outtextxy(280,300," TIME");
    outtextxy(300,350,time);
    goto last;
   }
  }
  if(cy<480&&i%2==0)
  {
   if((memory==1&&dinc==-1)||(memory==-1&&dinc==1))
   {
      if(cx==10||cx==630)
      {
      inc=-1;
      }
   cy=cy++;
   cx=cx+inc;
   circle(cx-inc,cy,r+1);
   }
   else if((memory==-1&&dinc==-1)||memory==1&&dinc==1)
    {
      if(cx==630||cx==10)
     {
      inc=-1;
     }
     cy=cy++;
     cx=cx-inc;           circle(cx+inc,cy,r+1);
    }
    else
    {
    cy++;
    }
  }
  else
  {
   if(dif>=-30&&dif<-5)
    {
       if(cx==630)
       {
       inc=-1;

       }
       memory=-1;
       cy--;
       cx=cx+inc;         circle(cx-inc,cy,r+1);
    }
    else if(dif>=-5&&dif<5)
    {
     cy--;
     memory=0;
    }
    else if(dif>=5&&dif<=30)
    {
       if(cx==8)
       {

	inc=-1;

       }
       memory=1;
    cy--;
    cx=cx-inc;           circle(cx+1*inc,cy,r+1); circle(cx+2*inc,cy,r+1);
    }
    else if(dif>30&&dif<47)
    {
     if(cx<=10)
     {
      inc=-1;
     }
     else if(cx>=630)
     {
      inc=1;
     }
     memory=1;
     cy--;
     cx=cx-2*inc;         circle(cx+2*inc,cy,r+1); circle(cx+1*inc,cy,r+1);
    }
    else if(dif<-30&&dif>-47)
    {
      if(cx>=630)
      {
       inc=-1;
      }
      else if(cx<=10)
      {
       inc=1;
      }
      memory=-1;
      cy--;
      cx=cx+2*inc;        circle(cx-2*inc,cy,r+1);   circle(cx-1*inc,cy,r+1);
    }
    else
    goto end;
  }
}
end:
  cleardevice();
// clrscr();
 setcolor(YELLOW);
 setfillstyle(SOLID_FILL,YELLOW);
 floodfill(1,1,YELLOW);
 floodfill(rx,455,YELLOW);
 floodfill(cx,cy,YELLOW);
 setcolor(RED);
 outtextxy(300,200,"OVER !!");
 itoa(score,result,10);
 outtextxy(320,250,result);
 last:
 delay(1000);
  setcolor(YELLOW);
 setfillstyle(SOLID_FILL,YELLOW);
 floodfill(1,1,YELLOW);
 floodfill(rx,455,YELLOW);
 floodfill(cx,cy,YELLOW);
 floodfill(cx+1,cy+1,YELLOW);
 floodfill(cx-1,cy-1,YELLOW);
 getch();
 delay(1000);

}

