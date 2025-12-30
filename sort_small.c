/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaim-so <jpaim-so@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 20:05:35 by jpaim-so          #+#    #+#             */
/*   Updated: 2025/12/30 17:54:30 by jpaim-so         ###   ########.fr       */
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

void	sort_five(t_state *state)
{
	int	min_idx;

	while (state->a.size > 3)
	{
		min_idx = is_min_index(state);
		while (min_idx != 0)
		{
			if (min_idx <= state->a.size / 2)
				ra(state, 1);
			else
				rra(state, 1);
			min_idx = is_min_index(state);
		}
		pb(state, 1);
	}
	sort_three(state);
	while (state->b.size > 0)
		pa(state, 1);
}
