#include<stdio.h>
#include<stdlib.h>

int main()
{
    int rows;
    printf("Enter the # of rows: ");
    scanf("%d",&rows);
    if(rows<0 || rows ==0)
    {do{
        printf("Entry must be >0, try again: ");
        scanf("%d",&rows);
    } while(rows<=0);}
int **matrix=NULL;
matrix=malloc(rows*sizeof(int*));
int *col=NULL;
col=malloc(rows*sizeof(int));
for(int i=0;i<rows;i++)
{
printf("Enter how many columns in row #%d: ",i+1);
scanf("%d",&col[i]);
matrix[i]=malloc(col[i]*sizeof(int));
for(int j=0;j<col[i];j++)
{
    printf("Enter element into row %d and colum %d: ",i+1,j+1);
    scanf("%d",&matrix[i][j]);
}
}
    for(int i=0;i<rows;i++)
    {
        for(int j=0;j<col[i];j++)
        {
            printf("%d ",matrix[i][j]);
        }
        printf("\n");
        free(matrix[i]);
    }
    free(col);
    free(matrix);
    return 0;
}