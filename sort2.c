/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdevries <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 10:57:40 by wdevries          #+#    #+#             */
/*   Updated: 2023/11/06 14:29:12 by wdevries         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_get_min_pos_val(t_stacks stacks, int *min_pos, int *min_val)
{
	int	pos_a;

	pos_a = -1;
	*min_pos = -1;
	*min_val = INT_MAX;
	while (++pos_a < stacks.a->size)
	{
		if (stacks.a->array[pos_a] < *min_val)
		{
			*min_pos = pos_a;
			*min_val = stacks.a->array[pos_a];
		}
	}
}

static void	ft_get_to_pos(int pos_b, t_stacks stacks, t_sorting_params *sp)
{
	int	pos_a;
	int	min_pos;
	int	min_val;

	ft_get_min_pos_val(stacks, &min_pos, &min_val);
	sp->to_pos = -1;
	sp->to_val = INT_MAX;
	pos_a = -1;
	while (++pos_a < stacks.a->size)
	{
		if (stacks.a->array[pos_a] > stacks.b->array[pos_b]
			&& stacks.a->array[pos_a] < sp->to_val)
		{
			sp->to_pos = pos_a;
			sp->to_val = stacks.a->array[pos_a];
		}
	}
	if (sp->to_pos == -1)
	{
		sp->to_pos = min_pos;
		sp->to_val = min_val;
	}
}

static void	ft_get_sorting_params(int pos_b, t_stacks stacks,
		t_sorting_params *sp)
{
	int	i;
	int	costs[4];

	sp->from_pos = pos_b;
	ft_get_to_pos(pos_b, stacks, sp);
	costs[CASE1] = ft_max((stacks.b->size - sp->from_pos), (stacks.a->size
				- sp->to_pos));
	costs[CASE2] = ft_max(sp->from_pos, sp->to_pos);
	costs[CASE3] = (stacks.b->size - sp->from_pos) + sp->to_pos;
	costs[CASE4] = sp->from_pos + (stacks.a->size - sp->to_pos);
	i = -1;
	sp->cost = INT_MAX;
	while (++i < 4)
	{
		if (costs[i] < sp->cost)
		{
			sp->from_val = stacks.b->array[pos_b];
			sp->cost = costs[i];
			sp->case_number = i;
		}
	}
}

static void	ft_get_next_to_sort(t_stacks stacks, t_sorting_params *sp)
{
	int					pos_b;
	t_sorting_params	temp;

	pos_b = 0;
	ft_get_sorting_params(pos_b, stacks, sp);
	while (++pos_b < stacks.b->size)
	{
		if (pos_b < sp->cost || pos_b > stacks.b->size - sp->cost)
		{
			ft_get_sorting_params(pos_b, stacks, &temp);
			if (temp.cost < sp->cost)
				*sp = temp;
		}
	}
}

void	ft_sort_phase2(t_stacks *stacks)
{
	t_sorting_params	sp;

	while (stacks->b->size)
	{
		ft_get_next_to_sort(*stacks, &sp);
		ft_execute_case(stacks, sp);
		ft_exec_operation(stacks, PA);
	}
}
