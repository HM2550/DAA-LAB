#include<stdio.h>
#include<time.h>
#include<stdlib.h>

void insertion(int a[],int n)
{
    int j;
    for(int i=1;i<n;i++)
    {
        int k=a[i];
        j=i-1;
        while(j>=0&&a[j]>k)
        {
            a[j+1]=a[j];
            j=j-1;
        }
        a[j+1]=k;
    }
}

void main()
{
    int a[50000];
    int n;
    printf("Enter size of the array : ");
    scanf("%d",&n);

    for(int i=0;i<n;i++)
	{
		a[i]=rand()%1000;
	}

    printf("\n\nArray before sorting :\n\n");
	for(int i=0;i<n;i++)
	{
		printf("%d ",a[i]);
	}
	printf("\n");

    insertion(a,n);
    printf("\n\nArray after sorting in ascending order once :\n\n");
	for(int i=0;i<n;i++)
	{
		printf("%d ",a[i]);
	}

    clock_t t1=clock();

    insertion(a,n);
    printf("\n\nArray after sorting in ascending order twice :\n\n");
	for(int i=0;i<n;i++)
	{
		printf("%d ",a[i]);
	}
   
    clock_t t2=clock();

    double t=((double)(t2-t1))/CLOCKS_PER_SEC;
    printf("\n\n\nTime taken for sorting the array in ascending order twice(Best Case) : %lf",t);
}