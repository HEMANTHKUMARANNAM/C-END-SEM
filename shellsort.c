#include <stdio.h>    

int shell(int a[], int n)  
{  
    for (int interval = n/2; interval > 0; interval /= 2)  
    {  
        for (int i = interval; i < n; i ++)  
        {    
            int temp = a[i];  
            int j;        
            for (j = i; j >= interval && a[j - interval] > temp; j -= interval)  
            {
                a[j] = a[j - interval];
                printf("y%d\n", j); 
            }
            a[j] = temp;  
            printf("x%d\n" ,i);
        }  
    }  
    return 0;  
}  

int main()  
{  
    int a[] = { 33, 31, 40, 8, 12, 17, 25, 42 };  
    int n = 8;                                  //int n = sizeof(a) / sizeof(a[0]);    
    shell(a, n);  
    printf("After applying shell sort, the array elements are - \n");    
    for(int i = 0; i < n; i++)
    {
        printf("%d ", a[i]); 
    }
    return 0;  
}  
