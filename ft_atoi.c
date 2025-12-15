/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaim-so <jpaim-so@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 20:47:32 by jpaim-so          #+#    #+#             */
/*   Updated: 2025/12/15 21:45:52 by jpaim-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	symb;
	int	result;

	i = 0;
	symb = 1;
	result = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '+' || str[i] == '-')
		if (str[i++] == '-')
			symb = -1;
	if (!ft_isdigit(str[i]))
		return (0);
	while (ft_isdigit(str[i]))
	{
		if (result > (INT_MAX - (str[i] - '0')) / 10)
			return (0);
		result = result * 10 + (str[i++] - '0');
	}
	if (str[i] == '\0')
		return (0);
	if (symb == -1 && result == 2147483648)
		return (-2147483648);
	return (symb * result);
}
