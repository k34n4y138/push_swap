/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmoumen <zmoumen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 19:28:41 by zmoumen           #+#    #+#             */
/*   Updated: 2023/02/16 18:34:50 by zmoumen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	subchunk_devider(int stacksize)
{
	if (stacksize > 250)
		return (6);
	else if (stacksize > 100)
		return (5);
	else if (stacksize > 60)
		return (3);
	return (2);
}

int	sort_stack(t_stack *stack)
{
	int	*tmps;

	tmps = ft_mergesortcpy(stack->stack_a, stack->sa_size);
	if (!tmps)
	{
		ft_putstr_fd("Error\n", 1);
		return (1);
	}
	if (ft_memcmp(tmps, stack->stack_a,
			stack->sa_size * sizeof(int)) == 0)
	{
		free(tmps);
		return (0);
	}
	while (stack->sa_size > 3)
		chunk_a_to_b(stack, tmps + stack->sb_size,
			stack->sa_size / subchunk_devider(stack->sa_size));
	if (stack->sa_size == 2)
		sort_two(stack);
	else if (stack->sa_size == 3)
		sort_three(stack);
	sort_b_to_a(stack, tmps);
	free(tmps);
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
		return (free_stack(&stack, 1));
	ret = sort_stack(&stack);
	free_stack(&stack, 0);
	return (ret);
}
