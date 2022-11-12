#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
typedef struct node {
int ogrenci_no;
char isim[20];
char soyisim[30];
char bolum[30];
int sinif;
struct node *link;
struct node *prev;

}NODE;
typedef struct
{
    int count;
    NODE* pos;
    NODE *head;
    NODE *rear;

}LIST;


// fonksiyon prototypleari

static bool search(LIST *pList, NODE *pPre, NODE *pLoc, int dataInPtr);
int addNode (LIST* pList, void* dataInPtr);
static bool _insert(LIST *pList, NODE *pPre, void *dataInPtr);
void deleteNode (LIST *pList, NODE* pPre, NODE *pLoc, void** dataOutPtr);
static bool disPlayList(LIST *pList, void* pArgu, void **dataOutPtr);




LIST *createList (int (*compare)(void* argu1, void* argu2))
{
    LIST *list;

    list = (LIST*)malloc (sizeof(LIST));

    if(list == NULL)
    {
        printf("bos liste");
        exit(0);
    }
    if(list)
    {
        list ->head = NULL;
        list -> pos = NULL;
        list -> rear = NULL;
        list -> count = 0;

    }
    return list;
}

int addNode (LIST* pList, void* dataInPtr)
{
    bool found;
    bool success;

    NODE *pPre;
    NODE *pLoc;

    pPre = (NODE *)malloc(sizeof(NODE));
    pLoc = (NODE *)malloc(sizeof(NODE));


    found = search(pList, &pPre, &pLoc, dataInPtr);

    if(found)
        return (+1);

    success = _insert(pList, pPre, dataInPtr);

    if(!success)
        pList = (LIST*)malloc(sizeof(LIST));
        return (-1);
    return (0);
}

static bool _insert(LIST *pList, NODE *pPre, void *dataInPtr)
{
    NODE *pNew;

    pNew = (NODE *)malloc(sizeof(NODE));
    pList = (LIST*)malloc(sizeof(LIST));
    if(!(pNew = (NODE*)malloc(sizeof(NODE))))
        return false;
    pNew -> ogrenci_no = dataInPtr;
//    pNew -> link = NULL;
//    pNew -> prev =  NULL;

    if(pPre == NULL)
    {
        pNew -> prev = NULL;
        pNew -> link = pList ->head;
        pList -> head = pNew;
//        if(pList -> count == 0)
//            pList ->rear = pNew;
    }
    else
    {
        pNew -> link = pPre -> link;
        pNew -> prev = pPre;
    }
    if (pPre -> link == NULL)
    {
        pList -> rear = pNew;
    }
    else
    {
        pPre -> prev = pNew;
    }
    pPre -> link = pNew;
    (pList -> count++);
  return true;
}

static bool search(LIST *pList, NODE *pPre, NODE *pLoc, int dataInPtr) // dataInPtr ogrenciNo olmali
{

    bool found;
    pPre = NULL;
    pLoc = pList -> head;
    pList = (LIST*)malloc(sizeof(LIST));
    while(pLoc != NULL && ((dataInPtr) > (pLoc -> ogrenci_no)))
    {
        pPre = pLoc;
        pLoc = pLoc -> link;
    }

    if(pLoc == NULL)
    {
        return false;
    }
    else
    {
        if(dataInPtr == pLoc -> ogrenci_no)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

}

void deleteNode (LIST *pList, NODE* pPre, NODE *pLoc, void** dataOutPtr)
{

    NODE *pGbp;
    pGbp = (NODE*)malloc(sizeof(NODE));// geriye bakan pointer
    pPre = (NODE*)malloc(sizeof(NODE));
    pLoc = (NODE*)malloc(sizeof(NODE));

    *dataOutPtr = pLoc -> ogrenci_no; // buraya bak
    if(pPre == NULL)
    {
        return;
    }

    (pList -> count)--;
    free(pLoc);

    if(pPre -> prev != NULL)
    {
        pGbp = pPre -> prev;
        pGbp -> link = pPre -> link;
    }
    else
    {
        pList -> head = pPre -> link;
    }

    if(pPre -> link != NULL)
    {
        pLoc = pPre -> link;
        pLoc -> prev = pLoc -> prev;
    }
    else
    {
        pList -> rear = pPre -> prev;
    }
    return;
}

static bool disPlayList(LIST *pList, void* pArgu, void **dataOutPtr)
{
    bool found;

    NODE *pPre;
    NODE *pLoc;

    pPre = (NODE*)malloc(sizeof(NODE));
    pLoc = (NODE*)malloc(sizeof(NODE));

    found = search(pList , &pPre, &pLoc, pArgu);

    if(found)
    {
        *dataOutPtr = pLoc -> ogrenci_no;
        return true;
    }

    *dataOutPtr = NULL;
    return false;
}



int main()
{
    // ORNEK PROGRAM

    printf("hello world");

    return 0;
}
