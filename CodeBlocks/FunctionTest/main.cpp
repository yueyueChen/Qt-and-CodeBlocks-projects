#include <stdio.h>
#include <stdlib.h>
#include <ctime>

#define LeftChild(i) (2*(i) +1)

void InsertionSort(int A[],int N)
{
    time_t startTime =time(0);
    printf("%d\n",startTime);
    int j , P;
    int tmp ;
    for(P = 1;P< N;++P)
    {
        tmp = A[P];
        for(j = P;j>0&&A[j-1] > tmp; --j)
            A[j] = A[j-1];
        A[j] = tmp;
    }
    time_t overTime = time(0);
    printf("%d",overTime);
}
void shellSort(int A[],int N)
{
    time_t startTime =time(0);
    printf("%d\n",startTime);
    int i,j,Increment;
    int tmp;
    for(Increment = N/2;Increment>0;Increment/=2)
    {
        for(i = Increment;i<N;++i)
        {
            tmp = A[i];
            for(j = i;j>=Increment&&tmp < A[j-Increment];j-=Increment)
                A[j] = A[j-Increment];
            A[j] = tmp;
        }
    }
    time_t overTime = time(0);
    printf("%d",overTime);
}
void PercDown(int A[],int i,int N)
{
    int child;
    int Tmp;

    for(Tmp = A[i];LeftChild(i) < N;i = child)
    {
        child = LeftChild(i);
        if(child != N-1 && A[child+1]>A[child])
            child++;
        if(Tmp < A[child])
            A[i] = A[child];
        else
            break;
    }
    A[i] = Tmp;
}
void Heapsort(int A[],int N)
{
    int i;
    time_t startTime = time(0);
    printf("%d\n",startTime);
    for(i = N/2;i>=0;i--)
        PercDown(A,i,N);
    for(i = N-1;i>0;i--)
    {
        int tmp;
        tmp = A[i];
        A[i] = A[0];
        A[0] = tmp;
        PercDown(A,0,i);
    }
    time_t overTime = time(0);
    printf("%d\n",overTime);
}
int main()
{
    int A[200000];
    srand((unsigned)time(0));
    for(int i = 0; i < 200000; ++i)
    {
        A[i] = rand()%200000;
    }
    //Heapsort(A,200000);
    //shellSort(A,200000);
    //InsertionSort(A,200000);
    return 0;
}
