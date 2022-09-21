#include<stdio.h>
#include<stdlib.h>
int count;
#define SIZE 1000


void merge(int a[SIZE], int l, int mid, int r)
{
  int i,j,k;
  int b[SIZE];
  i=l;
  j=mid+1;
  k=l;
  while(i<=mid && j<=r)
  { 
    count++;
    if(a[i]<=a[j])
     b[k++]=a[i++];
    else
     b[k++]=a[j++];
  }
 
  while(i<=mid)
  {
 
     b[k++]=a[i++];
     count++;
  }

  while(j<=r)
  {

     b[k++]=a[j++];
     count++;
  }

  for(i=l;i<=r;i++)
    a[i]=b[i];
}


void merge_sort(int a[SIZE], int l, int r)
{
   int mid;
   if(l<r)
  {
    mid=(l+r)/2;
    merge_sort(a,l,mid);
    merge_sort(a,mid+1,r);
    merge(a,l,mid,r);
  }
}


int main()
{
  int i,n,a[SIZE];
  int X[SIZE],Y[SIZE],Z[SIZE],j,c1,c2,c3;
  printf("\n Enter value of n: ");
  scanf("%d", &n);
  printf("\n Enter value of elements \n ");
  
  for(i=0;i<n;i++)
  {
   scanf("%d",&a[i]);
  }

 merge_sort(a,0,n-1);
 printf("\n Elements after sorting :");
 for(i=0;i<n;i++)
 printf("%d\t",a[i]);
 printf("\n Count = %d\n", count);
 printf("\n SIZE\tASC\tDSC\tRandom\n");
 for(i=8;i<SIZE;i=i*2)
 {
  for(j=0;j<i;j++)
   {
     X[j]=j;
     Y[j]=i-j-1;
     Z[j]=rand()%i;
   }
  count=0;
  merge_sort(X,0,i-1);
  c1=count;
  
  count=0;
  merge_sort(Y,0,i-1);
  c2=count;

  count=0;
  merge_sort(Z,0,i-1);
  c3=count;

 printf("\n %d\t%d\t%d\t%d\n",i,c1,c2,c3);
}
  
 
 return 0;
}