#include "play.h"

//进入
void showbitmap(bitmap *bm, char *q, int x, int y, int time)
{
    int var;
    int tmp = 799 - x;
    int tmp2 = 800 - x;
    int lcdline = 800 * 4;
    int lcdlist = 480;
    int bmpline = bm->width * 4;
    int start = y * lcdline + x * 4;
    q = q + start;
    // bzero(q, (800 - x) * bm->height * 4);
    if ((y + bm->height) <= 480)
    {
        var = bm->height;
    }
    else
    {
        var = lcdlist - y;
    }
    //printf("%d\n", var);

    for (int k = 0; k < 800 - x; k++)
    {
        for (int j = 0; j < var; j++)
        {
            int r = 0;
            for (int i = tmp; i < tmp2; i++)
            {
                memcpy(q + i * 4 + j * lcdline, bm->map + r * 4 + j * bmpline, 4);
                r++;
            }
        }
        if ((tmp2 - tmp) == bm->width)
        {
            tmp2--;
        }
        tmp--;
        usleep(time);
        // if (k != (800 - x - 1))
        // {
        //     bzero(q, 800 * bm->height * 4);
        // }
    }

    // 字体的信息：
    bm->width;
    bm->height;
    bm->byteperpixel;
    bm->map; // 指向RGB数据，没有上下颠倒，也没有一行4字节倍数的约束，就是纯粹的RGB
}

//退出
void quitbitmap2(bitmap *bm, char *q, int x, int y, int time)
{
    int var;
    int bmpline = bm->width * 4;
    int lcdline = 800 * 4;
    int lcdlist = 480;
    int start = y * lcdline;
    q += start;

    int tmp1 = x;
    int tmp2 = bm->width;
    int tmp3 = 0;
    int tmp4 = tmp2 + tmp1;

    if ((y + bm->height) <= 480)
    {
        var = bm->height;
    }
    else
    {
        var = lcdlist - y;
    }

    for (int k = 0; k < (x + bm->width); k++)
    {

        for (int j = 0; j < var; j++)
        {
            int r = tmp3;
            for (int i = tmp1; i < tmp4 && i < 800; i++)
            {
                memcpy(q + i * 4 + j * lcdline, bm->map + r * 4 + j * bmpline, 4);
                r++;
            }
        }
        if (tmp1 > 0)
        {
            tmp1--;
        }
        if (tmp1 == 0)
        {
            tmp3++;
        }
        tmp4--;
        usleep(time);
    }
}

