/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaim-so <jpaim-so@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 15:18:16 by jpaim-so          #+#    #+#             */
/*   Updated: 2025/12/29 19:54:15 by jpaim-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_state	state;

	state.a.array = NULL;
	state.b.array = NULL;
	if (ft_parse_input(argc, argv, &state) == 0)
	{
		ft_free_arrays(&state);
		ft_error();
	}
	ft_print_stacks(&state);
	pb(&state, 1);
	ft_print_stacks(&state);
	pb(&state, 1);
	ft_print_stacks(&state);
	pb(&state, 1);
	ft_print_stacks(&state);
	pa(&state, 1);
	ft_print_stacks(&state);
	pb(&state, 1);
	ft_print_stacks(&state);
	sa(&state, 1);
	ft_print_stacks(&state);
	sb(&state, 1);
	ft_print_stacks(&state);
	ss(&state, 1);
	ft_print_stacks(&state);
	ra(&state, 1);
	ft_print_stacks(&state);
	rb(&state, 1);
	ft_print_stacks(&state);
	rr(&state, 1);
	ft_print_stacks(&state);
	rra(&state, 1);
	ft_print_stacks(&state);
	rrb(&state, 1);
	ft_print_stacks(&state);
	rrr(&state, 1);
	ft_print_stacks(&state);
	ft_free_arrays(&state);
	return (0);
}

// REMOVE FT_PRINT_STACKS BEFORE SUBMISSION
