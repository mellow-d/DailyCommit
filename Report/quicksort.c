#include<stdio.h>
#include<stdlib.h>
#define SIZE 1000

// for quick sort: 
int count_quick=0;
int partition (int a[], int left, int right)
{
    int i, j, pivot, temp;
    pivot = a[left];
    i = left+1;
    j = right;
    while(1)
    {
        while(pivot>=a[i] && i<=right)
        {
            i++;
            count_quick++;
        }
        while(pivot<a[j] && j>left)
        {
            j--;
            count_quick++;
        }
        if(i<j)
        {
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
        else
        {
            a[left] = a[j];
            a[j] = pivot;
            return j;
        }
    }
}

void QuickSort(int a[], int left, int right)
{
    int s;
    if(left<right)
    {
        s = partition(a,left,right);
        QuickSort(a,left,s-1);
        QuickSort(a,s+1,right);
    }
}



// for bubble sort
void swap(int* xp, int* yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}
 
void bubbleSort(int arr[], int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++)
 
        // Last i elements are already in place
        for (j = 0; j < n - i - 1; j++)
            if (arr[j] > arr[j + 1])
                swap(&arr[j], &arr[j + 1]);
}

void printArray(int arr[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}



//for radix sort
int getMax(int array[], int n) {
  int max = array[0];
  for (int i = 1; i < n; i++)
    if (array[i] > max)
      max = array[i];
  return max;
}
// Using counting sort to sort the elements in the basis of significant places
void countingSort(int array[], int size, int place) {
  int output[size + 1];
  int max = (array[0] / place) % 10;

  for (int i = 1; i < size; i++) {
    if (((array[i] / place) % 10) > max)
      max = array[i];
  }
  int count[max + 1];

  for (int i = 0; i < max; ++i)
    count[i] = 0;

  // Calculate count of elements
  for (int i = 0; i < size; i++)
    count[(array[i] / place) % 10]++;
    
  // Calculate cumulative count
  for (int i = 1; i < 10; i++)
    count[i] += count[i - 1];

  // Place the elements in sorted order
  for (int i = size - 1; i >= 0; i--) {
    output[count[(array[i] / place) % 10] - 1] = array[i];
    count[(array[i] / place) % 10]--;
  }

  for (int i = 0; i < size; i++)
    array[i] = output[i];
}
// Main function to implement radix sort
void radixsort(int array[], int size) {
  // Get maximum element
  int max = getMax(array, size);

  // Apply counting sort to sort elements based on place value.
  for (int place = 1; max / place > 0; place *= 10)
    countingSort(array, size, place);
}




//for tree sort
int auxArr[1000];
int j=0;
// Part of Cosmos by OpenGenus Foundation
struct btreenode
{
    struct btreenode *leftchild ;
    int data ;
    struct btreenode *rightchild ;
} ;
void insert ( struct btreenode **, int ) ;
void inorder ( struct btreenode * ) ;





int main()
{
    int a[100], x[SIZE], y[SIZE], z[SIZE];
    int i, j, n, ele, c1, c2, c3;
    printf("\nQUICK SORT\n");
    printf("\nEnter the number of elements in the array - ");
    scanf("%d",&n);
    printf("\nEnter the elements of the array - ");
    for(i=0;i<n;i++)
    {
        scanf("%d",&ele);
        a[i] = ele;
    }
    count_quick = 0;
    QuickSort(a,0,n-1);
    printf("\nThe sorted elements are - ");
    for(i=0;i<n;i++)
    {
    printf("%d ",a[i]);
    }
    // printf("\n\nThe number of counts- %d\n",count_quick);
    // printf("\nSIZE\tASC\tDESC\tRAND\n"); 
    // for(i=16;i<550;i=i*2)
    // {
    //     for(j=0;j<i;j++)
    //     {
    //         x[j]=rand()%i; 
    //         y[j]=rand()%i; 
    //         z[j]=rand()%i; 
    //     }
    //     count_quick = 0;
    //     QuickSort(x,0,i-1);
    //     c1 = count_quick;
    //     count_quick = 0;
    //     QuickSort(y,0,i-1); 
    //     c2 = count_quick;
    //     count_quick = 0;
    //     QuickSort(z,0,i-1); 
    //     c3 = count_quick;
    //     printf("\n %d\t %d\t %d\t %d",i, c1, c2, c3); 
    // }
    // printf("\n");
    return 0;
}

void insert ( struct btreenode **sr, int num )
{
    if ( *sr == NULL )
    {
        *sr = malloc ( sizeof ( struct btreenode ) ) ;
        ( *sr ) -> leftchild = NULL ;
        ( *sr ) -> data = num ;
        ( *sr ) -> rightchild = NULL ;
    }
    else
    {
        if ( num < ( *sr ) -> data )
            insert ( &( ( *sr ) -> leftchild ), num ) ;
        else
            insert ( &( ( *sr ) -> rightchild ), num ) ;
    }
}
void inorder ( struct btreenode *sr )
{
    if ( sr != NULL )
    {
        inorder ( sr -> leftchild ) ;
        // printf ( "%d\t", sr -> data ) ;
        auxArr[j++]= sr->data;
        inorder ( sr -> rightchild ) ;
    }
}