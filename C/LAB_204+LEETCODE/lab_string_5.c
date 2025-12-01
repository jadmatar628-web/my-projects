#include<stdio.h>
#include<string.h>

int main()
{
    char word1[100];
    char word2[100];
    printf("Enter first string: ");
    fgets(word1,100,stdin);
    printf("Enter second string: ");
    fgets(word2,100,stdin);
    for(int i=0;i<sizeof(word1);i++)
    {
        if(word1[i]==word2[i])
        {
            word1[i]='j';
        }
    }
    printf("%s",word1);
    return 0;
}