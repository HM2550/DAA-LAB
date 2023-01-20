#include<stdio.h>
#include<limits.h>

// Matrix Ai has dimension p[i-1] x p[i] for i = 1..n
 
int MatrixChainMultiplication(int p[], int n)
{
    int m[n][n];
    int i, j, k, L, q;
 
    for (i=1; i<n; i++)
        m[i][i] = 0;    //number of multiplications are 0(zero) when there is only one matrix
 
    //Here L is chain length. It varies from length 2 to length n.
    for (L=2; L<n; L++)
    {
        for (i=1; i<n-L+1; i++)
        {
            j = i+L-1;
            m[i][j] = INT_MAX;  //assigning to maximum value
 
            for (k=i; k<=j-1; k++)
            {
                q = m[i][k] + m[k+1][j] + p[i-1]*p[k]*p[j];
                if (q < m[i][j])
                {
                    m[i][j] = q;    //if number of multiplications found less that number will be updated.
                }
            }
        }
    }
 
    return m[1][n-1];   //returning the final answer which is M[1][n]
}
 
int main()
{
    int n,i;
    printf("Enter the number of matrices : ");
    scanf("%d", &n);
 
    n++;
 
    int arr[n];
 
    printf("\nEnter the dimensions of the matrices :\n");
    for(i=0;i<n;i++)
    {
        printf("Enter dimension (p%d) of matrix %d : ", i, i+1);
        scanf("%d", &arr[i]);
    }
 
    int size = sizeof(arr)/sizeof(arr[0]);
    int result = MatrixChainMultiplication(arr, size);
    printf("\nMinimum number of multiplications required to multiply matrices = %d", result);
 
    return 0;
}