#include<stdio.h>

int main()
{
    int a[] = { 3 , 6 , 7 , 9 , 12 , 45 , 1};

    int len = 7 ;       // int len = sizeof(a)/sizeof(a[0]);

    printf("Enter key : ");
    int key;
    scanf("%d", &key);

    for(int i = 0; i < len; i++)
    {
        if( a[i] == key)
        {
            printf("value found at  %d", i);
            return 0;
        }
    }

    printf("Value not found ");

}