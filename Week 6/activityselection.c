#include<stdio.h>
 
// Prints a maximum set of activities that can be done by a single
// person, one at a time.
//  n   -->  Total number of activities
//  s[] -->  An array that contains start time of all activities
//  f[] -->  An array that contains finish time of all activities
void activityselect(int s[], int f[], int n)
{
    int i, j;
 
    printf ("\n\nThe activities that can be selected are : ");
 
    // The first activity always gets selected
    i = 0;
    printf("Activity %d ", i+1);
 
    // Consider rest of the activities
    for (j = 1; j < n; j++)
    {
      // If this activity has start time greater than or
      // equal to the finish time of previously selected
      // activity, then select it
      if (s[j] >= f[i])
      {
        printf ("Activity %d ", j+1);
        i = j;
      }
    }
}
 
// driver program to test above function
int main()
{
    int n;
    printf ("Enter the total number of activities : ");
    scanf("%d", &n);

    int s[n], f[n];

    printf ("Enter the start and end time for each activity : ");
    for (int i = 0; i < n; i++)
    {
        printf ("\nEnter the start and end time for activity %d : ", i+1);
        scanf("%d %d", &s[i], &f[i]);
    }

    printf ("\n\nThe activities are : ");
    printf ("\nStart Time\t\t\tEnd Time");
    for (int i = 0; i < n; i++)
    {
        printf ("\n\t%d\t\t\t%d", s[i], f[i]);
    }

    activityselect(s, f, n);
    return 0;
}