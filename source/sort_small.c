/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeshaye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 05:18:24 by pdeshaye          #+#    #+#             */
/*   Updated: 2021/12/10 05:18:25 by pdeshaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/header.h"

static void	solve_2(t_stacks *stacks)
{
	if ((*stacks->a)[0] > (*stacks->a)[1])
		swap_a(stacks, 0);
}

static void	solve_3(t_stacks *stacks)
{
	int	max;
	int	i;

	max = (*stacks->a)[0];
	i = 0;
	while (i < *stacks->size_a)
	{
		if (max < (*stacks->a)[i])
			max = (*stacks->a)[i];
		i++;
	}
	if ((*stacks->a)[0] == max)
	{
		rotate_a(stacks, 0);
		solve_2(stacks);
		return ;
	}
	while ((*stacks->a)[*stacks->size_a - 1] != max)
		reverse_rotate_a(stacks, 0);
	solve_2(stacks);
}

static void	solve_4(t_stacks *stacks, int min)
{
	int	median;
	int	i;

	i = 0;
	median = (*stacks->size_a - 1) / 2;
	while (i <= median)
	{
		if ((*stacks->a)[i] == min)
		{
			while ((*stacks->a)[0] != min)
				rotate_a(stacks, 0);
			push_b(stacks);
			solve_3(stacks);
			push_a(stacks);
			return ;
		}
		i++;
	}
	while ((*stacks->a)[0] != min)
		reverse_rotate_a(stacks, 0);
	push_b(stacks);
	solve_3(stacks);
	push_a(stacks);
}

static void	solve_5(t_stacks *stacks)
{
	int	median;
	int	i;

	i = 0;
	median = (*stacks->size_a - 1) / 2;
	while (i <= median)
	{
		if ((*stacks->a)[i] == 0)
		{
			while ((*stacks->a)[0] != 0)
				rotate_a(stacks, 0);
			push_b(stacks);
			solve_4(stacks, 1);
			push_a(stacks);
			return ;
		}
		i++;
	}
	while ((*stacks->a)[0] != 0)
		reverse_rotate_a(stacks, 0);
	push_b(stacks);
	solve_4(stacks, 1);
	push_a(stacks);
}

void	solve_5_or_less(t_stacks *stacks)
{
	if (*stacks->size_a == 2)
		swap_a(stacks, 0);
	else if (*stacks->size_a == 3)
		solve_3(stacks);
	else if (*stacks->size_a == 4)
		solve_4(stacks, 0);
	else if (*stacks->size_a <= 5)
		solve_5(stacks);
}
