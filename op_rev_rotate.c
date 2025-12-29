/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rev_rotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaim-so <jpaim-so@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 19:21:25 by jpaim-so          #+#    #+#             */
/*   Updated: 2025/12/29 19:54:45 by jpaim-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_state *state, int print)
{
	t_stack	*a;
	int		tmp;
	int		i;

	a = &state->a;
	if (a->size < 2)
		return ;
	tmp = a->array[a->size - 1];
	i = a->size - 1;
	while (i > 0)
	{
		a->array[i] = a->array[i - 1];
		i--;
	}
	a->array[0] = tmp;
	if (print)
	{
		state->move_count++;
		write(1, "rra\n", 4);
	}
}

void	rrb(t_state *state, int print)
{
	t_stack	*b;
	int		tmp;
	int		i;

	b = &state->b;
	if (b->size < 2)
		return ;
	tmp = b->array[b->size - 1];
	i = b->size - 1;
	while (i > 0)
	{
		b->array[i] = b->array[i - 1];
		i--;
	}
	b->array[0] = tmp;
	if (print)
	{
		state->move_count++;
		write(1, "rrb\n", 4);
	}
}

void	rrr(t_state *state, int print)
{
	if (state->a.size < 2 && state->b.size < 2)
		return ;
	rra(state, 0);
	rrb(state, 0);
	if (print)
	{
		state->move_count++;
		write(1, "rrr\n", 4);
	}
}