char *getime()
{

    time_t timer;
    struct tm *now;
    static char nowtime[44];

    time(&timer);
    now = localtime(&timer);

    nowtime[0] = '2';
    nowtime[1] = '0';

    nowtime[2] = now->tm_year % 100 / 10 + '0';
    nowtime[3] = now->tm_year % 100 % 10 + '0';

    nowtime[4] = -27; //年
    nowtime[5] = -71;
    nowtime[6] = -76;

    nowtime[7] = ' ';

    nowtime[8] = (now->tm_mon + 1) / 10 + '0';
    nowtime[9] = (now->tm_mon + 1) % 10 + '0';

    nowtime[10] = -26; //月
    nowtime[11] = -100;
    nowtime[12] = -120;

    nowtime[13] = now->tm_mday / 10 + '0';
    nowtime[14] = now->tm_mday % 10 + '0';

    nowtime[15] = -26; //日
    nowtime[16] = -105;
    nowtime[17] = -91;

    nowtime[18] = ' ';

    nowtime[19] = -26; //星期
    nowtime[20] = -104;
    nowtime[21] = -97;
    nowtime[22] = -26;
    nowtime[23] = -100;
    nowtime[24] = -97;

    switch (now->tm_wday)
    {
    case 1:
        nowtime[25] = -28;
        nowtime[26] = -72;
        nowtime[27] = -128;
        break;

    case 2:
        nowtime[25] = -28;
        nowtime[26] = -70;
        nowtime[27] = -116;
        break;

    case 3:
        nowtime[25] = -28;
        nowtime[26] = -72;
        nowtime[27] = -119;
        break;

    case 4:
        nowtime[25] = -27;
        nowtime[26] = -101;
        nowtime[27] = -101;
        break;

    case 5:
        nowtime[25] = -28;
        nowtime[26] = -70;
        nowtime[27] = -108;
        break;

    case 6:
        nowtime[25] = -27;
        nowtime[26] = -123;
        nowtime[27] = -83;
        break;

    case 0:
        nowtime[25] = -26;
        nowtime[26] = -105;
        nowtime[27] = -91;
        break;

    default:
        break;
    }

    nowtime[28] = ' ';

    nowtime[29] = now->tm_hour / 10 + '0';
    nowtime[30] = now->tm_hour % 10 + '0';

    nowtime[31] = -26; //时
    nowtime[32] = -105;
    nowtime[33] = -74;

    nowtime[34] = now->tm_min / 10 + '0';
    nowtime[35] = now->tm_min % 10 + '0';

    nowtime[36] = -27; //分
    nowtime[37] = -120;
    nowtime[38] = -122;

    nowtime[39] = now->tm_sec / 10 + '0';
    nowtime[40] = now->tm_sec % 10 + '0';

    nowtime[41] = -25; //秒
    nowtime[42] = -89;
    nowtime[43] = -110;

    nowtime[44] = '\0';

    return nowtime;
}
void frezplay(bitmap *bm, char *q, int x, int y)
{
    int lcdline = 800 * 4;
    int lcdlist = 480;
    int bmpline = bm->width * 4;
    int start = y * lcdline + x * 4;
    q = q + start;

    for (int j = 0; j < lcdlist && j < bm->height; j++)
    {
        for (int i = 0; i < 800 && i < bm->width; i++)
        {
            memcpy(q + j * lcdline + i * 4, bm->map + j * bmpline + i * 4, 4);
        }
    }
}

void rollplay(void *arg)
{
    struct node *var1 = (struct node *)arg;
    char *p = var1->q;
    const char *file = var1->file;
    int fd = open(file, O_RDONLY);
    off_t n = lseek(fd, 0, SEEK_END);
    printf("一共有%ld个字节\n", n);
    char buf[n];

    lseek(fd, 0, SEEK_SET);
    read(fd, buf, n);

    font *f1 = fontLoad("simfang.ttf");                     //打开字库
    fontSetSize(f1, rollsize);                              //设置字体大小
    int wordcount = (800 - 2 * rollpof) / rollsize * 2 - 2; //计算每一行能容纳多少个字
    
    char ct[2 * n];
    int j = 0, count = 0, countline = 1;
    for (int i = 0; i < n; i++)
    {
        if (count > wordcount)
        {
            ct[j++] = '\n';
            count = 0;
            countline++;
        }
        if (buf[i] == 47 && buf[i + 1] == 110 && buf[i + 2] == 120 && buf[i + 3] == 116 && buf[i + 4] == 47)
        {

            count = 0;
            ct[j++] = '\n';
            countline++;
            i += 4;
        }

        else if (buf[i] > 127 && buf[i + 1] > 127 && buf[i + 2] > 127)
        {
            ct[j++] = buf[i];
            ct[j++] = buf[i + 1];
            ct[j++] = buf[i + 2];
            i += 2;
            count += 2;
        }
        else if (buf[i] == 13 && buf[i + 1] == 10)
        {
            i++;
        }
        else
        {
            ct[j++] = buf[i];
            count++;
        }
    }
    ct[j] = '\0';
    printf("%s\n\n", ct);
    int start = 800 * 4 * pof;
    p += start;

    bitmap *bm1 = createBitmapWithInit(800, rollsize * countline + rollsize / 4 * countline + 2 * rollheight, 4, BACKGROUND2); //3.设置字体输出框的大小
    fontPrint(f1, bm1, rollpof, rollheight, ct, wordcolor2, 800);                                                              //把字体输出到框中
    while (1)
    {
        for (int c = 0; c < (rollsize / 4 * countline + rollsize * countline + rollheight); c++)
        {
            for (int k = 0; k < rollheight; k++)
            {
                for (int i = 0; i < 800; i++)
                {
                    memcpy(p + k * 800 * 4 + i * 4, bm1->map + k * 800 * 4 + i * 4 + c * 800 * 4, 4);
                }
            }
            usleep(time2);
        }
    }
}

