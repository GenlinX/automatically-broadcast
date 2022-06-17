#include <stdio.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/ioctl.h>

#include "font.h"
#define dateheight 20                                   //顶部日期横幅的高度兼字体大小
#define baseheight 40                                   //底部横幅的高度兼字体大小
#define rollsize 20                                     //滚动字体大小
#define rollpof 100                                      //滚动字体在输出框中的位置x
#define pof (dateheight + 20)                           //滚动框位置y
#define rollheight (480 - dateheight - baseheight - 40) //滚动框的高度

struct node
{
    char*q;
    const char* file;
};

#define white 0xffffff00
#define red 0xff000000
#define green 0x00ff0000
#define blue 0x0000ff00
#define black 0x00000000
#define DeepSkyBlue 0x00BFFF00
#define cyan 0x00ffff00
#define pink 0xff00ff00
#define yellow 0xffff0000
#define gray 0x80808000
#define WHITE 0xff
#define BLACK 0x00

#define wordcolor1 blue                   //顶部横幅字体颜色
#define wordcolor2 red                    //中间滚动字体颜色
#define wordcolor3 green                  //底部横幅字体颜色
 
#define BACKGROUND1 white
#define BACKGROUND2 yellow
#define BACKGROUND3 gray

#define time1       100
#define time2       7000
#define time3       5000

#define yofadv     200                    //广告的位置y轴
#define ctofadv    "道路千万,安全第一"    //广告内容，不超过10个字
#define sizeofadv  30                     //广告字体大小
#define colorofadv white                  //广告字体颜色
#define bgofadv    blue                   //广告背景色
                            




