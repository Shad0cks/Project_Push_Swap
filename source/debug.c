#include "../include/header.h"

void debug_pile(t_stacks *stacks)
{
    int i;
    int y;

    i = 0;
    y = 0;
    while(i < *stacks->size_a || y < *stacks->size_b)
    {
        if(i < *stacks->size_a)
            printf("%d == %s\t\t\t", (*stacks->a)[i], (*stacks->a_bin)[i]);
        else
            printf(" \t\t\t");        
        if (y < *stacks->size_b)
            printf("%d == %s\n", (*stacks->b)[y], (*stacks->b_bin)[y]);
        else
             printf("\n");
        i++;
        y++;
    }
    printf("-\t\t\t-\na\t\t\tb\n\n");
}
