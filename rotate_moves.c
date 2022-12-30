/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_moves.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmoumen <zmoumen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 17:26:51 by zmoumen           #+#    #+#             */
/*   Updated: 2022/12/30 12:13:11 by zmoumen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack_management.h"

int	rotate_a(t_stack *stack, int announce)
{
	int	hold;

	if (stack->sa_size > 1)
	{
		hold = stack->stack_a[0];
		ft_memmove(stack->stack_a,
			stack->stack_a + 1, (stack->sa_size - 1) * sizeof(int));
		stack->stack_a[stack->sa_size - 1] = hold;
		if (announce)
			ft_putstr_fd("ra\n", 1);
		return (1);
	}
	return (0);
}

int	rotate_b(t_stack *stack, int announce)
{
	int	hold;

	if (stack->sb_size > 1)
	{
		hold = stack->stack_b[0];
		ft_memmove(stack->stack_b,
			stack->stack_b + 1, (stack->sb_size - 1) * sizeof(int));
		stack->stack_b[stack->sb_size - 1] = hold;
		if (announce)
			ft_putstr_fd("rb\n", 1);
		return (1);
	}
	return (0);
}

int	reverse_rotate_a(t_stack *stack, int announce)
{
	int	hold;

	if (stack->sa_size > 1)
	{
		hold = stack->stack_a[stack->sa_size - 1];
		ft_memmove(stack->stack_a + 1,
			stack->stack_a, (stack->sa_size - 1) * sizeof(int));
		stack->stack_a[0] = hold;
		if (announce)
			ft_putstr_fd("rra\n", 1);
		return (1);
	}
	return (0);
}

int	reverse_rotate_b(t_stack *stack, int announce)
{
	int	hold;

	if (stack->sb_size > 1)
	{
		hold = stack->stack_b[stack->sb_size - 1];
		ft_memmove(stack->stack_b + 1,
			stack->stack_b, (stack->sb_size - 1) * sizeof(int));
		stack->stack_b[0] = hold;
		if (announce)
			ft_putstr_fd("rrb\n", 1);
		return (1);
	}
	return (0);
}
