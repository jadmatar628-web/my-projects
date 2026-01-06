#include<stdio.h>
#include<stdlib.h>

void matrixstore(int *matrix, int col, int row)
{
    FILE *mat=fopen("mat.dat","wb");
    if(!mat)
    {
        return;
    }
   fwrite(&row,sizeof(int),1,mat);
   fwrite(&col,sizeof(int),1,mat);
   for(int i=0;i<row;i++)
   {
    for(int j=0;j<col;j++)
    {
        fwrite(&matrix[i*col+j],sizeof(int),1,mat);
    }
   }
fclose(mat);
}