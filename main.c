/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmoumen <zmoumen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 19:28:41 by zmoumen           #+#    #+#             */
/*   Updated: 2022/12/23 20:34:10 by zmoumen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"
#include <stdio.h>

void	test_print_stack(t_stack *stack)
{
	printf("\n stack a: ");
	for (int i = 0; stack->sa_size > i; i++)
		printf("%d\t", stack->stack_a[i]);
	printf("\n stack b: ");
	for (int i = 0; stack->sb_size > i; i++)
		printf("%d\t", stack->stack_b[i]);
	printf("\n");
}
// sort stack_a in a temp stack
// get the value in elems = sa_size / 2, store it in m_v
// if value in top of stack a is less than m_v, push it to b, if more, swap it
// after you move elems number of elements, sort the remaining stack a in same manner
// keep a count of how many times this action happened
// repeat untill there's two or less elements left in stack_a
//  on top of the stack of b, 
int	main(int ac, char **av)
{
	int		iter;
	t_stack	stack;

	stack = (t_stack){0};
	if (ac <= 1)
		return (0);
	iter = 0;
	if (gen_stacks(ac - 1, av + 1, &stack))
		return (1);
	
	return (0);
}
