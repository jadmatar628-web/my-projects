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


void findmax()
{
    FILE *jad=fopen("mat.dat","rb");
    if(!jad)
    {
        return;
    }
    int posi, posj,value;
    fread(&posi,sizeof(int),1,jad);
    fread(&posj,sizeof(int),1,jad);
    int indi=0;
    int indj=0;
    int max;
    fread(&max,sizeof(int),1,jad); //first element of the matrix
    for(int i=0;i<posi;i++)
    {
        for(int j=0;j<posj;j++)
        {
            fread(&value,sizeof(int),1,jad);
            if(value>max)
            {
                max=value;
                indi=i;
                indj=j;
            }
        }
    }
    fclose(jad);
}
void update(int i, int j, int ii, int jj)
{
    FILE *j=fopen("mat.dat","rwb+");
    if(!j)
    {
        return ;
    }
      int posi, posj;
    fread(&posi,sizeof(int),1,j);
    fread(&posj,sizeof(int),1,j);
    

}