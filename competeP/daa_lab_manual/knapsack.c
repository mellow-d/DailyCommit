#include<stdio.h>
#include<stdlib.h>

int W,n,x[20],w[20],V[20][20],v[20];

int max(int a,int b)
{
  return(a>b?a:b);
}

void print_sol()
{
  int i,j;
  i=n;
  j=W;;
  while(i!=0 || j!=0)
{
  if(V[i][j]!=V[i-1][j])
  {
    x[i]=1;
    j=j-w[i];
  }
i=i-1;
}
}

int main()
{
  int i,j;
  
  printf("Enter no of objects :\n");
  scanf("%d",&n);
  printf("Enter weight of %d objects \n",n);
  for(i=1;i<=n;i++)
  {
    scanf("%d",&w[i]);
  }

 printf("Enter values of profits");
 for(i=1;i<=n;i++)
   scanf("%d",&v[i]);

 printf("Enter capacity");
 scanf("%d",&W);

  for(i=0;i<=n;i++)
	{
	  for(j=0;j<=W;j++){
		if(i==0||j==0)
		{
		  V[i][j]=0;
		}
		else if(j<w[i])
		{
		  V[i][j]=V[i-1][j];
		}
		else
		{
		  V[i][j]= max(V[i-1][j],(v[i]+V[i-1][j-w[i]]));
		}
	
	}
    
  
}

printf("\n Table is\n ");
for(i=0;i<=n;i++)
{
  for(j=0;j<=W;j++)
    printf("%d\t",V[i][j]);
  printf("\n");
}

printf("Optimal solution is %d\n", V[n][W]);
print_sol();
printf("Objects selected");

for(i=1;i<=n;i++)
  if(x[i]==1)
    printf("%d,%d,%d \n",i,w[i],v[i]);

return 0;
}
