/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rev_rotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaim-so <jpaim-so@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 19:21:25 by jpaim-so          #+#    #+#             */
/*   Updated: 2025/12/29 18:12:17 by jpaim-so         ###   ########.fr       */
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
		write(1, "rra\n", 3);
	}
}

void	rrb(t_state *state, int print);
void	rrr(t_state *state, int print);