#include "../include/header.h"
#include <fcntl.h>

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

void multiple_list(char *argv[], int argc)
{
    int i;
    int j;

    i = 1;
    while (i < argc)
    {
        j = 0;
        while (argv[i][j] && !(argv[i][j] >= '0' && argv[i][j] <= '9'))
            j++;
        while (argv[i][j] && (argv[i][j] >= '0' && argv[i][j] <= '9'))
            j++;
        while(argv[i][j])
        {
            if (argv[i][j] >= '0' && argv[i][j] <= '9')
            {
                ft_putstr_fd("Error\n", 2);
                exit(-1);
            }
            j++;   
        }
        i++;
    }
}

int is_sort(int *a, int size_a)
{
    int i;

    i = 0;
    if(size_a <= 1)
    {
        free(a);
        exit(0);
    }
    while (i < size_a)
    {
        if(i + 1 < size_a && a[i] > a[i + 1])
            return (0);
        i++;
    }
    return (1);
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

int error_notnb(char *nbs)
{
    int i;

    i = 0;
    while (nbs[i])
    {
        if(nbs[i] == ' ' || nbs[i] == '-' || nbs[i] == '+' || (nbs[i] <= '9' && nbs[i] >= '0'))
        {
            if (nbs[i] == '-' || nbs[i] == '+')
            {
                if (nbs[i + 1] && (nbs[i] == '-' || nbs[i] == '+') && (nbs[i + 1] <= '9' && nbs[i + 1] >= '0'))
                {
                    i++;
                    continue;
                }
                else
                    return (1);
            }
            i++;
            continue;
        }
        return (1);
    }
    return (0);
}

void error_double(int **pile, int pile_size)
{
    int i;
    int j;
    int temp;
    int count_nb; 

    i = 0;
    while (i < pile_size)
    {
        j = 0;
        count_nb = 0;
        temp = (*pile)[i];
        while(j < pile_size)
        {
            if (temp == (*pile)[j])
                count_nb++;
            if (count_nb >= 2)
            {
                ft_putstr_fd("Error\n", 2);
                free(*pile);
                exit(-1);
            }
            j++;
        }
        i++;
    }
}

int error_notnbs(char *argv[] ,int argc)
{
    int i;

    i = 1;
    while (i < argc)
    {
        if(error_notnb(argv[i]) == 0)
        {
            i++;
            continue;
        }
        return (1);
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
    int save_a;

    b = NULL;
    a_bin = NULL;
    b_bin = NULL;
    size_a = 0;
    size_b = 0;
    a_cp = NULL;

    if (argc == 1)
    {
        ft_putstr_fd("Error\n", 2);
        return (0);
    }
    else if(argc == 2)
    {
        if (error_notnb(argv[1]) == 1)
        {
            ft_putstr_fd("Error\n", 2);
            return (0);
        }
        a = get_pile_string(argv[1], &size_a);
    }
    else
    {
        multiple_list(argv, argc);
        if (error_notnbs(argv, argc) == 1)
        {
            ft_putstr_fd("Error\n", 2);
            return (0);
        }
        a = get_pile(argv, &size_a, argc);
    }
    
    error_double(&a, size_a);
    if(is_sort(a, size_a) == 1)
    {
        free(a);
        return (0);
    }

    if (size_a <= 1)
    {
        ft_putstr_fd("Error\n", 2);
        free(a);
        return (0);
    }
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
        solve_5_or_less(&stacks);

    del_a_bin(a_bin);
    if(b_bin)
        del_a_bin(b_bin);
    free(*stacks.b);
    free(*stacks.a);
    return (0);
}