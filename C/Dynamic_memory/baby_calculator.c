#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int main()
{
    int *p=NULL;
    int count=0;
    int input=0;
    while(input!=-1)
    {
    
        printf("Enter numbers (-1 to stop): ");
        scanf("%d",&input);
          if(input==-1)
        {
            break;
            exit(1);
        }
        p=realloc(p,(count+1)*sizeof(int));
        p[count]=input;
        count++;
    }
    float sum=0;
    float avg;
    for(int i=0;i<count;i++)
    {
        sum+=p[i];
    }
    printf("Count=%d\nSum=%.0f\n",count,sum);
    avg=(sum/count);
    printf("The average of all the %d entered elements is %.2f.\n",count,avg);
    printf("The whole array:\n");
    for(int i=0;i<count;i++)
    {
        printf("%d ", p[i]);
    }
    free(p);
    return 0;
}