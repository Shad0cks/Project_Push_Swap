#include "../include/header.h"

void push_a(t_stacks *stacks)
{

    if (*stacks->size_b >= 1)
    {
        *stacks->a = ft_realloc_add(*stacks->a, *stacks->size_a + 1);
        *stacks->size_a += 1;
        (*stacks->a)[0] = (*stacks->b)[0];
        *stacks->b = ft_realloc_del(*stacks->b, *stacks->size_b - 1);
        *stacks->size_b -= 1;  
        refresh_bin(stacks);
        ft_putstr_fd("pa\n", 1);
    }
}

void reverse_rotate_a(t_stacks *stacks, int mute)
{
    int i;
    int temp;

    i = *stacks->size_a - 1;
    while(i >= 0)
    {
        if(i - 1 >= 0)
        {
            temp = (*stacks->a)[i - 1];
            (*stacks->a)[i - 1] = (*stacks->a)[i];
            (*stacks->a)[i] = temp;
        }
        i--;
    }
    if(mute == 0)
        ft_putstr_fd("rra\n", 1);
    refresh_bin(stacks);
}

void reverse_rotate_b(t_stacks *stacks, int mute)
{
    int i;
    int temp;

    i = *stacks->size_b - 1;
    while(i >= 0)
    {
        if(i - 1 >= 0)
        {
            temp = (*stacks->b)[i - 1];
            (*stacks->b)[i - 1] = (*stacks->b)[i];
            (*stacks->b)[i] = temp;
        }
        i--;
    }
    if(mute == 0)
        ft_putstr_fd("rrb\n", 1);
    refresh_bin(stacks);
}

void rev_rot_all(t_stacks *stacks)
{
    reverse_rotate_a(stacks, 1);
    reverse_rotate_b(stacks, 1);
    refresh_bin(stacks);
    ft_putstr_fd("rrr\n", 1);
}