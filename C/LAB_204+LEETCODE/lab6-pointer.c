#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main()
{
    printf("Enter how many students do you have: ");
    int stdcount, coursecount;
    scanf("%d",&stdcount);
    int **arr=malloc(stdcount*sizeof(int *));
    for(int i=0;i<stdcount;i++)
    {
        printf("Enter how many courses for student #%d: ",i+1);
        scanf("%d",&arr[i]);
        arr[i]=malloc(coursecount*sizeof(int));

    }

}