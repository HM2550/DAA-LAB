#include<stdio.h>
int main()
{
    int n;
    printf("Enter the size of the array\n");
    scanf("%d",&n);

    printf("Enter the elements of the array :\n");
    int a[n];
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }

    int max=a[0];
    int min=a[0];

    for(int i=0;i<n;i++)
    {
        if(a[i]>max)
        max=a[i];
        if(a[i]<min)
        min=a[i];
    }

    printf("Largest=%d\nSmallest=%d", max, min);
}