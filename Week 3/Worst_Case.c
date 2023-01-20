#include<stdio.h>
#include<time.h>
#include<stdlib.h>

void insertion_reverse(int a[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int k = a[i];
        int j = i - 1;

        while (k > a[j] && j >= 0)
        {
            // For ascending order, change key> arr[j] to key < arr[j].
            a[j + 1] = a[j];
            --j;
        }
        a[j + 1] = k;
    }
}

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
    
    insertion_reverse(a,n);
    printf("\n\nArray after sorting in reverse order:\n\n");
	for(int i=0;i<n;i++)
	{
		printf("%d ",a[i]);
	}
	printf("\n");

    clock_t t1=clock();

    insertion(a,n);
    printf("\n\nArray after sorting in ascending order:\n\n");
	for(int i=0;i<n;i++)
	{
		printf("%d ",a[i]);
	}

    clock_t t2=clock();

    //  printf("\nTime taken to search element using 1 : %ld", t1);
    //  printf("\nTime taken to search element using 2 : %ld", t2);
    double t=((double)(t2-t1))/CLOCKS_PER_SEC;
    printf("\n\n\nTime taken for sorting the array in reverse and then in ascending order(Worst Case) : %lf",t);
}