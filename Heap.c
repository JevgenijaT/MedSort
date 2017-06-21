#include<stdio.h>


void CreateHeap(int [], int);
void SortHeap(int [],int);
int main(void)
{
    int arr[50],child,parent,q,key,n,t,i;
   
    printf("\n enter the no. of elements: ");
    scanf(" %d",&n);
    printf("\n Now enter the array elements: ");
    for(i=1;i<=n;i++)
        scanf(" %d",&arr[i]);
    CreateHeap(arr,n);
    SortHeap(arr,n);
    return(0);
}
void CreateHeap(int arr[],int n)
{
    int i,q, parent,child,temp;
    for(q=2;q<=n;q++)
    {
        child=q;
        parent=(int)child/2;
        while(child >1 && arr[child] > arr[parent])
        {
            temp=arr[child];
            arr[child]= arr[parent];
            arr[parent]=temp;
            child=parent;
            parent=(int)child/2;
            if(parent < 1)
                parent=1;
        }
    }
    printf("\n Now the array in heap form is: ");
    for(i=1;i<=n;i++)
        printf(" %3d",arr[i]);
}
/* function to sort a heap */
void SortHeap(int arr[],int n)
{
    int current,parent,child,i,maxnodes, med;
    for(maxnodes=n;maxnodes>=2;maxnodes--)
    {
        current=arr[maxnodes];;
        arr[maxnodes]=arr[1];
        /* adjust the array to be a heap of size n-1 */
        parent=1;
        /* obtain the larger of the root's children */
        if (maxnodes-1 >= 3 && arr[3] > arr[2])
            child=3;
        else
            child = 2;
        /* move keys upwards to find place for current */
        while (child<=maxnodes-1 && arr[child]>=current)
        {
            arr[parent]=arr[child];
            parent=child;
            child=child*2;
            if(child+1 <= maxnodes-1 && arr[child+1] > arr[child])
                child = child + 1;
        }
        arr[parent]=current;
    } /* end of for */
    printf("\n The sorted array is : ");
    for(i=1;i<=n;i++)
        printf("%4d",arr[i]);
  
    /* calculation of median  */
    if ( n % 2 == 0)
        med = (arr[n/2] + arr[n/2+1])/2.0 ;
    else
        med = arr[n/2 + 1];
    
    printf("\n\nMedian value is: %d\n", med);
    
    
}
