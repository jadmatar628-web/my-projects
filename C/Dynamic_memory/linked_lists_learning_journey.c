#include<stdio.h>
#include<string.h>
struct student{
    char name[50];
    int age;
};
void updateage(struct student *s, int newage)
{
s->age=newage;
}
int main()
{
    struct student students[3];
   for(int i=0; i<3; i++) {
    printf("Enter the name of student #%d and his age respectively: ", i+1);
    fgets(students[i].name, sizeof(students[i].name), stdin);

    // Remove trailing newline
    size_t len = strlen(students[i].name);
    if (len > 0 && students[i].name[len - 1] == '\n') {
        students[i].name[len - 1] = '\0';
    }

    scanf("%d", &students[i].age);
    while(getchar() != '\n');  // Clear input buffer
}

    for(int i=0;i<3;i++)
    {
        printf("The name of student #%d is %s and he is %d years old.\n",i+1,students[i].name,students[i].age);
    }
    printf("Using pointer:\n");
    struct student *p=students;
    (p+1)->age=25;// changing the age of student #2 to 25
    for(p;p<students+3;p++)
    {
        printf("The name of student #%d is %s and his age is %d\n",p-students+1,p->name,p->age);
        
    }
    p=students;
    printf("Enter the updated age for student #1: ");
    int newage;
    scanf("%d",&newage);
    updateage(&students[1],newage);
    printf("The updated age of student %s is %d.",students[0].name,students[1].age);
}
