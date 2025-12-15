/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaim-so <jpaim-so@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 22:30:58 by jpaim-so          #+#    #+#             */
/*   Updated: 2025/12/15 22:54:18 by jpaim-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_parse_input(int argc, char *argv[], t_stack *a, t_stack *b)
{
	int		i;
	int		value;
	char	**list;

	i = 1;
	if (argc == 2)
	{
		list = ft_split(argv[1], ' ');
		if (!list)
			ft_error();
		i = 0;
		while (list[i])
		{
			value = ft_atoi(list[i]);
			a->array[i] = value;
			i++;
		}
		a->size = i;
		ft_free_split(list);
	}
	else if (argc > 2)
	{
		i = 1;
		while (i < argc)
		{
			value = ft_atoi(argv[1]);
			a->array[i - 1] = value;
			i++;
		}
		a->size = argc - 1;
	}
	if (ft_checkduplicates(a->array, a->size))
		ft_error();
	b->size = 0;
	return (1);
}
