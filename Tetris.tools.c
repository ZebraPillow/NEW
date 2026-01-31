#include <fcntl.h> 
#include <stdio.h>

int myget()	
{
  fd_set rfds;
  struct timeval tv;
  int ch = 0;
  FD_ZERO(&rfds);
  FD_SET(0, &rfds);
  tv.tv_sec = 0;
  tv.tv_usec = 10; 
  if (select(1, &rfds, NULL, NULL, &tv) > 0)
  {
      ch = getchar(); 
  }
  return ch;
}

void drawPoint(int x, int y, int color)
{
	printf("\033[%d;%dH", y+1, x*2+1);
	printf("\033[1;%dm■ \033[0m", color);
}

