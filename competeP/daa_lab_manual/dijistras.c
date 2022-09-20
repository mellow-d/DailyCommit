#include<stdio.h>
#include<stdlib.h>
void dijs(int n,int sv, int cost[10][10],int dist[],int pred[])//n:numer of vertices sv:source vertex pred:parent
{
    int i,v,count,w,j,visited[23],min;
    for (i=0;i<n;i++)//filling up distances to vertices adjacent to source vertex
    {
        visited[i]=0;
        dist[i]=cost[sv][i];//distance vector is created only once and modifications happen in it
        if( dist[i] !=999)
            pred[i]=sv;
    }
    visited[sv]=1;
    dist[sv]=0;
    pred[sv]=-1;
    count=1;
    while (count< n)
    {
        min=999;
        for (w=0;w<n;w++)
        {
            if (!visited[w] && dist[w]<min )//minimum not visited distance from source vertex
            {
            min =dist[w];
            v=w;//smallest distance becomes the new source
            }
        }
        visited[v]=1;
        count++;
        for (w=0;w<n;w++)//relaxation
        {
            if (!visited[w] && dist[v]+cost[v][w]<dist[w])
            {
            dist[w]=dist[v]+cost[v][w];
            pred[w]=v;
        
            }
        }
    }
}
int main()
{
// weight of an edge if 999 means infinity : vertices are not connected
    int n,sv,i,j,dist[10],cost[10][10],pred[10];
    printf("\nDijkstra\n");
    printf("Enter the number of vertices:");
    scanf("%d",&n);
    printf("Enter the cost of matrix:\n");
    for (i=0;i<n;i++)
    {
        for (j=0;j<n;j++)
        {
        scanf("%d",&cost[i][j]);
        if (cost[i][j]==0)
        cost[i][j]=999;
        
        }
    }
    printf("Enter the source:");
    scanf("%d",&sv);
    dijs(n,sv,cost,dist,pred);
    printf("\nShortest path:\n");
    for(i=0;i<n;i++)
    if(i!=sv)
    {
        printf("\nShotest Distance of vertex %d=%d",i,dist[i]);//parent of each vertex in present in pred
        printf("\nPath=%d",i);
        
        j=i;
        do
        {
            j=pred[j];
            printf("<-%d",j);
        }while(j!=sv);
    }
    return 0;
}
