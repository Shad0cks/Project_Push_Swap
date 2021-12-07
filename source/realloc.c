#include "../include/header.h"

int *ft_realloc_del(int *pile, int new_size)
{
    int *new_pile;
    int i;

    i = 0;
    new_pile = malloc(sizeof(int) * new_size);
    if(new_pile == NULL)
        exit(-1);
    while(i < new_size)
    {
        new_pile[i] = pile[i + 1];
        i++;
    }
    free(pile);
    pile = NULL;
    return (new_pile);
}

int *ft_realloc_add(int *pile, int new_size)
{
    int *new_pile;
    int i;

    i = 0;
    new_pile = malloc(sizeof(int) * new_size);
    if(new_pile == NULL)
        exit(-1);
    while(i < new_size - 1)
    {
        new_pile[i + 1] = pile[i];
        i++;
    }
    new_pile[0] = 0;
    free(pile);
    pile = NULL;
    return (new_pile);
}