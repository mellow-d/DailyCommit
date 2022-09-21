#include <stdio.h>
#include<stdlib.h>
void dfs(int a[10][10], int n, int v[10], int source)
{
    int i;
    v[source] = 1; 
    for(i=1; i<=n; i++)
    if(a[source][i] == 1 && v[i] == 0)
    {
        //printf("%d ",i);
        dfs(a,n,v,i);
    }
}
void bfs(int a[10][10], int n, int v[10], int source)
{
    int q[10], front=0, rear=-1;
    int node, i;
    v[source] = 1; 
    q[++rear] = source;
    while(front <= rear)
    {
        node = q[front++];
        for(i=1;i<=n;i++)
            if(a[node][i] == 1 && v[i] == 0)
            {
                //printf("%d ",i);
                v[i] = 1;
                q[++rear] = i;
            }
    }
}
int main()
{
    int n,ch;
    int a[10][10];
    int v[10];
    int source;
    int i, j;

    int count = 0;
    printf("Enter no of nodes: ");
    scanf("%d",&n);
    printf("\n Read Adjacency matrix \n");
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
            scanf("%d",&a[i][j]);
    printf("\n DFS\n");
    for(i=1;i<=n;i++) 
        v[i] = 0;
    for(i=1;i<=n;i++)
    {
        if(v[i] == 0)
        {
            printf("%d ",i);
            dfs(a,n,v,i);
            count++;
        }
    }
    if(count == 1)
        printf("\nGraph is Connected with 1 component\n");
    else
        printf("\nGraph is NOT Connected with %d Components\n",count);
    printf("\n BFS\n");
    count = 0;
    for(i=1;i<=n;i++)
        v[i] = 0;
    for(i=1;i<=n;i++)
    {
    if(v[i] == 0)
    {
        //printf("%d ",i);
        bfs(a,n,v,i);
        count++;
    }
    }
    if(count == 1)
        printf("\nGraph is Connected with one component ");
    else
        printf("\nGraph is NOT Connected with %d Components\n",count);
    return 0;

}