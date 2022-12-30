/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmoumen <zmoumen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 19:28:41 by zmoumen           #+#    #+#             */
/*   Updated: 2022/12/30 19:03:40 by zmoumen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	sort_stack(t_stack *stack)
{
	t_stack	tmps;

	ft_bzero(&tmps, sizeof(t_stack));
	tmps.stack_a = ft_mergesortcpy(stack->stack_a, stack->sa_size);
	tmps.stack_b = ft_mergesortcpy(stack->stack_a, stack->sa_size);
	if (!tmps.stack_a || !tmps.stack_b)
		return (free_stack(&tmps, 1));
	if (ft_memcmp(tmps.stack_a, stack->stack_a,
			stack->sa_size * sizeof(int)) == 0)
		return (0);
	while (stack->sa_size > 3)
	{	
		if (stack->sa_size > 8)
			chunk_a_to_b(stack, tmps.stack_a, stack->sa_size / 4);
		else
			chunk_a_to_b(stack, tmps.stack_a, stack->sa_size / 2);
		ft_memmove(tmps.stack_a, stack->stack_a, stack->sa_size * sizeof(int));
		ft_mergesort(tmps.stack_a, stack->sa_size);
	}
	sort_three(stack);
	sort_b_to_a(stack, tmps.stack_b);
	free_stack(&tmps, 0);
	return (0);
}

int	main(int ac, char **av)
{
	int		ret;
	t_stack	stack;

	ft_bzero(&stack, sizeof(t_stack));
	if (ac == 1)
		return (0);
	if (gen_stacks(ac - 1, av + 1, &stack))
		return (1);
	ret = sort_stack(&stack);
	free_stack(&stack, 0);
	return (ret);
}
