/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaim-so <jpaim-so@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 20:47:32 by jpaim-so          #+#    #+#             */
/*   Updated: 2025/12/29 19:10:51 by jpaim-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_check_sign(const char *str, int *i, int *symb)
{
	if (str[*i] == '+' || str[*i] == '-')
	{
		if (str[*i] == '-')
			*symb = -1;
		(*i)++;
	}
}

static int	ft_check_overflow(long long result, int next_digit, int sign)
{
	long long	num;

	num = result * 10 + next_digit;
	if (sign == 1 && num > INT_MAX)
		return (1);
	if (sign == -1 && num > (long long)INT_MAX + 1)
		return (1);
	return (0);
}

int	ft_atoi(const char *str, int *error)
{
	int				i;
	int				symb;
	long long int	result;

	i = 0;
	symb = 1;
	result = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	ft_check_sign(str, &i, &symb);
	if (!ft_isdigit(str[i]))
		return (*error = 1, 0);
	while (ft_isdigit(str[i]))
	{
		if (ft_check_overflow(result, str[i] - '0', symb))
			return (*error = 1, 0);
		result = result * 10 + (str[i++] - '0');
	}
	if (str[i] != '\0')
		return (*error = 1, 0);
	return (symb * result);
}
