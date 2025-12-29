/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaim-so <jpaim-so@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 19:20:49 by jpaim-so          #+#    #+#             */
/*   Updated: 2025/12/29 14:05:33 by jpaim-so         ###   ########.fr       */
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
	else
	{
		tmp = a->array[0];
		a->array[0] = a->array[1];
		a->array[1] = tmp;
		state->move_count++;
	}
	if (print)
		write(1, "sa\n", 3);
}

void	sb(t_state *state, int print)
{
	t_stack	*b;
	int		tmp;

	b = &state->b;
	if (b->size < 2)
		return ;
	else
	{
		tmp = b->array[0];
		b->array[0] = b->array[1];
		b->array[1] = tmp;
		state->move_count++;
	}
	if (print)
		write(1, "sb\n", 3);
}

void	ss(t_state *state, int print)
{
	t_stack	*a;
	t_stack	*b;
	int		tmpa;
	int		tmpb;

	a = &state->a;
	b = &state->b;
	if (a->size < 2 || b->size < 2)
		return ;
	else
	{
		tmpa = a->array[0];
		tmpb = b->array[0];
		a->array[0] = a->array[1];
		b->array[0] = b->array[1];
		a->array[1] = tmpa;
		b->array[1] = tmpb;
		state->move_count++;
	}
	if (print)
		write(1, "ss\n", 3);
}
