/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeshaye <pdeshaye@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 05:09:17 by pdeshaye          #+#    #+#             */
/*   Updated: 2021/12/11 16:30:53 by pdeshaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/header.h"

int	check_nb(int nb, char *strnb)
{
	int	i;
	int	j;

	if (nb == -2147483648 && ft_strncmp(strnb, "-2147483648", 11) == 0)
		return (0);
	j = 0;
	i = int_count(nb) - 1;
	if (strnb[0] == '-')
	{
		if (nb >= 0)
			return (1);
		nb *= -1;
		j = 1;
		i += 1;
	}
	while (i >= j)
	{	
		if (nb % 10 != strnb[i] - '0')
			return (1);
		i--;
		nb /= 10;
	}
	return (0);
}

int	*get_pile_string(char *nbs, int *size_a)
{
	int		i;
	int		*pile_int;
	char	**split_nbs;

	i = 0;
	split_nbs = ft_split(nbs, ' ');
	while (split_nbs[i])
		i++;
	pile_int = malloc(sizeof(int) * i);
	if (pile_int == NULL)
		exit(-1);
	i = -1;
	while (split_nbs[++i])
	{
		pile_int[i] = ft_atoi(split_nbs[i]);
		if (check_nb(pile_int[i], split_nbs[i]) == 1)
		{
			ft_putstr_fd("Error\n", 2);
			del_a_bin(split_nbs);
			exit(-1);
		}
		*size_a += 1;
	}
	del_a_bin(split_nbs);
	return (pile_int);
}

int	*get_pile(char *argv[], int *size_a, int argc)
{
	int	i;
	int	*pile_int;

	pile_int = malloc(sizeof(int) * argc - 1);
	if (pile_int == NULL)
		exit(-1);
	i = 0;
	while (i < argc - 1)
	{
		pile_int[i] = ft_atoi(argv[i + 1]);
		if (check_nb(pile_int[i], argv[i + 1]) == 1)
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

void	copy_int(int **dest, int **src, int size)
{
	int	i;

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

int	main(int argc, char *argv[])
{
	t_stacks		stacks;
	t_stacks_init	stacks_init;
	int				*a_cp;

	stacks_init.b = NULL;
	stacks_init.a = NULL;
	stacks_init.a_bin = NULL;
	stacks_init.b_bin = NULL;
	stacks_init.size_a = 0;
	stacks_init.size_b = 0;
	a_cp = NULL;
	check_error_part1(argv, argc, &stacks_init);
	check_error_part2(&stacks_init);
	pre_algo(&a_cp, &stacks_init);
	set_stackp1(&stacks, &stacks_init);
	sort_high(&stacks);
	free_all(&stacks_init, &stacks);
	return (0);
}
