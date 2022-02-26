#include<stdio.h>
#include<stdlib.h>

int main()
{
    int i;
    int *ptr=(int*)malloc(2*sizeof(int));

    if (ptr==NULL)
    {
        printf("memory is not available");
        exit(1);
    }
    printf("enter the two numbers:");
    for ( i = 0; i < 2; i++)
    {
        scanf("%d",ptr+i);
    }
    
    // memory allocation for two more integers
    ptr=(int*)realloc(ptr,4*sizeof(int));

    if (ptr==NULL)
    {
        printf("memory not available");
        exit(1);
    }
    printf("enter 2 more integers: ");
    for ( i = 2; i <4 ; i++)
    {
        scanf("%d",ptr+i);
    }
    for ( i = 0; i < 4; i++)
    {
        printf("%d \n",*(ptr+i));
    }
    return 0;

}