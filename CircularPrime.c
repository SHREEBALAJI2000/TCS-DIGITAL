#include <stdio.h>
#include <math.h>
int isPrime();

int main() 
{
    
    long long int input;
    printf("Enter the number:");
    scanf("%lld",&input);
    if(isPrime(input)==0)
    {
        printf("\n%lld is not a Circular PRIME",input);
    }
    else
    {
        long long int tempinput=input,INPUT=input;
        int no_of_digits=0;
        while(tempinput>0)
        {
            tempinput=tempinput/10;
            no_of_digits+=1;
        }
        //printf("\nNo of digits in %lld is: %d",input,no_of_digits);
        int temp,flag=0;
        for(int i =0;i<no_of_digits-1;i++)
        {
            flag = 0;
        
            temp = input%10;
            input = (temp*(pow(10,(no_of_digits-1))))+(input/10);
            //printf("\n%lld is input || %d is temp ",input,temp);
            //printf("\n %lld",input);
            if(isPrime(input)==0)
            {
                printf("\n%lld is not PRIME ",input);
                flag =1;
                break;
            }
        }
        if(flag==0)
        printf("\n%lld is circular prime",INPUT);

    }


    return 0;
}

int isPrime(long long int Check)
{
    long long int check_factor,range;
    if(Check%2==0&&Check!=2)
    {
        return 0;
    }
    else
    {
        range = sqrt(Check);
        for(check_factor=3 ; check_factor<=range ; check_factor=check_factor+2)
            if(Check%check_factor==0)
                break;
        if(check_factor > range )
            return 1;
        else
            return 0;

    }
}
