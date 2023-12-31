/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdevries <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 15:41:20 by wdevries          #+#    #+#             */
/*   Updated: 2023/11/08 10:47:54 by wdevries         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

static bool	ft_numbers_ok(size_t size, char **args)
{
	long	num;
	int		sign;
	char	*ptr;

	while (size--)
	{
		num = 0;
		sign = 1;
		ptr = args[size];
		if (*ptr == '-')
		{
			sign = -1;
			ptr++;
		}
		while (*ptr)
		{
			num = num * 10 + (*ptr - '0');
			if (!ft_isdigit(*ptr) || sign * num > INT_MAX || sign
				* num < INT_MIN)
				return (false);
			ptr++;
		}
	}
	return (true);
}

static bool	ft_doubles_ok(size_t size, int *int_array)
{
	size_t	i;
	size_t	j;

	i = -1;
	while (++i < size)
	{
		j = i;
		while (++j < size)
			if (int_array[i] == int_array[j])
				return (false);
	}
	return (true);
}

static int	*ft_init_int_array(size_t size, char **args)
{
	int	*int_array;

	int_array = (int *)malloc(size * sizeof(int));
	if (!int_array)
		ft_error(NULL, args, size);
	while (size--)
		int_array[size] = ft_atoi(args[size]);
	return (int_array);
}

void	ft_parse_args(t_stacks *stacks, size_t size, char **args)
{
	int	*int_array;

	if (!ft_numbers_ok(size, args))
		ft_error(NULL, args, size);
	int_array = ft_init_int_array(size, args);
	if (!ft_doubles_ok(size, int_array))
		ft_error(int_array, args, size);
	if (!ft_init_stacks(size, int_array, stacks))
	{
		write(1, "System ", 7);
		ft_free_stacks(stacks);
		ft_error(int_array, args, size);
	}
}

void	ft_parse_string(t_stacks *stacks, char *argv)
{
	size_t	size;
	char	**args;

	size = ft_word_count(argv, ' ');
	if (size < 1 || size > 500)
		exit(0);
	args = ft_split(argv, ' ');
	ft_parse_args(stacks, size, args);
	ft_free_array(args, size);
}
