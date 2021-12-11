/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_checksp2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeshaye <pdeshaye@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 05:08:23 by pdeshaye          #+#    #+#             */
/*   Updated: 2021/12/11 16:11:07 by pdeshaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/header.h"

int	is_sort(int *a, int size_a)
{
	int	i;

	i = 0;
	if (size_a <= 1)
	{
		free(a);
		exit(0);
	}
	while (i < size_a)
	{
		if (i + 1 < size_a && a[i] > a[i + 1])
			return (0);
		i++;
	}
	return (1);
}

void	error_double(int **pile, int pile_size)
{
	int	i;
	int	j;
	int	temp;
	int	count_nb;

	i = 0;
	while (i < pile_size)
	{
		j = 0;
		count_nb = 0;
		temp = (*pile)[i];
		while (j < pile_size)
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

void	check_error_part2(t_stacks_init *init)
{
	error_double(&init->a, init->size_a);
	if (is_sort(init->a, init->size_a) == 1)
	{
		free(init->a);
		exit(0);
	}
}
