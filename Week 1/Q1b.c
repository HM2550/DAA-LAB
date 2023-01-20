#include<stdio.h>
#include<stdlib.h>
int main()
{
    int n;

    printf("Enter the size of the array :");
    scanf("%d",&n);

    int a[n];
    printf("Enter the array elements :\n");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }

    int s=a[0],ss=a[1];
    int g=a[0],sg=a[1];

    for(int i=0;i<n;i++)
    {
        if(a[i]<s)
        {
            ss=s;
            s=a[i];
        }
        if(a[i]<ss&&a[i]!=s)
        {
            ss=a[i];
        }
        
        if(a[i]>g)
        {
            sg=g;
            g=a[i];
        }
        if(a[i]>sg&&a[i]!=g)
        {
            sg=a[i];
        }
    }

    printf("Smallest :%d\nSecond Smallest :%d\n",s,ss);
    printf("Largest :%d\nSecond Largest :%d\n",g,sg);

    return 0;
}