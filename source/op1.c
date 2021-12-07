#include "../include/header.h"

void swap_a(t_stacks *stacks, int mute)
{
    int temp;

    if (*stacks->size_a >= 2)
    {
        temp = (*stacks->a)[0];
        (*stacks->a)[0] = (*stacks->a)[1];
        (*stacks->a)[1] = temp;
        refresh_bin(stacks);
        if(mute == 0)
            ft_putstr_fd("sa\n", 1);
    }
}

void swap_b(t_stacks *stacks, int mute)
{
    int temp;

    if (*stacks->size_b >= 2)
    {
        temp = (*stacks->b)[0];
        (*stacks->b)[0] = (*stacks->b)[1];
        (*stacks->b)[1] = temp;
        refresh_bin(stacks);
        if(mute == 0)
            ft_putstr_fd("sb\n", 1);
    }
}

void swap_all(t_stacks *stacks)
{
    swap_a(stacks, 1);
    swap_b(stacks, 1);
    refresh_bin(stacks);
    ft_putstr_fd("ss\n", 1);
}

void push_b(t_stacks *stacks)
{

    if (*stacks->size_a >= 1)
    {
        *stacks->b = ft_realloc_add(*stacks->b, *stacks->size_b + 1);
        *stacks->size_b += 1;
        (*stacks->b)[0] = (*stacks->a)[0];
        *stacks->a = ft_realloc_del(*stacks->a, *stacks->size_a - 1);
        *stacks->size_a -= 1;
        refresh_bin(stacks);
        ft_putstr_fd("pb\n", 1);
    }
}


