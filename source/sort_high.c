/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_high.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeshaye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 05:17:17 by pdeshaye          #+#    #+#             */
/*   Updated: 2021/12/10 05:17:20 by pdeshaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/header.h"

void	sort_high(t_stacks *stacks)
{
	refresh_bin(stacks);
	if (*stacks->size_a > 5)
		sort_big_stack(stacks);
	else
		solve_5_or_less(stacks);
}
