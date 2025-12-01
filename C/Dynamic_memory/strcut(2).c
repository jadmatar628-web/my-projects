#include<stdio.h>
struct student{
    char name[50];
    int age;
};
void printstudent(struct stuedent *s,struct student *p)
{
    printf("The name of the student is %s and they are %d years old.\n",s->student.name,p->student.age);
}

