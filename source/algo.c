#include "../include/header.h"

void sort(int **a_cp, int size_a)
{
    int i;
    int temp;

    i = 0;
    while (i < size_a)
    {
        if(i + 1 < size_a && (*a_cp)[i] > (*a_cp)[i + 1])
        {
            temp = (*a_cp)[i];
            (*a_cp)[i] = (*a_cp)[i + 1];
            (*a_cp)[i + 1] = temp;
            i = 0;
            continue;
        }
        i++;
    }
}

void symplify(int **a_cp, int **a, int size_a)
{
    int i;
    int j;
    int *a_temp;

    a_temp = NULL;
    copy_int(&a_temp, a, size_a);
    i = 0;
    while (i < size_a)
    {
        j = 0;
        while (j < size_a)
        {
            if (a_temp[i] == (*a_cp)[j])
                (*a)[i] = j;
            j++;
        }
        i++;
    }
    free(*a_cp);
    free(a_temp);
}


int have_nb(t_stacks *stacks, int i)
{
    int j;

    j = 0;
    while((*stacks->a_bin)[j])
    {
        if ((*stacks->a_bin)[j][i] == '0')
            return (1);
        j++;
    }
    return (0);
}

void sort_big_stack(t_stacks *stacks)
{
    int i;
    int temp;

    i = ft_strlen((*stacks->a_bin)[0]) - 1;
    while (i >= 0)
    {
        temp = (*stacks->a)[0];
        while (have_nb(stacks, i) == 1)
        {
            if ((*stacks->a_bin)[0][i] == '0')
            {
                if (temp == (*stacks->a)[0] && *stacks->size_a > 0)
                    temp = (*stacks->a)[1];
                push_b(stacks);
            }
            else
                rotate_a(stacks, 0);
        }
        while (temp != (*stacks->a)[0])
            rotate_a(stacks, 0);
        while(*stacks->size_b > 0)
            push_a(stacks);            
        i--;
    }
}

void sort_low_stack(t_stacks *stacks)
{
    int i;
    int j;
    int tmp_a;

    i = 0;
    tmp_a = *stacks->size_a;
    while (i < tmp_a)
    {
        j = 0;
        while (j < tmp_a)
        {
            if((*stacks->a)[0] > (*stacks->a)[1])
                swap_a(stacks, 0);
            else
                rotate_a(stacks, 0);
            j++;
        }
        i++;
    }
}