#include "../include/header.h"

void sort_high(t_stacks *stacks)
{
    refresh_bin(stacks);
    if (*stacks->size_a > 5)
        sort_big_stack(stacks);
    else
        solve_5_or_less(stacks);
}