/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_validators.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmoumen <zmoumen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 18:22:41 by zmoumen           #+#    #+#             */
/*   Updated: 2023/02/16 18:29:20 by zmoumen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack_management.h"

static int	calc_intlen(int n)
{
	int	size;

	size = 0;
	if (n < 0)
		size++;
	while (n / 10 != 0)
	{
		n /= 10;
		size++;
	}
	return (size + 1);
}

static int	isalldigit(char *str)
{
	if (*str == '-' || *str == '+')
		str++;
	while (*str)
		if (!ft_isdigit(*str++))
			return (0);
	return (1);
}

static int	predict_atoilen(char *s)
{
	int	len;

	len = 0;
	if (*s == '+')
		s++;
	else if (*s == '-' && s++)
		len++;
	while (*s == '0' && *(s + 1) != '\0')
		s++;
	if (*s == '0' && *(s + 1) == '\0')
		return (1);
	while (*s && ft_isdigit(*(s++)))
		len++;
	return (len);
}

int	str_isvalidnum(char *str, t_stack *stack)
{
	int	len;
	int	val;
	int	iter;

	len = predict_atoilen(str);
	val = ft_atoi(str);
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

int	rawargs_validation(int ac, char **av)
{
	int		ret;
	char	*s;

	ret = 0;
	while (ac-- > 0)
	{
		ret = 0;
		s = av[ac];
		while (*s)
		{
			if (!ft_strchr(" +-0123456789",*s))
				return (-1);
			if (ft_strchr("0123456789",*s))
				ret++;
			s++;
		}
		if (ret <= 0)
			return (0);
	}
	return (1);
}
