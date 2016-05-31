#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MaxLength 100


typedef char Elemtype;
typedef struct seqStack
{
    Elemtype data[MaxLength];
    int top;
}seqStack;

void palindromeJudge(char A[],int N)
{
    seqStack * judgeStack = (seqStack*)malloc(sizeof(seqStack));
    judgeStack->top = -1;

    int i;
    for(i = 0; i < N; ++i)
    {
        ++judgeStack->top;
        judgeStack->data[judgeStack->top] = A[i];
        if(judgeStack->top >= MaxLength)
            printf("stack overflow !!\n");
    }
    //����ջ�����������ʣ����±���һ��A[] ջȫ���ܵ������ǻ���
    for(i = 0; i < N; ++i)
        if(A[i]==judgeStack->data[judgeStack->top])
            --judgeStack->top;
    if(judgeStack->top == -1)
        printf("the string is a palindrome !\n");
    else
        printf("the string is'nt a palindrome !\n");
    free(judgeStack);
}

int main()
{
    char *p1 = "i was able,elba saw i";
    palindromeJudge(p1,strlen(p1));

    char *p2 = "dfsfhvhgs";
    palindromeJudge(p2,strlen(p2));
    return 0;
}
