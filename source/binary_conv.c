/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   binary_conv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeshaye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 05:04:04 by pdeshaye          #+#    #+#             */
/*   Updated: 2021/12/10 05:05:40 by pdeshaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/header.h"

int	binary_size(int n)
{
	int	i;

	i = 0;
	while (n != 0)
	{
		n /= 2;
		i++;
	}
	return (i);
}

char	*rev_str(char *str)
{
	int		i;
	char	temp;

	i = 0;
	while (i < (int)ft_strlen(str) / 2)
	{
		temp = str[i];
		str[i] = str[ft_strlen(str) - i - 1];
		str[ft_strlen(str) - i - 1] = temp;
		i++;
	}
	return (str);
}

char	*binary_convert(int n, int size_max)
{
	char	*bin;
	int		i;

	i = 0;
	bin = malloc(binary_size(n) * sizeof(char) + 1);
	if (bin == NULL)
		exit(-1);
	while (n != 0)
	{
		bin[i] = (n % 2) + '0';
		n = n / 2;
		i++;
	}
	bin[i] = '\0';
	while ((int)ft_strlen(bin) < size_max)
		bin = ft_strjoin(bin, "0");
	return (rev_str(bin));
}

int	size_max(int *a, int size_a)
{
	int	i;
	int	size_max_pile;

	size_max_pile = 0;
	i = 0;
	while (i < size_a)
	{
		if (size_max_pile < binary_size(a[i]))
			size_max_pile = binary_size(a[i]);
		i++;
	}
	return (size_max_pile);
}

char	**a_conv_bin(int *a, int size_a, int size_max)
{
	char	**a_bin;
	int		i;

	i = 0;
	a_bin = malloc(sizeof(char *) * (size_a) + 1);
	if (a_bin == NULL)
		exit(-1);
	while (i < size_a)
	{
		a_bin[i] = binary_convert(a[i], size_max);
		i++;
	}
	a_bin[i] = NULL;
	return (a_bin);
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
