#include "../include/header.h"

void set_stackp1(t_stacks *stacks, int **a, int **b, int *size_a)
{
    stacks->a = a;
    stacks->b = b;
    stacks->size_a = size_a;
    stacks->size_max = size_max(*a, *size_a);
}

void set_stackp2(t_stacks *stacks, char ***a_bin, char ***b_bin, int *size_b)
{
    stacks->size_b = size_b;
    stacks->a_bin = a_bin;
    stacks->b_bin = b_bin;
}

void pre_algo(int **a_cp, int **a, int size_a)
{
    copy_int(a_cp, a, size_a);
    sort(a_cp, size_a);
    symplify(a_cp, a, size_a);
}

void free_all(char **a_bin, char **b_bin, t_stacks *stacks)
{
    del_a_bin(a_bin);
    if(b_bin)
        del_a_bin(b_bin);
    free(*(stacks->b));
    free(*(stacks->a));
}