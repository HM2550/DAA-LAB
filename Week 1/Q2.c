#include<stdio.h>

void swap(int a, int b, int c){
    c=c+a;
    a=c-a;
    c=c+b;
    b=c-b;
    c=c-b;

   printf("\n\nFirst number after swapping: %d", a);
   printf("\nSecond number after swapping : %d", b);
   printf("\nThird number after swapping : %d", c);
}

int main(){
    int a, b, c;
    printf("Enter the first number : ");
    scanf("%d", &a);
    
    printf("Enter the second number : ");
    scanf("%d", &b);

    printf("Enter the third number : ");
    scanf("%d", &c);

    printf("\nFirst number before swapping: %d", a);
    printf("\nSecond number before swapping : %d", b);
    printf("\nThird number before swapping : %d", c);

    swap(a, b, c);
}