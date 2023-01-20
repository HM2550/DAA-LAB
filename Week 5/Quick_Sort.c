//QUICK SORT

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int partition (int a[], int start, int end)  
{  
    int pivot = a[start];
    int i = start;
    int j = end+1;  

    while (i < j)
    {
        do{
            i++;
        }while(a[i] <= pivot);

        do{
            j--;
        }while(a[j] > pivot);

        if (i<j)
        {
            int t = a[i];  
            a[i] = a[j];  
            a[j] = t;  
        }
    }

    int t1 = a[start];
    a[start] = a[j];
    a[j] = t1;

    return j;
  
    // for (int j = start; j <= end - 1; j++)  
    // { 
    //     if (a[j] < pivot)  
    //     {  
    //         i++;
            // int t = a[i];  
            // a[i] = a[j];  
            // a[j] = t;  
    //     }  
    // }  

    // int t = a[i+1];  
    // a[i+1] = a[end];  
    // a[end] = t;  
    // return (i + 1);  
}  

void quick(int a[], int start, int end) 
{  
    if (start < end)  
    {  
        int p = partition(a, start, end); //p is the partitioning index  
        quick(a, start, p );  
        quick(a, p+1, end);  
    }  
}  
  
void printArr(int a[], int n)  
{  
    int i;  
    for (i = 0; i < n; i++)  
        printf("%d ", a[i]);  
}  

int main()  
{  
    srand(time(NULL));
	int n;
	printf("\n\nEnter the size of the array : ");
	scanf("%d",&n);

	int a[n];
    printf("\nEnter the elements of the array : ");
	for(int i=0;i<n;i++)
	{
        printf("\nEnter element %d : ", i+1);
		scanf("%d",&a[i]);
	}

    printf("\n\nBefore sorting array elements are - \n");  
    printArr(a, n);  

    quick(a, 0, n - 1);  
    printf("\n\nAfter sorting array elements are - \n");    
    printArr(a, n);  
      
    return 0;  
}  