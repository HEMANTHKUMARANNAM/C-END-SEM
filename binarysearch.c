#include<stdio.h>

int main()
{
    int a[] = { 3 , 6 , 7 , 9 , 12 , 45 , 1};
    int len = 7 ;       // int len = sizeof(a)/sizeof(a[0]);
    for( int i =0 ; i< len ; i++)
    {
        for(int j = 0 ; j < len-1 ; j++)
        {
            if( a[j] > a[j+1] )
            {
                int temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
    }

    for(int i =0 ; i< len ; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");

    printf("Enter key : ");
    int key;
    scanf("%d", &key);

    int l =0;
    int h = len;

    while( l <= h )
    {
        int mid = (l+h) / 2;

        if( key == a[mid])
        {
            printf("Value found at %d ", mid);
            return 0;
        }
        else if( key < a[mid] )
        {
            h = mid -1;
        }
        else if (key > a[mid] )
        {
            l = mid + 1;
        }
    }

    printf("Value not found ");
}