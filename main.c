/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmoumen <zmoumen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 19:28:41 by zmoumen           #+#    #+#             */
/*   Updated: 2022/12/31 17:46:19 by zmoumen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	sort_stack(t_stack *stack)
{
	int	*tmps;

	tmps = ft_mergesortcpy(stack->stack_a, stack->sa_size);
	if (!tmps && (1 || write(1, "Error\n", 7)))
		return (1);
	if (ft_memcmp(tmps, stack->stack_a,
			stack->sa_size * sizeof(int)) == 0)
		return (0);
	while (stack->sa_size > 3)
	{	
		if (stack->sa_size > 8)
			chunk_a_to_b(stack, tmps + stack->sb_size, stack->sa_size / 4);
		else
			chunk_a_to_b(stack, tmps + stack->sb_size, stack->sa_size / 2);
	}
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
		return (1);
	ret = sort_stack(&stack);
	free_stack(&stack, 0);
	return (ret);
}
