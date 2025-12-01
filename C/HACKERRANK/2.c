#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num, *arr, i;
    scanf("%d", &num);
    arr = (int*) malloc(num * sizeof(int));
    for(i = 0; i < num; i++) {
        scanf("%d", arr + i);
    }
    for(i=0;i<num;i++)
    {
     int temp=arr[i];
     arr[i]=arr[num-1];
     arr[num-1]=temp;
     num--;

    }

    for(i = 0; i < num*2; i++)
        printf("%d ", *(arr + i));
    return 0;
}