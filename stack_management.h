/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_management.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmoumen <zmoumen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 17:34:18 by zmoumen           #+#    #+#             */
/*   Updated: 2022/12/23 18:30:06 by zmoumen          ###   ########.fr       */
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
	char	*stack_a;
	int		sb_size;
	char	*stack_b;
}				t_stack;

// sa sb ss
int	swap_a(t_stack *stack, int announce);
int	swap_b(t_stack *stack, int announce);
int	swap_stacks(t_stack *stack);

// pa pb
int	push_a(t_stack *stack);
int	push_b(t_stack *stack);

// ra rb rr
int	rotate_a(t_stack *stack, int announce);
int	rotate_b(t_stack *stack, int announce);
int	rotate_stacks(t_stack *stack);

// rra rrb rrr
int	reverse_rotate_a(t_stack *stack, int announce);
int	reverse_rotate_b(t_stack *stack, int announce);
int	reverse_rotate_stacks(t_stack *stack);


int	gen_stacks(int ac, char **av, t_stack *stack);
#endif