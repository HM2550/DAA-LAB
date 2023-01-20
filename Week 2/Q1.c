#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void fun()
{
    printf("fun() starts \n");
    printf("Press enter to stop fun \n");
    while(1)
    {
        if (getchar())
            break;
    }
    printf("fun() ends \n");
}
 

int main(void)
{
    int n, temp;

    printf("Enter the size of array :");
    scanf("%d",&n);

    int randArray[n],i;
    
        for(i=0;i<n;i++)
            randArray[i]=rand()%1000;  

    printf("\nElements of the array : ");
    for(i=0;i<n;i++)
    {
        printf("\nElement %d = %d",i+1,randArray[i]);
    }

    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(randArray[i]>randArray[j])
            {
                temp=randArray[i];
                randArray[i]=randArray[j];
                randArray[j]=temp;
            }
        }
    }

//    clock_t t;
//     t = clock();

//     fun();
//     t = clock() - t;
//     double time_taken = ((double)t)/CLOCKS_PER_SEC; 

    printf("\nElements of the array after sorting using selection sort: ");
    for(i=0;i<n;i++)
    {
        printf("\nElement %d = %d",i+1,randArray[i]);
    }

 
    // printf("fun() took %f seconds to execute \n", time_taken);

    return 0;
}