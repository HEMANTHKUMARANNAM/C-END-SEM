#include<stdio.h>

int main()
{
    int a[]= { 1 , 8 , 2 , 0 , 12 , 19 , 21 , 3 , 22 , 15 , 14 };

    int len = 11;                                          // int l = sizeof(a) / sizeof(a[0]);

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

    for (int i = 0; i < len ; i++)
    {
        printf("%d ", a[i]);
    }

    printf("\n");

}