#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void main()
{
    int a[1000];
    int n;
    printf("Input numner of elemnts : \n");
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

    for(int i=0;i<n-1;i++)
    {
        int min=a[i],pos=i;
        for(int j=i+1;j<n;j++)
        {
            if(a[j]<min)
            {
                min=a[j];
                pos=j;
            }
        }
        
        int t=a[i];
        a[i]=a[pos];
        a[pos]=t;
    }

    printf("After Sorting array : \n");
    for(int i=0;i<n;i++)
        printf("%d ",a[i]);
        printf("\n");
    
    clock_t t=clock();
    printf("Time taken\n");
    printf("%ld\n",t);
}