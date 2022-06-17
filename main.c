#include "main.h"
int main(int argc,const char *argv[])
{
    int lcd = open("/dev/fb0", O_RDWR);
    if (lcd == -1)
    {
        perror("打开设备失败");
        return 0;
    }
    char *p = mmap(NULL, 800 * 480 * 4, PROT_READ | PROT_WRITE, MAP_SHARED, lcd, 0);
    if (p == MAP_FAILED)
    {
        printf("映射内存失败");
        return 0;
    }
    bzero(p, 800 * 480 * 4);
    

   struct node *var1=calloc(1,sizeof(struct node));
   var1->q=p;
   var1->file=argv[1];

   struct node*var2=calloc(1,sizeof(struct node));
   var2->q=p;
   var2->file=argv[2];


   
    

    pthread_t tid1,tid2,tid3,tid4;
    int ret1,ret2,ret3,ret4;
    ret4 = pthread_create(&tid4, NULL, (void *)&randomplay, p);
    if (ret4 != 0)
    {
        printf("创建线程4失败\n");
        return -1;
    }
    ret2 = pthread_create(&tid2, NULL, (void *)&rollplay, var1);
    if (ret2 != 0)
    {
        printf("创建线程2失败\n");
        return -1;
    }
    ret1=pthread_create(&tid1 , NULL ,(void*)&showtime, p);
    if(ret1!=0)
    {
        printf("创建线程1失败\n");
        return -1;
    }
    ret3 = pthread_create(&tid3, NULL, (void *)&baseshow, var2);
    if (ret3 != 0)
    {
        printf("创建线程3失败\n");
        return -1;
    }
    
    

    while(1)
    {

    }

    return 0;

}
