/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_management.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmoumen <zmoumen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 17:34:18 by zmoumen           #+#    #+#             */
/*   Updated: 2022/12/30 13:12:52 by zmoumen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_MANAGEMENT_H
# define STACK_MANAGEMENT_H
# include "libft/libft.h"

typedef struct pstack
{
	char	**rawstack;
	int		movescount;
	int		stacksize;
	int		sa_size;
	int		*stack_a;
	int		sb_size;
	int		*stack_b;
}				t_stack;

typedef struct tmpstack
{
	int		movescount;
	int		*stack;
	int		*chunksizes;	
}			t_tmpstack;

// sa sb ss
int	swap_a(t_stack *stack, int announce);
int	swap_b(t_stack *stack, int announce);
int	swap_stacks(t_stack *stack, int announce);

// pa pb
int	push_a(t_stack *stack, int announce);
int	push_b(t_stack *stack, int announce);

// ra rb rr
int	rotate_a(t_stack *stack, int announce);
int	rotate_b(t_stack *stack, int announce);
int	rotate_stacks(t_stack *stack, int announce);

// rra rrb rrr
int	reverse_rotate_a(t_stack *stack, int announce);
int	reverse_rotate_b(t_stack *stack, int announce);
int	reverse_rotate_stacks(t_stack *stack, int announce);

int	gen_stacks(int ac, char **av, t_stack *stack);
int	free_stack(t_stack	*stack, int is_error);
#endif