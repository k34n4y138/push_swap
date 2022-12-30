/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_moves.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmoumen <zmoumen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 13:22:46 by zmoumen           #+#    #+#             */
/*   Updated: 2022/12/30 13:09:57 by zmoumen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack_management.h"

int	push_a(t_stack *stack, int announce)
{
	if (stack->sb_size)
	{
		ft_memmove(stack->stack_a + 1,
			stack->stack_a, (stack->sa_size++) * sizeof(int));
		stack->stack_a[0] = stack->stack_b[0];
		ft_memmove(stack->stack_b,
			stack->stack_b + 1, --(stack->sb_size) * sizeof(int));
		if (announce)
			ft_putstr_fd("pa\n", 1);
		return (1);
	}
	return (0);
}

int	push_b(t_stack *stack, int announce)
{
	if (stack->sa_size)
	{
		ft_memmove(stack->stack_b + 1,
			stack->stack_b, (stack->sb_size++) * sizeof(int));
		stack->stack_b[0] = stack->stack_a[0];
		ft_memmove(stack->stack_a,
			stack->stack_a + 1, --(stack->sa_size) * sizeof(int));
		if (announce)
			ft_putstr_fd("pb\n", 1);
		return (1);
	}
	return (0);
}

int	swap_a(t_stack *stack, int announce)
{
	int	hold;

	if (stack->sa_size > 1)
	{
		hold = stack->stack_a[0];
		stack->stack_a[0] = stack->stack_a[1];
		stack->stack_a[1] = hold;
		if (announce)
			ft_putstr_fd("sa\n", 1);
		return (1);
	}
	return (0);
}

int	swap_b(t_stack *stack, int announce)
{
	int	hold;

	if (stack->sb_size > 1)
	{
		hold = stack->stack_b[0];
		stack->stack_b[0] = stack->stack_b[1];
		stack->stack_b[1] = hold;
		if (announce)
			ft_putstr_fd("sb\n", 1);
		return (1);
	}
	return (0);
}
