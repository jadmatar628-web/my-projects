#include<stdio.h>
#include<strings.h>
#include<stdlib.h>
#include"queue.h"

int *findchar(Queue *q)
{
    char ch='a';
    int freq[26]={0};
    while(!isEmpty(q)&& freq[ch-'a']!=-1)
}