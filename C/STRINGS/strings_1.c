//strlen gunciton

#include<stdio.h>
#include<string.h>

int strlent(char name[])
{
    int i=0;
    while(name[i]!='\0')
    {
        i++;
      
    }
      return i;
}

int main()
{
    printf("Enter a word\n");
    char name[100];
    int i=0;
    scanf("%s",name);
        printf("%s\n",name);
        int count=strlent(name);
        printf("the length of the entered string is: %d",count);
    return 0;

}