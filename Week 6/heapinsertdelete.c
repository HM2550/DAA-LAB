#include <stdio.h>
// Function to swap the the position of two elements
int size = 0;
void swap(int *a, int *b) 
{
  int temp = *a;
  *a = *b;
  *b = temp;
}

void heapify(int arr[], int size, int i) 
{
  // Find largest among root, left child and right child
  int largest = i;
  int left = 2*i;
  int right = 2*i+1;

  if (left < size && arr[left] > arr[largest])
    largest = left;

  if (right < size && arr[right] > arr[largest])
    largest = right;

  // Swap and continue heapifying if root is not largest
  if (largest != i) 
  {
    swap(&arr[i], &arr[largest]);
    heapify(arr, size, largest);
  }
}

void insert(int array[], int newNum)
{
  if (size == 0)
  {
    array[0] = newNum;
    size += 1;
  }
  else
  {
    array[size] = newNum;
    size += 1;
    for (int i = size / 2 - 1; i >= 0; i--)
    {
      heapify(array, size, i);
    }
  }
}
void delete(int array[], int num)
{
  int i;
  for (i = 0; i < size; i++)
  {
    if (num == array[i])
      break;
  }

  swap(&array[i], &array[size - 1]);
  size -= 1;
  for (int i = size / 2 - 1; i >= 0; i--)
  {
    heapify(array, size, i);
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

  insert(arr, 3);
  printf("Array after insertion is \n");
  display(arr, n);

    delete(arr, 4);
    printf("After deleting an element: ");
    display(arr, n);


}

// int main()
// {
//   int array[10];

//   insert(array, 4);
//   insert(array, 9);
//   insert(array, 5);
//   insert(array, 2);

//   printf("Max-Heap array: ");
//   printArray(array, size);



//   printArray(array, size);
// }