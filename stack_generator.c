/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_generator.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmoumen <zmoumen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 17:46:47 by zmoumen           #+#    #+#             */
/*   Updated: 2022/12/25 20:31:37 by zmoumen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack_management.h"

static int	calc_intlen(int n)
{
	int	size;

	size = 0;

	while (n / 10 > 0)
	{
		size++;
		n /= 10;
	}
	return (size + 1);
}

static int	isalldigit(char *str)
{
	while (*str)
		if (!ft_isdigit(*str++))
			return (0);
	return (1);
}

static int	str_isvalidnum(char *str, t_stack *stack)
{
	int	len;
	int	val;
	int	iter;

	val = 1;

	if (*str == '-' && str++)
		val = -1;
	len = ft_strlen(str);
	val *= ft_atoi(str);
	if (len == 0
		|| !isalldigit(str)
		|| (len > 1 && len != calc_intlen(val)))
		return (0);
	iter = 0;
	while (iter < stack->sa_size)
		if (stack->stack_a[iter++] == val)
			return (0);
	return (1);
}

static int	return_with_error(t_stack	*pushstack)
{
	free(pushstack->rawstack);
	free(pushstack->stack_a);
	free(pushstack->stack_b);
	ft_putstr_fd("Error", 1);
	return (1);
}

int	gen_stacks(int ac, char **av, t_stack *stack)
{
	char	*hldr;

	hldr = ft_strnjoin(ac, av, " ");
	if (!hldr)
		return (1);
	stack->rawstack = ft_split(hldr, ' ');
	free(hldr);
	stack->stacksize = 0;
	while (stack->rawstack[stack->stacksize])
		stack->stacksize++;
	stack->stack_a = ft_calloc(stack->stacksize, sizeof(int));
	stack->stack_b = ft_calloc(stack->stacksize, sizeof(int));
	while (stack->sa_size < stack->stacksize)
	{
		if (!str_isvalidnum(stack->rawstack[stack->sa_size], stack))
			return (return_with_error(stack));
		stack->stack_a[stack->sa_size]
			= ft_atoi(stack->rawstack[stack->sa_size]);
		stack->sa_size++;
	}
	return (0);
}
