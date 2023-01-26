#include <stdio.h>
#include <stdlib.h>

int *dizi = NULL;
int sira =0;
int sirabasi = 0;
int boyut = 2;

int dequeue()
{
    if(sira == sirabasi)
    {
        printf("sira bos");
        return -1;
    }
    return dizi[sirabasi++];

}

void toparla()
{
   if(sirabasi == 0)
   {
       return;
   }
   for(int i =0; i < boyut; i++)
   {
       dizi[i] = dizi[i+sirabasi];
   }
   sira = sira - sirabasi;
   sirabasi = 0;

}

void enqueue(int a)
{
    if(dizi == NULL)
    {
        dizi = (int*)malloc(sizeof(int) * 2);

    }
    if(sira >= boyut)
    {
        boyut*=2;
        int *dizi2 = (int*)malloc(sizeof(int)* boyut);
        for(int i =0; i < boyut/2; i++)
        {
            dizi2[i] = dizi[i];
        }
        free(dizi);
        dizi = dizi2;
    }
    dizi[sira++] = a;
}
int main()
{
    for(int i=0; i < 10; i++)
    {
        enqueue(i*10);

    }

    for(int i =0; i < 10; i++)
    {

        printf("%d ", dequeue());


    }
    for(int i = 0; i < 20; i++)
    {
        enqueue(i+1 * 10);
    }
    printf("\n");
    for(int i = 0; i < 20; i++)
    {
        printf("%d ", dequeue());
    }
    return 0;
}
