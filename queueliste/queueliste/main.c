#include <stdio.h>
#include <stdlib.h>
typedef struct n
{
    struct n* next;
    int a;
}node;
node *root = NULL;
node *son = NULL;

void bastir()
{
    node *iter;
    iter = root;
    while(iter != NULL)
        printf("%d", iter -> a);
}
void enqueue(int x)
{
    if(root == NULL)
    {
        root = (node*)malloc(sizeof(node));
        root -> next = NULL;
        root -> a = x;
        son = root;
    }
    else{
        son-> next  = (node*)malloc(sizeof(node));
        son -> next -> a = x;
        son = son -> next;
        son -> next = NULL;
    }


}

int dequeue()
{
    if(root == NULL)
    {
       printf(" linked list bos");
       return -1;
    }
    int rvalue = root -> a;
    node *temp;
    temp = root;

    root = root -> next;
    free(temp);
    return rvalue;
}
int main()
{
    enqueue(5);
    enqueue(6);
    enqueue(7);
    enqueue(9);
   printf("%d", dequeue());
   printf("%d", dequeue());
   printf("%d", dequeue());
   printf("%d", dequeue());
   printf("%d", dequeue());


    return 0;
}
