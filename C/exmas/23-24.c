#include<stdio.h>
#include<stdlib.h>

typedef struct Movie //struct to store movies
{
    int ID, releaseyaer, qty;
    char director[50];
    char title [100];
} Movie;

typedef struct MovieNode //linked lists of movies
{
    Movie movie;
    struct MovieNode *next;
} MovieNode;

typedef struct FilmArchive //more like a local search engine 
{
    char name[50];
    int address;
    struct MovieNode *movies;
} FilmArchive; 

int findmoviebyid(int id, FilmArchive *archive)
{
    int found =0;
    MovieNode *current=archive->movies;
    while(current!=NULL)
    {
        if(current->movie.ID==id)
        {
            found=1;
            return current->movie.qty;
        }
        current=current->next;
    }
    if(found==0)
    {
        return 0;
    }
}

void addmovie(FilmArchive *head, Movie m)
{
    MovieNode *current=head->movies;
    while(current!=NULL)
    {
        if(current->movie.ID==m.ID)
        {
            current->movie.qty+=m.qty;
            return;
        }
        current=current->next;
    }  
    current=head->movies;
    MovieNode* newnode= (MovieNode*)malloc(sizeof(MovieNode));

    newnode->movie=m;
    while(current!=NULL)
    {
        if(current->next==NULL)
        {
            current->next=newnode;
            current=newnode;
            newnode->next=NULL;
            return;
        }
        current=current->next;
    }
}

void savemovie(FilmArchive *head)
{
    FILE *jad=fopen("movies.dat","wb");
    if(!jad)
    {
        return;
    }
    MovieNode *current=head->movies;

    while(current!=NULL)
    {
        fwrite(&current->movie,sizeof(Movie),1,jad);
        current=current->next;
    }
    fclose(jad);
}
void editm(int year, int id)
{
    FILE *nagham=fopen("movies.dat","rwb+");
    if(!nagham)
    {
        return;
    }
    while(fread(&id))
}
