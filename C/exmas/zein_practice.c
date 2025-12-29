#include<stdio.h>
#include<string.h>

typedef struct Student
{
    int id;
    char name[50];
    float avg;
} Student;
int main()
{
Student alice;
FILE *fp=fopen("students.txt","r");
if(fp==NULL)
{
    printf("Error\n");
    return 1;
}
char line[100];
fgets(line,100,fp);
sscanf(line,"ID: %d",&alice.id);
fgets(line,100,fp);
sscanf(line,"Name: %49[^\n]",alice.name);
fgets(line,100,fp);
sscanf(line,"Average: %f",&alice.avg);
printf("%d\n%s\n%.2f\n",alice.id,alice.name,alice.avg);
fclose(fp);
}