#include<stdio.h>
#include<stdlib.h>
#include<math.h>
struct point
{
    int x,y,z;
    char name[4];
    char color[2];
};

void readpoint(struct point *a)
{
   printf("Enter the coordinates of your point: ");
   scanf("%d %d %d",&a->x,&a->y,&a->z);
   printf("Enter its name: ");
   scanf(" %3s",a->name);
   printf("Enter its color: ");
   scanf(" %c",&a->color[0]);
}

double distance(struct point *a,struct point *b)
{
 return(sqrt(pow(a->x-b->x,2)+(pow(a->y-b->y,2))+(pow(a->z-b->z,2))));
}
void check(struct point *a, struct point *b)
{
 double res=distance(&a,&b);
 if(res==0)
 {
    if(a->color==b->color)
    {
        printf("Identical.\n");
    }
}

    else
    printf("Not indentical");

}
int main()
{
struct point a;
struct point b;
readpoint(&a);
readpoint(&b);
double res=distance(&a,&b);
printf("%lf",res);
}
 