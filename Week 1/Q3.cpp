#include <iostream> 
using namespace std;

void sort(int arr[],int size){ 
    int i,j,temp; 
    
    for(i=0;i<size-1;i++){ 
        for(j=0;j<size-i-1;j++){ 
            if(arr[j]>=arr[j+1]) 
            { 
                temp=arr[j]; 
                arr[j]=arr[j+1]; 
                arr[j+1]=temp; 
            } 
        } 
    } 
} 

int main() 
{ 
    int size,i; 
    cout<<"Enter the size of array: "; 
    cin>>size; 

    int array[size]; 

    cout<<"Input the element to array: "; 
    for(i=0; i<size; i++) 
        cin>>array[i]; 

    sort(array,size); 
    cout<<"The second largest element in array: "<<array[size-2]<<endl; 
    cout<<"The second smallest element in array: "<<array[1]; 
    return 0; 
}