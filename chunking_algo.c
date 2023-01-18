/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunking_algo.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmoumen <zmoumen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 11:57:46 by zmoumen           #+#    #+#             */
/*   Updated: 2023/01/17 10:07:52 by zmoumen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algos.h"

static void	rotation_dir(t_stack *stack, int pivotval)
{
	int	i;
	int	topnum;
	int	bottomnum;

	topnum = 0;
	bottomnum = 0;
	i = 1;
	while (stack->sa_size <= 5 && i < (stack->sa_size - stack->sa_size / 6))
	{
		if (stack->stack_a[i] <= pivotval)
			topnum++;
		if (stack->stack_a[stack->sa_size - i] <= pivotval)
			bottomnum++;
		i++;
	}
	if (topnum - bottomnum < 0)
		reverse_rotate_a(stack, 1);
	else
		rotate_a(stack, 1);
}

static void	aux_push_a_to_b(t_stack *stack, int chunkmid, int pivotval)
{
	push_b(stack, 1);
	if (stack->stack_b[0] > chunkmid)
	{
		if (stack->stack_a[0] > pivotval)
			rotate_stacks(stack, 1);
		else
			rotate_b(stack, 1);
	}
	if (stack->sa_size > 5 && stack->stack_b[1] > stack->stack_b[0])
	{
		if (stack->stack_a[1] > stack->stack_a[0])
			swap_stacks(stack, 1);
		else
			swap_b(stack, 1);
	}
}

void	chunk_a_to_b(t_stack *stack, int *sorted, int chunksize)
{
	int	pivotval;
	int	chunkmid;

	pivotval = sorted[chunksize - 1];
	chunkmid = sorted[chunksize / 2];
	while (chunksize)
	{
		if (stack->stack_a[0] <= pivotval && chunksize--)
			aux_push_a_to_b(stack, chunkmid, pivotval);
		else
			rotation_dir(stack, pivotval);
	}
}
