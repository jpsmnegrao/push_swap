/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaim-so <jpaim-so@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 20:07:40 by jpaim-so          #+#    #+#             */
/*   Updated: 2025/12/29 20:10:48 by jpaim-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_state *state)
{
	int	i;

	i = 0;
	while (i < state->a.size - 1)
	{
		if (state->a.array[i] > state->a.array[i + 1])
			return (0);
		i++;
	}
	return (1);
}
