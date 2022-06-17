#include "play.h"
#include <pthread.h>
void showbitmap(bitmap *bm, char *q, int x, int y, int time);
void quitbitmap2(bitmap *bm, char *q, int x, int y, int time);
char *getime();
void frezplay(bitmap *bm,char *q, int x, int y);
void rollplay(void*arg);
void showtime(char *p);
void baseshow(void*arg);
void advt(char*p);
void randomplay(char*p);