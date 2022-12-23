/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmoumen <zmoumen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 22:14:35 by zmoumen           #+#    #+#             */
/*   Updated: 2022/12/23 12:18:36 by zmoumen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_ttlsz(int size, char **strs, char *sep)
{
	int	res;

	res = 0;
	res += (size - 1) * ft_strlen(sep);
	while (--size >= 0)
		res += ft_strlen(strs[size]);
	return (res);
}

char	*ft_strnjoin(int size, char **strs, char *sep)
{
	int		*v;
	char	*p;

	v = (int []){0, 0, 0};
	p = (char *)malloc(sizeof(char [1 + get_ttlsz(size, strs, sep)]));
	if (!p)
		return (NULL);
	while (v[0] < size)
	{
		v[1] = 0;
		while (strs[v[0]][v[1]])
			p[v[2]++] = strs[v[0]][v[1]++];
		v[1] = 0;
		if (v[0] < size - 1)
			while (sep[v[1]])
				p[v[2]++] = sep[v[1]++];
		v[0]++;
	}
	p[v[2]] = '\0';
	return (p);
}
