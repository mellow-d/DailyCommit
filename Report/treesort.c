#include <stdio.h>
#include<stdlib.h>

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
void main( )


{
    struct btreenode *bt ;
    int arr[100] ,n;
    printf("Enter number of elements ");
    scanf("%d",&n);
    printf("Enter the elements for the array: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&arr[i]);
    }
    bt = NULL ;
    printf ( "Binary tree sort.\n" ) ;
    for ( int i = 0 ; i <= n ; i++ )
        insert ( &bt, arr[i] ) ;
    printf ( "\nIn-order traversal of binary tree:\n" ) ;
    inorder ( bt ) ;
     for (int i = 0; i < n; i++)
    {
        printf("%d\t",auxArr[i]);
    }
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
  