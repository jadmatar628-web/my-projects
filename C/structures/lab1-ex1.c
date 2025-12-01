#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct person
{
    char firstname[50];
    char lastname[50];
    int age;
    char job[100];
    struct person *father; 
};

int main()
{
   // struct person Jules;
   // printf("Enter Jules's last name: ");
  //  scanf("%s",Jules.lastname);
   // printf("Enter Jule's Age: ");
   // scanf("%d",&Jules.age);
  //  printf("Enter Jule's Job: ");
 //   scanf("%s",Jules.job);
 //   printf("Jules last name is %s, her age is %d and she works as a %s.",Jules.lastname,Jules.age,Jules.job);
    struct person pjules;
    strcpy(pjules.lastname,"Patric");
    strcpy(pjules.firstname,"David");
    pjules.age=80;
    strcpy(pjules.job,"Painting");
    pjules.father=NULL;
    struct person jules;
    strcpy(jules.firstname,"Durand");
    strcpy(jules.lastname,"Jules");
    jules.age=27;
    strcpy(jules.job,"Engineering");
    jules.father=&pjules;
    printf("Jules last name is %s, her age is %d and she works as a %s and her father name is %s.\n",jules.lastname,jules.age,jules.job,jules.father->lastname);

}
