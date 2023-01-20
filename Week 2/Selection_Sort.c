#include<stdio.h>
#include<stdlib.h>
#include<time.h>

// void display(int a[],int n);
void swap(int *a,int i,int j);
void selectionsort(int *a,int n);

int main()
{
	srand(time(NULL));
	int n;
	printf("Enter the size of the array : ");
	scanf("%d",&n);

	int a[n];
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
    
	selectionsort(a,n);
	printf("\n\nSorted Array :\n\n");
	for(int i=0;i<n;i++)
	{
		printf("%d ",a[i]);
	}
	printf("\n");

	printf("\n");
	clock_t t=clock();
	printf("Time taken to complete execution : ");
	printf("%ld\n",t);
}


// void display(int a[],int n)
// {
// 	for(int i=0;i<n;i++)
// 	{
// 		printf("%d ",a[i]);
// 	}
// 	printf("\n");
// }

void swap(int *a,int i,int j)
{
	int temp=a[i];
	a[i]=a[j];
	a[j]=temp;
}

void selectionsort(int *a,int n)
{
	for(int i=0;i<n-1;i++)
	{
		int min=i+1;
		for(int j=i+1;j<n;j++)
		{
			if(a[min]>a[j])
			{
				min=j;
			}
		}
		if(a[i]>a[min])
		swap(a,i,min);
	}
}