void showtime(char *p)
{
    int i;
    font *f1 = fontLoad("simfang.ttf"); //打开字库
    fontSetSize(f1, dateheight);        //设置字体大小

    if (19 * dateheight > 800)
    {

        while (1)
        {
            for (i = -800; i < dateheight * 19; i++)
            {

                // memset(bm1->map, BACKGROUND1, 800 * dateheight * 4);
                bitmap *bm1 = createBitmapWithInit(800, dateheight, 4, BACKGROUND1); //3.设置字体输出框的大小
                fontPrint(f1, bm1, -i, 0, getime(), wordcolor1, 19 * dateheight);    //4.把字体输出到输出框中
                frezplay(bm1, p, 0, 0);
                free(bm1->map);
                free(bm1);
                usleep(time1);
            }
        }
    }
    else
    {
        while (1)
        {
            bitmap *bm1 = createBitmapWithInit(800, dateheight, 4, BACKGROUND1); //3.设置字体输出框的大小
            // memset(bm1->map, BACKGROUND1, 800 * dateheight * 4);
            fontPrint(f1, bm1, (800 - dateheight * 19) / 2 + dateheight, 0, getime(), wordcolor1, 800); //4.把字体输出到输出框中
            frezplay(bm1, p, 0, 0);
            // free(bm1->map);
            // free(bm1);
            sleep(1);
        }
    }
}

void baseshow(void *arg)
{
    struct node *var2 = (struct node *)arg;
    char *p = var2->q;
    const char *file = var2->file;

    int fd = open(file, O_RDONLY);
    off_t n = lseek(fd, 0, SEEK_END);
    printf("一共有%ld个字节\n", n);
    char buf[n];
    lseek(fd, 0, SEEK_SET);
    read(fd, buf, n);

    char ct[2 * n];
    int j = 0, count = 0;
    for (int i = 0; i < n; i++)
    {
        if (buf[i] == 13 && buf[i + 1] == 10)
        {
            ct[j++] = ' ';
            ct[j++] = ' ';
            ct[j++] = ' ';
            i++;
            count += 3;
        }
        else if (buf[i] > 127 && buf[i + 1] > 127 && buf[i + 2] > 127)
        {
            ct[j++] = buf[i];
            ct[j++] = buf[i + 1];
            ct[j++] = buf[i + 2];
            i += 2;
            count += 2;
        }
        else
        {
            ct[j++] = buf[i];
            count++;
        }
    }
    ct[j] = '\0';
    printf("%s\n", ct);

    int start = (480 - baseheight) * 800 * 4;
    int baselenth = count / 2 * baseheight + 1;
    p += (480 - baseheight) * 800 * 4;

    font *f1 = fontLoad("simfang.ttf");                                              //打开字库
    fontSetSize(f1, baseheight);                                                     //设置字体大小
    bitmap *bm1 = createBitmapWithInit(baselenth + 800, baseheight, 4, BACKGROUND3); //3.设置字体输出框的大小
    fontPrint(f1, bm1, 800, 0, ct, wordcolor3, baselenth + 800);                     //4.把字体输出到输出框中

    while (1)
    {
        for (int k = 0; k < baselenth; k++)
        {
            for (int m = 0; m < baseheight; m++)
            {
                for (int i = 0; i < 800; i++)
                {
                    memcpy(p + 800 * 4 * m + i * 4, bm1->map + m * (baselenth + 800) * 4 + i * 4 + k * 4, 4);
                }
            }
            usleep(time3);
        }
    }
}

