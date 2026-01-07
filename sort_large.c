/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_large.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaim-so <jpaim-so@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/30 17:53:38 by jpaim-so          #+#    #+#             */
/*   Updated: 2026/01/07 20:44:53 by jpaim-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_chunk_size(int n)
{
	if (n <= 50)
		return (8);
	if (n <= 100)
		return (16);
	if (n <= 500)
		return (32);
	return (45);
}

void	push_to_b(t_state *state)
{
	int	i;
	int	range;

	range = get_chunk_size(state->total_size);
	i = 0;
	while (state->a.size > 0)
	{
		if (state->a.array[0] < i)
		{
			pb(state, 1);
			if (state->a.size > 1
				&& state->a.array[0] > (i + range))
				rr(state, 1);
			else
				rb(state, 1);
			i++;
		}
		else if (state->a.array[0] <= i + range)
		{
			pb(state, 1);
			i++;
		}
		else
			ra(state, 1);
	}
}

void	push_to_a(t_state *state)
{
	int	pos;

	pos = get_max_pos(&state->b);
	while (state->b.size > 0)
	{
		if (pos == 0)
			pa(state, 1);
		else if (pos <= state->b.size / 2)
			rb(state, 1);
		else
			rrb(state, 1);
		pos = get_max_pos(&state->b);
	}
}

int	get_max_pos(t_stack *b)
{
	int	i;
	int	max_idx;

	if (b->size == 0)
		return (-1);
	i = 1;
	max_idx = 0;
	while (i < b->size)
	{
		if (b->array[i] > b->array[max_idx])
			max_idx = i;
		i++;
	}
	return (max_idx);
}

void	sort_large(t_state *state)
{
	push_to_b(state);
	push_to_a(state);
}
