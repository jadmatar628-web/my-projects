#include<stdio.h>
#include<stdlib.h>

int main()
{
    int *p=NULL;
    int count=0;
    int input;
    while(1)
{
    if(input==-1)
    {
        break;
    }
    else{
        p=realloc(p,(count+1)*sizeof(int));
        printf("Enter Numbers(-1 to stop): ");
        scanf("%d",&input);
        p[count]=input;
        count++;
    }
}
printf("You entered %d numbers:\n",count);
for(int i=0;i<count;i++)
{
    printf("%d ", p[i]);
}
free(p);
}