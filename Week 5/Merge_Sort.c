//MERGE SORT

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
  
void merge(int a[], int beg, int mid, int end)    
{    
    int i, j, k;  
    int n1 = mid - beg + 1;    
    int n2 = end - mid;    
      
    int LeftArray[n1], RightArray[n2]; 
      
    for (int i = 0; i < n1; i++)    
    LeftArray[i] = a[beg + i];    
    for (int j = 0; j < n2; j++)    
    RightArray[j] = a[mid + 1 + j];    
      
    i = 0;  
    j = 0; 
    k = beg; 
      
    while (i < n1 && j < n2)    
    {    
        if(LeftArray[i] <= RightArray[j])    
        {    
            a[k] = LeftArray[i];    
            i++;    
        }    
        else    
        {    
            a[k] = RightArray[j];    
            j++;    
        }    
        k++;    
    }    
    while (i<n1)    
    {    
        a[k] = LeftArray[i];    
        i++;    
        k++;    
    }    
      
    while (j<n2)    
    {    
        a[k] = RightArray[j];    
        j++;    
        k++;    
    }    
}    
  
void mergeSort(int a[], int beg, int end)  
{  
    if (beg < end)   
    {  
        int mid = (beg + end) / 2;  
        mergeSort(a, beg, mid);  
        mergeSort(a, mid + 1, end);  
        merge(a, beg, mid, end);  
    }  
}  
  
/* Function to print the array */  
void printArray(int a[], int n)  
{  
    int i;  
    for (i = 0; i < n; i++)  
        printf("%d ", a[i]);  
    printf("\n");  
}  
  
int main()  
{  
    // srand(time(NULL));
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

    clock_t t1=clock();

    printf("\n\nBefore sorting array elements are - \n");  
    printArray(a, n);  
    mergeSort(a, 0, n - 1);  


    printf("\n\n\n\nAfter sorting array elements are - \n");  
    printArray(a, n);  

    clock_t t2=clock();
    printf("\n\nTime taken to sort elements using merge sort : %lf", (float)(t2-t1)/CLOCKS_PER_SEC);
    
    return 0;  
}  