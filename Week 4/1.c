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

int Linear_Search(int a[], int n, int val) {  
    for (int i = 0; i < n; i++)  
    {  
        if (a[i] == val)  
        return i+1;  
    }  

    return -1;  
}  

int Binary_Search(int a[], int low, int high, int item)    
{    
    int mid;    
    if(high >= low)     
    {     
        if(low == high)
        {
            if (a[low] == item)
                return low;

            else
            {
                return -1;
            }
        }   
        mid = (low + high)/2;    

        if(a[mid] == item)    
        {                 
            return mid+1;    
        }    
        
        else if(a[mid] < item)     
        {  
            return Binary_Search(a, mid+1, high, item);    
        }    
        
        else     
        {  
            return Binary_Search(a, low, mid-1, item);    
        }          
    }  

    return -1;     
}  

void display(int a[], int n)
{
    for(int i=0;i<n;i++)
	{
		printf("%d ",a[i]);
	}
}

void main()
{
    int a[50000];
    int n, key1;
    printf("Enter size of the array : ");
    scanf("%d",&n);

    for(int i=0;i<n;i++)
	{
		a[i]=rand()%1000;
	}

    printf("\n\nArray Display :\n\n");
	display(a, n);

    printf("\n\nEnter the element you want to search : ");
    scanf("%d", &key1);
    
    int result1 = Linear_Search(a, n-1, key1);

    if (result1 == -1)  
        printf("\nElement is not present in the array");  
    else  
        printf("\nElement is present at position %d of the array", result1);  
    clock_t t1=clock();

    insertion(a,n);
    printf("\n\nArray after sorting in ascending order :\n\n");
	display(a, n);

    int result2 = Binary_Search(a, 0, n-1, key1);

    if (result2 == -1)  
        printf("\nElement is not present in the array");  
    else  
        printf("\nElement is present at position %d of the array", result2);  

    clock_t t2=clock();

    float t3 = t2-t1;

    printf("\nTime taken to search element using linear search : %lf", (float)t1/CLOCKS_PER_SEC);
    printf("\nTime taken to search element using binary search : %lf", (float)t3/CLOCKS_PER_SEC);
    printf("\nTime taken for complete execution of both search algorithms : %lf", (float)t2/CLOCKS_PER_SEC);

}