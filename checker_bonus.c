/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmoumen <zmoumen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 18:05:08 by zmoumen           #+#    #+#             */
/*   Updated: 2022/12/31 20:20:05 by zmoumen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack_management.h"

int	apply_instruction(t_stack *stack, char *instruction)
{
	if (!ft_strncmp(instruction, "sa\n", 3))
		swap_a(stack, 0);
	else if (!ft_strncmp(instruction, "sb\n", 3))
		swap_b(stack, 0);
	else if (!ft_strncmp(instruction, "ss\n", 3))
		swap_stacks(stack, 0);
	else if (!ft_strncmp(instruction, "pa\n", 3))
		push_a(stack, 0);
	else if (!ft_strncmp(instruction, "pb\n", 3))
		push_b(stack, 0);
	else if (!ft_strncmp(instruction, "ra\n", 3))
		rotate_a(stack, 0);
	else if (!ft_strncmp(instruction, "rb\n", 3))
		rotate_b(stack, 0);
	else if (!ft_strncmp(instruction, "rr\n", 3))
		rotate_stacks(stack, 0);
	else if (!ft_strncmp(instruction, "rra\n", 4))
		reverse_rotate_a(stack, 0);
	else if (!ft_strncmp(instruction, "rrb\n", 4))
		reverse_rotate_b(stack, 0);
	else if (!ft_strncmp(instruction, "rrr\n", 4))
		reverse_rotate_stacks(stack, 0);
	else
		return (0);
	return (1);
}

int	check_sorting(t_stack *stack)
{
	char	*instruction;
	int		*expect;
	int		not_sorted;

	not_sorted = 0;
	instruction = get_next_line(0);
	expect = ft_mergesortcpy(stack->stack_a, stack->sa_size);
	if (!expect)
		return (-2);
	while (instruction && !not_sorted)
	{
		if (!apply_instruction(stack, instruction))
			not_sorted = -2;
		free(instruction);
		if (!not_sorted)
			instruction = get_next_line(0);
	}
	if (stack->sb_size)
		not_sorted = -1;
	if (not_sorted == 0 && ft_memcmp(expect, stack->stack_a, stack->stacksize))
		not_sorted = -1;
	free(expect);
	return (not_sorted);
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
	ret = check_sorting(&stack);
	free_stack(&stack, 0);
	if (ret == 0)
		ft_putstr_fd("OK\n", 1);
	else if (ret == -1)
		ft_putstr_fd("KO\n", 1);
	else
		ft_putstr_fd("Error\n", 1);
	return (ret);
}
