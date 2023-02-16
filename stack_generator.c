/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_generator.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmoumen <zmoumen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 17:46:47 by zmoumen           #+#    #+#             */
/*   Updated: 2023/02/16 18:35:28 by zmoumen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack_management.h"

int	free_stack(t_stack	*stack, int is_error)
{
	int	i;

	i = 0;
	if (stack->rawstack)
	{
		while (stack->rawstack[i])
			free(stack->rawstack[i++]);
		free(stack->rawstack);
	}
	if (stack->stack_b)
		free(stack->stack_a);
	if (stack->stack_a)
		free(stack->stack_b);
	if (is_error)
		ft_putstr_fd("Error\n", 1);
	return (1);
}

int	gen_stacks(int ac, char **av, t_stack *stack)
{
	char	*hldr;

	if (rawargs_validation(ac, av) < 1)
		return (1);
	hldr = ft_strnjoin(ac, av, " ");
	if (!hldr)
		return (1);
	stack->rawstack = ft_split(hldr, ' ');
	free(hldr);
	stack->stacksize = 0;
	while (stack->rawstack[stack->stacksize])
		stack->stacksize++;
	if (stack->stacksize == 0)
		return (1);
	stack->stack_a = ft_calloc(stack->stacksize, sizeof(int));
	stack->stack_b = ft_calloc(stack->stacksize, sizeof(int));
	while (stack->sa_size < stack->stacksize)
	{
		if (!str_isvalidnum(stack->rawstack[stack->sa_size], stack))
			return (1);
		stack->stack_a[stack->sa_size]
			= ft_atoi(stack->rawstack[stack->sa_size]);
		stack->sa_size++;
	}
	return (0);
}
