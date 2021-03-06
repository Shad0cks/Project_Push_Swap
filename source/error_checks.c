/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_checks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeshaye <pdeshaye@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 05:06:24 by pdeshaye          #+#    #+#             */
/*   Updated: 2021/12/11 16:14:29 by pdeshaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/header.h"

int	is_whine_or_nb(char c)
{
	if (c == ' ' || c == '\t' || c == '\n' || c == '\v'
		|| c == '\f' || c == '\r' || c == '-' || c == '+'
		|| (c <= '9' && c >= '0'))
		return (1);
	return (0);
}

int	error_notnb(char *nbs)
{
	int	i;

	i = 0;
	while (nbs[i])
	{
		if (is_whine_or_nb(nbs[i]) == 1)
		{
			if (nbs[i] == '-' || nbs[i] == '+')
			{
				if (nbs[i + 1] && (nbs[i] == '-' || nbs[i] == '+')
					&& (nbs[i + 1] <= '9' && nbs[i + 1] >= '0'))
				{
					i++;
					continue ;
				}
				else
					return (1);
			}
			i++;
			continue ;
		}
		return (1);
	}
	return (0);
}

void	multiple_list(char *argv[], int argc)
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j] && !(argv[i][j] >= '0' && argv[i][j] <= '9'))
			j++;
		while (argv[i][j] && (argv[i][j] >= '0' && argv[i][j] <= '9'))
			j++;
		while (argv[i][j])
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

int	error_notnbs(char *argv[], int argc)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (error_notnb(argv[i]) == 0)
		{
			i++;
			continue ;
		}
		return (1);
	}
	return (0);
}

void	check_error_part1(char *argv[], int argc, t_stacks_init *init)
{
	if (argc == 1)
	{
		ft_putstr_fd("Error\n", 2);
		exit(-1);
	}
	else if (argc == 2)
	{
		if (error_notnb(argv[1]) == 1)
		{
			ft_putstr_fd("Error\n", 2);
			exit(-1);
		}
		init->a = get_pile_string(argv[1], &init->size_a);
	}
	else
	{
		multiple_list(argv, argc);
		if (error_notnbs(argv, argc) == 1)
		{
			ft_putstr_fd("Error\n", 2);
			exit(-1);
		}
		init->a = get_pile(argv, &init->size_a, argc);
	}
}
