#include "../include/header.h"

int    *get_pile_string(char *nbs, int *size_a)
{
    int i;
    int *pile_int;
    char **split_nbs;

    i = 0;
    split_nbs = ft_split(nbs, ' ');
    while (split_nbs[i])
        i++;
    pile_int = malloc(sizeof(int) * i);
    if(pile_int == NULL)
        exit(-1);
    i = 0;
    while (split_nbs[i])
    {
        pile_int[i] = ft_atoi(split_nbs[i]);
        *size_a += 1;
        i++;
    }
    del_a_bin(split_nbs);
    return (pile_int);
}

int    *get_pile(char *argv[], int *size_a, int argc)
{
    int i;
    int *pile_int;

    pile_int = malloc(sizeof(int) * argc - 1);
    if(pile_int == NULL)
        exit(-1);
    i = 0;
    while (i < argc - 1)
    {
        pile_int[i] = ft_atoi(argv[i + 1]);
        *size_a += 1;
        i++;
    }
    return (pile_int);
}

void copy_int(int **dest, int **src, int size)
{
    int i;

    i = 0;
    *dest = malloc(sizeof(int) * (size));
    if (dest == NULL)
        exit(-1);
    while (i < size)
    {
        (*dest)[i] = (*src)[i];
        i++;
    }
}

void refresh_bin(t_stacks *stacks)
{
    if(*stacks->size_a > 0 && *stacks->a_bin != NULL)
    {
        del_a_bin(*stacks->a_bin);
        *stacks->a_bin = a_conv_bin(*stacks->a, *stacks->size_a, stacks->size_max);
    }
    else if(*stacks->size_a > 0 && *stacks->a_bin == NULL)
        *stacks->a_bin = a_conv_bin(*stacks->a, *stacks->size_a, stacks->size_max);

    if(*stacks->size_b > 0 && *stacks->b_bin != NULL)
    {
        del_a_bin(*stacks->b_bin);
        *stacks->b_bin = a_conv_bin(*stacks->b, *stacks->size_b, stacks->size_max);
    }
    else if(*stacks->size_b > 0 && *stacks->b_bin == NULL)
        *stacks->b_bin = a_conv_bin(*stacks->b, *stacks->size_b, stacks->size_max);
}

int main(int argc, char* argv[])
{
    t_stacks stacks;
    int *a;
    int *a_cp;
    int *b;
    char **a_bin;
    char **b_bin;
    int size_a;
    int size_b;
    int save_a;

    b = NULL;
    a_bin = NULL;
    b_bin = NULL;
    size_a = 0;
    size_b = 0;
    a_cp = NULL;
    if (argc == 1)
        return (0);
    else if(argc <= 2)
        a = get_pile_string(argv[1], &size_a);
    else
        a = get_pile(argv, &size_a, argc);
    

    save_a = size_a;
    copy_int(&a_cp, &a, save_a);
    sort(&a_cp, save_a);
    symplify(&a_cp, &a, save_a);
    stacks.a = &a;
    stacks.b = &b;
    stacks.size_a = &size_a;
    stacks.size_b = &size_b;
    stacks.a_bin = &a_bin;
    stacks.b_bin = &b_bin;
    stacks.size_max = size_max(a, save_a);

    refresh_bin(&stacks);

    if (save_a > 5)
        sort_big_stack(&stacks);
    else
        sort_big_stack(&stacks);

    del_a_bin(a_bin);
    del_a_bin(b_bin);
    free(*stacks.b);
    free(*stacks.a);
    return (0);
}