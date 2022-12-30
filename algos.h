/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algos.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmoumen <zmoumen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 11:32:05 by zmoumen           #+#    #+#             */
/*   Updated: 2022/12/30 17:48:10 by zmoumen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALGOS_H
# define ALGOS_H
# include "stack_management.h"

void	chunk_a_to_b(t_stack *stack, int *sorted, int chunksize);
int		sort_b_to_a(t_stack *stack, int *sorted);
void	sort_two(t_stack *stack);
void	sort_three(t_stack *stack);
#endif