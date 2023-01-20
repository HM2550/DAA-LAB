// #include <stdio.h>
// // Function to swap the the position of two elements
// void swap(int *a, int *b) 
// {
//   int temp = *a;
//   *a = *b;
//   *b = temp;
// }

// void heapify(int arr[], int n, int i) 
// {
//   // Find largest among root, left child and right child
//   int largest = i;
//   int left = 2*i;
//   int right = 2*i+1;

//   if (left < n && arr[left] > arr[largest])
//     largest = left;

//   if (right < n && arr[right] > arr[largest])
//     largest = right;

//   // Swap and continue heapifying if root is not largest
//   if (largest != i) 
//   {
//     swap(&arr[i], &arr[largest]);
//     heapify(arr, n, largest);
//   }
// }

// void insert(arr, n, item)
// {
//     n = n++;
//     arr[n] = item;

//     int i=n;
//     int parent = i/2;

//     while(i>1)
//     {
//         if(arr[parent] < arr[i])
//         {
//             swap
//         }
//     }


// }

// // Main function to do heap sort
// void heapSort(int arr[], int n) 
// {
//   for (int i = n / 2 - 1; i >= 0; i--)
//     heapify(arr, n, i);

//   for (int i = n - 1; i >= 0; i--) 
//   {
//     swap(&arr[0], &arr[i]);
//     heapify(arr, i, 0);
//   }
// }

// void display(int arr[], int n) 
// {
//   for (int i = 0; i < n; ++i)
//     printf("%d ", arr[i]);
//   printf("\n");
// }

// int main() 
// {
//   int n; 
//   printf("Enter the number of elements in the arr : ");
//   scanf("%d", &n);

//   int arr[n];

//   printf("Enter the elements of the arr");
//   for(int i = 0; i < n; i++)
//   {
//     printf("\nEnter element %d :", i+1); 
//     scanf("%d", &arr[i]);
//   }

//   printf("Array before sorting :  \n");
//   display(arr, n);

//   heapSort(arr, n);

//   printf("Sorted arr is \n");
//   display(arr, n);
// }

// Max-Heap data structure in C

#include <stdio.h>

int size = 0;

void swap(int *a, int *b)
{
    int temp = *b;
    *b = *a;
    *a = temp;
}

void heapify(int arr[], int size, int i)
{
    if (size == 1)
    {
        printf("Single element in the heap");
    }
    
    else
    {
        int largest = i;
        int l = 2*i;
        int r = 2*i+1;

        if (l < size && arr[l] > arr[largest])
            largest = l;
        if (r < size && arr[r] > arr[largest])
            largest = r;    
        if (largest != i)
        {
            swap(&arr[i], &arr[largest]);
            heapify(arr, size, largest);
        }
    }
}

void insert(int arr[], int item)
{
    if (size == 0)
    {
        arr[0] = item;
        size += 1;
    }

    else
    {
        arr[size] = item;
        size += 1;
       
        for (int i = size / 2 - 1; i >= 0; i--)
        {
            heapify(arr, size, i);
        }
    }
}

void delete(int arr[], int item)
{
    int i;
    for (i = 0; i < size; i++)
    {
        if (item == arr[i])
        break;
    }

    swap(&arr[i], &arr[size - 1]);
    size -= 1;
    for (int i = size / 2 - 1; i >= 0; i--)
    {
        heapify(arr, size, i);
    }
}

void display(int arr[], int size)
{
    for (int i = 0; i < size; ++i)
        printf("%d ", arr[i]);
    printf("\n");
}

int main()
{
    int n=5; 
    // printf("Enter the number of elements in the array : ");
    // scanf("%d", &n);
    int arr[50];

  	// int a[n];
    // printf("\nEnter the elements of the array : ");
	// for(int i=0;i<n;i++)
	// {
    //     // printf("\nEnter element %d : ", i+1);
	// 	scanf("%d",&a[i]);
	// }

    insert(arr, 36);
    insert(arr, 49);
    insert(arr, 25);
    insert(arr, 9);
    insert(arr, 64);

    // for (int i = 0; i < 10; i++){
    // insert(arr,a[i]);
    // }

    printf("Heap array after insertion of elements : ");
    display(arr, n);

    delete(arr, 36);

    printf("After deletion array : ");

    display(arr, n);
}