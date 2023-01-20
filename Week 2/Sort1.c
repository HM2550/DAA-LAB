#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void main()
{
    int a[1000];
    int n;
    
    printf("Input numebr of elments : \n");
    scanf("%d",&n);
    
    for(int i=0;i<n;i++)
    {
        a[i]=rand();
    }
    
    for(int i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }

    printf("\n");
    for(int i=0;i<n-i-1;i++)
    {
        for(int j=0;j<n-1;j++)
        {
        
            if(a[j]>a[j+1])
            {
                int t=a[j];
                a[j]=a[j+1];
                a[j+1]=t;
            }
        }
    }

    printf("After Sorting array : \n");
    for(int i=0;i<n;i++)
        printf("%d ",a[i]);
        printf("\n");

    clock_t t=clock();
    printf("Time taken\n");
    printf("%ld\n",t);
}