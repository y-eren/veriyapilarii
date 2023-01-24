#include <stdio.h>
#include <stdlib.h>

typedef struct n
{
    struct n *next;
    int data;
} node;


int pop(node* r);
node *push(node* r, int a);

void bastir(node * root)
{
    while(root != NULL)
    {
        printf("%d -> ", root -> data);
        root = root -> next;
    }
}


int pop(node * r)
{
   if(r == NULL)
   {
       return -1;
   }
   node* iter;
   iter = r;
   while(iter -> next -> next != NULL)
   {
       iter = iter -> next;

   }
   node *temp;
    temp = iter -> next;
   int rvalue = temp -> data;
    free(temp);
    iter -> next = NULL;
    return rvalue;


}

node *push(node *r, int a)
{
    if(r == NULL)
    {
        r = (node*)malloc(sizeof(node));
        r -> next = NULL;
        r -> data = a;
        return r;
    }
    node *iter;
    iter = r;
    while(iter -> next != NULL)
    {
        iter = iter -> next;
    }
    node *temp;
    temp = (node*)malloc(sizeof(node));
    temp -> next = NULL;
    temp -> data = a;
    iter -> next = temp;
    return r;

}

int main()
{
   node *s = NULL;
   s = push(s, 10);
   s = push(s, 20);
   s = push(s, 30);
   s = push(s, 40);
   bastir(s);
   printf("\n");
   pop(s);
   bastir(s);


}
