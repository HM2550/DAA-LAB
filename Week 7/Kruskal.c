#include<stdio.h>
#include<stdlib.h>

int i, j, k, a, b, u, v, n, E=1; //n=no of vertices, E no of edges
int min, mincost=0, adj[100][100], parent[100];

int find(int i)
{
	while(parent[i])
	    i=parent[i];
	return i;
}

int uniun(int i, int j)
{
	if(i!=j)
	{
		parent[j]=i;
		return 1;
	}
	return 0;
}

int main()
{
	printf("Enter the number of vertices: ");
	scanf("%d", &n);
	printf("\nEnter the cost adjacency matrix: \n");
	for(i=1; i<=n; i++)
	{
		for(j=1; j<=n; j++)
		{
			scanf("%d", &adj[i][j]);

			if(adj[i][j]==0)
			    adj[i][j]=999;
		}
	}
	printf("\n\nThe edges of mininum cost spanning tree are : \n");
	while(E<n)
	{
		for(i=1, min=999; i<=n; i++)
		{
			for(j=1;j<=n;j++)
			{
				if(adj[i][j]<min)
				{
					min = adj[i][j];
					a=u=i;
					b=v=j;
				}
			}
		}

		u=find(u);
		v=find(v);
		if(uniun(u, v))
		{
			printf("%d (Node%d and Node %d) = %d\n", E++, a, b, min);
			mincost += min;
		}
		adj[a][b]=adj[b][a]=999;
	}

	printf("\nMinimum cost of the spanning tree = %d\n", mincost);
}

// 0 3 1 6 0 0
// 3 0 5 0 3 0
// 1 5 0 5 6 4
// 6 0 5 0 0 2
// 0 3 6 0 0 6
// 0 0 4 2 6 0