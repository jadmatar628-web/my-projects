#include<stdio.h>
typedef struct Movie{
    char *title;
    int id;
    char *director;
    int release_year;
    int qty;
    struct Movie *next;
} Movie;

typedef struct filmarchive{
    char *name;
    char *address;
    Movie *movie;
}filmarchive;

int finder(int id, filmarchive *film)
{
    Movie *current= film->movie;
  while(current!=NULL)
  {
    if(id==current->id)
    {
        return current->qty;
    }
    current=current->next;
}
        return -1;
}

void addmovie(filmarchive *new, Movie *m)
{
    Movie *current=new->movie;
    while(current!=NULL)
    {
        if(m->id==current->id)
        {
            current->qty+=m->qty;
            return;
        }
        current=current->next;
    }
    if(new->movie == NULL) {
    new->movie = m;
    m->next = NULL;
    return;
}
    current=new->movie;
        m->next=NULL;
    while(current!=NULL)
    {
       if(current->next==NULL)
       {
        current->next=m;
        break;
       }
       current=current->next;
    }
} //end of exercise, i still haven't started files so imma stop here