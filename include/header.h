/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeshaye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 04:57:56 by pdeshaye          #+#    #+#             */
/*   Updated: 2021/12/10 05:00:18 by pdeshaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include "../libft/libft.h"

typedef struct s_stacks
{
	int		**a;
	int		**b;
	int		*size_a;
	int		*size_b;
	char	***a_bin;
	char	***b_bin;
	int		size_max;
}	t_stacks;

int		*ft_realloc_del(int *pile, int new_size);
int		*ft_realloc_add(int *pile, int new_size);
void	swap_a(t_stacks *stacks, int mute);
void	swap_b(t_stacks *stacks, int mute);
void	swap_all(t_stacks *stacks);
void	push_b(t_stacks *stacks);
void	push_a(t_stacks *stacks);
void	rotate_a(t_stacks *stacks, int mute);
void	rotate_b(t_stacks *stacks, int mute);
void	rot_all(t_stacks *stacks);
void	reverse_rotate_a(t_stacks *stacks, int mute);
void	reverse_rotate_b(t_stacks *stacks, int mute);
void	rev_rot_all(t_stacks *stacks);
void	sort_high(t_stacks *stacks);
void	sort_big_stack(t_stacks *stacks);
void	solve_5_or_less(t_stacks *stacks);
void	sort(int **a_cp, int size_a);
void	symplify(int **a_cp, int **a, int size_a);
void	del_a_bin(char **a_bin);
char	**a_conv_bin(int *a, int size_a, int size_max);
void	copy_int(int **dest, int **src, int size);
void	refresh_bin(t_stacks *stacks);
int		size_max(int *a, int size_a);
void	check_error_part1(char *argv[], int argc, int **a, int *size_a);
void	check_error_part2(int **a, int size_a);
int		*get_pile_string(char *nbs, int *size_a);
int		*get_pile(char *argv[], int *size_a, int argc);
void	set_stackp1(t_stacks *stacks, int **a, int **b, int *size_a);
void	set_stackp2(t_stacks *stacks, char ***a_bin,
			char ***b_bin, int *size_b);
void	pre_algo(int **a_cp, int **a, int size_a);
void	free_all(char **a_bin, char **b_bin, t_stacks *stacks);
#endif