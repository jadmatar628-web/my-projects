#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main()
{
    printf("Enter a word: ");
    char *word;
    word=malloc(100*sizeof(char));
    scanf("%s",word);
    int len=strlen(word);
    int found=0;
    int isunique=0;
    int isduplicate=0;
    for(int i=0;i<len;i++)
    {
       isduplicate=0;
        for(int j=0;j<len;j++)
        {  
            if(i!=j && *(word+i)==*(word+j))
            {
            isduplicate=1;
            break;
            }
        } 
            if(!isduplicate)
            {
             printf("The first non-repeating charcters in %s is %c.\n",word,*(word+i));
             free(word);
             return 0;
            }
    
    }
  printf("$\n");
}