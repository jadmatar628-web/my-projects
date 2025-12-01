#include<stdio.h>
#include<string.h>

int compress(char *word)
{
    int len=strlen(word);
    int count=0;
    int i=0;
    int write=0;
    while(i<len)
    {
        char current=word[i];
        while(i<len && word[i]==current)
        {
            i++;
            count++;
        }
        word[write++]=current;
        if(count>9)
        {
            char temp[100];
            sprintf(temp,"%d",count);
            for (int j = 0; temp[j] != '\0'; j++)
            word[write++] = temp[j];

        }
        count=0;
    }
    return write;
}

int main()
{
    printf("Enter a string: ");
    char word[100];
    scanf("%s",word);
    int write=compress(word);
    printf("%d",write);
}