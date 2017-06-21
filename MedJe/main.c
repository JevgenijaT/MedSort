#define N 10

main( )
{
    int i,j,n;
    float med,arr[N],temp;
    printf( "Please enter the number of items:\n");
    scanf("%d", &n);
    /*Reading item into array a*/
    
    printf("input %d values\n",n);
    for (i=1;i<=n;i++)
        scanf("%f", &arr[i]);
    
    /* Sort begins */
    for (i = 1 ; i <= n-1 ; i++)
    {
        for (j = 1 ; j <= n-i ; j++)
        {
            if (arr[j] <= arr[j+1])
            {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
            else
                continue ;
        }
    } /* sort ends */
    /* calculation of median  */
    if ( n % 2 == 0)
        med = (arr[n/2] + arr[n/2+1])/2.0 ;
    else
        med = arr[n/2 + 1];
    
    /*  Printing values */
    for (i = 1 ; i <= n ; i++)
        printf("%f  ", arr[i]);
    printf("\n\nMedian value is: %f\n", med);
    
}
