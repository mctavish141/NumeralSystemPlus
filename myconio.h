#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>
#include <termios.h>
#include <fcntl.h>

struct timeval now;
int rc;
double nowt;

double nowtime ()

{
	rc = gettimeofday (&now, 0);
	if (rc==0)
		{
			nowt = now.tv_sec + (now.tv_usec/1000000.0);
		}
	else
		{
			printf ("Cannot get current time. Please, try again.");
		}
	return nowt;
}

// x - height, y - width
void gotoxy (int x, int y) {
    printf ("\033[%d;%df", x+1, y+1);
}
void clrscr () {
    printf ("\033[2J");
    printf ("\033[0;0f");
}
void setAttribute (int attribute) {
    printf ("\033[%dm", attribute);
}
void setColors (int mainColor, int backgroundColor) {
    printf ("\033[%d;%dm", mainColor, backgroundColor);
}

int getch ()

{
  struct termios oldt,
                 newt;
  int            ch;
  tcgetattr( STDIN_FILENO, &oldt );
  newt = oldt;
  newt.c_lflag &= ~( ICANON | ECHO );
  tcsetattr( STDIN_FILENO, TCSANOW, &newt );
  ch = getchar();
  tcsetattr( STDIN_FILENO, TCSANOW, &oldt );
  return ch;
}

int kbhit ()

{
  struct termios oldt, newt;
  int ch;
  int oldf;
 
  tcgetattr(STDIN_FILENO, &oldt);
  newt = oldt;
  newt.c_lflag &= ~(ICANON | ECHO);
  tcsetattr(STDIN_FILENO, TCSANOW, &newt);
  oldf = fcntl(STDIN_FILENO, F_GETFL, 0);
  fcntl(STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK);
 
  ch = getchar();
 
  tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
  fcntl(STDIN_FILENO, F_SETFL, oldf);
 
  if(ch != EOF)
  {
    ungetc(ch, stdin);
    return 1;
  }
 
  return 0;
}

void Sleep (double millisecs)

{
	double t1, t2;
	double secs = millisecs/1000.0;
	t1 = nowtime ();
	bool exit = false;
	while ((exit == false))
		{
			t2 = nowtime ();
			if ((t2 - t1) > secs)
				{
					exit = true;
				}
			if (kbhit())
				{
					getch ();
				}
		}
}

void setcursor (int position)

{
	if (position==0)
		{
			printf("\e[?25l");
		}
	else
		{
			printf("\e[?25h");
		}
}

/*

void setAttribute (int)
Improving appearance by using 0-107 ANSI Escape codes

void setcursor (int)
setcursor (0) - hide cursor
setcursor (1) - show cursor

void gotoxy (int x, int y)
x - x coordinate (from 0)
y - y coordinate (from 0)
Terminal standart configuraion is 24x80, could be changed in its parameters.

void clrscr ()
Just clears the screen, like standard terminal "clear" function

int kbhit ()
Check if keyboard key has been pressed.
Use loop construction like while (!kbhit()) and then getch()

int getch ()
Identify the pressed keybord key code number.
Arrows: sequence of getch'es: 27 (ESC), 91 ([), ABCD letter:
A - Up
B - Down
C - Right
D - Left

void setColors (int mainColor, int backgroundColor)
maincolor from 30 to 37
backgroundColor from 40 to 47
30, 40 - black
31, 41 - red
32, 42 - green
33, 43 - yellow
34, 44 - blue
35, 45 - magenta
36, 46 - cyan
37, 47 - white
maincolor high intensity from 90 to 99
backgroundColor high intensity from 100 to 109
or just 1;%d - making text bold and high intensive

void Sleep (double millisecs)
sleeps for specified amount of milliseconds
using nowtime () function

double nowtime ()
returns current time in seconds, supports resolution up to microseconds
needs such code to be globally written:
#include <sys/time.h>
struct timeval now;
int rc;
double nowt;
 
*/
