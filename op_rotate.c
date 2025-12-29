/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaim-so <jpaim-so@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 19:21:14 by jpaim-so          #+#    #+#             */
/*   Updated: 2025/12/29 18:11:50 by jpaim-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_state *state, int print)
{
	t_stack	*a;
	int		tmp;
	int		i;

	a = &state->a;
	if (a->size < 2)
		return ;
	tmp = a->array[0];
	i = 0;
	while (i < a->size - 1)
	{
		a->array[i] = a->array[i + 1];
		i++;
	}
	a->array[a->size - 1] = tmp;
	if (print)
	{
		state->move_count++;
		write(1, "ra\n", 3);
	}
}

void	rb(t_state *state, int print)
{
	t_stack	*b;
	int		tmp;
	int		i;

	b = &state->b;
	if (b->size < 2)
		return ;
	tmp = b->array[0];
	i = 0;
	while (i < b->size - 1)
	{
		b->array[i] = b->array[i + 1];
		i++;
	}
	b->array[b->size - 1] = tmp;
	if (print)
	{
		state->move_count++;
		write(1, "rb\n", 3);
	}
}

void	rr(t_state *state, int print)
{
	if (state->a.size < 2 && state->b.size < 2)
		return ;
	ra(state, 0);
	rb(state, 0);
	if (print)
	{
		state->move_count++;
		write(1, "rr\n", 3);
	}
}
