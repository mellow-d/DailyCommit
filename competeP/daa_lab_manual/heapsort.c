#include<stdio.h>
#include<stdlib.h>
#define SIZE 1000
int count=0;
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
                count++;

            }
            else
            {
                H[k]=H[j];
                k=j;
                count++;
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
    printf("\nSIZE\tASCENDING\tDESCENDING\tRANDOM\n");
    for(i=1;i<517;i=i*2)
    {
        int j,c1,c2,c3;
        int H1[SIZE],H2[SIZE],H3[SIZE];
        for(j=0;j<i;j++)
        {
            H1[j]=j;
            H2[j]=i-j;
            H3[j]= rand()%i;
        }
        count=0;
        Heapsort(H1,i);
        c1= count;it 
        count=0;
        Heapsort(H2,i);
        c2= count;
        count=0;
        Heapsort(H3,i);
        c3= count;
        printf("%d\t%d\t%d\t%d",i,c1,c2,c3);
        printf("\n");

    }
    return 0;
}