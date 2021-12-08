#include "../include/header.h"

int	int_count(int nb)
{
	int	count;

	count = 0;
	while (nb / 10)
	{
		count++;
		nb /= 10;
	}
	return (count + 1);
}

int check_nb(int nb, char *strnb)
{
    int i;
    int j;
    
    if (nb == -2147483648 && ft_strncmp(strnb, "-2147483648", 11) == 0)
        return (0);
    j = 0;
    i = int_count(nb) - 1;
    if(strnb[0] == '-')
    {
        if(nb >= 0)
            return(1);
        nb *= -1;
        j = 1;
        i += 1;
    }
    while(i >= j)
    {   
        if (nb % 10 != strnb[i] - '0')
            return (1);
        i--;
        nb /= 10;
    }
    return (0);
}


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
        if(check_nb(pile_int[i], split_nbs[i]) == 1)
        {
            ft_putstr_fd("Error\n", 2);
            del_a_bin(split_nbs);
            exit(-1);
        }
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
        if(check_nb(pile_int[i], argv[i + 1]) == 1)
        {
            ft_putstr_fd("Error\n", 2);
            free(pile_int);
            exit(-1);
        }
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

    b = NULL;
    a_bin = NULL;
    b_bin = NULL;
    size_a = 0;
    size_b = 0;
    a_cp = NULL;
    check_error_part1(argv, argc, &a, &size_a);
    check_error_part2(&a, size_a);
    pre_algo(&a_cp, &a, size_a);
    set_stackp1(&stacks, &a, &b, &size_a);
    set_stackp2(&stacks, &a_bin, &b_bin, &size_b);
    sort_high(&stacks);
    free_all(a_bin, b_bin, &stacks);
    return (0);
}