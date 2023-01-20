#include<stdio.h>

int a[20][20], q[20],reach[20], visited[20], n, i, j, f = 0, r = -1, count = 0;

void bfs(int v) 
{
    for(i = 1; i <= n; i++)
        if(a[v][i] && !visited[i])
            q[++r] = i;
        if(f <= r) 
        {
            visited[q[f]] = 1;
            bfs(q[f++]);
        }
}

void dfs(int v) 
{
	int i;
	reach[v]=1;
	for (i=1;i<=n;i++)
        if(a[v][i] && !reach[i])
        {
            // printf("\n%d->%d", v, i);
            printf("%d\t", i);
            dfs(i);
	    }
}

void main() 
{
    int v;
    printf("\nEnter the number of vertices: ");
    scanf("%d", &n);

    for(i=1; i <= n; i++) 
    {
        q[i] = 0;
        visited[i] = 0;
    }

    for (i=1;i<=n;i++) 
    {
        reach[i]=0;
        for (j=1;j<=n;j++)
            a[i][j]=0;
    }

    printf("\nEnter adjacency matrix for the graph:\n");
    for(i=1; i<=n; i++) 
    {
        for(j=1;j<=n;j++) 
        {
            scanf("%d", &a[i][j]);
        }
    }

    printf("\nEnter the starting vertex: ");
    scanf("%d", &v);

    bfs(v);
    printf("\n\nThe traversal using BFS:\t");
    for(i=1; i <= n; i++) 
    {
        if(visited[i])
        {
            printf("%d\t", i);
        }

        else 
        {
            printf("\nBfs is not possible. Not all nodes are reachable");
            break;
        }
    }

    printf("\n\nThe traversal using DFS:\t1\t");
    dfs(v);
    printf("\n");
    for (i=1;i<=n;i++) 
    {
        if(reach[i])
            count++;
    }

    if(count==n)
        printf("\nGraph is connected"); 
    else
        printf("\nGraph is not connected");
}

// 0 1 1 0 0 0 0 
// 1 0 0 1 1 0 0
// 1 0 0 0 0 1 1
// 0 1 0 0 0 0 0
// 0 1 0 0 0 0 0 
// 0 0 1 0 0 0 0
// 0 0 1 0 0 0 0