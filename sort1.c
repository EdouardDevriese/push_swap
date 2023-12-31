/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdevries <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 08:23:47 by wdevries          #+#    #+#             */
/*   Updated: 2023/07/05 11:27:51 by warredevriese    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_threshold(t_stacks stacks)
{
	int	threshold;
	int	average;
	int	sum;
	int	i;

	average = 0;
	sum = 0;
	i = -1;
	while (++i < stacks.a->size)
		sum += stacks.a->array[i];
	average = sum / stacks.a->size;
	threshold = average - stacks.a->size / 5;
	return (threshold);
}

void	ft_sort_phase1(t_stacks *stacks)
{
	while (stacks->a->size > 3)
	{
		if (stacks->a->array[0] <= ft_threshold(*stacks)
			|| stacks->a->size <= 5)
			ft_exec_operation(stacks, PB);
		else
			ft_exec_operation(stacks, RA);
	}
	ft_sort_three(stacks);
}
