#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main()
{
    char **words=NULL;
    char buffer[100];
    int count=0;
    while(1)
    {
        printf("Enter words (type \"finish\" to stop): ");
        fgets(buffer,100,stdin);
        buffer[strcspn(buffer, "\n")] = 0;
        char *entry=malloc(strlen(buffer)+1);
        strcpy(entry,buffer);
        words=realloc(words,(count+1)*sizeof(char *));
        words[count]=entry;
        count++;
        if(strcmp(buffer,"finish")==0)
        {
            count--;
            break;
        }
    }
    printf("You entered %d words:\n",count);
    for(int i=0;i<count;i++)
    {
        printf("%s ",words[i]);
        free(words[i]);
    }
    free(words);
    return 0;
}