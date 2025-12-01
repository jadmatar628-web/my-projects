#include<stdio.h>
//implement strlen using pointer arithmetic
size_t mystrlen(char *word)
{
    int count=0;
    char *p=word;
    while(*p!='\0')
    {
        count++;
        p++;
    }


return count;
}

int main()
{
    printf("Enter a string to measure its length: ");
    char word[100];
    fgets(word,100,stdin);
    printf("The length of %s is %ld.\n",word,mystrlen(word));
}