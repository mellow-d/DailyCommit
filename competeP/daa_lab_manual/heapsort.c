#include<stdio.h>
#include<stdlib.h>
#define SIZE 1000

void heapify(int H[SIZE],int n)
{
    int i,k,val,j,flag;
    for(i=n/2;i>0;i--)
    {
        flag =0;
        k = i;
        val = H[k];
        while(!flag && 2*k<=n)
        {
            j=2*k;
            if(j<n)
            {
                if(H[j]<H[j+1])
                {
                    j=j+1;
                }
            }
            if(val>=H[j])
            {
                flag=1;
            }
            else
            {
                H[k]=H[j];
                k=j;
            }
        }
        H[k]=val;

    }
}

void Heapsort(int a[SIZE],int n)
{
    int i,temp;
    heapify(a,n);
    for(i=n;i>0;i--)
    {
        temp = a[1];
        a[1] = a[i];
        a[i]=temp;
        heapify(a,i-1);
    }
}


int main()
{
    int n,H[SIZE],i;
    printf("enter value of n ");
    scanf("%d",&n);
    printf("enter the values of array ");
    for(i=1;i<=n;i++)
    {
        scanf("%d",&H[i]);
    }
    printf("the original data is: ");
    for(i=1;i<=n;i++)
    {
        printf("%d\t",H[i]);
    }

    Heapsort(H,n);
    printf("\nthis is sorted data: ");
    for(i=1;i<=n;i++)
    {
        printf("%d\t",H[i]);
    }
    return 0;
}