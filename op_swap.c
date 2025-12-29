/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaim-so <jpaim-so@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 19:20:49 by jpaim-so          #+#    #+#             */
/*   Updated: 2025/12/29 17:37:50 by jpaim-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_state *state, int print)
{
	t_stack	*a;
	int		tmp;

	a = &state->a;
	if (a->size < 2)
		return ;
	tmp = a->array[0];
	a->array[0] = a->array[1];
	a->array[1] = tmp;
	if (print)
	{
		state->move_count++;
		write(1, "sa\n", 3);
	}
}

void	sb(t_state *state, int print)
{
	t_stack	*b;
	int		tmp;

	b = &state->b;
	if (b->size < 2)
		return ;
	tmp = b->array[0];
	b->array[0] = b->array[1];
	b->array[1] = tmp;
	if (print)
	{
		state->move_count++;
		write(1, "sb\n", 3);
	}
}

void	ss(t_state *state, int print)
{
	if (state->a.size < 2 && state->b.size < 2)
		return ;
	sa(state, 0);
	sb(state, 0);
	if (print)
	{
		state->move_count++;
		write(1, "ss\n", 3);
	}
}
