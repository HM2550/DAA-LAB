#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{
    srand(time(NULL));
    int n;

    printf("Enter the size of the array\n");
    scanf("%d",&n);

    int a[n];
    for(int i=0;i<n;i++)
    {
        a[i]=rand()%10;
    }

    int max=a[0];
    int min=a[0];

    printf("Random elemnts are :\n");
    for(int i=0;i<n;i++)
    {
        printf("%d ",a[i]);
        if(a[i]>max)
        max=a[i];
        if(a[i]<min)
        min=a[i];
    }

    printf("\nLargest =%d\nSmallset =%d",max,min);

    return 0;
}