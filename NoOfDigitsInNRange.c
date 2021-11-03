#include <stdio.h>
#include <math.h>

int main() 
{
    int inp;// = 13;
    printf("Enter the number:");
    scanf("%d",&inp);
    int no_of_digits=0,N;
    int tempinput=inp;
    while(tempinput>0)
    {
        tempinput=tempinput/10;
        no_of_digits+=1;
    }
    N = no_of_digits;
    int Count=0;
    while(N>0)
    {
        Count+=(inp-(pow(10,N-1)-1))*N;
        //printf("\n%d  %d   %d",Count,inp,N);
        inp=pow(10,N-1)-1;
        N-=1;
    }
    printf("\n%d",Count);
    return 0;
}
