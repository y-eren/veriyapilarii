#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define COUNT 10

typedef struct n
{
    int data;
    struct n* sol;
    struct n* sag;

}node;

node *ekle(node* agac, int x)
{
    if(agac == NULL)
    {
        node* root = (node*)malloc(sizeof(node));
        root -> data = x;
        root-> sol = NULL;
        root -> sag = NULL;
        agac = root;
        return agac;
    }

    if(agac -> data < x)
    {
        agac -> sag = ekle(agac -> sag, x);
    return agac;
    }
    agac -> sol = ekle(agac -> sol, x);
    return agac;
}
void dolas(node *agac)
{
   if(agac == NULL)
   {
       return;
   }
   dolas(agac-> sol);
   printf("%d ", agac-> data);
   dolas(agac-> sag);
}

void bastir(node *agac)
{
    if(agac == NULL)
    {
        return;
    }
    bastir(agac->sol);
    printf("%d ", agac->data);
    bastir(agac-> sag);
}



void bul(node* agac, int x)
{
    if(agac == NULL)
    {
       printf("agac bulunamadi");
       return;
    }
    if(agac-> data == x)
    {
        printf("agac bulundu");
    }
    else{

       if(agac-> data < x)
        {
           bul(agac -> sag , x);
        }
         if(agac -> data > x )
        {
            bul(agac -> sol, x);

        }

    }




    }

int maxbul(node* agac)
{
    if(agac -> sag == NULL)
    {
        return agac-> data;
    }
    return maxbul(agac -> sag);

}
int minbul(node* agac)
{
    if(agac -> sol == NULL)
    {
        return agac -> data;
    }
   return minbul(agac-> sol);
}



node* sil(node* agac, int x)
{
    if(agac == NULL)
    {
        return NULL;
    }
    if(agac -> data == x)
    {
        if(agac -> sol == NULL && agac -> sag == NULL)
        {
            return NULL;
        }
        if(agac -> sag != NULL){
        agac -> data = minbul(agac -> sag);
        sil(agac -> sag, minbul(agac -> sag));
        return agac;
        }
        agac -> data = maxbul(agac -> sol);
       sil(agac -> sol, maxbul(agac -> sol));
        return agac;
    }
    if(agac -> data < x)

    {
        agac -> sag = sil(agac-> sag, x);
        return agac;
    }

   agac -> sol = sil(agac-> sol, x);
    return agac;


}
void print2d(node* agac, int space)
{
    if(agac == NULL)
    {
        return;
    }
    space += COUNT;

    print2d(agac -> sag, space);

    printf("\n");

    for(int i =COUNT; i < space; i++)
    {
        printf(" ");
    }
    printf("%d\n", agac -> data);

    print2d(agac -> sol, space);
}

void print2dd(node* agac)
{
    print2d(agac, 0);
}

int main()
{
   node *agac = NULL;
   agac = ekle(agac, (char)'*');
   agac = ekle(agac,200);
   agac = ekle(agac,26);
   agac = ekle(agac,190);
   agac = ekle(agac,213);
   agac = ekle(agac,12);
   agac = ekle(agac,24);
   agac = ekle(agac, 18);
   agac = ekle(agac, 27);
   agac = ekle(agac, 28);

   print2dd(agac);
   dolas(agac);


//  print2dd(agac);


    return 0;
}
