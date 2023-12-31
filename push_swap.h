/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdevries <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 15:02:15 by wdevries          #+#    #+#             */
/*   Updated: 2023/11/08 10:47:36 by wdevries         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

//LIBRARIES
# include "libft/inc/libft.h"
# include <limits.h>
# include <stdbool.h>
# include <stdlib.h>

//OPERATION ID'S
# define SA 0
# define SB 1
# define SS 2
# define PA 3
# define PB 4
# define RA 5
# define RB 6
# define RR 7
# define RRA 8
# define RRB 9
# define RRR 10

//CASE ID'S
# define CASE1 0
# define CASE2 1
# define CASE3 2
# define CASE4 3

//TYPEDEFS
typedef struct s_sorting_params
{
	int		cost;
	int		case_number;
	int		from_pos;
	int		from_val;
	int		to_pos;
	int		to_val;
}			t_sorting_params;

typedef struct s_stack
{
	int		*array;
	int		size;
}			t_stack;

typedef struct s_stacks
{
	t_stack	*a;
	t_stack	*b;
}			t_stacks;

//FUNCTIONS
void		ft_error(int *int_array, char **args, size_t size);
void		ft_free_stacks(t_stacks *stacks);
void		ft_parse_args(t_stacks *stacks, size_t size, char **args);
void		ft_parse_string(t_stacks *stacks, char *argv);
int			ft_init_stacks(size_t size, int *int_array, t_stacks *stacks);
void		ft_sort(t_stacks *stacks);
void		ft_exec_operation(t_stacks *stacks, int operation);
void		ft_execute_case(t_stacks *stacks, t_sorting_params sp);
bool		ft_is_sorted(t_stacks *stacks);
void		ft_print_operation(int operation);
void		ft_sort_three(t_stacks *stacks);
void		ft_sort_phase1(t_stacks *stacks);
void		ft_sort_phase2(t_stacks *stacks);

#endif
