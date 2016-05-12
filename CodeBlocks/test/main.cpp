#include <stdio.h>
#include <stdlib.h>

typedef struct CircleLinkList
{
    int data;
    struct CircleLinkList *next;
}CircleLinkList;

// n to set the CircleList's Length
CircleLinkList * CreateList(int _n);
// Josephus loop
void JosephusLoop(CircleLinkList * Head,int _s,int _m);

int main()
{
    int n,s,m;
    printf("please set the List's length:");
    scanf("%d",&n);
    printf("\nplease set Josephus Loop's start number:");
    scanf("%d",&s);
    printf("\nplease set Josephus Loop's out number:");
    scanf("%d",&m);
    CircleLinkList *L = CreateList(n);
    JosephusLoop(L,s,m);
    return 0;
}
CircleLinkList * CreateList(int _n)
{
    CircleLinkList *Head = (CircleLinkList*)malloc(sizeof(CircleLinkList));
    CircleLinkList *r = Head;
    CircleLinkList *p = (CircleLinkList*)malloc(sizeof(CircleLinkList));
    int i = 1;
    while(i <= _n)
    {
        p = (CircleLinkList*)malloc(sizeof(CircleLinkList));
        p->data = i;
        r->next = p;
        r       = p;
        ++i;
    }
    //略过头指针形成一个循环链表
    r->next = Head->next;
    return Head;
}
void JosephusLoop(CircleLinkList * Head,int _s,int _m)
{
    CircleLinkList *p = Head->next;
    CircleLinkList *q = Head;
    CircleLinkList *r;
    int i = 1;
    while(i<_s)
    {
        p = p->next;
        q = q->next;
        ++i;
    }

    while(p)
    {
        i = 1;
        while(i<_m)
        {
            p = p->next;
            q = q->next;
            ++i;
        }
        printf("\n the out number is : %d\n",p->data);
        r = p;
        q->next = p->next;
        p = p->next;
        free(r);
        if(p->next == p)
        {
            printf("\nthe last out number is : %d\n",p->data);
            break;
        }
    }
}
