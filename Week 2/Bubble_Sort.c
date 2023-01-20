#include<stdio.h>
// #include<math.h>
// #include<unistd.h>
#include<stdlib.h>
#include<time.h>

// void display(int *a,int n);
void bubblesort(int *a,int n);

int main()
{
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
    bubblesort(a,n);

    printf("\n\nSorted array :\n\n");
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

// void display(int *a,int n)
// {
//     for(int i=0;i<n;i++)
//     {
//         printf("%d ",a[i]);
//     }
//     printf("\n");
// }

void bubblesort(int *a,int n)
{
    for(int i=0;i< n-1;i++)
    {
        int flag=0;
        for(int j=0;j< n-1-i;j++)
        {
            if(a[j]>a[j+1])
            {
                int temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
                flag=1;
            }
        }

        if(flag==0)
        break;
    }
}