void advt(char *p)
{

    font *f1 = fontLoad("simfang.ttf"); //打开字库
    fontSetSize(f1, sizeofadv);         //设置字体大小

    bitmap *bm1 = createBitmapWithInit(9 * sizeofadv, sizeofadv, 4, bgofadv); //3.设置字体输出框的大小
    fontPrint(f1, bm1, 0, 0, ctofadv, colorofadv, 9 * sizeofadv);             //把字体输出到框中
    while (1)
    {
        showbitmap(bm1, p, 0, yofadv, 10000);
        quitbitmap2(bm1, p, 0, yofadv, 10000);

        sleep(5);
    }
}

void randomplay(char *p)
{
    font *f1 = fontLoad("simfang.ttf"); //打开字库
    fontSetSize(f1, sizeofadv);         //设置字体大小

    bitmap *bm1 = createBitmapWithInit(9 * sizeofadv, sizeofadv, 4, bgofadv); //3.设置字体输出框的大小
    fontPrint(f1, bm1, 0, 0, ctofadv, colorofadv, 9 * sizeofadv);             //把字体输出到框中

    int plusorminus, randomx, randomy;

    int i, j, posx = 0, posy = pof;
    while (1)
    {
        srand((unsigned)time(NULL));
        randomx = rand();

        if (posx == 0)
        {
            plusorminus = 1;
        }
        else if (posx == (800 - 9 * sizeofadv))
        {
            plusorminus = -1;
        }
        else if (randomx % 2 == 1)
        {
            plusorminus = 1;
        }
        else
        {
            plusorminus = -1;
        }
        for (i = 0; i < (randomx % (800 - 9 * sizeofadv)); i++) //
        {

            if ((posx + plusorminus) > 0 && (posx + plusorminus) < (800 - 9 * sizeofadv))
            {
                posx += plusorminus;
                for (int y = 0; y < sizeofadv; y++)
                {
                    for (int x = 0; x < 9 * sizeofadv; x++)
                    {
                        memcpy(p + 800 * 4 * posy + posx * 4 + y * 800 * 4 + x * 4, bm1->map + y * bm1->width * 4 + x * 4, 4);
                    }
                }
                if (posx != 0 || posx != (800 - 9 * sizeofadv))
                {
                    srand((unsigned)time(NULL));
                    randomx = rand();
                    usleep(randomx % (time2 / 2));
                }

                // bzero(p, 800 * 480 * 4);
            }
            else
            {
                break;
            }
        }

        srand((unsigned)time(NULL));
        randomy = rand();

        if (posy == pof)
        {
            plusorminus = 1;
        }
        else if (posy == (pof + rollheight - 40))
        {
            plusorminus = -1;
        }
        else if (randomy % 2 == 1)
        {
            plusorminus = 1;
        }
        else
        {
            plusorminus = -1;
        }
        for (j = 0; j < (randomy % rollheight); j++) //
        {

            if ((posy + plusorminus) > pof && (posy + plusorminus) < (pof + rollheight - sizeofadv))
            {
                posy += plusorminus;
                for (int y = 0; y < sizeofadv; y++)
                {
                    for (int x = 0; x < 9 * sizeofadv; x++)
                    {
                        memcpy(p + 800 * 4 * posy + posx * 4 + y * 800 * 4 + x * 4, bm1->map + y * bm1->width * 4 + x * 4, 4);
                    }
                }
                if (posy != pof || posy != (pof + rollheight - sizeofadv))
                {
                    srand((unsigned)time(NULL));
                    randomy = rand();
                    usleep(randomy % (time2 / 2));
                }

                // bzero(p, 800 * 480 * 4);
            }
            else
            {
                break;
            }
        }
    }
}