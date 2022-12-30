/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_algo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmoumen <zmoumen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 11:33:30 by zmoumen           #+#    #+#             */
/*   Updated: 2022/12/30 17:48:15 by zmoumen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algos.h"

void	sort_two(t_stack *stack)
{
	if (stack->stack_a[0] > stack->stack_a[1])
		swap_a(stack, 1);
}

void	sort_three(t_stack *stack)
{
	int	*stk;

	stk = stack->stack_a;
	if (stk[1] > stk[0] && stk[1] > stk[2])
		reverse_rotate_a(stack, 1);
	if (stk[1] > stk[0] && stk[1] > stk[2])
		swap_a(stack, 1);
	if (stk[0] > stk[1] && stk[0] > stk[2])
		rotate_a(stack, 1);
	sort_two(stack);
}

static int	stack_maxidx(int *stack, int stacksize, int *target_val)
{
	int	i;	
	int	max_idx;

	i = 0;
	max_idx = 0;
	*target_val = stack[0];
	while (++i < stacksize)
	{
		if (stack[max_idx] < stack[i])
		{
			max_idx = i;
			*target_val = stack[i];
		}
	}
	return (max_idx);
}

static int	is_second_val(int *sorted, int maxval, int compval)
{
	int	i;

	i = 0;
	while (sorted[i] < maxval)
	{
		if (sorted[i + 1] == maxval)
			return (sorted[i] == compval);
		i++;
	}
	return (0);
}

int	sort_b_to_a(t_stack *stack, int *sorted)
{
	int	tg_dx;
	int	tg_val;

	while (stack->sb_size)
	{
		tg_dx = stack_maxidx(stack->stack_b, stack->sb_size, &tg_val);
		if (tg_dx == 0 || is_second_val(sorted, tg_val, stack->stack_b[0]))
		{
			push_a(stack, 1);
			if (stack->stack_a[0] > stack->stack_a[1])
			{
				if (stack->stack_b[0] < stack->stack_b[1])
					swap_stacks(stack, 1);
				else
					swap_a(stack, 1);
			}
		}
		else if (tg_dx == 1)
			swap_b(stack, 1);
		else if (tg_dx >= stack->sb_size / 2)
			reverse_rotate_b(stack, 1);
		else
			rotate_b(stack, 1);
	}
	return (0);
}
