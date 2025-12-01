#include<string.h>
#include<stdio.h>
#include<stdlib.h>
int main()
{
    printf("Enter 2 words: ");
    char *word1, *word2;
    word1=malloc(100);
    word2=malloc(100);
    scanf("%s%s",word1,word2);
    int len=strlen(word1);
    int len1=strlen(word2);
    for(int i=0;i<len;i++)
    {
        for(int j=0;j<len1;j++)
        {

            if(*(word1+i)==*(word2+j))
            {
                int temp=i;
                while(*(word1+i)!='\0')
                {
                    *(word1+i)=*(word1+i+1);
                    i++;
                }
                i=temp-1;
            }
        }
    }
    
    printf("%s\n",word1);
    free(word1);
    free(word2);
return 0;
}