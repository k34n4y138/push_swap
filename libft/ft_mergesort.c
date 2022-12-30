/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mergesort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmoumen <zmoumen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 19:05:59 by zmoumen           #+#    #+#             */
/*   Updated: 2022/12/30 13:27:22 by zmoumen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	*ft_substack(int	*stack, int start, int end)
{
	int	*cpy;

	cpy = ft_calloc(end - start, sizeof(int));
	if (!cpy)
		return (NULL);
	ft_memmove(cpy, stack + start, (end - start) * sizeof(int));
	return (cpy);
}

static int	sort_substacks(int *stack, int **left, int **right, int *idx)
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
