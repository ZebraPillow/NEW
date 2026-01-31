#define STTY_US  "stty raw -echo -F "
#define STTY_DEF  "stty -raw echo -F "

#define START_INPUT system( STTY_US  TTY_PATH ); 
#define END_INPUT system( STTY_DEF TTY_PATH );

void drawPoint(int x, int y, int color);
int myget();