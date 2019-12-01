#include <stdio.h>
  #include <conio.h>
  #include <iostream>
  #include <graphics.h>
  #include <time.h>
  #include <dos.h>
  #include <string.h>
  #include <windows.h>

  using namespace std;

  void digital();
  void stopwatch();
  void watch();

  int main() {
        /* request auto detection */
        int gdriver = DETECT, gmode, err;

        /* initialize graphic mode */
        initgraph(&gdriver, &gmode, "C:/TURBOC3/BGI");
        err = graphresult();

        if (err != 0) {
                /* error occurred */
                cout<<"Graphics Error: %s\n"<<
                                grapherrormsg(err);
                return 0;
        }


        {cout<<"\n\n\t\t\t\t ENTER YOUR CHOICE"<<endl;
        cout<<"\n\n\t\t\t\t 1 FOR DIGITAL CLOCK"<<endl;
        cout<<"\n\n\t\t\t\t 2 FOR STOPWATCH"<<endl;
        int x;
        cin>>x;
        switch (x)
        {

        case 1:
        digital();
        break;
        case 2:
        stopwatch();
        break;
        default:
            cout<<"Invalid Input";
        }
        getche();

        /* deallocate memory allocated for graphic screen */
        closegraph();
        return 0;
  }
  }

  void digital ()
  {
        int midx, midy;
        long mytime;
        char date[256];


        /* mid positions in x and y axis */
        midx = getmaxx() / 2;
        midy = getmaxy() / 2;

        /* mid positions in x and y axis */
        midx = getmaxx() / 2;
        midy = getmaxy() / 2;

        while (!kbhit()) {
                /* clears graphic screen */
                delay(1000);
                cleardevice();


                /* get time in seconds */
                mytime = time(NULL);

                /* store the date and time in the given string */
                strcpy(date, ctime(&mytime));

                setcolor(10);
                settextjustify(CENTER_TEXT, CENTER_TEXT);
                settextstyle(TRIPLEX_FONT, HORIZ_DIR, 4);

                /* locate the postion to write */
                moveto(midx, midy);

                /* print the date and time */
                outtext(date);
        }

  }

  int h=0,m=0,s=0,ms=0;
char ch = 'p';
void stopwatch()
{
watch();

while(1)
{
ch=getche();
if(ch=='s'||ch=='S')
break;
if(ch=='e'||ch=='E')
exit(0);
}
while(1)
{
watch();
delay(35);
if(_kbhit())
ch=getche();
if(ch=='r'||ch=='R')
{
h=m=s=ms=0;
watch();
while(1)
{
if(_kbhit())
ch = getche();
if(ch=='s'||ch=='S')
break;
if(ch=='e'||ch=='E')
exit(0);
}
}
else
if(ch=='p'||ch=='P')
while(1)
{
if(_kbhit())
ch=getche();
if(ch=='s'||ch=='S')
break;
if(ch=='e'||ch=='E')
exit(0);
if(ch=='r'||ch=='R')
{
ch='c';
h=m=s=ms=0;
watch();
}
}
else
if(ch=='e'||ch=='E')
exit(0);
if(ms!=9)
ms++;
else
{
ms=0;
if(s!=59)
s++;
else
{
s=0;
if(m!=59)
m++;
else
{
m=0;
h++;
}

}
}
}
}
void watch()
{
system("cls");
cout<<"#***********************#";
cout<<"\n#\t The A.R.T\t#";
cout<<"\n#\t Stopwatch\t#";
cout<<"\n#***********************#";
cout<<"\n#\t "<<h<<":"<<m<<":"<<s<<":"<<ms<<" \t#";
cout<<"\n#***********************#";
cout<<"\n\n#***********************#";
cout<<"\n#\tPress Key\t#";
cout<<"\n#\tS -> Start\t#";
cout<<"\n#\tP -> Pause\t#";
cout<<"\n#\tR -> Reset\t#";
cout<<"\n#\tE -> Exit\t#";
cout<<"\n#***********************#";
}
