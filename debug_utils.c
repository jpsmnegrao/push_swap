/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaim-so <jpaim-so@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 18:13:15 by jpaim-so          #+#    #+#             */
/*   Updated: 2025/12/16 18:22:04 by jpaim-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	ft_print_stacks(t_stack *a, t_stack *b)
{
	int	i;
	int	max_size;

	i = 0;
	if (a->size > b->size)
		max_size = a->size;
	else
		max_size = b->size;
	printf("\n-- STACKS A | B --\nSIZE A: %d | SIZE B: %d\n-------------\n",
		a->size, b->size);
	while (i < max_size)
	{
		if (i < a->size)
			printf("%-10d", a->array[i]);
		else
			printf("%-10s", "");
		printf("|");
		if (i < b->size)
			printf("%-10d", b->array[i]);
		else
			printf("%-10s", "");
		printf("\n");
		i++;
	}
	printf("-------------------\n\n");
}
