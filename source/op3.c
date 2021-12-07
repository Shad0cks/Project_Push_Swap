#include "../include/header.h"

void rotate_a(t_stacks *stacks, int mute)
{
    int i;
    int temp;

    i = 0;
    while(i < *stacks->size_a)
    {
        if(i + 1 < *stacks->size_a)
        {
            temp = (*stacks->a)[i + 1];
            (*stacks->a)[i + 1] = (*stacks->a)[i];
            (*stacks->a)[i] = temp;
        }
        i++;
    }
    if(mute == 0)
        ft_putstr_fd("ra\n", 1);
    refresh_bin(stacks);
}

void rotate_b(t_stacks *stacks, int mute)
{
    int i;
    int temp;

    i = 0;
    while(i < *stacks->size_b)
    {
        if(i + 1 < *stacks->size_b)
        {
            temp = (*stacks->b)[i + 1];
            (*stacks->b)[i + 1] = (*stacks->b)[i];
            (*stacks->b)[i] = temp;
        }
        i++;
    }
    if(mute == 0)
        ft_putstr_fd("rb\n", 1);
    refresh_bin(stacks);
}

void rot_all(t_stacks *stacks)
{
    rotate_a(stacks, 1);
    rotate_b(stacks, 1);
    refresh_bin(stacks);
    ft_putstr_fd("rr\n", 1);
}
