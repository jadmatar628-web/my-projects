#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct student{
    int age;
    char name[50];
};
int main()
{
printf("Enter the number of students: ");
int number;
scanf("%d",&number);
while(getchar()!='\n');
struct student *p=NULL;
p=malloc(number*sizeof(struct student));
if(p==NULL)
{
    printf("Memory allocation failed");
    return 1;
}
for(int i=0;i<number;i++)
{
printf("Enter the name of student #%d: ",i+1);
fgets(p[i].name, sizeof(p[i].name), stdin);
size_t len=strlen(p[i].name);
if(len>0 && p[i].name[len-1]=='\n')
{
    p[i].name[len-1]='\0';
}
printf("Enter the age of student #%d: ",i+1);
scanf("%d",&p[i].age);
while(getchar()!='\n'); 

}

for(int i=0;i<number;i++)
{
    printf("The name of student #%d is %s and they are %d years old.\n",i+1,p[i].name,p[i].age);
}
free(p);
}