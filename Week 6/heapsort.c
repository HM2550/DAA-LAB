#include <stdio.h>
// Function to swap the the position of two elements
void swap(int *a, int *b) 
{
  int temp = *a;
  *a = *b;
  *b = temp;
}

void heapify(int arr[], int n, int i) 
{
  // Find largest among root, left child and right child
  int largest = i;
  int left = 2*i;
  int right = 2*i+1;

  if (left < n && arr[left] > arr[largest])
    largest = left;

  if (right < n && arr[right] > arr[largest])
    largest = right;

  // Swap and continue heapifying if root is not largest
  if (largest != i) 
  {
    swap(&arr[i], &arr[largest]);
    heapify(arr, n, largest);
  }
}

// Main function to do heap sort
void heapSort(int arr[], int n) 
{
  for (int i = n / 2 - 1; i >= 0; i--)
    heapify(arr, n, i);

  for (int i = n - 1; i >= 0; i--) 
  {
    swap(&arr[0], &arr[i]);
    heapify(arr, i, 0);
  }
}

void display(int arr[], int n) 
{
  for (int i = 0; i < n; ++i)
    printf("%d ", arr[i]);
  printf("\n");
}

int main() 
{
  int n; 
  printf("Enter the number of elements in the array : ");
  scanf("%d", &n);

  int arr[n];

  printf("Enter the elements of the array");
  for(int i = 0; i < n; i++)
  {
    printf("\nEnter element %d :", i+1); 
    scanf("%d", &arr[i]);
  }

  printf("Array before sorting :  \n");
  display(arr, n);

  heapSort(arr, n);

  printf("Sorted array is \n");
  display(arr, n);
}