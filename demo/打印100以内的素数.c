#include <stdio.h>
 
int main()
{
    int x;
    for (x = 2; x <= 100; x++)
    {
        int i;
        int isPrime=1;
        for (i = 2; i < x; i++)
        {   
        	//说明能够整除 
            if (x%i==0)
            {
                isPrime = 0;
                break;
            }
        }
        if (isPrime == 1)
        {
            printf("%d ", x);
        }
    }
    printf("/n");
    return 0;
}
