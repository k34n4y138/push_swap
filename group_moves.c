/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   group_moves.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmoumen <zmoumen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 17:33:33 by zmoumen           #+#    #+#             */
/*   Updated: 2022/12/30 13:11:06 by zmoumen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack_management.h"

int	swap_stacks(t_stack *stack, int announce)
{
	int	ret;

	ret = swap_a(stack, 0) | swap_b(stack, 0);
	if (ret && announce)
		ft_putstr_fd("ss\n", 1);
	return (ret);
}

int	rotate_stacks(t_stack *stack, int announce)
{
	int	ret;

	ret = rotate_a(stack, 0) | rotate_b(stack, 0);
	if (ret && announce)
		ft_putstr_fd("rr\n", 1);
	return (ret);
}

int	reverse_rotate_stacks(t_stack *stack, int announce)
{
	int	ret;

	ret = reverse_rotate_a(stack, 0) | reverse_rotate_b(stack, 0);
	if (ret && announce)
		ft_putstr_fd("rrr\n", 1);
	return (ret);
}
