#include <stdio.h>
#include <stdlib.h>
typedef struct n {

 int data;
  struct n* next;


}node;

node * siraliekle(node* r, int a)
{
    if(r == NULL)
    {
       r = (node*)malloc(sizeof(node));
       r ->next = NULL;
       r -> data = a;
       return r;
    }
    if(r -> data > a)
        {
            node *temp;
        temp = (node*)malloc(sizeof(node));
        temp -> data = a;
        temp -> next = r;
        r = temp;
        return temp;
        }

    node *itr;
    itr = r;
    while(itr -> next != NULL && itr -> next -> data < a)
    {
        itr = itr -> next;

    }
    node *temp = (node*)malloc(sizeof(node));
    temp -> next = itr -> next;
    temp -> data = a;
    itr -> next = temp;
    return r;

     if(r -> next == NULL)
    {



        }
        else
        {
            node *temp;
        temp = (node*)malloc(sizeof(node));
        temp -> data = a;
        r -> next = temp;
        temp -> next = NULL;
        return r;


        }


    }


void ekle(node* r, int a)
{
   while(r -> next != NULL)
   {
        r = r -> next;
   }
       r -> next = (node*)malloc(sizeof(node));
       r -> next -> data = a;
       r -> next -> next = NULL;
}

void bastir(node *r)
{
    while(r != NULL){
        printf("%d -> ", r -> data);


       r = r -> next;
    }

}

node *sil(node*r, int a)
{
   node * iter;
   node *temp;
   iter = r;

   while(iter -> next !=NULL && iter -> next -> data != a )
   {
       iter = iter -> next;
   }
   if(iter -> next == NULL)
   {
       printf("bulunamadi");
       return r;
   }
   else if(iter -> next -> data == a)
   {
       temp = iter -> next;
       iter -> next = iter -> next -> next;
       free(temp);
       return r;

   }
   else if(iter -> data == a){
    temp = iter;
    r = iter -> next;
    free(temp);

   }
}



int main()
{


   node *root;
   root = NULL;


  root = siraliekle(root, 400);
  siraliekle(root, 40);
  siraliekle(root, 4);
  siraliekle(root, 450);
  siraliekle(root, 50);

    bastir(root);


    node* temp;
    temp = (node*)malloc(sizeof(node));
    temp -> data = 25;
    temp -> next = NULL;
    node *iter;

    root = iter;

    while(iter != NULL)
    {
        if(iter -> next -> next == NULL)
        {
            temp -> next = iter -> next;
            iter -> next = temp;
        }
       iter = iter -> next;
    }




    return 0;
}




