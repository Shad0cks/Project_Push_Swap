/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_values.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeshaye <pdeshaye@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 05:16:44 by pdeshaye          #+#    #+#             */
/*   Updated: 2021/12/11 16:29:06 by pdeshaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/header.h"

void	set_stackp1(t_stacks *stacks, t_stacks_init *init)
{
	stacks->a = &init->a;
	stacks->b = &init->b;
	stacks->size_a = &init->size_a;
	stacks->size_max = size_max(init->a, init->size_a);
	stacks->size_b = &init->size_b;
	stacks->a_bin = &init->a_bin;
	stacks->b_bin = &init->b_bin;
}

void	pre_algo(int **a_cp, t_stacks_init *init)
{
	copy_int(a_cp, &init->a, init->size_a);
	sort(a_cp, init->size_a);
	symplify(a_cp, &init->a, init->size_a);
}

void	free_all(t_stacks_init *init, t_stacks *stacks)
{
	del_a_bin(init->a_bin);
	if (init->b_bin)
		del_a_bin(init->b_bin);
	free(*(stacks->b));
	free(*(stacks->a));
}

void	del_a_bin(char **a_bin)
{
	int	i;

	i = 0;
	while (a_bin[i])
	{
		free(a_bin[i]);
		i++;
	}
	free(a_bin);
	a_bin = NULL;
}
