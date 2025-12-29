/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaim-so <jpaim-so@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 19:21:01 by jpaim-so          #+#    #+#             */
/*   Updated: 2025/12/29 15:45:51 by jpaim-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_state *state, int print)
{
	t_stack	*a;
	t_stack	*b;
	int		tmp;
	int		i;

	a = &state->a;
	b = &state->b;
	i = 0;
	if (b->size == 0)
		return ;
	tmp = b->array[0];
	while (i < b->size - 1)
	{
		b->array[i] = b->array[i + 1];
		i++;
	}
	b->size--;
	i = a->size;
	while (i > 0)
	{
		a->array[i] = a->array[i - 1];
		i--;
	}
	a->array[0] = tmp;
	a->size++;
	if (print)
		write(1, "pa\n", 3);
}

void	pb(t_state *state, int print)
{
	t_stack	*a;
	t_stack	*b;
	int		tmp;
	int		i;

	a = &state->a;
	b = &state->b;
	i = 0;
	if (a->size == 0)
		return ;
	tmp = a->array[0];
	while (i < a->size - 1)
	{
		a->array[i] = a->array[i + 1];
		i++;
	}
	a->size--;
	i = b->size;
	while (i > 0)
	{
		b->array[i] = b->array[i - 1];
		i--;
	}
	b->array[0] = tmp;
	b->size++;
	if (print)
		write(1, "pb\n", 3);
}
