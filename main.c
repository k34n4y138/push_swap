/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmoumen <zmoumen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 19:28:41 by zmoumen           #+#    #+#             */
/*   Updated: 2022/12/25 20:17:17 by zmoumen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"
#include <stdio.h>

void	test_print_stack(t_stack *stack)
{
	printf("\n stack a(%d): ", stack->sa_size);
	for (int i = 0; stack->sa_size > i; i++)
		printf("%d\t", stack->stack_a[i]);
	printf("\n stack b(%d): ", stack->sb_size);
	for (int i = 0; stack->sb_size > i; i++)
		printf("%d\t", stack->stack_b[i]);
	printf("\n");
}

void	sort_two(t_stack *stack)
{
	if (stack->stack_a[0] > stack->stack_a[1])
		swap_a(stack, 1);
}

void	sort_three(t_stack *stack)
{
	int	*stk;

	stk = stack->stack_a;
	if (stk[1] > stk[0] && stk[1] > stk[2])
		reverse_rotate_a(stack, 1); 
	if (stk[1] > stk[0] && stk[1] > stk[2])
		swap_a(stack, 1);
	if (stk[0] > stk[1] && stk[0] > stk[2])
		rotate_a(stack, 1);
	sort_two(stack);
}

int	*ft_substack(int	*stack, int start, int end)
{
	int	*cpy;

	cpy = ft_calloc(end - start, sizeof(int));
	if (!cpy)
		return (NULL);
	ft_memmove(cpy, stack + start, (end - start) * sizeof(int));
	return (cpy);
}
int	ft_mergesort(int *stack, int size);

int	sort_substacks(int *stack, int **left, int **right, int *idx)
{
	*left = ft_substack(stack, 0, idx[3]);
	if (!*left)
		return (-1);
	*right = ft_substack(stack, idx[3], idx[5]);
	if (!*right)
	{
		free(*left);
		return (-1);
	}
	if (ft_mergesort(*left, idx[3]) == -1
		|| ft_mergesort(*right, idx[4]) == -1)
	{
		free(left);
		free(right);
		return (-1);
	}	
	return (0);
}

int	ft_mergesort(int *stack, int size)
{
	int	*left;
	int	*right;
	int	*idx;

	if (size < 2)
		return (0);
	idx = (int []){0, 0, 0, (size / 2), size - (size / 2), size};
	if (sort_substacks(stack, &left, &right, idx) == -1)
		return (-1);
	while (idx[0] < idx[3] && idx[1] < idx[4])
	{
		if (left[idx[0]] < right[idx[1]])
			stack[idx[2]++] = left[idx[0]++];
		else
			stack[idx[2]++] = right[idx[1]++];
	}
	while (idx[0] < idx[3])
		stack[idx[2]++] = left[idx[0]++];
	while (idx[1] < idx[4])
		stack[idx[2]++] = right[idx[1]++];
	free(left);
	free(right);
	return (0);
}

void move_to_b(t_stack *stack, int pivot_val, int len)
{
	while (len--)
	{
		while (1)
		{
			if (stack->stack_a[0] < pivot_val && push_b(stack))
				break ;
			else
				rotate_a(stack, 1);
		}
	}
}

int	sort_stack(t_stack *stack)
{
	int	*tmpstack;
	int	pivot_val;

	tmpstack = ft_calloc(stack->sa_size, sizeof(int));
	while (stack->sa_size > 3)
	{
		printf("LONG !!\n");
		ft_memmove(tmpstack, stack->stack_a, stack->sa_size * sizeof(int));
		if (ft_mergesort(tmpstack, stack->sa_size) == -1)
			return (-1);
		pivot_val = tmpstack[stack->sa_size / 2];
		printf("pivot is :%d\n",pivot_val);
		move_to_b(stack, pivot_val, stack->sa_size / 2);
		stack->movescount++;
	}
	if (stack->sa_size == 3)
		sort_three(stack);
	else
		sort_two(stack);
	while (stack->movescount--)
	{
		
	}
	return (0);
}


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
	sort_stack(&stack);
	test_print_stack(&stack);
	return (0);
}