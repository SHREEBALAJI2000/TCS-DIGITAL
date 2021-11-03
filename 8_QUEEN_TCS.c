#include <stdio.h>
#include <stdlib.h>
/*
The eight queens problem is the problem of placing eight queens
on an 8×8 chessboard such that none of them attack one another
(no two are in the same row, column, or diagonal).
More generally, the n queens problem places n queens
on an n×n chessboard.
*/
int SafeCheck(int n,int POS[n],int Crow,int Ccol)
{
    int Count = 1;
    if(Crow>0)
    for(int i=Crow-1;i>=0;i--)
    {
        //printf("i : %d \n",i);

        //North Check;
        if(i>=0)
        {
            if( POS[i]== Ccol)
            {
                //printf("\nN   i :%d    POS[%d] : %d    Ccol : %d\n",i,i,POS[i],Ccol);
                return 0;
            }
        }
        //North West Check;
        if(Ccol-Count>=0)
        {
            //printf("\nNORTH WEST");


            if(POS[i]==Ccol - Count)
            {
                //printf("\nNW  i :%d    POS[%d] : %d    Ccol : %d\n",i,i,POS[i],Ccol-Count);
                return 0;
            }
        }
        // North East Check;
        if(Ccol + Count < n+1)
        {
            //printf("\nNORTH EAST");

            if(POS[i] == Ccol +Count)
            {
                //printf("\nNE  i :%d    POS[%d] : %d    Ccol : %d\n",i,i,POS[i],Ccol+Count);
                return 0;
            }
        }
        Count++;
    }
    return 1;

}

int main()
{
    //printf("Hello world!\n");
    int N=8;
    //printf("Enter the Matrix SIZE : ");
    //scanf("%d",&N);

    int pos[N];
    for(int i =0; i < N;i++)
    {
        pos[i]=-1;
    }
    //pos[0]=1;
    //for(int i =0;i<N;i++)
    //printf("%d ",pos[i]);
    //printf("\n");

    int r=0,c=0;
    while(r<N)
    {
        //if(F==0)
           // c=0;
         //else
        // {
         // F=1;
             c=pos[r]+1;
         //}
         while(c<=N)
         {
            if(c==N)
            {
                pos[r]=-1;
                //printf(" \n SKIP ================================================= \n");
                /*for(int i =0;i<N;i++)
                    printf("%2d ",i);
                    printf("\n");

                for(int i =0;i<N;i++)
                    printf("%2d ",pos[i]);
                    //printf("\n");
                */
                r=r-2;
                //c=pos[r]+1;
                //printf("\n c: %d   r: %d ",c,r);
                break;
            }
            if(SafeCheck(N,pos,r,c))
            {
                pos[r]=c;
                //printf("\n MAIN  r: %d  c: %d ************************************** \n",r,pos[r]);

                //for(int i =0;i<N;i++)
                //    printf("%2d ",i);
                //    printf("\n");

                //for(int i =0;i<N;i++)
                //    printf("%2d ",pos[i]);
                //    printf("\n");
                break;
            }
            c++;
         }
         r++;
    }
    for(int i =0;i<N;i++)
        printf("%2d ",i);
        printf("\n");
    for(int i =0;i<N;i++)
        printf("%2d ",pos[i]);
        printf("\n");
    return 0;
}
