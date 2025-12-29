/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaim-so <jpaim-so@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 20:05:35 by jpaim-so          #+#    #+#             */
/*   Updated: 2025/12/29 20:20:42 by jpaim-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_state *state)
{
	int	a;
	int	b;
	int	c;

	if (is_sorted(state))
		return ;
	a = state->a.array[0];
	b = state->a.array[1];
	c = state->a.array[2];
	if (a > b && a > c)
	{
		ra(state, 1);
		if (!is_sorted(state))
			sa(state, 1);
	}
	else if (b > a && b > c)
	{
		rra(state, 1);
		if (!is_sorted(state))
			sa(state, 1);
	}
	else
		sa(state, 1);
}
