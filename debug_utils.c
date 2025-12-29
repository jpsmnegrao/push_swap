/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaim-so <jpaim-so@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 18:13:15 by jpaim-so          #+#    #+#             */
/*   Updated: 2025/12/29 19:17:27 by jpaim-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	ft_print_stacks(t_state *state)
{
	int		i;
	int		max_size;

	i = 0;
	if (!state || !state->a.array || !state->b.array)
		return ;
	max_size = state->a.size;
	if (state->b.size > max_size)
		max_size = state->b.size;
	printf("-- STACKS A | B --\nSIZE A: %d | SIZE B: %d\n-------------\n",
		state->a.size, state->b.size);
	while (i < max_size)
	{
		if (i < state->a.size)
			printf("%-10d", state->a.array[i]);
		else
			printf("%-10s", "");
		printf("|");
		if (i < state->b.size)
			printf("%-10d", state->b.array[i]);
		else
			printf("%-10s", "");
		printf("\n");
		i++;
	}
	printf("--------------\n\n");
	printf("MOVES COUNT: %d\n\n", state->move_count);
}
